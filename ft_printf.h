/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolof <lnicolof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:15:43 by lnicolof          #+#    #+#             */
/*   Updated: 2023/12/18 18:47:16 by lnicolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_parse(va_list arg, const char c);
int		ft_printchar(char c);
int		ft_printdeci(int n);
int		ft_printf(const char *s, ...);
int		ft_printhexaupp(unsigned int nb);
int		ft_printhexalow(unsigned int nb);
int		ft_printint(int n);
int		ft_printstr(char *s);
int		ft_printunsigneddeci(unsigned int n);
int		ft_ptrisnull(unsigned long long nb);
void	ft_putchar(char c);
int		ft_check(char *s);
char	*ft_strchr(const char *s, int c);

#endif