/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:23:09 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/12 23:23:10 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	long int	i;

	i = n;
	if (i < 0)
	{
		ft_putchar_count('-', count);
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr (i / 10, count);
		ft_putnbr (i % 10, count);
	}
	else
		ft_putchar_count (i + '0', count);
}
