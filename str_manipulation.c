#include "monty.h"

/**
 * _strlen - returns the length of a string.
 * @s: string to be used
 * Return: length of string
 */

int _strlen(char *s)
{
	int len = 0;

	while (*(s + len) != '\0')
		len++;

	return (len);
}
/**
 * _strcat - concatenates two strings.
 * @src: string to be appended
 * @dest: destination char pointer
 * Return: pointer to the dest string
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (*(dest + i) != '\0')
	{
		i++;
	}
	j = 0;
	while (*(src + j) != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);

}
/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: destination string
 * @src: source string
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int len = 0;

	while (*(src + len) != '\0')
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: 0, if the s1 and s2 are equal, a negative value if
 * s1 is less than s2, a positive value if s1 is greater than s2.
 */

int _strcmp(char *s1, char *s2)
{
	int cmpstr, i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			cmpstr = s1[i] - s2[i];
			break;
		}
		cmpstr = s1[i] - s2[i];
		i++;
	}
	return (cmpstr);
}
