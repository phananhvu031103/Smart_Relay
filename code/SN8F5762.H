/*--------------------------------------------------------------------------
SN8F5762.H

Header file for SNOiX SN8F5762 microcontroller.
Copyright (c) 2021 SONiX Technology Co., Ltd.

Version 1.0    2021-01-29
--------------------------------------------------------------------------*/

#ifndef __SN8F5762_H__
#define __SN8F5762_H__

/*      Register      */
sfr     P0       = 0x80;
  sbit  P07      = P0^7;
  sbit  P06      = P0^6;
  sbit  P05      = P0^5;
  sbit  P04      = P0^4;
  sbit  P03      = P0^3;
  sbit  P02      = P0^2;
  sbit  P01      = P0^1;
  sbit  P00      = P0^0;
sfr     SP       = 0x81;
sfr     DPL      = 0x82;
sfr     DPH      = 0x83;
sfr     DPL1     = 0x84;
sfr     DPH1     = 0x85;
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
sfr     LVDCON   = 0x8E;
sfr     PEDGE    = 0x8F;
sfr     P1       = 0x90;
  sbit  P17      = P1^7;
  sbit  P16      = P1^6;
  sbit  P15      = P1^5;
  sbit  P14      = P1^4;
  sbit  P13      = P1^3;
  sbit  P12      = P1^2;
  sbit  P11      = P1^1;
  sbit  P10      = P1^0;
sfr     P1W      = 0x91;
sfr     DPS      = 0x92;
sfr     DPC      = 0x93;
sfr     PECMD    = 0x94;
sfr16   PEROM    = 0x95;
sfr     PEROML   = 0x95;
sfr     PEROMH   = 0x96;
sfr     PERAM    = 0x97;
sfr     S0CON    = 0x98;
  sbit  S0M0     = S0CON^7;
  sbit  S0M1     = S0CON^6;
  sbit  S0M20    = S0CON^5;
  sbit  REN0     = S0CON^4;
  sbit  TB80     = S0CON^3;
  sbit  RB80     = S0CON^2;
  sbit  TI0      = S0CON^1;
  sbit  RI0      = S0CON^0;
sfr     S0BUF    = 0x99;
sfr     IEN2     = 0x9A;
sfr     S0CON2   = 0x9B;
sfr     S0RELL   = 0x9C;
sfr     S0RELH   = 0x9D;
sfr     P2CON    = 0x9E;
sfr     P1CON    = 0x9F;
sfr     P2       = 0xA0;
  sbit  P21      = P2^1;
  sbit  P20      = P2^0;
sfr16   PW1Y	   = 0xA1;
sfr     PW1YL 	 = 0xA1;
sfr     PW1YH    = 0xA2;
sfr16   PW10D    = 0xA3;
sfr     PW10DL   = 0xA3;
sfr     PW10DH   = 0xA4;
sfr16   PW11D    = 0xA5;
sfr     PW11DL   = 0xA5;
sfr 	  PW11DH	 = 0xA6;
sfr 	  PERAMCNT = 0xA7;
sfr     IEN0     = 0xA8;
  sbit   EAL     = IEN0^7;
  sbit   EX2     = IEN0^4; 
  sbit   ET1     = IEN0^3;
  sbit   EX1     = IEN0^2;  
  sbit   ET0     = IEN0^1;
  sbit   EX0     = IEN0^0;
sfr     IP0      = 0xA9;  
sfr16   PW12D    = 0xAA;
sfr     PW12DL   = 0xAA;
sfr     PW12DH   = 0xAB;  
sfr16   PW13D    = 0xAC;
sfr     PW13DL   = 0xAC;
sfr     PW13DH   = 0xAD;  
sfr     T2M      = 0xAE;
sfr     BZM		   = 0xAF;
sfr     PW1M	   = 0xB0;
sfr     PW1CH	   = 0xB1;
sfr     PW1NV	   = 0xB2; 
sfr     PW1O	   = 0xB3; 
sfr16   T2C	     = 0xB4;
sfr     T2CL     = 0xB4;
sfr     T2CH     = 0xB5;
sfr16   PW2Y	   = 0xB6;
sfr     PW2YL	   = 0xB6;
sfr     PW2YH    = 0xB7;
sfr     IEN1     = 0xB8;
  sbit  EU1RX    = IEN1^5;
  sbit  EU1TX    = IEN1^4;
  sbit  EU0RX    = IEN1^3;
  sbit  EU0TX    = IEN1^2;
  sbit  ESPI     = IEN1^1;
  sbit  EI2C     = IEN1^0;
