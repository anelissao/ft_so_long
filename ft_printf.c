/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:22:10 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/12 23:22:13 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_args(va_list p, char c, int *count)
{
	if (c == 'c')
		ft_putchar_count(va_arg(p, int), count);
	if (c == 's')
		ft_print_string(va_arg(p, char *), count);
	if (c == 'x')
		ft_print_hex(va_arg(p, unsigned int), 'x', count);
	if (c == 'X')
		ft_print_hex(va_arg(p, unsigned int), 'X', count);
	if (c == 'p')
	{
		ft_print_string("0x", count);
		ft_print_hex(va_arg(p, unsigned long), 'x', count);
	}
	if (c == 'u')
		ft_print_u(va_arg(p, unsigned int), count);
	if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(p, int), count);
	if (c == '%')
		ft_putchar_count('%', count);
}

int	ft_printf(const char *str, ...)
{
	va_list	p;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(p, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			check_args(p, str[i], &count);
		}
		else
			ft_putchar_count(str[i], &count);
		i++;
	}
	va_end(p);
	return (count);
}
