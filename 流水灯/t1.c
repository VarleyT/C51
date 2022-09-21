#include "reg51.h"

void delay(unsigned int x){
	unsigned int j;
	while((x--)!=0)
		for(j=0;j<125;j++);
}

void main(){
	int i;
	P1=0xF8;
	while(1){
		for(i=0;i<13;i++){
			if(P1!=0x1F && P1!=0x3E && P1!=0x7C){
				P1=(P1<<1)+1;
				delay(100);
			}else{
				P1<<=1;
				delay(100);
			}
		}
		for(i=0;i<2;i++){
			P1=0x7E;
			delay(100);
			P1=0xBD;
			delay(100);
			P1=0xDB;
			delay(100);
			P1=0xE7;
			delay(100);
			P1=0xDB;
			delay(100);
			P1=0xBD;
			delay(100);
			P1=0x7E;
			delay(100);
		}
		P1=0xF8;
		delay(100);
	}
	
}
