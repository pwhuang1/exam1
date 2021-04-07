#include "mbed.h"
#include "uLCD_4DGL.h"
 


AnalogOut aout(D7);
AnalogIn ain(A3);
uLCD_4DGL uLCD(D1, D0, D2);
DigitalIn up(A0);
DigitalIn down(A1);
DigitalIn confirm(A2);


float i;
int j;
int l;
int slew = 0;
float slew1;
int x;
int y;
float T = 0;
float ADCdata[128];
int conf = 0;
int main(void)
{
    uLCD.cls();
    uLCD.text_width(4);
    uLCD.text_height(4);
    uLCD.locate(1,1);
    uLCD.printf("\n 1/8 \n");
    
    while(1){
        if(up==1){
            if(slew < 3)
                slew = slew + 1;
            else
                slew = slew;
            uLCD.cls();
            uLCD.text_width(4);
            uLCD.text_height(4);
            uLCD.locate(1,2);
            //uLCD.printf("%d\n", slew);

            if(slew == 0){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1/8 \n");
            }
            else if (slew == 1){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1/4 \n");
            }
            else if (slew == 2){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1/2 \n");
            }
            else if (slew == 3){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1 \n");
            }


        }
        if(down==1){
            if(slew > 0)
                slew = slew - 1;
            else
                slew = slew;
            uLCD.cls();
            uLCD.text_width(4);
            uLCD.text_height(4);
            uLCD.locate(1,2);
            //uLCD.printf("%d\n", slew);
            if(slew == 0){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1/8 \n");
            }
            else if (slew == 1){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1/4 \n");
            }
            else if (slew == 2){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1/2 \n");
            }
            else if (slew == 3){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1 \n");
            }
        }
        if(confirm==1){
            conf = 1;
            T = 240;

            if(slew == 0){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1/8 \n");
                slew1 = 1/8;
                x=24;
            }
            else if (slew == 1){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1/4 \n");
                slew1 = 1/4;
                x=12;
            }
            else if (slew == 2){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1/2 \n");
                slew1 = 1/2;
                x=6;
            }
            else if (slew == 3){
                uLCD.text_width(4);
                uLCD.text_height(4);
                uLCD.locate(1,2);
                uLCD.printf("\n 1 \n");
                slew1 = 1;
                x=3;
            }
        }
        
        

        
        
        
        if(conf==1){

            for (i = 0; i < 0.9; i +=  T/x) {
                aout = i;
            }
            for (i = 0; i < 0.9; i += T-2*(T/x)){
                aout = 0.9;
            }

            for (i = 0.9; i > 0; i -=  T/x) {
                aout = i;
            }




            for(j = 0; j < 128; j++){
                ADCdata[j] = ain;
                ThisThread::sleep_for(1000ms/slew);
            }
            if(j == 127){
                printf("%d\r\n", slew);
                for(l=0; l<128; l++){
                    printf("%f\r\n", ADCdata[l]);
                    ThisThread::sleep_for(1000ms/slew);
                }
                j = 0;
            }
            conf = 0;
        }
    }
}
