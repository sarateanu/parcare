/*
 * parcareinteligenta.c
 *
 * Created: 5/2/2018 12:55:37 PM
 * Author : Mircea.Sarateanu
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#define F_CPU 1000000

#define zero PORTD = 0xb00000010
#define unu PORTD = 0xb10011110
#define doi PORTD = 0xb00100100
#define trei PORTD = 0xb00001100
#define patru PORTD = 0xb10011000
#define  cinci PORTD = 0xb01001000
#define  sase PORTD = 0xb01000000
#define  sapte PORTD = 0xb00011110
#define  opt PORTD = 0xb00000000
#define noua PORTD = 0xb00001000


static unsigned int locurilibere = 10;
static unsigned int baleiaj = 0;

static unsigned int intrare = 0;
static unsigned int iesire = 0;

void afisare_LCD(unsigned int numar1, unsigned int digit)
{
	unsigned int separat[3];
	unsigned int unitati, zeci, sute;
	unsigned int valoare, count, aux;
	valoare = numar1;
	count = 0;
	aux = 0;
	separat[0] = separat[1] = separat[2] = 0;
	while(valoare!=0)
	{
		aux = valoare % 10;
		valoare = valoare / 10;
		separat[count] = aux;
		count ++;
		
	}//END WHILE
	
	sute = separat[2];
	zeci = separat[1];
	unitati = separat[0];//Separa numarul in componente numar1
	
	
	
		
		
	
	
	
	
	
	if(digit == 0){
		PORTA |= (1<<PA0);
		PORTA &= ~((1<<PA2)|(1<<PA1));
		switch(unitati){
			
			case 0 : PORTC = 0b01111110;  break;
			case 1 : PORTC = 0b00110000;  break;
			case 2 : PORTC = 0b01101101;  break;
			case 3 : PORTC = 0b01111001;  break;
			case 4 : PORTC = 0b00110011;  break;
			case 5 : PORTC = 0b01011011;  break;
			case 6 : PORTC = 0b01011111;  break;
			case 7 : PORTC = 0b01110000;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01111011;  break;
			
			
			
		}
		
	}//END IF
	if(digit == 1){
		PORTA |=(1<<PA1);
		PORTA &= ~((1<<PA2)|(1<<PA0));
		switch(zeci){
			
			case 0 : PORTC = 0b01111110;  break;
			case 1 : PORTC = 0b00110000;  break;
			case 2 : PORTC = 0b01101101;  break;
			case 3 : PORTC = 0b01111001;  break;
			case 4 : PORTC = 0b00110011;  break;
			case 5 : PORTC = 0b01011011;  break;
			case 6 : PORTC = 0b01011111;  break;
			case 7 : PORTC = 0b01110000;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01111011;  break;
			
			
			
		}
		
		
		
	}
	
	if(digit == 2){
		PORTA |=(1<<PA2);
		PORTA &= ~((1<<PA1)|(1<<PA0));
		switch(sute){
			
			case 0 : PORTC = 0b01111110;  break;
			case 1 : PORTC = 0b00110000;  break;
			case 2 : PORTC = 0b01101101;  break;
			case 3 : PORTC = 0b01111001;  break;
			case 4 : PORTC = 0b00110011;  break;
			case 5 : PORTC = 0b01011011;  break;
			case 6 : PORTC = 0b01011111;  break;
			case 7 : PORTC = 0b01110000;  break;
			case 8 : PORTC = 0b01111111;  break;
			case 9 : PORTC = 0b01111011;  break;
			
			
			
		}
		
		
		
	}
	
	
	
}







ISR(TIMER0_OVF_vect){
	
	
	afisare_LCD(locurilibere, baleiaj);
	baleiaj = baleiaj + 1;
	if(baleiaj == 3){baleiaj = 0;}
	
	
	
}

ISR(INT0_vect){
	
	if(locurilibere < 100){
		if((PIND&(1<<PD0))==0){
			locurilibere = locurilibere + 1;
		}
	
	}
	
}

ISR(INT1_vect){
	
	if(locurilibere > 0){
		
		locurilibere = locurilibere - 1;
	}
	
	
	
	
	
}


int main(void)
{
	
	unsigned int countintrare = 0;
	unsigned int countiesire = 0;
	unsigned int trecereintrare = 0;
	unsigned int trecereiesire = 0;
	sei();
	DDRC = 0xFF;
	PORTC = 0;
	
	DDRD = 0;
	
	
	
	
	DDRA = 0xFF;
	PORTA = 0;
	TIMSK |= (1<<TOIE0);
	TCCR0 = 0;
	TCCR0 |= (1<<CS01);//SETARE CLK/8 si atunci 1.000.000 / 8 = 125.000  si 125.000 / 255 = 490 HZ
	//Se implementeaza astfel sistemul de afisare
	
	GICR |= (1<<INT0) | (1<<INT1);
	MCUCR |= (1<<ISC11)|(1<<ISC10)|(1<<ISC01)|(1<<ISC00);//pagina 77 din datasheet
	//Se implementeza sistemul de citire al potentiometrelor
	//Am implementat citirea potentiometrilor pe ADC, sistemul de afisare
    /* Replace with your application code */
    while (1) 
    {
		//
		
			
			
		
		if(locurilibere>0){
			
			PORTA |= (1<<PA6);
			PORTA &= ~(1<<PA5);
			
			
    }
	
	else {
		
		PORTA |=(1<<PA5);
		PORTA &= ~(1<<PA6);
	}
		
	
}

		}

