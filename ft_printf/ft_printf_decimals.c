/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_decimals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:49:12 by asmalawl          #+#    #+#             */
/*   Updated: 2023/12/12 11:49:14 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	decimal(int d)
{
	int	i;
	int	j;

	i = 0;
	ft_putnbr(d);
	if (d == 0)
		return (1);
	if (d < 0)
	{
		d = -d;
		i++;
	}
	j = d;
	while (j != 0)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

int	unsigneddecimal(unsigned int d)
{
	int	i;

	i = 0;
	ft_putnbrunsigned(d);
	if (d == 0)
		return (1);
	while (d != 0)
	{
		d = d / 10;
		i++;
	}
	return (i);
}
