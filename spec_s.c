#include "main.h"
/**
 * spec_s - print string
 * @arg: string type char *
 * Return: void
 */
void spec_s(char *arg)
{
	int i;

	for (i = 0; i < _strlen(arg); i++)
	{
		_putchar(arg[i]);
	}
}
