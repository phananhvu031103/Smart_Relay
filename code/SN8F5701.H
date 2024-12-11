/*--------------------------------------------------------------------------
SN8F5701.H

Header file for SNOiX SN8F5701 microcontroller.
Copyright (c) 2016 SONiX Technology Co., Ltd.

Version 1.1    2016-12-21
--------------------------------------------------------------------------*/

#ifndef __SN8F5701_H__
#define __SN8F5701_H__

/*      Register      */
// special function register
sfr     P0       = 0x80; // dinh nghia cong p0 tai dia chi 0x80
  sbit  P05      = P0^5; // cac bit trong thanh ghi cua fsr co the truy cap bang cach su dung tu khoa sbit
  sbit  P04      = P0^4;  // cho phep truy cap den bit t4 trong thanh ghi
  sbit  P03      = P0^3;
  sbit  P02      = P0^2;
  sbit  P01      = P0^1;
  sbit  P00      = P0^0;
sfr     SP       = 0x81;
sfr     DPL      = 0x82;
sfr     DPH      = 0x83;
sfr     WDTR     = 0x86;
sfr     PCON     = 0x87;
sfr     TCON     = 0x88;
  sbit  TF1      = TCON^7;
  sbit  TR1      = TCON^6;
  sbit  TF0      = TCON^5;
  sbit  TR0      = TCON^4;
  sbit  IE1      = TCON^3;
  sbit  IE0      = TCON^1;
sfr     TMOD     = 0x89;
sfr     TL0      = 0x8A;
sfr     TL1      = 0x8B;
sfr     TH0      = 0x8C;
sfr     TH1      = 0x8D;
sfr     CKCON    = 0x8E;
sfr     PEDGE    = 0x8F;
sfr     DPC      = 0x93;
sfr     PECMD    = 0x94;
sfr16   PEROM    = 0x95;
sfr     PEROML   = 0x95;
sfr     PEROMH   = 0x96;
sfr     PERAM    = 0x97;
sfr     S0CON    = 0x98;
  sbit  SM0      = S0CON^7;
  sbit  SM1      = S0CON^6;
  sbit  SM20     = S0CON^5;
  sbit  REN0     = S0CON^4;
  sbit  TB80     = S0CON^3;
  sbit  RB80     = S0CON^2;
  sbit  TI0      = S0CON^1;
  sbit  RI0      = S0CON^0;
sfr     S0BUF    = 0x99;
sfr     IEN2     = 0x9A;
sfr     P0CON    = 0x9E;
sfr			T3M			 = 0xA1;
sfr			T3CL		 = 0xA2;
sfr			T3CH		 = 0xA3;
sfr16   T3Y      = 0xA4;
sfr			T3YL		 = 0xA4;
sfr			T3YH		 = 0xA5;
sfr16   PW0D     = 0xA6;
sfr			PW0DL		 = 0xA6;
sfr			PW0DH		 = 0xA7;
sfr     IEN0     = 0xA8;
  sbit   EAL     = IEN0^7;
  sbit   ES0     = IEN0^4;
  sbit   ET1     = IEN0^3;
	sbit   EX1     = IEN0^2;	
  sbit   ET0     = IEN0^1;
  sbit   EX0     = IEN0^0;
sfr     IP0      = 0xA9;
sfr     S0RELL   = 0xAA;
sfr16   PW1D     = 0xAB;
sfr     PW1DL    = 0xAB;
sfr		  PW1DH    = 0xAC;
sfr16   PW2D     = 0xAD;
sfr     PW2DL    = 0xAD;
sfr     PW2DH    = 0xAE;
sfr16   PW3D     = 0xB1;
sfr     PW3DL    = 0xB1;
sfr     PW3DH    = 0xB2;
sfr16   PW4D     = 0xB3;
sfr     PW4DL    = 0xB3;
sfr     PW4DH    = 0xB4;
sfr16   PW5D     = 0xB5;
sfr     PW5DL    = 0xB5;
sfr     PW5DH    = 0xB6;
sfr     IP1      = 0xB9;
sfr     S0RELH   = 0xBA;
sfr     PWNV     = 0xBC;
sfr     PWO      = 0xBD;
sfr     PWCH    = 0xBE;
sfr     IRCON2   = 0xBF;
sfr     PSW      = 0xD0;
  sbit  CY       = PSW^7;
  sbit  AC       = PSW^6;
  sbit  F0       = PSW^5;
  sbit  RS1      = PSW^4;
  sbit  RS0      = PSW^3;
  sbit  OV       = PSW^2;
  sbit  F1       = PSW^1;
  sbit  P        = PSW^0;
sfr     ADM      = 0xD2;
sfr     ADB      = 0xD3;
sfr     ADR      = 0xD4;
sfr     VREFH    = 0xD5;
sfr     S0CON2   = 0xD8;
  sbit  BD       = S0CON2^7;
sfr     ACC      = 0xE0;
sfr     P0OC     = 0xE4;
sfr     CLKSEL   = 0xE5;
sfr     CLKCMD   = 0xE6;
sfr     TCON0    = 0xE7;
sfr     B        = 0xF0;
sfr     P0UR     = 0xF1;
sfr16   FRQ      = 0xF2;
sfr     FRQL     = 0xF2;
sfr     FRQH     = 0xF3;
sfr     FRQCMD   = 0xF4;
sfr     SRST     = 0xF7;
sfr     P0M      = 0xF9;
sfr     PFLAG    = 0xFF;

/*      Interrupt Vector      */
// dinh nghia so ngat cho cac nguon khac nhau
#define ISRInt0    0 // ngat ngoai 0
#define ISRTimer0  1 //ngat timer 0
#define ISRInt1    2 // ngat ngoai 1
#define ISRTimer1  3 // ngat timer 1
#define ISRUart    4 // ngat uart 
#define ISRInt2    16 // ngat ngoai 2
#define ISRAdc     17 // ngat adc
#define ISRTimer3  29 // ngat timer 3

/*      C51 Macros      */
// cung cap cac phim tat cho che do cho hoac lap trinh trong he thong
#ifdef __C51__ 
#include <intrins.h> 
#define IDLE() {PCON |= 0x01;} // dat vi dieu khien vao che do cho bang cach dat bit tuong ung trong thanh ghi PCON
#define STOP() {PCON |= 0x02;}
#define PISP(ROM_ADDRESS, RAM_ADDRESS) {PERAM = (RAM_ADDRESS); PEROM = ((ROM_ADDRESS) & 0xFFE0); PECMD = 0x5A; _nop_(); _nop_();}
#define BISP(ROM_ADDRESS, RAM_ADDRESS) {PERAM = (RAM_ADDRESS); PEROM = ((ROM_ADDRESS) & 0xFFFF); PECMD = 0x1E; _nop_(); _nop_();}

#endif  // __C51__

#ifndef uint8_t
#define uint8_t unsigned char
#endif  // uint8_t

#ifndef uint16_t
#define uint16_t unsigned int
#endif  // uint16_t

#ifndef uint32_t
#define uint32_t unsigned long
#endif  // uint32_t

#endif  // __SN8F5814_H__
