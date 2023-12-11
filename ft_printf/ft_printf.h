/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asmalawl <asmalawl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:32:32 by asmalawl          #+#    #+#             */
/*   Updated: 2023/12/11 11:32:36 by asmalawl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putnbrunsigned(unsigned long int n);
void	ft_putstr(char *str);

int		hexlow(unsigned int x);
int		hexupp(unsigned int x);
int		decimal(int d);
int		unsigneddecimal(unsigned int d);
int		string(char *str);
int		charpointer(char c);
int		pointer(unsigned long p);
int		ft_printf(const char *str, ...);

#endif
