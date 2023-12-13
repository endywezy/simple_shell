#include "shell.h"

/**
 * new_main - for entry point
 *
 * Return: 0
 *

int main(void)
{
	return (custom_main());
}*/

/**
 * custom_main - entry level for custom main
 *
 * Return: 0 success, 1 on err
 */
int custom_main(void)
{
    /* the cmd to print a message function */
	printMessage();

	return (0);
}

/**
 * printMessage - This is to print a message
 * Betty would be proud
 */
void printMessage(void)
{
	/* to take input */
	char *message = "Betty would be proud, written by Endurance Ossai";
	int a;

	for (a = 0; message[a] != '\0'; a++)
	{
		/*Print the message*/
		__putchar(message[a]);
	}
	__putchar('\n');
}
