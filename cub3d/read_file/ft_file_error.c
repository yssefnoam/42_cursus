/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:31:44 by ynoam             #+#    #+#             */
/*   Updated: 2020/10/19 17:59:10 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

/*
** print the error and exit the programme;
*/

int	ft_file_error(void)
{
	ft_putstr_fd("wolf: error: your file syntax not good.\n", 2);
	exit(EXIT_FAILURE);
	return (1);
}