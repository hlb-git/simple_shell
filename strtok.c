#include "main.h"

char *_strchr(const char *str, int c);
size_t _strspn(const char *str1, const char *str2);
size_t _strcspn(const char *str1, const char *str2);

/**
* _strtok - breaks the string str into tokens and null-terminates them.
* Delimiter-Characters at the beginning and end
* of str are skipped.
* @str: string to tokenize
* @delim: sets of character that delimit str.
* Return: the first or next token if possible, a null-pointer otherwise.
*/
char *_strtok(char *str, const char *delim)
{
	static char *ptr;

	if (str)
		ptr = str;
	else if (!ptr)
		return (0);
	str = ptr + _strspn(ptr, delim);
	ptr = str + _strcspn(str, delim);
	if (ptr == str)
		return (ptr = 0);
	ptr = *ptr ? *ptr = 0, ptr + 1 : 0;
	return (str);
}
/**
 * _strcspn - computes the length of the maximum initial segment of the string
 * pointed to by s1 which consists entirely of characters not from the
 * string pointed to by str2.
 * @str1: string to check
 * @str2: string useful to compare
 * Return: the length of the segment.
 **/
size_t _strcspn(const char *str1, const char *str2)
{
	size_t len = 0;

	while (*str1)
	{
		if (_strchr(str2, *str1))
			return (len);
		str1++, len++;
	}
	return (len);
}
/**
 * _strspn - computes the length of the maximum initial segment of the string
 * pointed to by str1 which consists entirely of characters from the string
 * pointed to by str2.
 * @str1: string to compute the lengh
 * @str2: string delimit
 * Return: the length of the segment.
 **/
size_t _strspn(const char *str1, const char *str2)
{
	size_t len = 0;

	while (*str1 && _strchr(str2, *str1++))
		len++;
	return (len);
}
/**
 * _strchr - locates the first occurrence of c (converted to a char) in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string.
 * @str: string
 * @c: character
 * Return: a pointer to the located character, or a null pointer
 * if the character does not occur in the string.
 **/
char *_strchr(const char *str, int c)
{
	while (*str != (char)c)
		if (!*str++)
			return (0);
	return ((char *)str);
}
