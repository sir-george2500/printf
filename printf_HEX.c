#include "main.h"

/**
 * printf_HEX - prints an hexgecimal number.
 * @val: arguments.
 * Return: counter.
 */
int printf_HEX(va_list val)
{
	/*variables **/
	int i;
	int *array;
	int counter = 0;
	unsigned int num = va_arg(val, unsigned int);
	unsigned int temp = num;

	/*counting digits */

	while (num / 16 != 0)
	{
		num /= 16;
		counter++;
	}
	counter++;
	array = malloc(counter * sizeof(int));
	/*convert it to hexedecimal*/
	for (i = 0; i < counter; i++)
	{
		array[i] = temp % 16;
		temp /= 16;
	}
	for (i = counter - 1; i >= 0; i--)
	{
	/*split out letter if they are above 9 */
		if (array[i] > 9)
			array[i] = array[i] + 7;
		_putchar(array[i] + '0');
	}
	/*free that memory back to the heap */
	free(array);
	return (counter);
}
