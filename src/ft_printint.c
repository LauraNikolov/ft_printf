/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:43:10 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 13:31:57 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_printint_recursive(long nb, int *counter)
{
	if (nb < 0)
	{
		ft_putchar('-');
		(*counter)++;
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_printint_recursive(nb / 10, counter);
		ft_printint_recursive(nb % 10, counter);
	}
	else
	{
		nb = nb + '0';
		ft_putchar(nb);
		(*counter)++;
	}
	return (*counter);
}

int	ft_printint(int n)
{
	int		counter;
	long	nb;

	counter = 0;
	nb = n;
	ft_printint_recursive(nb, &counter);
	return (counter);
}
