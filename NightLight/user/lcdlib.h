// ------------------  汉字字模的数据结构定义 ------------------------ //
struct typFNT_GB16{                 // 汉字字模数据结构
       char Index[2];               // 汉字内码索引
       char Msk[32];                       // 点阵码数据
};



/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 汉字库: 繁宋16.dot 纵向取模下高位,数据排列:从左到右从上到下         //
/////////////////////////////////////////////////////////////////////////
const struct typFNT_GB16  GB_16[] =        // 数据表
{
"南", 0x04,0xE4,0x24,0x24,0x64,0xA4,0x24,0x3F,0x24,0xA4,0x64,0x24,0x24,0xE6,0x04,0x00,
      0x00,0xFF,0x00,0x09,0x09,0x09,0x09,0x7F,0x09,0x09,0x09,0x49,0x80,0x7F,0x00,0x00,

"京", 0x04,0x04,0x04,0xE4,0x24,0x24,0x25,0x26,0x24,0x24,0x24,0xE4,0x04,0x06,0x04,0x00,
      0x00,0x40,0x20,0x13,0x1A,0x42,0x82,0x7E,0x02,0x02,0x0A,0x13,0x30,0x60,0x00,0x00,

"师", 0x04,0xFE,0x45,0x44,0x44,0x7C,0x02,0xE2,0x22,0x22,0xFE,0x22,0x22,0xF3,0x22,0x00,
      0x00,0x7F,0x11,0x11,0x11,0x3F,0x00,0x3F,0x00,0x00,0xFF,0x10,0x20,0x1F,0x00,0x00,

"范", 0x00,0xA8,0xA4,0xA3,0xF6,0xAA,0xA2,0xA8,0x04,0xE3,0x26,0x2A,0x22,0xE2,0x00,0x00,
      0x20,0x2F,0x2A,0x2A,0xFF,0x2A,0x2A,0x2F,0x20,0x7F,0x40,0x44,0x48,0x47,0x70,0x00,

"大", 0x20,0x20,0x20,0x20,0x20,0x20,0xA0,0x7F,0xA0,0x20,0x20,0x20,0x20,0x30,0x20,0x00,
      0x00,0x40,0x40,0x20,0x10,0x0C,0x03,0x00,0x01,0x06,0x08,0x10,0x20,0x60,0x20,0x00,

"学", 0x00,0xC0,0x7F,0x55,0x55,0x40,0x55,0x4A,0x55,0x40,0x55,0x55,0x7F,0x40,0xC0,0x00,
      0x09,0x08,0x08,0x09,0x09,0x49,0x89,0x7D,0x0D,0x0B,0x09,0x08,0x08,0x09,0x08,0x00,

"电", 0x00,0xF8,0x48,0x48,0x48,0x48,0xFF,0x48,0x48,0x48,0x48,0xFC,0x08,0x00,0x00,0x00,
      0x00,0x07,0x02,0x02,0x02,0x02,0x3F,0x42,0x42,0x42,0x42,0x47,0x40,0x70,0x00,0x00,

"压", 0x00,0x00,0xFE,0x02,0x82,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0xC3,0x82,0x00,0x00,
      0x40,0x30,0x0F,0x40,0x40,0x40,0x40,0x40,0x7F,0x40,0x42,0x44,0x4C,0x60,0x40,0x00,

"流", 0x10,0x22,0x64,0x0C,0x80,0x44,0x44,0x64,0x55,0x4E,0x44,0x54,0x66,0xC4,0x00,0x00,
      0x04,0x04,0xFE,0x01,0x00,0x80,0x40,0x3F,0x00,0xFF,0x00,0x3F,0x40,0x40,0x70,0x00,
      /*--  文字:  数  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"数", 0x10,0x92,0x54,0x38,0xFF,0x38,0x54,0x52,0x80,0xF0,0x1F,0x12,0x10,0xF0,0x10,0x00,
      0x42,0x42,0x2A,0x2E,0x13,0x1A,0x26,0x02,0x40,0x20,0x13,0x0C,0x33,0x60,0x20,0x00,

/*--  文字:  字  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"字", 0x00,0x10,0x0C,0x24,0x24,0x24,0x25,0x26,0xA4,0x64,0x24,0x04,0x14,0x0C,0x00,0x00,
      0x00,0x02,0x02,0x02,0x02,0x42,0x82,0x7F,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x00,

/*--  文字:  量  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"量", 0x40,0x40,0x40,0xDF,0x55,0x55,0x55,0xD5,0x55,0x55,0x55,0xDF,0x40,0x40,0x40,0x00,
0x40,0x40,0x40,0x57,0x55,0x55,0x55,0x7F,0x55,0x55,0x55,0x57,0x50,0x40,0x40,0x00,

/*--  文字:  理  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"理", 0x44,0x44,0xFC,0x44,0x44,0x00,0xFE,0x92,0x92,0xFE,0x92,0x92,0x92,0xFE,0x00,0x00,
0x10,0x10,0x0F,0x08,0x48,0x40,0x45,0x44,0x44,0x7F,0x44,0x44,0x44,0x45,0x40,0x00,

/*--  文字:  论  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"论", 0x40,0x41,0xCE,0x04,0x00,0x40,0x20,0xD0,0x0C,0x03,0x04,0x88,0x10,0x60,0x20,0x00,
0x00,0x00,0x7F,0x20,0x10,0x08,0x00,0x3F,0x42,0x42,0x41,0x41,0x41,0x70,0x00,0x00,

/*--  文字:  电  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"电", 0x00,0x00,0xF8,0x48,0x48,0x48,0x48,0xFF,0x48,0x48,0x48,0x48,0xF8,0x00,0x00,0x00,
0x00,0x00,0x0F,0x04,0x04,0x04,0x04,0x3F,0x44,0x44,0x44,0x44,0x4F,0x40,0x70,0x00,

/*--  文字:  压  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"压", 0x00,0x00,0xFE,0x02,0x42,0x42,0x42,0x42,0xFA,0x42,0x42,0x42,0x62,0x42,0x02,0x00,
0x20,0x18,0x27,0x20,0x20,0x20,0x20,0x20,0x3F,0x20,0x21,0x2E,0x24,0x20,0x20,0x00,

/*--  文字:  值  --*/
/*--  宋体12;  此字体下对应的点阵为：宽x高=16x16   --*/
"值", 0x80,0x40,0xF0,0x2F,0x02,0x04,0xE4,0xA4,0xB4,0xAF,0xA6,0xA4,0xE4,0x04,0x00,0x00,
0x00,0x00,0xFF,0x00,0x40,0x40,0x7F,0x4A,0x4A,0x4A,0x4A,0x4A,0x7F,0x40,0x40,0x00,


};


