/*
 * Serial Communication Example on ATmega128
 * Created: 8/14/2015 9:29:24 AM
 * Author: sandeep, reach me at sandeep@exploreembedded.com
 * www.exploreembedded.com
 * This example demonstrates blinking LEDs connected to all ports of atmega128
 *
 * #########################IMPORTANT NOTE:#########################################
 * Atmega128 is a wierd MCU. Read the tutorial below to understand how to set it up properly at
 * http://exploreembedded.com/wiki/Setting_up_ATmega128
 *
 * If you're using Explore Atmega128 breakout board, you need not setup anything. We have done all of it for you.
 * Or if you're planning to buy a board, do check out our nice little board.
 * https://www.exploreembedded.com/product/Explore%20ATMEGA128%20Breakout
 */ 




#include<avr/io.h>

void serial_init()
{
	UCSR0B= 0x18;   // Enable Receiver and Transmitter
	UCSR0C= 0x86;   // Asynchronous mode 8-bit data and 1-stop bit
	UCSR0A= 0x00;   // Normal Baud rate(no doubling), Single processor commn
	UBRR0H= 0;
	UBRR0L= 103;     // 9600 Baud rate at 16Mhz

	UCSR1B= 0x18;   // Enable Receiver and Transmitter
	UCSR1C= 0x86;   // Asynchronous mode 8-bit data and 1-stop bit
	UCSR1A= 0x00;   // Normal Baud rate(no doubling), Single processor commn
	UBRR1H= 0;
	UBRR1L= 103;     // 9600 Baud rate at 16Mhz
}

void tx_char(char ch)
{
	while((UCSR0A & 0x20)==0); // Wait till Transmitter(UDR) register becomes Empty
	UDR0 =ch;           // Load the data to be transmitted
}

void tx_string(char *str_ptr)
{
	while(*str_ptr)
	tx_char(*str_ptr++);
}

void tx_char1(char ch)
{
	while((UCSR1A & 0x20)==0); // Wait till Transmitter(UDR) register becomes Empty
	UDR1 =ch;           // Load the data to be transmitted
}

void tx_string1(char *str_ptr)
{
	while(*str_ptr)
	tx_char1(*str_ptr++);
}

void main()
{
	
	serial_init();
	
	while(1)
	{
		tx_string("Channel 0 ExploreEmbedded.com \r\n");
		tx_string1("Channel 1 Lets build....   \r\n");
	}
}
