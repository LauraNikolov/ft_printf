/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:12:02 by lnicolof          #+#    #+#             */
/*   Updated: 2023/12/18 18:46:38 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list arg, const char c)
{
	int	retour;

	retour = 0;
	if (c == 'c')
		retour += ft_printchar(va_arg(arg, int));
	if (c == 's')
		retour += ft_printstr(va_arg(arg, char *));
	if (c == 'p')
		retour += (ft_ptrisnull(va_arg(arg, unsigned long long)));
	if (c == 'd')
		retour += ft_printdeci(va_arg(arg, int));
	if (c == 'i')
		retour += ft_printint(va_arg(arg, int));
	if (c == 'u')
		retour += ft_printunsigneddeci(va_arg(arg, unsigned int));
	if (c == 'x')
		retour += ft_printhexalow(va_arg(arg, unsigned int));
	if (c == 'X')
		retour += ft_printhexaupp(va_arg(arg, unsigned int));
	if (c == '%')
	{
		ft_putchar(c);
		retour++;
	}
	return (retour);
}
