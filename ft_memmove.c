/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:36:15 by ynoam             #+#    #+#             */
/*   Updated: 2019/10/18 13:36:20 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*vimmercopy(void *distination, const void *source, size_t len);

void	*ft_memmove(void *distination, const void *source, size_t lenth)
{
	char		*dst2;
	const char	*src2;

	dst2 = (char *)distination;
	src2 = (char *)source;
	if (!distination && !source)
		return (0);
	if (distination > source)
		while (lenth--)
			dst2[lenth] = src2[lenth];
	else if (distination < source)
		vimmercopy(distination, source, lenth);
	return ((unsigned char *)distination);
}

void	*vimmercopy(void *distination2, const void *source2, size_t len)
{
	char		*pintertodist;
	const char	*pintertosrc;

	pintertodist = distination2;
	pintertosrc = source2;
	while (len--)
		*pintertodist++ = *pintertosrc++;
	return ((char *)distination2);
}
