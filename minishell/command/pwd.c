/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:02:53 by ynoam             #+#    #+#             */
/*   Updated: 2020/02/23 19:00:19 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main(void)
{
	char	*pwd_buff;

	pwd_buff = NULL;
	if ((pwd_buff = malloc(sizeof(char) * 1024)) == NULL)
		return (EXIT_FAILURE);
	getcwd(pwd_buff, 1024);
	ft_putstr_fd(pwd_buff, 1);
	ft_putstr_fd("\n", 1);
	free(pwd_buff);
	return (EXIT_SUCCESS);
}
