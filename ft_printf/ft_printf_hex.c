/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:36:26 by asmalawl          #+#    #+#             */
/*   Updated: 2023/12/19 17:58:06 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlow(unsigned int x)
{
	char	str[16];
	char	*base_char;
	int		printed_chars;
	int		i;

	i = 0;
	base_char = "0123456789abcdef";
	if (x == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (x != 0)
	{
		str[i] = base_char[x % 16];
		x = x / 16;
		i++;
	}
	printed_chars = i;
	while (i--)
		ft_putchar(str[i]);
	return (printed_chars);
}

int	hexupp(unsigned int x)
{
	char	str[16];
	char	*base_char;
	int		printed_chars;
	int		i;

	i = 0;
	base_char = "0123456789ABCDEF";
	if (x == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (x != 0)
	{
		str[i] = base_char[x % 16];
		x = x / 16;
		i++;
	}
	printed_chars = i;
	while (i--)
		ft_putchar(str[i]);
	return (printed_chars);
}
