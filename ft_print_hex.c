/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:20:58 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/12 23:21:00 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned long n, char c, int *count)
{
	char	*str;

	if (c == 'x')
		str = "0123456789abcdef";
	else if (c == 'X')
		str = "0123456789ABCDEF";
	if (n > 15)
	{
		ft_print_hex(n / 16, c, count);
		ft_putchar_count(str[n % 16], count);
	}
	else
		ft_putchar_count(str[n], count);
}
