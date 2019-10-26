/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:47:18 by ynoam             #+#    #+#             */
/*   Updated: 2019/10/20 23:58:24 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *string1, char const *string2)
{
	char	*thenew;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (string1[i])
		i++;
	while (string2[j])
		j++;
	thenew = (char *)malloc(i + j + 1);
	if (thenew == NULL)
		return (NULL);
	thenew[i + j] = 0;
	while (j--)
		thenew[i + j] = string2[j];
	while (i--)
		thenew[i] = string1[i];
	return (thenew);
}