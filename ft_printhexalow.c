/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexalow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:15:24 by lnicolof          #+#    #+#             */
/*   Updated: 2023/12/18 18:15:17 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexalow_recursive(long nb, int *counter)
{
	char	*base;

	base = "0123456789abcdef";
	if (nb < 0)
	{
		ft_putchar('-');
		(*counter)++;
		nb *= -1;
	}
	if (nb > 15)
	{
		ft_hexalow_recursive(nb / 16, counter);
		ft_hexalow_recursive(nb % 16, counter);
	}
	else
	{
		ft_putchar(base[nb]);
		(*counter)++;
	}
	return (*counter);
}

int	ft_printhexalow(unsigned int n)
{
	int					counter;
	unsigned long int	nb;

	counter = 0;
	nb = n;
	ft_hexalow_recursive(nb, &counter);
	return (counter);
}
