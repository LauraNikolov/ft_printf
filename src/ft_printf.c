/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:31 by lnicolof          #+#    #+#             */
/*   Updated: 2024/04/04 13:31:42 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (c == 0 && str[i] == 0)
		return ((char *)str + i);
	return (NULL);
}

int	ft_check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		while (s[i] && s[i] != '%')
			i++;
		if (s[i] == '%')
		{
			i++;
			if (!ft_strchr("cspdiuxX%", (int)s[i]))
				return (0);
			else
				return (1);
		}
	}
	return (1);
}

int	ft_printf(const char *s, ...)
{
	int	i;
	int	retour;

	va_list(arg);
	va_start(arg, s);
	i = 0;
	retour = 0;
	if (!s || !ft_check((char *)s))
		return (-1);
	while (s[i])
	{
		while (s[i] && s[i] != '%')
		{
			retour += write(1, &s[i], 1);
			i++;
		}
		if (s[i] == '%')
		{
			i++;
			retour += ft_parse(arg, s[i]);
			i++;
		}
	}
	va_end(arg);
	return (retour);
}
/* #include "limits.h"

int	main(void)
{
	ft_printf ("|%x|\n", LONG_MAX);
	printf("%x", LONG_MAX);
}  */
// attention si a la fin il y a un pourcentage on met une erreur (-1);
