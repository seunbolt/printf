#include "main.h"

/**
 * get_specifier_func - handles format specifiers
 * @fmt: format to print
 *
 * Return: Format specifier function else NULL if not found
 */
int (*get_specifier_func(char fmt))(va_list, int *, char *)
{
	int i = 0;
	spec_t spec[] = {
		{'c', handle_character_specifier},
		{'s', handle_string_specifier},
		{'d', handle_integer_specifier},
		{'i', handle_integer_specifier},
		{'b', handle_binary_specifier},
		{'S', handle_mod_string_specifier},
		{'p', handle_mem_addr_specifier},
	};

	while (i < (int)(sizeof(spec) / sizeof(spec[i])))
	{
		if (fmt == '\0')
			return (NULL); /*Unexpected end of format string after %*/

		if (fmt == spec[i].fmt)
			return (spec[i].func);
		i++;
	}

	return (NULL);
}