sfr     IP1      = 0xB9;
sfr16   PW2D     = 0xBA;
sfr     PW2DL    = 0xBA;
sfr 	  PW2DH	   = 0xBB;
sfr 	  PW2DB	   = 0xBC;
sfr   	P0OC	   = 0xBD;
sfr   	P2OC	   = 0xBE;
sfr     IRCON2   = 0xBF;
sfr     S1CON    = 0xC1;
sfr 	  S1BUF	   = 0xC2;
sfr 	  S1RELL 	 = 0xC3;
sfr 	  S1RELH	 = 0xC4;
sfr     FRQCMD   = 0xC5;
sfr     SYSMOD   = 0xC6;
sfr     CPTM	   = 0xC7;
sfr     PW2M	   = 0xC8;
sfr     PW2CH	   = 0xC9;
sfr     PW2NV	   = 0xCA; 
sfr16   CPTC     = 0xCB;
sfr     CPTCL	   = 0xCB; 
sfr     CPTCH	   = 0xCC; 
sfr16   FRQ      = 0xCD;
sfr     FRQL     = 0xCD;
sfr     FRQH     = 0xCE;
sfr     DEGCMD   = 0xCF;
sfr     PSW      = 0xD0;
  sbit  CY       = PSW^7;
  sbit  AC       = PSW^6;
  sbit  F0       = PSW^5;
  sbit  RS1      = PSW^4;
  sbit  RS0      = PSW^3;
  sbit  OV       = PSW^2;
  sbit  F1       = PSW^1;
  sbit  P        = PSW^0;
sfr     CPTS     = 0xD1; 
sfr     ADM      = 0xD2;
sfr     ADB      = 0xD3;
sfr     ADR      = 0xD4;
sfr     VREFH    = 0xD5;
sfr     P0CON    = 0xD6;
sfr     ADCAL    = 0xD9;
sfr     I2CDAT   = 0xDA;
sfr     I2CADR   = 0xDB;
sfr     I2CCON   = 0xDC;
sfr     I2CSTA   = 0xDD;
sfr     SMBSEL   = 0xDE;
sfr     SMBDST   = 0xDF;
sfr     ACC      = 0xE0;
sfr     SPSTA    = 0xE1;
sfr     SPCON    = 0xE2;
sfr     SPDAT    = 0xE3;
sfr     TCON0    = 0xE7;
sfr     B        = 0xF0;
sfr     P0UR     = 0xF1;
sfr     P1UR     = 0xF2;
sfr     P2UR     = 0xF3;
sfr     PDRV     = 0xF4;
sfr16   LFRQ     = 0xF5;
sfr     LFRQL    = 0xF5;
sfr     LFRQH    = 0xF6;
sfr     SRST     = 0xF7;
sfr     CLKCAL   = 0xF8;
sfr     P0M      = 0xF9;
sfr     P1M      = 0xFA;
sfr     P2M      = 0xFB;
sfr     P0DR     = 0xFC;
sfr     P1DR     = 0xFD;
sfr     P2DR     = 0xFE;
sfr     PFLAG    = 0xFF;

/*      Interrupt Vector      */
#define ISRInt0    0	   /* Vector 0x03 */
#define ISRTimer0  1	   /* Vector 0x0B */
#define ISRInt1    2	   /* Vector 0x13 */
#define ISRTimer1  3	   /* Vector 0x1B */
#define ISRInt2    4	   /* Vector 0x23 */
#define ISRTimer2  5	   /* Vector 0x2B */
#define ISRI2C	   8	   /* Vector 0x43 */ 
#define ISRSPI	   9	   /* Vector 0x4B */	 
#define ISRUart0RX 10    /* Vector 0x53 */ 
#define ISRUart0TX 11    /* Vector 0x5B */ 
#define ISRUart1RX 12    /* Vector 0x63 */ 
#define ISRUart1TX 13    /* Vector 0x6B */ 
#define ISRPwm1    16    /* Vector 0x83 */
#define ISRPwm2    17    /* Vector 0x8B */
#define ISRAdc     21    /* Vector 0xAB */
#define ISRLVD     23    /* Vector 0xBB */


/*      C51 Macros      */
#ifdef __C51__
#include <intrins.h>
#define IDLE() {PCON |= 0x01;}
#define STOP() {PCON |= 0x02;}
//#define PISP(ROM_ADDRESS, RAM_ADDRESS) {PERAM = (RAM_ADDRESS); PEROM = ((ROM_ADDRESS) & 0xFFE0); PECMD = 0x5A; _nop_(); _nop_();}
//#define BISP(ROM_ADDRESS, RAM_ADDRESS) {PERAM = (RAM_ADDRESS); PEROM = ((ROM_ADDRESS) & 0xFFFF); PECMD = 0x1E; _nop_(); _nop_();}


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

#endif  // __SN8F5762_H__
