/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:08:19 by asmalawl          #+#    #+#             */
/*   Updated: 2023/12/11 11:56:05 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
// This function calculates the length of a null-terminated string str and returns the result as a size_t

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
//This function prints a single character c to the standard output using
void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0'); // convertion takes place, turns the int to an ascii
	}
	else
	{
		ft_putchar(nb + '0');
	}
}////this function prints an integer nb to the standard output. It handles the special case where nb is equal to the minimum integer value (-2147483648) separately,
//as printing it directly would lead to overflow. For other negative values, it prints the negative sign,
// updates nb to its absolute value, and then recursively calls itself to print the remaining digits.

void	ft_putnbrunsigned(unsigned long int n)
{
	if (n == (unsigned long)LONG_MIN)
		ft_putchar('0');
	if (n >= 4294967295)
		ft_putnbrunsigned(4294967295);//4294967295, it prints the maximum representable value. Otherwise, it recursively calls itself to print the digits.
	else if (n >= 10)
	{
		ft_putnbrunsigned(n / 10);
		ft_putnbrunsigned(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}
