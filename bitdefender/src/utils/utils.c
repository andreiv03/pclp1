#include <ctype.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int ends_with(const char *string, const char *search)
{
	size_t string_length = strlen(string);
	size_t search_length = strlen(search);

	if (string_length < search_length)
		return false;

	for (size_t index = 0; index < search_length; ++index) {
		char character_one = string[string_length - search_length + index];
		char character_two = search[index];
		if (tolower(character_one) != tolower(character_two))
			return false;
	}

	return true;
}

char **split(char *string, char *separators, size_t *length)
{
	char **list = calloc(*length, sizeof(char *));
	char *item = strtok(string, separators);

	while (item) {
		list = realloc(list, (*length + 1) * sizeof(char *));
		list[*length] = calloc(strlen(item) + 1, sizeof(char));
		strcpy(list[*length], item);
		*length = *length + 1;

		item = strtok(NULL, separators);
	}

	return list;
}

void free_allocated_memory(size_t number, ...)
{
	va_list list;
	va_start(list, number);

	for (size_t index = 0; index < number; ++index)
		free(va_arg(list, char *));

	va_end(list);
}

void free_allocated_memory_array(char **array, size_t length)
{
	for (size_t index = 0; index < length; ++index)
		free(array[index]);
	free(array);
}
