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
