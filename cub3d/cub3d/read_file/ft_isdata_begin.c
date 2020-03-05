/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdata_begin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:40:28 by ynoam             #+#    #+#             */
/*   Updated: 2020/03/05 15:32:16 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdata_begin(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (ft_isalpha(line[i]))
		return (1);
	return (0);
}
