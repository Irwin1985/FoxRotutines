/*
* Visual FoxPro commons routines implementation.
*/
#include <ctype.h>
#include <stdlib.h>

/*
* len(): devuelve la longitud de una cadena.
* para conocer su longitud es necesario 
* recorrer todo el string.
*/
int len(char* str)
{
	int length = 0;
	while (*str)
	{
		length += 1;
		str += 1;
	}
	return length;
}
/*
* alltrim(): devuelve una cadena quitando los espacios a la derecha e izquierda
* de la cadena original.
*/
char* alltrim(char* str)
{
	int left = 0;
	int right = len(str) - 1;	
	// Comer los espacios desde la izquierda
	// hasta encontrar un alphanumérico.
	while (isspace(str[left]) && str[left] != '\0') 
	{
		left += 1;
	}
	// Comer de derecha a izquierda.
	while (isspace(str[right]) && right > left)
	{
		right -= 1;
	}
	if (left + right > 0)
	{
		int size = right - left;
		char *new_str = malloc(sizeof(char) * size);
		int count = 0;
		while (left <= right)
		{			
			new_str[count] = str[left];
			count += 1;
			left += 1;
		}
		new_str[count] = '\0';
		return new_str;
	}
	else
	{
		char *new_str = "";
		return new_str;
	}
}

/*
* left(): devuelve un trozo del string cortando por la izquierda.
*/
char* left(char* str, int offset)
{
	if (len(str) == 0 || offset <= 0)
	{
		return "";
	}
	char* value = malloc(sizeof(char) * offset+1);
	// comer desde la posición 0 hasta offset
	int i = 0;
	for (i = 0; i < offset; i++)
	{
		value[i] = str[i];
	}
	value[i] = '\0';
	return value;
}

/*
* right(): devuelve un trozo del string cortando por la derecha.
*/
char* right(char* str, int offset)
{
	int length = len(str);
	if (length == 0 || offset <= 0)
	{
		return "";
	}
	int i = 0, count = 0;
	int start = length - offset;
	char* value = malloc(sizeof(char) * offset);
	for (i = start; i <= length; i++)
	{
		value[count] = str[i];
		count += 1;
	}
	value[count] = '\0';
	return value;
}