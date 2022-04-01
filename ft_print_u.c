/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:21:53 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/12 23:21:54 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u(unsigned long n, int *count)
{
	unsigned long	i;

	i = n;
	if (i > 9)
	{
		ft_print_u (i / 10, count);
		ft_print_u (i % 10, count);
	}
	else
		ft_putchar_count (i + '0', count);
}
