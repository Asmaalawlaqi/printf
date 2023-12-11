/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:36:26 by asmalawl          #+#    #+#             */
/*   Updated: 2023/12/11 11:35:34 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexlow(unsigned int x)// we declure the char array to store the hexadecimal
{
	char	str[25]; //Define characters for the hexadecimal representation (lowercase)
	char	*base_char;
	int		printed_chars; // Loop counter variable
	int		i;

	i = 0; //Initialize the loop counter to 0
	base_char = "0123456789abcdef"; // Variable to store the number of printed characters
	if (x == 0) //// Check if the input value is 0
	{
		ft_putchar('0');
		return (1);
	}
	while (x != 0) //// While the input value is not 0
	{
		str[i] = base_char[x % 16];
		x = x /16; // updit the input with the value by dividing it by 16
		i++;
	}
	printed_chars = i; //store the number of printed charchter
	while (i--) // Print the hexadecimal representation by iterating through the array in reverse
		ft_putchar(str[i]);
	return (printed_chars); /// Return the number of printed characters
}
