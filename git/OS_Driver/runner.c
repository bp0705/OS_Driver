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

typedef struct {
	uint8_t cmd;
	uint16_t portA,
		 portB,
		 trisA,
		 trisB;
		}cmd_t;

void open_dev();
void close_dev();
int menu();
void set_status();
void get_status();
void receive_config();
void send_config(uint16_t LEDS);

//global variable for file pointer
FILE *devID;

int main(void)
{
	open_dev();
	
	while(menu());

	close_dev();

	return 0;
}

//open the device file, exit upon failure
inline void open_dev()
{
	devID = fopen("/dev/LED0", "r+");
	if(devID == NULL)
	{
		printf("Error opening device!\n");
		exit(-1);
	}
}

//close the device file
inline void close_dev()
{
	fclose(devID);
}

//shows the menu
int menu()
{
	char input;
	printf("-------\nLEDS - 1\nButtons - 2\nQuit - anything else\n--> ");
	scanf(" %c", &input);
	printf("-------\n");
	switch(input)
	{
		case '1':
			set_status();
			break;

		case '2':
			get_status();
			break;

		default:
			return 0;
			break;
	}

	return 1;
}

//ask for LEDs and build message
void set_status()
{
	uint16_t LEDS = 0;
	int options[4];
	printf("Enter status of LEDS (ex: 0 0 0 0): ");
	scanf("%d%d%d%d", &options[0], &options[1], &options[2], &options[3]);	

	if(options[0] == 1)
		LEDS += (1 << 10);
	if(options[1] == 1)
		LEDS += (1 << 11);
	if(options[2] == 1)
		LEDS += (1 << 12);
	if(options[3] == 1)
		LEDS += (1 << 13);
	send_config(LEDS);
}

//build message to get configuration
void get_status()
{
	cmd_t reply;

	receive_config(&reply);

	printf("Cmd: 0x%x\nPortA: 0x%x\nPortB: 0x%x\nTrisA: 0x%x\nTrisB: 0x%x\n\n", reply.cmd, reply.portA, reply.portB, reply.trisA, reply.trisB);

	printf("Button 1 pressed: ");
	if((uint8_t)(reply.portA >> 6) & (0x0001) == 1)
		printf("True\n");
	else
		printf("False\n");
	
	printf("Button 2 pressed: ");

	if((uint8_t)(reply.portA >> 7) & (0x0001) == 1)
		printf("True\n");
	else
		printf("False\n");

}

//send configuration message
void send_config(uint16_t LEDS)
{
	cmd_t package_out;
	cmd_t package_in;

	package_out.cmd = SET_STATUS_CMD;
	package_out.portA = 0x0000;
	package_out.portB = LEDS;
	package_out.trisA = 0xFFFF;
	package_out.trisB = 0x0000;
	
	fwrite((uint8_t *)(&package_out), sizeof(uint8_t), MSG_SIZE, devID);
	fread((uint8_t *)(&package_in), sizeof(uint8_t), MSG_SIZE, devID);
}

//store bitfields from device configuration
void receive_config(cmd_t *package_in)
{
	cmd_t package_out;
	package_out.cmd = GET_STATUS_CMD;
	package_out.portA = 0;
	package_out.portB = 0;
	package_out.trisA = 0;
	package_out.trisB = 0;

	fwrite(&package_out, sizeof(uint8_t), MSG_SIZE, devID);

	fread((uint8_t *)(package_in), sizeof(uint8_t), MSG_SIZE, devID);
}
