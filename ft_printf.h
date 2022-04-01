/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:22:30 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/12 23:22:35 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_print_hex(unsigned long n, char c, int *count);
void	ft_print_string(char *s, int *count);
void	ft_print_u(unsigned long n, int *count);
void	ft_putchar_count(char c, int *count);
int		ft_printf(const char *str, ...);
void	ft_putnbr(int n, int *count);

#endif
