#include "SN8F5762.H"
#include <math.h>

unsigned int adc_value_1, adc_value_2;  // bien de luu gia tri 2 cam bien

void setup() {
  P0M &= ~(1 << 0); // dat P00 la dau ra GPIO
  P0M &= ~(1 << 1); // dat P01 la dau ra GPIO
	P1M |= (1 << 6);  // dat P16 la dau vao analog
  P1M |= (1 << 7);  // dat P17 la dau vao analog
  ADM = 0x80;  // ADENB = 1 de bat ADC
  VREFH = 0x04;  // dat dien ap tham chieu la VDD
  ADCAL = 0x01;  // bat che do tu dieu chinh ADC
}
// marco dieu khien cac relay
#define RELAY1_ON  (P00 = 1)  // bat relay 1
#define RELAY1_OFF (P00 = 0)  // tat relay 1
#define RELAY2_ON  (P01 = 1)  // bat relay 2
#define RELAY2_OFF (P01 = 0)  // tat relay 2

// ham chuyen doi gia tri anlog sang nhiet do
// su dung cam bien mf58
int convert_adc_to_temperature(unsigned int adc_value) {
  long resistance = 10000L * (4095 - adc_value) / adc_value;
  int temperature = (3950 * (25 + 273) / (3950 + (25 + 273) * log (resistance / 10000.0)) - 273);
 	return temperature;
}

// doc gia tri ADC tu kenh chi dinh
unsigned int read_adc(unsigned char channel) {
	ADM &= 0xFC; // xoa cac bit kenh
	ADM |= channel; // chon kenh
	ADM |= 0x40; // bat dau chuyen doi ADC
	while(ADCAL & 0x40); // doi den khi chuyen doi hoan tat
	return (ADB << 4) + (ADR & 0x0F); // ket hop cac bit cao va thap cua ket qua ADC
}



void main() {
	int temp_1, temp_2;
  setup();
  while (1) {
		
		// ma nguon cho cam bien nong
    adc_value_1 = read_adc(0x06); // goi ham doc gia tri tu cam bien nong
    temp_1 = convert_adc_to_temperature(adc_value_1); // chuyen doi analog sang nhiet do
		// neu nhiet do cam bien nong > 90 do thi relay nong tat 
    if (temp_1 > 90) { 
      RELAY1_OFF;
    } else if (temp_1 < 85) {  // neu nhiet do cam bien nong < 85 do thi relay nong bat
      RELAY1_ON;
    }

    // ma nguon cho cam bien lanh
    adc_value_2 = read_adc(0x07); // goi ham doc gia tri tu cam bien lanh
    temp_2 = convert_adc_to_temperature(adc_value_2); // chuyen doi analog sang nhiet do
		// neu nhiet do cam bien lanh < 5  do thi relay lanh tat
    if (temp_2 < 5) {  
      RELAY2_OFF;
    } else if(temp_2 > 10) {		// neu nhiet do cam bien lanh > 10 thi relay lanh bat
			RELAY2_ON;
    }
  }
}
