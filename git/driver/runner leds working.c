#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define MSG_SIZE 9
#define GET_STATUS_CMD 0x80
#define GET_STATUS_REPLY 0x81
#define SET_STATUS_CMD 0x82
#define SET_STATUS_REPLY 0x83
#define LED1  4
#define LED2  8
#define LED3  16
#define LED4  32

void open_dev();
void close_dev();
int menu();
void ledMenu();
void buttonsMenu();
void getStatus();
void setStatus(uint16_t portA, uint16_t portB, uint16_t trisA, uint16_t trisB);

//global variable for file pointer
FILE *devID;

int main(void)
{
	open_dev();
	
	while(menu());

	close_dev();

	return 0;
}

inline void open_dev()
{
	devID = fopen("/dev/LED0", "r+");
	if(devID == NULL)
	{
		printf("Error opening device!\n");
		exit(-1);
	}
}

inline void close_dev()
{
	fclose(devID);
}

//shows the menu
int menu()
{
	char input;
	printf("LEDS - 1\nButtons - 2\nQuit - anything else\n--> ");
	scanf(" %c", &input);
	switch(input)
	{
		case '1':
			ledMenu();
			break;

		case '2':
			buttonsMenu();
			break;

		default:
			return 0;
			break;
	}

	return 1;
}

void ledMenu()
{
	uint16_t portA = 0, portB = 0, trisA = 0, trisB = 0;

	setStatus(portA, portB, trisA, trisB);
}

void buttonsMenu()
{
	printf("yay buttons menu\n");
}

void getStatus()
{
}

void setStatus(uint16_t portA, uint16_t portB, uint16_t trisA, uint16_t trisB)
{
	char outBuffer[9], inBuffer[9];
	for(int i = 0; i < 9; i++)
	{
		outBuffer[i] = 0x00;
		inBuffer[i] = 0x00;
	}

	
	outBuffer[0] = SET_STATUS_CMD;
	outBuffer[1] = 0x00;
	outBuffer[2] = 0x00;
	outBuffer[3] = 0x00;
	outBuffer[4] = 0x00;
	outBuffer[5] = LED1 + LED2;
	outBuffer[6] = 0x00;
	outBuffer[7] = 0x00;
	outBuffer[8] = 0x00;
	/*
	outBuffer[1] = portA >> 8;
	outBuffer[2] = portA;
	outBuffer[3] = portB >> 8;
	outBuffer[4] = portB;
	outBuffer[5] = trisA >> 8;
	outBuffer[6] = trisA;
	outBuffer[7] = trisB >> 8;
	outBuffer[8] = trisB;
	*/

	fwrite(outBuffer, 1, MSG_SIZE, devID);
	for(int i = 0; i < 9; i++)
	{
		printf("%x ", (uint8_t)outBuffer[i]);
	}
	printf("\n");
	fread(inBuffer, 1, MSG_SIZE, devID);
	for(int i = 0; i < 9; i++)
	{
		printf("%x ", (uint8_t)inBuffer[i]);
	}
}
