/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:41:37 by ynoam             #+#    #+#             */
/*   Updated: 2019/12/30 22:03:18 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int		ft_all(char **p, va_list ap, int space, int zero)
{
	int	bd;
	int	bz;

	ft_init(&bd, &bz);
	if (is_pc(p))
		return(ft_changem(p, ap));
	while (ft_is_flage(**p))
		if (**p == '.' && (*p)++ && ++bd)
			zero = ft_atoi(p, ap);
		else if (**p == '0' && ++bz && (*p)++ && (zero = ft_atoi(p, ap)))
			(**p == '.') ? space = zero : 1;
		else if (**p == '-' || ft_isdigit(**p) || **p == '*')
			space = ft_atoi(p, ap);
	if (**p == 's')
		ft_changes(&space, &zero, bz, bd);
	else if (**p == 'd' || **p == 'i' || **p == 'x' || **p == 'X' || **p == 'u')
		ft_changed(&space, &zero, bz, bd);
	else if (**p == 'p' && !bd)
	{
			if (!bz && !space && !zero && (space = -1) != 0)
					zero = -1;
			else
					zero = -1;
	}
	return (space = ft_f1(space, zero, **p, ft_cnv(p, ap)));
}

int		is_pc(char **p)
{
	int i;

	i = 0;
	while (ft_is_flage(p[0][i]))
		i++;
	if (p[0][i] == '%')
		return (1);
	return (0);
}
