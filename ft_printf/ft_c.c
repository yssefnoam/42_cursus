/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:10:22 by ynoam             #+#    #+#             */
/*   Updated: 2019/12/31 14:56:20 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_c(char *s, int sp)
{
	int	a;
	int	nu;

	ft_init(&nu, &a);
	if (*s == 0)
		nu = 1;
	if (sp > 0)
		a += ft_space(--sp);
	if (nu == 0)
		a += write(1, s, 1);
	else
		a += write(1, "\0", 1);
	if (sp < 0)
	{
		sp = sp * -1;
		a += ft_space(--sp);
	}
	return (a);
}
