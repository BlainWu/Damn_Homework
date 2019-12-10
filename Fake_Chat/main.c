//
// Created by peilin on 2019/12/10.
//

#include "stdio.h"
void window_name(void);
int main(){
    window_name();
}
void window_name(void){

    char line1[]={'########    ###    ##    ## ########     ######  ##     ##    ###    ######## '};
    char line2[]={'##         ## ##   ##   ##  ##          ##    ## ##     ##   ## ##      ##    '};
    char line3[]={'######   ##     ## #####    ######      ##       ######### ##     ##    ##   '};
    char line4[]={'##       ######### ##  ##   ##          ##       ##     ## #########    ##   '};
    char line5[]={'##       ##     ## ##   ##  ##          ##    ## ##     ## ##     ##    ##   '};
    char line6[]={'##       ##     ## ##    ## ########     ######  ##     ## ##     ##    ##   '};

    for(int i=0;i<79;i++)
    {
        printf("%c",line1[i]);
    }
    printf('\n');
    for(int i=0;i<77;i++)
    {
        printf("%c",line2[i]);
    }
    printf('\n');
    for(int i=0;i<77;i++)
    {
        printf("%c",line3[i]);
    }
    printf('\n');
    for(int i=0;i<77;i++)
    {
        printf("%c",line4[i]);
    }
    printf('\n');
    for(int i=0;i<77;i++)
    {
        printf("%c",line5[i]);
    }
    for(int i=0;i<77;i++)
    {
        printf("%c",line6[i]);
    }
    printf('\n');

}