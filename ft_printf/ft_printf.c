/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:38:47 by ynoam             #+#    #+#             */
/*   Updated: 2019/12/28 21:43:20 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_printf(const char *p, ...)
{
	char		*s;
	va_list		ap;
	long int	i;

	s = NULL;
	i = 0;
	va_start(ap, p);
	while (*p != '\0')
	{
		if (*p == '%' && p++)
			if (!(ft_is_flage(*p)))
				if (*p == '%')
					i += write(1, p++, 1);
				else
					i += ft_putstr(ft_cnv(p++, ap), *p);
			else
				i += ft_all((char **)&p, ap);
		else
			i += write(1, p++, 1);
	}
	va_end(ap);
	return (i);
}
