/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrisnull.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:25:42 by lnicolof          #+#    #+#             */
/*   Updated: 2023/12/18 18:12:06 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long long nb)
{
	char	*base;
	int		counter;

	base = "0123456789abcdef";
	counter = 0;
	if (nb > 15)
	{
		counter += ft_printptr(nb / 16);
		counter += ft_printptr(nb % 16);
	}
	else
	{
		ft_putchar(base[nb]);
		counter++;
	}
	return (counter);
}

int	ft_ptrisnull(unsigned long long nb)
{
	int	counter;

	counter = 0;
	if (nb == 0)
	{
		write(1, "(nil)", 5);
		counter = 5;
		return (counter);
	}
	else
	{
		counter += write(1, "0x", 2);
		counter += ft_printptr(nb);
	}
	return (counter);
}