// 汉字表：
// 南京师范大学电气

// ------------------  ASCII字模的数据表 ------------------------ //
// 码表从0x20~0x7e                                                //
// 字库: D:\study\C51\lcmzimo\lcmzimo\Asc8X16E.dat 纵向取模下高位 //
// -------------------------------------------------------------- //
struct ASCII8_16{
	unsigned char Msk[16];
};
const struct ASCII8_16 nAsciiDot[] =              // ASCII
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // - -0x20

	0x00,0x00,0x38,0xFC,0xFC,0x38,0x00,0x00,0x00,0x00,0x00,0x0D,0x0D,0x00,0x00,0x00, // -!-

	0x00,0x0E,0x1E,0x00,0x00,0x1E,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // -"-

	0x20,0xF8,0xF8,0x20,0xF8,0xF8,0x20,0x00,0x02,0x0F,0x0F,0x02,0x0F,0x0F,0x02,0x00, // -#-

	0x38,0x7C,0x44,0x47,0x47,0xCC,0x98,0x00,0x03,0x06,0x04,0x1C,0x1C,0x07,0x03,0x00, // -$-

	0x30,0x30,0x00,0x80,0xC0,0x60,0x30,0x00,0x0C,0x06,0x03,0x01,0x00,0x0C,0x0C,0x00, // -%-

	0x80,0xD8,0x7C,0xE4,0xBC,0xD8,0x40,0x00,0x07,0x0F,0x08,0x08,0x07,0x0F,0x08,0x00, // -&-

	0x00,0x10,0x1E,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // -'-

	0x00,0x00,0xF0,0xF8,0x0C,0x04,0x00,0x00,0x00,0x00,0x03,0x07,0x0C,0x08,0x00,0x00, // -(-

	0x00,0x00,0x04,0x0C,0xF8,0xF0,0x00,0x00,0x00,0x00,0x08,0x0C,0x07,0x03,0x00,0x00, // -)-

	0x80,0xA0,0xE0,0xC0,0xC0,0xE0,0xA0,0x80,0x00,0x02,0x03,0x01,0x01,0x03,0x02,0x00, // -*-

	0x00,0x80,0x80,0xE0,0xE0,0x80,0x80,0x00,0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x00, // -+-

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x1E,0x0E,0x00,0x00,0x00, // -,-

	0x80,0x80,0x80,0x80,0x80,0x80,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ---

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00, // -.-

	0x00,0x00,0x00,0x80,0xC0,0x60,0x30,0x00,0x0C,0x06,0x03,0x01,0x00,0x00,0x00,0x00, // -/-

	0xF8,0xFC,0x04,0xC4,0x24,0xFC,0xF8,0x00,0x07,0x0F,0x09,0x08,0x08,0x0F,0x07,0x00, // -0-

	0x00,0x10,0x18,0xFC,0xFC,0x00,0x00,0x00,0x00,0x08,0x08,0x0F,0x0F,0x08,0x08,0x00, // -1-

	0x08,0x0C,0x84,0xC4,0x64,0x3C,0x18,0x00,0x0E,0x0F,0x09,0x08,0x08,0x0C,0x0C,0x00, // -2-

	0x08,0x0C,0x44,0x44,0x44,0xFC,0xB8,0x00,0x04,0x0C,0x08,0x08,0x08,0x0F,0x07,0x00, // -3-

	0xC0,0xE0,0xB0,0x98,0xFC,0xFC,0x80,0x00,0x00,0x00,0x00,0x08,0x0F,0x0F,0x08,0x00, // -4-

	0x7C,0x7C,0x44,0x44,0xC4,0xC4,0x84,0x00,0x04,0x0C,0x08,0x08,0x08,0x0F,0x07,0x00, // -5-

	0xF0,0xF8,0x4C,0x44,0x44,0xC0,0x80,0x00,0x07,0x0F,0x08,0x08,0x08,0x0F,0x07,0x00, // -6-

	0x0C,0x0C,0x04,0x84,0xC4,0x7C,0x3C,0x00,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00,0x00, // -7-

	0xB8,0xFC,0x44,0x44,0x44,0xFC,0xB8,0x00,0x07,0x0F,0x08,0x08,0x08,0x0F,0x07,0x00, // -8-

	0x38,0x7C,0x44,0x44,0x44,0xFC,0xF8,0x00,0x00,0x08,0x08,0x08,0x0C,0x07,0x03,0x00, // -9-

	0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x00,0x00,0x00, // -:-

	0x00,0x00,0x00,0x30,0x30,0x00,0x00,0x00,0x00,0x00,0x08,0x0E,0x06,0x00,0x00,0x00, // -;-

	0x00,0x80,0xC0,0x60,0x30,0x18,0x08,0x00,0x00,0x00,0x01,0x03,0x06,0x0C,0x08,0x00, // -<-

	0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x00, // -=-

	0x00,0x08,0x18,0x30,0x60,0xC0,0x80,0x00,0x00,0x08,0x0C,0x06,0x03,0x01,0x00,0x00, // ->-

	0x18,0x1C,0x04,0xC4,0xE4,0x3C,0x18,0x00,0x00,0x00,0x00,0x0D,0x0D,0x00,0x00,0x00, // -?-

	0xF0,0xF8,0x08,0xC8,0xC8,0xF8,0xF0,0x00,0x07,0x0F,0x08,0x0B,0x0B,0x0B,0x01,0x00, // -@-

	0xE0,0xF0,0x98,0x8C,0x98,0xF0,0xE0,0x00,0x0F,0x0F,0x00,0x00,0x00,0x0F,0x0F,0x00, // -A-

	0x04,0xFC,0xFC,0x44,0x44,0xFC,0xB8,0x00,0x08,0x0F,0x0F,0x08,0x08,0x0F,0x07,0x00, // -B-

	0xF0,0xF8,0x0C,0x04,0x04,0x0C,0x18,0x00,0x03,0x07,0x0C,0x08,0x08,0x0C,0x06,0x00, // -C-

	0x04,0xFC,0xFC,0x04,0x0C,0xF8,0xF0,0x00,0x08,0x0F,0x0F,0x08,0x0C,0x07,0x03,0x00, // -D-

	0x04,0xFC,0xFC,0x44,0xE4,0x0C,0x1C,0x00,0x08,0x0F,0x0F,0x08,0x08,0x0C,0x0E,0x00, // -E-

	0x04,0xFC,0xFC,0x44,0xE4,0x0C,0x1C,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00,0x00,0x00, // -F-

	0xF0,0xF8,0x0C,0x84,0x84,0x8C,0x98,0x00,0x03,0x07,0x0C,0x08,0x08,0x07,0x0F,0x00, // -G-

	0xFC,0xFC,0x40,0x40,0x40,0xFC,0xFC,0x00,0x0F,0x0F,0x00,0x00,0x00,0x0F,0x0F,0x00, // -H-

	0x00,0x00,0x04,0xFC,0xFC,0x04,0x00,0x00,0x00,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00, // -I-

	0x00,0x00,0x00,0x04,0xFC,0xFC,0x04,0x00,0x07,0x0F,0x08,0x08,0x0F,0x07,0x00,0x00, // -J-

	0x04,0xFC,0xFC,0xC0,0xF0,0x3C,0x0C,0x00,0x08,0x0F,0x0F,0x00,0x01,0x0F,0x0E,0x00, // -K-

	0x04,0xFC,0xFC,0x04,0x00,0x00,0x00,0x00,0x08,0x0F,0x0F,0x08,0x08,0x0C,0x0E,0x00, // -L-

	0xFC,0xFC,0x38,0x70,0x38,0xFC,0xFC,0x00,0x0F,0x0F,0x00,0x00,0x00,0x0F,0x0F,0x00, // -M-

	0xFC,0xFC,0x38,0x70,0xE0,0xFC,0xFC,0x00,0x0F,0x0F,0x00,0x00,0x00,0x0F,0x0F,0x00, // -N-

	0xF0,0xF8,0x0C,0x04,0x0C,0xF8,0xF0,0x00,0x03,0x07,0x0C,0x08,0x0C,0x07,0x03,0x00, // -O-

	0x04,0xFC,0xFC,0x44,0x44,0x7C,0x38,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00,0x00,0x00, // -P-

	0xF8,0xFC,0x04,0x04,0x04,0xFC,0xF8,0x00,0x07,0x0F,0x08,0x0E,0x3C,0x3F,0x27,0x00, // -Q-

	0x04,0xFC,0xFC,0x44,0xC4,0xFC,0x38,0x00,0x08,0x0F,0x0F,0x00,0x00,0x0F,0x0F,0x00, // -R-

	0x18,0x3C,0x64,0x44,0xC4,0x9C,0x18,0x00,0x06,0x0E,0x08,0x08,0x08,0x0F,0x07,0x00, // -S-

	0x00,0x1C,0x0C,0xFC,0xFC,0x0C,0x1C,0x00,0x00,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00, // -T-

	0xFC,0xFC,0x00,0x00,0x00,0xFC,0xFC,0x00,0x07,0x0F,0x08,0x08,0x08,0x0F,0x07,0x00, // -U-

	0xFC,0xFC,0x00,0x00,0x00,0xFC,0xFC,0x00,0x01,0x03,0x06,0x0C,0x06,0x03,0x01,0x00, // -V-

	0xFC,0xFC,0x00,0x80,0x00,0xFC,0xFC,0x00,0x03,0x0F,0x0E,0x03,0x0E,0x0F,0x03,0x00, // -W-

	0x0C,0x3C,0xF0,0xC0,0xF0,0x3C,0x0C,0x00,0x0C,0x0F,0x03,0x00,0x03,0x0F,0x0C,0x00, // -X-

	0x00,0x3C,0x7C,0xC0,0xC0,0x7C,0x3C,0x00,0x00,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00, // -Y-

	0x1C,0x0C,0x84,0xC4,0x64,0x3C,0x1C,0x00,0x0E,0x0F,0x09,0x08,0x08,0x0C,0x0E,0x00, // -Z-

	0x00,0x00,0xFC,0xFC,0x04,0x04,0x00,0x00,0x00,0x00,0x0F,0x0F,0x08,0x08,0x00,0x00, // -[-

	0x38,0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x0E,0x00, // -\-

	0x00,0x00,0x04,0x04,0xFC,0xFC,0x00,0x00,0x00,0x00,0x08,0x08,0x0F,0x0F,0x00,0x00, // -]-

	0x08,0x0C,0x06,0x03,0x06,0x0C,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // -^-

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20, // -_-

	0x00,0x00,0x03,0x07,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // -`-

	0x00,0xA0,0xA0,0xA0,0xE0,0xC0,0x00,0x00,0x07,0x0F,0x08,0x08,0x07,0x0F,0x08,0x00, // -a-

	0x04,0xFC,0xFC,0x20,0x60,0xC0,0x80,0x00,0x08,0x0F,0x07,0x08,0x08,0x0F,0x07,0x00, // -b-

	0xC0,0xE0,0x20,0x20,0x20,0x60,0x40,0x00,0x07,0x0F,0x08,0x08,0x08,0x0C,0x04,0x00, // -c-

	0x80,0xC0,0x60,0x24,0xFC,0xFC,0x00,0x00,0x07,0x0F,0x08,0x08,0x07,0x0F,0x08,0x00, // -d-

	0xC0,0xE0,0xA0,0xA0,0xA0,0xE0,0xC0,0x00,0x07,0x0F,0x08,0x08,0x08,0x0C,0x04,0x00, // -e-

	0x40,0xF8,0xFC,0x44,0x0C,0x18,0x00,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00,0x00,0x00, // -f-

	0xC0,0xE0,0x20,0x20,0xC0,0xE0,0x20,0x00,0x27,0x6F,0x48,0x48,0x7F,0x3F,0x00,0x00, // -g-

	0x04,0xFC,0xFC,0x40,0x20,0xE0,0xC0,0x00,0x08,0x0F,0x0F,0x00,0x00,0x0F,0x0F,0x00, // -h-

	0x00,0x00,0x20,0xEC,0xEC,0x00,0x00,0x00,0x00,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00, // -i-

	0x00,0x00,0x00,0x00,0x20,0xEC,0xEC,0x00,0x00,0x30,0x70,0x40,0x40,0x7F,0x3F,0x00, // -j-

	0x04,0xFC,0xFC,0x80,0xC0,0x60,0x20,0x00,0x08,0x0F,0x0F,0x01,0x03,0x0E,0x0C,0x00, // -k-

	0x00,0x00,0x04,0xFC,0xFC,0x00,0x00,0x00,0x00,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00, // -l-

	0xE0,0xE0,0x60,0xC0,0x60,0xE0,0xC0,0x00,0x0F,0x0F,0x00,0x0F,0x00,0x0F,0x0F,0x00, // -m-

	0x20,0xE0,0xC0,0x20,0x20,0xE0,0xC0,0x00,0x00,0x0F,0x0F,0x00,0x00,0x0F,0x0F,0x00, // -n-

	0xC0,0xE0,0x20,0x20,0x20,0xE0,0xC0,0x00,0x07,0x0F,0x08,0x08,0x08,0x0F,0x07,0x00, // -o-

	0x20,0xE0,0xC0,0x20,0x20,0xE0,0xC0,0x00,0x40,0x7F,0x7F,0x48,0x08,0x0F,0x07,0x00, // -p-

	0xC0,0xE0,0x20,0x20,0xC0,0xE0,0x20,0x00,0x07,0x0F,0x08,0x48,0x7F,0x7F,0x40,0x00, // -q-

	0x20,0xE0,0xC0,0x60,0x20,0x60,0xC0,0x00,0x08,0x0F,0x0F,0x08,0x00,0x00,0x00,0x00, // -r-

	0x40,0xE0,0xA0,0x20,0x20,0x60,0x40,0x00,0x04,0x0C,0x09,0x09,0x0B,0x0E,0x04,0x00, // -s-

	0x20,0x20,0xF8,0xFC,0x20,0x20,0x00,0x00,0x00,0x00,0x07,0x0F,0x08,0x0C,0x04,0x00, // -t-

	0xE0,0xE0,0x00,0x00,0xE0,0xE0,0x00,0x00,0x07,0x0F,0x08,0x08,0x07,0x0F,0x08,0x00, // -u-

	0x00,0xE0,0xE0,0x00,0x00,0xE0,0xE0,0x00,0x00,0x03,0x07,0x0C,0x0C,0x07,0x03,0x00, // -v-

	0xE0,0xE0,0x00,0x00,0x00,0xE0,0xE0,0x00,0x07,0x0F,0x0C,0x07,0x0C,0x0F,0x07,0x00, // -w-

	0x20,0x60,0xC0,0x80,0xC0,0x60,0x20,0x00,0x08,0x0C,0x07,0x03,0x07,0x0C,0x08,0x00, // -x-

	0xE0,0xE0,0x00,0x00,0x00,0xE0,0xE0,0x00,0x47,0x4F,0x48,0x48,0x68,0x3F,0x1F,0x00, // -y-

	0x60,0x60,0x20,0xA0,0xE0,0x60,0x20,0x00,0x0C,0x0E,0x0B,0x09,0x08,0x0C,0x0C,0x00, // -z-

	0x00,0x40,0x40,0xF8,0xBC,0x04,0x04,0x00,0x00,0x00,0x00,0x07,0x0F,0x08,0x08,0x00, // -{-

	0x00,0x00,0x00,0xBC,0xBC,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x0F,0x00,0x00,0x00, // -|-

	0x00,0x04,0x04,0xBC,0xF8,0x40,0x40,0x00,0x00,0x08,0x08,0x0F,0x07,0x00,0x00,0x00, // -}-

	0x08,0x0C,0x04,0x0C,0x08,0x0C,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // -~-

	0x80,0xC0,0x60,0x30,0x60,0xC0,0x80,0x00,0x07,0x07,0x04,0x04,0x04,0x07,0x07,0x00, // --
};

