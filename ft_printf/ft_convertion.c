/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:57:19 by ynoam             #+#    #+#             */
/*   Updated: 2020/01/01 15:38:00 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char	*ft_cnv(char **c, va_list ap, int i)
{
	char	*s;
	int		*j;

	s = ft_strdup("");
	if (**c == 'd' || **c == 'i')
		s = ft_itoa(va_arg(ap, int));
	else if (**c == 'c')
		s = ft_ctoa(va_arg(ap, int));
	else if (**c == 's')
	{
		if ((s = va_arg(ap, char*)))
			s = ft_strdup(s);
		else
			s = ft_strdup("(null)");
	}
	else if (**c == 'p')
		s = ft_addtop(va_arg(ap, unsigned long int));
	else if (**c == 'n' && (j = va_arg(ap, int*)))
		*j = i;
	else if (**c == 'x' || **c == 'X' || **c == 'u')
		s = ft_itox(va_arg(ap, unsigned int), **c);
	(*c)++;
	return (s);
}
