#include <MKL25Z4.H>
#define BUF_SIZE 30
void delay(int n);
void UART0_init (void);
void UART1_init (void);
void UART0_Tx (uint8_t data);
uint8_t UART0_Rx ( void );
void UART1_Tx (uint8_t data);
uint8_t UART1_Rx (void);
void window_name(void);
void space(int m);
void friend_name(void); // the friend name
void host_name(void); // myself name
void still_my_text(int m);
char reci_message[BUF_SIZE]={0};
int reci_count,count=0,reciev_flag=0;
char message[BUF_SIZE]={0};
void green_bubble_pre(void);
void green_bubble_back(void);
void white_bubble_pre(void);
void white_bubble_back(void);

int main()
	{
    UART0_init();
    UART1_init();
    window_name();
    char temp;
    while(1){
        reci_count=0;
        if(UART1->S1&0x20)
        {
            while(1){
                temp=UART1_Rx();
                reci_message[reci_count] = temp;

                if((temp=='\r')&&(reci_count==0))//when the other transmit and empty
                {
                    for(int i;i<count;i++)//cover the unfinished msg
                    {
                        UART0_Tx('\b');
                    }
                    for(int i;i<count;i++)//cover the unfinished msg
                    {
                        UART0_Tx(' ');
                    }
                    for(int i;i<count;i++)//cover the unfinished msg
                    {
                        UART0_Tx('\b');
                    }
                    friend_name();
                    green_bubble_pre();UART0_Tx(' ');green_bubble_back();
                    reciev_flag=1;
                    break;
                }
                else if(temp=='\r')//when the other transmit and not empty
                {
                    for(int i;i<count;i++)//cover the unfinished msg
                    {
                        UART0_Tx('\b');
                    }
                    for(int i;i<count;i++)//cover the unfinished msg
                    {
                        UART0_Tx(' ');
                    }
                    for(int i;i<count;i++)//cover the unfinished msg
                    {
                        UART0_Tx('\b');
                    }
                    friend_name();
                    reciev_flag=1;
                    break;
                }
                    reci_count++;//store the msg recived
                    }
        }
        
        for(int i =0;i<reci_count;i++)//show the msg got
        {
            if(i==0) white_bubble_pre();
            UART0_Tx(reci_message[i]);
            reci_message[i] = 0;
            if(i==reci_count-1) white_bubble_back();
        }
        if(reciev_flag) //show the unfinsed msg
        {
            UART0_Tx('\r');
            UART0_Tx('\n');
            for(int i =0;i<count;i++)
            {
                UART0_Tx(message[i]);
            }
            reciev_flag=0;
        }
        while(UART0->S1&0x20)
        {
            uint8_t dt;
            dt = UART0_Rx();
            delay(10);
            UART0_Tx(dt);
            if(dt == '\b')
            {
                UART0_Tx(' ');
                UART0_Tx('\b');
                message[count-1]=0;
                count--;
                continue;
            }
            message[count]= dt;
            count++;

            if(dt == '\r')
            {
                for(int i =0;i<count;i++) //clear the temp msg
                {
                    UART0_Tx('\b');
                }
                for(int i =0;i<count;i++) //clear the temp msg
                {
                    UART0_Tx(' ');
                }

                space(50);
                host_name();

                for(int i =0;i<count+4;i++) //make sure the right side on parall
                {
                    UART0_Tx('\b');
                }
                for(int i =0;i<count;i++) //show the local msg
                {
                    if(i==0) green_bubble_pre();
                    UART0_Tx(message[i]);
                    UART1_Tx(message[i]);//transmit msg and clear local message buffer
                    message[i] = 0;
                    if(i==count-1) green_bubble_back();
                }
                UART0_Tx('\r');
                UART0_Tx('\n');
                count = 0;
          }
				}
		}
}
void delay(int n)
{
    int i=0;
    while(i<n)
    {
        i=i+1;
    }
}

