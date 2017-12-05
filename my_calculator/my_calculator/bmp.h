#ifndef _BMP_H
#define _BMP_H
//这个文件是在Windows.h里定义过的，这里把它捞出来再用一遍，而无需再次包含Windows.h
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned long DWORD;
#define SIZE 40

#pragma pack(push)
#pragma pack(1)

typedef struct tagBITMAPFILEHEADER {
    WORD bfType;
    DWORD bfSize;    
    WORD bfReserved1;
    WORD bfReserved2;  
    DWORD bfOffBits; 
                         
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
    DWORD   biSize;   //   本结构所占用字节数 
    DWORD   biWidth;   //   位图的宽度，以像素为单位 
    DWORD   biHeight;   //   位图的高度，以像素为单位 
    WORD    biPlanes;   //   目标设备的级别，必须为1 
    WORD    biBitCount;//   每个像素所需的位数，必须是1(双色), 4(16色)，8(256色)或24(真彩色)之一 
    DWORD   biCompression;   //   位图压缩类型，必须是   0(不压缩), 1(BI_RLE8压缩类型)或2(BI_RLE4压缩类型)之一 
    DWORD   biSizeImage;   //   位图的大小，以字节为单位 
    DWORD   biXPelsPerMeter;   //   位图水平分辨率，每米像素数 
    DWORD   biYPelsPerMeter;   //   位图垂直分辨率，每米像素数 
    DWORD   biClrUsed;//   位图实际使用的颜色表中的颜色数 
    DWORD   biClrImportant;//   位图显示过程中重要的颜色数 
}BITMAPINFOHEADER;


#pragma pack(pop)

#endif
