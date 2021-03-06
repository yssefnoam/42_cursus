/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:38:47 by ynoam             #+#    #+#             */
/*   Updated: 2020/01/01 15:36:45 by ynoam            ###   ########.fr       */
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
				if (*p == '%' && ++i)
					write(1, p++, 1);
				else
					i += ft_putstr(ft_cnv((char **)&p, ap, i), *(p - 1));
			else
				i += ft_all((char **)&p, ap, 0, 0);
		else
			i += write(1, p++, 1);
	}
	va_end(ap);
	return (i);
}
