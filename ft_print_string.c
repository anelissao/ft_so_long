/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelissao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 23:21:28 by aelissao          #+#    #+#             */
/*   Updated: 2021/12/12 23:21:30 by aelissao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(char *s, int *count)
{
	int	i;

	if (s == NULL)
	{
		ft_print_string("(null)", count);
		return ;
	}
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_count(s[i], count);
		i++;
	}
}
