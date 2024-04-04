/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignedeci.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:11:15 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 13:32:06 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printunsignedeci_recursive(unsigned long nb, int *counter)
{
	if (nb > 9)
	{
		ft_printunsignedeci_recursive(nb / 10, counter);
		ft_printunsignedeci_recursive(nb % 10, counter);
	}
	else
	{
		nb = nb + '0';
		ft_putchar(nb);
		(*counter)++;
	}
	return (*counter);
}

int	ft_printunsigneddeci(unsigned int n)
{
	int				counter;
	unsigned long	nb;

	counter = 0;
	nb = n;
	ft_printunsignedeci_recursive(nb, &counter);
	return (counter);
}