// ------------------  ASCII字模的数据表 ------------------------ //
// 码表从0x20~0x7e                                                //
// 字库: F:\NEUDC\竞赛培训\LCD12864\LCD取模软件\Asc6X12E.dat 纵向取模下高位//
// -------------------------------------------------------------- //
struct ASCII6_12{
	unsigned char Msk[12];
};
const struct ASCII6_12 nAsciiDots[] =              // ASCII
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // - -

	0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x09,0x00,0x00, // -!-

	0x00,0x70,0x10,0x00,0x70,0x10,0x00,0x00,0x00,0x00,0x00,0x00, // -"-

	0x00,0x80,0xC0,0xB0,0xC0,0xB0,0x00,0x1A,0x07,0x1A,0x07,0x02, // -#-

	0x00,0xC0,0x20,0x30,0x20,0x00,0x00,0x06,0x05,0x1D,0x03,0x00, // -$-

	0x00,0x20,0x50,0x20,0x80,0x80,0x00,0x01,0x01,0x05,0x0A,0x04, // -%-

	0x00,0x00,0x80,0x40,0x40,0x00,0x00,0x06,0x09,0x0A,0x04,0x0A, // -&-

	0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // -'-

	0x00,0x00,0x00,0xC0,0x30,0x00,0x00,0x00,0x00,0x0F,0x30,0x00, // -(-

	0x00,0x00,0x30,0xC0,0x00,0x00,0x00,0x00,0x30,0x0F,0x00,0x00, // -)-

	0x00,0x20,0xA0,0x70,0xA0,0x20,0x00,0x00,0x01,0x00,0x01,0x00, // -*-

	0x00,0x00,0x00,0xE0,0x00,0x00,0x01,0x01,0x01,0x0F,0x01,0x01, // -+-

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x1C,0x04,0x00, // -,-

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x01, // ---

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00,0x00, // -.-

	0x00,0x00,0x00,0x00,0xC0,0x30,0x00,0x10,0x0C,0x03,0x00,0x00, // -/-

	0x00,0xE0,0x10,0x10,0x10,0xE0,0x00,0x07,0x08,0x08,0x08,0x07, // -0-

	0x00,0x00,0x10,0xF0,0x00,0x00,0x00,0x08,0x08,0x0F,0x08,0x08, // -1-

	0x00,0x20,0x10,0x10,0x90,0x60,0x00,0x0C,0x0A,0x09,0x08,0x0C, // -2-

	0x00,0x20,0x10,0x90,0x90,0x60,0x00,0x04,0x08,0x08,0x08,0x07, // -3-

	0x00,0x00,0x80,0x60,0x10,0xF0,0x00,0x03,0x02,0x02,0x0A,0x0F, // -4-

	0x00,0x00,0xF0,0x90,0x90,0x10,0x00,0x04,0x08,0x08,0x08,0x07, // -5-

	0x00,0xC0,0xA0,0x90,0x90,0x10,0x00,0x07,0x08,0x08,0x08,0x07, // -6-

	0x00,0x30,0x10,0x10,0x90,0x70,0x00,0x00,0x00,0x0C,0x03,0x00, // -7-

	0x00,0x60,0x90,0x90,0x90,0x60,0x00,0x07,0x08,0x08,0x08,0x07, // -8-

	0x00,0xE0,0x10,0x10,0x10,0xE0,0x00,0x08,0x09,0x09,0x05,0x03, // -9-

	0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x00,0x0C,0x0C,0x00,0x00, // -:-

	0x00,0x00,0x00,0xC0,0xC0,0x00,0x00,0x00,0x18,0x0C,0x04,0x00, // -;-

	0x00,0x80,0x80,0x40,0x20,0x20,0x01,0x02,0x02,0x04,0x08,0x08, // -<-

	0x00,0x80,0x80,0x80,0x80,0x80,0x00,0x02,0x02,0x02,0x02,0x02, // -=-

	0x20,0x20,0x40,0x80,0x80,0x00,0x08,0x08,0x04,0x02,0x02,0x01, // ->-

	0x00,0x00,0x40,0x20,0x20,0xC0,0x00,0x00,0x08,0x0A,0x01,0x00, // -?-

	0x00,0xF0,0x08,0x88,0x48,0xF0,0x00,0x0F,0x10,0x11,0x12,0x0B, // -@-

	0x00,0x00,0xD0,0x30,0xC0,0x00,0x08,0x0E,0x0B,0x02,0x0B,0x0E, // -A-

	0x10,0xF0,0x90,0x90,0x90,0x60,0x08,0x0F,0x08,0x08,0x08,0x07, // -B-

	0x00,0xE0,0x10,0x10,0x10,0x30,0x00,0x07,0x08,0x08,0x08,0x04, // -C-

	0x10,0xF0,0x10,0x10,0x20,0xC0,0x08,0x0F,0x08,0x08,0x04,0x03, // -D-

	0x10,0xF0,0x90,0xD0,0x10,0x30,0x08,0x0F,0x08,0x09,0x08,0x0C, // -E-

	0x00,0x10,0xF0,0x90,0xD0,0x10,0x00,0x08,0x0F,0x08,0x01,0x00, // -F-

	0x00,0xE0,0x10,0x10,0x10,0x30,0x00,0x07,0x08,0x08,0x09,0x07, // -G-

	0x10,0xF0,0x90,0x80,0x90,0xF0,0x08,0x0F,0x08,0x00,0x08,0x0F, // -H-

	0x00,0x10,0x10,0xF0,0x10,0x10,0x00,0x08,0x08,0x0F,0x08,0x08, // -I-

	0x00,0x00,0x10,0x10,0xF0,0x10,0x00,0x07,0x08,0x08,0x07,0x00, // -J-

	0x10,0xF0,0x10,0x80,0x50,0x30,0x08,0x0F,0x09,0x01,0x02,0x0C, // -K-

	0x00,0x10,0xF0,0x10,0x00,0x00,0x00,0x08,0x0F,0x08,0x08,0x0E, // -L-

	0x10,0xF0,0x70,0x80,0x70,0xF0,0x08,0x0F,0x08,0x01,0x08,0x0F, // -M-

	0x10,0xF0,0x70,0x80,0x10,0xF0,0x08,0x0F,0x08,0x03,0x0C,0x0F, // -N-

	0x00,0xE0,0x10,0x10,0x10,0xE0,0x00,0x07,0x08,0x08,0x08,0x07, // -O-

	0x00,0x10,0xF0,0x10,0x10,0xE0,0x00,0x08,0x0F,0x09,0x01,0x00, // -P-

	0x00,0xE0,0x10,0x10,0x10,0xE0,0x00,0x07,0x08,0x18,0x18,0x17, // -Q-

	0x10,0xF0,0x10,0x10,0x10,0xE0,0x08,0x0F,0x09,0x01,0x03,0x04, // -R-

	0x00,0x60,0x90,0x90,0xA0,0x30,0x00,0x0C,0x04,0x08,0x08,0x07, // -S-

	0x30,0x10,0x10,0xF0,0x10,0x10,0x00,0x00,0x08,0x0F,0x08,0x00, // -T-

	0x10,0xF0,0x10,0x00,0x10,0xF0,0x00,0x07,0x08,0x08,0x08,0x07, // -U-

	0x10,0x70,0x90,0x00,0x90,0x70,0x00,0x00,0x03,0x0C,0x03,0x00, // -V-

	0x10,0xF0,0x10,0x80,0x10,0xF0,0x00,0x07,0x08,0x07,0x08,0x07, // -W-

	0x10,0x30,0x40,0x80,0x40,0x30,0x08,0x0C,0x02,0x01,0x02,0x0C, // -X-

	0x10,0x30,0xD0,0x00,0xD0,0x30,0x00,0x00,0x08,0x0F,0x08,0x00, // -Y-

	0x00,0x30,0x10,0x90,0x50,0x30,0x00,0x0C,0x0A,0x09,0x08,0x0C, // -Z-

	0x00,0x00,0xF0,0x10,0x10,0x00,0x00,0x00,0x3F,0x20,0x20,0x00, // -[-

	0x00,0x10,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x1C,0x00, // -\-

	0x00,0x00,0x10,0x10,0xF0,0x00,0x00,0x00,0x20,0x20,0x3F,0x00, // -]-

	0x00,0x80,0x40,0x30,0x40,0x80,0x00,0x00,0x00,0x00,0x00,0x00, // -^-

	0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x40,0x40,0x40,0x40,0x40, // -_-

	0x00,0x00,0x00,0x10,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // -`-

	0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x06,0x09,0x09,0x09,0x0F, // -a-

	0x10,0xF0,0x80,0x40,0x40,0x80,0x08,0x0F,0x08,0x08,0x08,0x07, // -b-

	0x00,0x80,0x40,0x40,0x40,0xC0,0x00,0x07,0x08,0x08,0x08,0x04, // -c-

	0x00,0x80,0x40,0x40,0x90,0xF0,0x00,0x07,0x08,0x08,0x08,0x0F, // -d-

	0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x07,0x09,0x09,0x09,0x09, // -e-

	0x00,0x40,0xE0,0x50,0x50,0x50,0x00,0x08,0x0F,0x08,0x08,0x08, // -f-

	0x00,0x80,0x40,0x40,0x80,0xC0,0x00,0x07,0x28,0x28,0x28,0x1F, // -g-

	0x10,0xF0,0x80,0x40,0x40,0x80,0x08,0x0F,0x08,0x00,0x08,0x0F, // -h-

	0x00,0x40,0x40,0xD0,0x00,0x00,0x00,0x08,0x08,0x0F,0x08,0x08, // -i-

	0x00,0x40,0x40,0x50,0xC0,0x00,0x00,0x20,0x20,0x20,0x1F,0x00, // -j-

	0x10,0xF0,0x00,0x40,0xC0,0x40,0x08,0x0F,0x01,0x0B,0x0C,0x08, // -k-

	0x00,0x00,0x10,0xF0,0x00,0x00,0x00,0x08,0x08,0x0F,0x08,0x08, // -l-

	0x40,0xC0,0x40,0x80,0x40,0x80,0x08,0x0F,0x08,0x0F,0x08,0x0F, // -m-

	0x40,0xC0,0x80,0x40,0x40,0x80,0x08,0x0F,0x08,0x00,0x08,0x0F, // -n-

	0x00,0x80,0x40,0x40,0x40,0x80,0x00,0x07,0x08,0x08,0x08,0x07, // -o-

	0x40,0xC0,0x80,0x40,0x40,0x80,0x20,0x3F,0x28,0x08,0x08,0x07, // -p-

	0x00,0x80,0x40,0x40,0x80,0xC0,0x00,0x07,0x08,0x08,0x28,0x3F, // -q-

	0x00,0x40,0xC0,0x80,0x40,0x40,0x00,0x08,0x0F,0x08,0x08,0x08, // -r-

	0x00,0x80,0x40,0x40,0x40,0xC0,0x00,0x0C,0x09,0x09,0x09,0x06, // -s-

	0x00,0x40,0xE0,0x40,0x40,0x40,0x00,0x00,0x07,0x08,0x08,0x08, // -t-

	0x40,0xC0,0x00,0x00,0x40,0xC0,0x00,0x07,0x08,0x08,0x04,0x0F, // -u-

	0x40,0xC0,0x40,0x00,0x40,0xC0,0x00,0x01,0x06,0x08,0x06,0x01, // -v-

	0x40,0xC0,0x40,0x00,0x40,0xC0,0x00,0x07,0x08,0x07,0x08,0x07, // -w-

	0x40,0xC0,0x00,0x00,0xC0,0x40,0x08,0x0C,0x03,0x03,0x0C,0x08, // -x-

	0x40,0xC0,0x40,0x00,0x40,0xC0,0x00,0x20,0x23,0x3C,0x26,0x01, // -y-

	0x00,0xC0,0x40,0x40,0xC0,0x40,0x00,0x0C,0x0A,0x09,0x08,0x0C, // -z-

	0x00,0x00,0x00,0xE0,0x10,0x00,0x00,0x00,0x02,0x1D,0x20,0x00, // -{-

	0x00,0x00,0x00,0xF0,0x00,0x00,0x00,0x00,0x00,0x1F,0x00,0x00, // -|-

	0x00,0x00,0x10,0xE0,0x00,0x00,0x00,0x00,0x20,0x1D,0x02,0x00, // -}-

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x01,0x02,0x02,0x01, // -~-

	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // --
};






