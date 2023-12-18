/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:45:58 by asmalawl          #+#    #+#             */
/*   Updated: 2023/12/12 11:46:01 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// VARIADIXC
// it checks the format specifier that we are using in our ft_printf in the int main
// and then uses the function needed according to the format specifier
static int	checker(char c, va_list *args)
{
	if (c == 'c')
		return (charpointer(va_arg(*args, int)));
	else if (c == 's')
		return (string(va_arg(*args, char *)));
	else if (c == 'p')
		return (pointer(va_arg(*args, unsigned long)));
	else if (c == 'd')
		return (decimal(va_arg(*args, unsigned long)));
	else if (c == 'i')
		return (decimal(va_arg(*args, unsigned long)));
	else if (c == 'u')
		return (unsigneddecimal(va_arg(*args, unsigned long)));
	else if (c == 'x')
		return (hexlow(va_arg(*args, unsigned long)));
	else if (c == 'X')
		return (hexupp(va_arg(*args, unsigned long)));
	else if (c == '%')
		return (charpointer('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		chars_printed;

	i = 0;
	chars_printed = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			chars_printed = chars_printed + checker(str[i], &args);
			// here we use str[i] in the checker function and it prints the required arg
			// depending on the format specifier.
		}
		else
		{
			chars_printed++;
			ft_putchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (chars_printed);
}

int	main(void)
{			// FORMAT SPECIFIER	   //VARIADIC LIST THAT HOLDS ALL TYPES OF ARGS
	ft_printf("%s %d %p %x %X %i %u %c %%\n", "hahaha", 122, "dhfiusdhf", 435,
			435, 122, -789, 'a');
	printf("%s %d %p %x %X %i %u %c %%\n", "hahaha", 122, "dhfiusdhf", 435, 435,
			122, -789, 'a');
}

// va_list: It's like a list or a pointer that helps you access the arguments passed to a function.
// va_start: Initializes the va_list to point to the first variable argument.
// va_arg: Retrieves the value of the next argument in the list.
// va_end: Cleans up the va_list after you're done using it.
