//INCLUDE
#include <SN8F5762.h>
#include <intrins.h>

//DEFINE
#define ADCAIN12_4V (2 << 0) //AIN12 = 4.5V
#define ADCAIN12_3V (1 << 0) //AIN12 = 3.5V
#define ADCAIN12_2V (0 << 0) //AIN12 = 2.5V
#define ADCAIN12_1V (3 << 0) //AIN12 = 1.5V
#define ADCInRefVDD (1 << 2) //internal reference from VDD
#define ADCExHighRef (1 << 7) //high reference from AVREFH/P1.0

#define ADCClkFosc (0 << 7) //ADC clock source = fosc
#define ADCClkFlosc (1 << 7) //ADC clock source = flosc

#define ADCSpeedDiv1 (0 << 0) //ADC clock = fosc/1 or flosc/1
#define ADCSpeedDiv2 (1 << 0) //ADC clock = fosc/2 or flosc/2
#define ADCSpeedDiv4 (2 << 0) //ADC clock = fosc/4 or flosc/4
#define ADCSpeedDiv8 (3 << 0) //ADC clock = fosc/8 or flosc/8
#define ADCSpeedDiv16 (4 << 0) //ADC clock = fosc/16 or flosc/16
#define ADCSpeedDiv32 (5 << 0) //ADC clock = fosc/32 or flosc/32
#define ADCSpeedDiv64 (6 << 0) //ADC clock = fosc/64 or flosc/64
#define ADCSpeedDiv128 (7 << 0) //ADC clock = fosc/128 or flosc/128

#define ADCChannelEn (1 << 6) //enable ADC channel

#define SelAIN7 (7 << 0) //select ADC channel 7 / P06  
#define SelAIN8 (8 << 0) //select ADC channel 8 / P05

#define ADCStart (1 << 6) //start ADC conversion
#define ADCEn (1 << 7) //enable ADC
#define ADCISREn (1 << 0) //enable ADC interrupt
#define ClearEOC 0xDF;
#define ADCCal (1 << 7) //ADC calibration starts
#define ADCCovAddCal (1 << 6) //ADC conversion with calibration value

#define CLR_ADCCH (ADM & 0xF0) //clear CHS[3:0]
#define _EOC (ADM & 0x20)			 // ADC status (EOC)


//DEFINE TEMPERATURE_LEVEL ADC_VALUE
#define Hot_Upper_Value 350 	//Nhiet do 90 do
#define Hot_Lower_Value 401		//Nhiet do 85 do
#define Cold_Upper_Value 2738	//Nhiet do 10 do
#define Cold_Lower_Value 2956	//Nhiet do 5 do

//DEFINE OUTPUT
#define Hot_Block_Control  P14
#define Cold_Block_Control P15
unsigned int ADCBuffer; // data buffer

//Delay1ms
void Delay1ms(unsigned int n)
{
    unsigned int i, j;

    // init value
    i = 0;
    j = 0;

    for (i=0; i<n; i++) {
        for (j=0; j<220; j++) {
            _nop_();    _nop_();
            _nop_();    _nop_();
            _nop_();    _nop_();
            _nop_();    _nop_();
        }
    }
}

// Ham chon kenh ADC de doc gia tri ADC
void ADC_Select_Input_Channel(uint8_t Channel)
{
		switch (Channel)   						// CHS[4:0]
		{
			case(0):
			{
				ADM =  CLR_ADCCH | SelAIN7; //Select AIN7 for Hot Block
				break;
			}
			case(1):
			{
				ADM =  CLR_ADCCH | SelAIN8; //Select AIN8 for Cold Block
				break;
			}
			default:
			{
				break;
			}	
		}	
}

//Configure ADC
void ADCInit(void)
{
		P0  = 0x00;
		P0M = 0x80;
	
		// set AIN7/P06 and AIN8/P05 pin's mode at pure analog pin
		P0CON |= 0x60; //AIN7/P0.6   AIN8/P0.5
		P0M   &= 0x9F; //input mode for P05 and P06
		P1UR  &= 0x9F; //disable pull-high

	
		// ADC clock source, enable channel and select conversion speed
		ADR   = ADCClkFosc | ADCChannelEn;
		ADCAL = ADCSpeedDiv4;
	
		// configure reference voltage
		VREFH = ADCInRefVDD;

		// enable ADC
		ADM |= ADCEn;

}



void ADC_Start_Covering(void)
{
	// ADC Calibration. 
		ADCAL |= ADCCal; //ADC start calibration
		while(ADCAL & ADCCal); //Check ADC calibrationbit
		ADCAL |= ADCCovAddCal; //ADC conversion with calibration value
	
	// start ADC conversion
		ADM |= ADCStart;
}


int main(void)
{
		uint16_t adc_value[2];//Contain adc_value of input 
		ADCInit();					  //Configure ADC
		P1M = 0xFF; 				  //Set Port 1 is OUTPUT
		P1 = 0x00;  				  //All pin in PORT 1 has default output is 0
		
	  //Infinity loop
		while(1)
		{
			//Read ADC of Hot controller sensor AIN7
			ADC_Select_Input_Channel(0);
			ADC_Start_Covering();
			while (!_EOC); 
			ADM &= ClearEOC;
			adc_value[0] = (ADB << 4) | (ADR & 0x0F);
			
			//Read ADC of Cold controller sensor AIN8
			ADC_Select_Input_Channel(1);
			ADC_Start_Covering();
			while (!_EOC);
			ADM &= ClearEOC;
			adc_value[1] = (ADB << 4) | (ADR & 0x0F);
			
			//Check condition and  output signal
 			if (adc_value[0] < Hot_Upper_Value)//350
			{
				//Off hot block
				Hot_Block_Control = 0;
			}
			else if (adc_value[0] > Hot_Lower_Value)//401
			{
				//On hot block
				Hot_Block_Control = 1;
			}
			
			if (adc_value[1] < Cold_Upper_Value)//2738
			{
				//On cold block
				Cold_Block_Control = 1;
			}
			else if (adc_value[1] > Cold_Lower_Value)//2956
			{
				//Off cold block
				Cold_Block_Control = 0;
			}
			
			Delay1ms(1000);  //Delay 1s
		}	
		
}
