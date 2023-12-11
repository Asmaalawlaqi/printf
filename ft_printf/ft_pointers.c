/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:23:47 by asmalawl          #+#    #+#             */
/*   Updated: 2023/12/11 12:43:20 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	pointer(unsigned long p)
{
	char	str[16]; //char str[25];: Declares an array to store the hexadecimal representation of the input.
	char	*base_char;
	int		i;
	int		j;

	i = 0;
	base_char = "0123456789abcdef"; //to represent the values 10, 11, 12, 13, 14, and 15, respectively.
	write(1, "0x", 2); //characters represent a number in hexadecimal but we need 0x at the start to show us that it is a pointer address
	if (p == 0) // a specific block of code is executed
	{
		ft_putchar('0'); //It prints the character '0' using
		return (3); //It returns the value 3.
	}
	while (p != 0) // continues as long as the value of p is not equal 0. // another word to keep contunie until its p equal 0;
	{
		str[i] = base_char[p % 16]; // calculates the remainder when p is divided by 16.
		//remainder is then used as an index to access a character in the base_char array.
		p = p / 16;  //This line updates the value of p by dividing it by 16.
		i++;//his increments the index
	}
	j = i;// copy from i to j;
	while (i--) //This means "keep looping as long as i is not zero.The i-- operation decrements the value of i by 1 for each iteration.
		ft_putchar(str[i]);  // to print each char in the str
	return (j + 2);
}
