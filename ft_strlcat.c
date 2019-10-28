/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:41:16 by ynoam             #+#    #+#             */
/*   Updated: 2019/10/28 15:16:59 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int dlen;
	int slen;
	int x;

	dlen = ft_strlen(dst);
	slen = ft_strlen((char *)src);
	if (dlen >= (int)size)
		return (ft_strlen((char *)src) + size);
	else
	{
		x = slen;
		dst += dlen;
		while (x-- && --size - dlen)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (slen + dlen);
}
