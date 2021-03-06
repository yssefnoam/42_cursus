/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:59:46 by ynoam             #+#    #+#             */
/*   Updated: 2019/12/31 21:09:44 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

char		*ft_itoa(int n)
{
	char			*ptr;
	unsigned int	copy;
	int				i;
	int				sign;

	sign = 0;
	if (n < 0 && ++sign)
		copy = n * -1;
	else
		copy = n;
	i = ft_intlen(copy);
	if (!(ptr = malloc(i + sign + 1)))
		return (NULL);
	ptr[i + sign] = '\0';
	while (copy > 9)
	{
		ptr[--i + sign] = (copy % 10) + 48;
		copy /= 10;
	}
	ptr[--i + sign] = copy + 48;
	if (n < 0)
		ptr[--i + sign] = '-';
	return (ptr);
}
