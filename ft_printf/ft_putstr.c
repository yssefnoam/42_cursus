/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 22:44:54 by ynoam             #+#    #+#             */
/*   Updated: 2019/12/28 21:35:19 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_putstr(char *s, char c)
{
	int	i;

	if (c == 'c' && *s == 0)
		i = write(1, "\0", 1);
	i = write(1, s, ft_strlen(s));
	ft_free(&s);
	return (k);
}