void UART0_init (void){
    SIM ->SCGC4 |= 0x0400 ; // enable clock for UART0
    SIM ->SOPT2 |= 0x04000000 ; // use MCGFLLCLK output for UART Baud rate generator
    UART0 ->C2 = 0 ; // turn off UART0 while changing configurations
    UART0 ->BDH = 0x00;
    UART0 ->BDL = 0x17 ; //57600 Baud ?? Please double check
    UART0 ->C4 = 0x0F ; // Over Sampling Ratio 16
    UART0 ->C1 = 0x00 ; // 8 bit data
    UART0 ->C2 = 0x0C ; // enable transmit
    SIM ->SCGC5 |= 0x0200; // enable clock for PORTA
    PORTA ->PCR[1] = 0x0200; // make PTA1 UART0_Rx pin
    PORTA ->PCR[2] = 0x0200; // make PTA2 UART0_Tx pin
}
void UART0_Tx (uint8_t data){ //output the character
    while (!(UART0 ->S1 & 0x80));
    UART0 ->D = data;
}
uint8_t UART0_Rx ( void ){
    while (!(UART0 ->S1 & 0x20));
    return UART0 -> D;
}
void UART1_init (void){
    SIM ->SCGC4 |= (1u<<11) ; // enable clock for UART1
    SIM ->SOPT2 |= 0x04000000 ; // use MCGFLLCLK output for UART Baud rate generator
    UART1 ->C2 = 0 ; // turn off UART1 while changing configurations

    UART1 ->BDH = 0x00;
    UART1 ->BDL = 0x17 ; //57600 Baud ?? Please double check
    UART1 ->C4 = 0x0F ; // Over Sampling Ratio 16

    UART1 ->C1 = 0x00 ; // 8 bit data
    UART1 ->C2 = 0x0C ; // enable transmit
    SIM ->SCGC5 |= (1U<<13); // enable clock for PORTA
    PORTE ->PCR[0] = (0b011<<8); // make PTE0 UART1_Rx pin
    PORTE ->PCR[1] = (0b011<<8); // make PTE1 UART1_Tx pin
}
void UART1_Tx (uint8_t data){
    while (!(UART1 ->S1 & 0x80));
    UART1 ->D = data;
}
uint8_t UART1_Rx ( void ){
    while (!(UART1 ->S1 & 0x20));
    return UART1 -> D;
}
void host_name(void){
    char host_name[3] = ":me";
    for(int i=0;i<3;i++)
    {
        UART0_Tx(host_name[i]);
    }
}
void window_name(void){
    //char line1[35]=" CCCCCC  HH   HH   AA     TTTTTT \r\n";
    //char line3[35]="CC       HHHHHHH  A   A     TT   \r\n";
    //char line4[35]="CC       HH   HH AAAAAAA    TT   \r\n";
    //char line6[35]=" CCCCCC  HH   HH AA    AA   TT   \r\n";

    char line1[35]=" CCCCCC  HH   HH    A     TTTTTT \r\n";
    char line3[35]="CC       HHHHHHH   A  A     TT   \r\n";
    char line4[35]="CC       HH   HH  AAAAAA    TT   \r\n";
    char line6[35]=" CCCCCC  HH   HH AA    AA   TT   \r\n";

    for(int i=0;i<35;i++)
    {
        UART0_Tx(line1[i]);
    }


    for(int i=0;i<35;i++)
    {
        UART0_Tx(line3[i]);
    }

    for(int i=0;i<35;i++)
    {
        UART0_Tx(line4[i]);
    }

    for(int i=0;i<35;i++)
    {
        UART0_Tx(line6[i]);
    }
    UART0_Tx('\n');
}
void friend_name(void){
    char terminal[22] = "\033[31mEbby:\033[0m";
    for(int i=0;i<22;i++)
    {
        UART0_Tx(terminal[i]);
    }
}
void space(int m){
    for(int i=0;i<m;i++)
    {
        UART0_Tx(' ');
    }
}
void green_bubble_pre(void)
{
    char pre[12]="\033[30;42m ";
    for(int i =0;i<12;i++)
    {
        UART0_Tx(pre[i]);
    }
}
void green_bubble_back(void){
    char back[7]="\033[0m";
    for(int i =0;i<7;i++)
    {
        UART0_Tx(back[i]);
    }
}

void white_bubble_pre(void){
    char pre[12]="\033[30;47m ";
    for(int i =0;i<12;i++)
    {
        UART0_Tx(pre[i]);
    }
}

void white_bubble_back(void){
    char pre[9]=" \033[0m";
    for(int i =0;i<9;i++)
    {
        UART0_Tx(pre[i]);
    }
}