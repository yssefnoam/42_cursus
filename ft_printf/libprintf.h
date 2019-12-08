/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:11:02 by ynoam             #+#    #+#             */
/*   Updated: 2019/12/08 20:56:35 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*ft_addtop(unsigned long int n);
char	*ft_all(char **ptr, va_list ap);
char	*ft_convertion(char **c, va_list ap);
char	*ft_ctoa(int c);
char	*ft_find_conv(char	*ptr, va_list ap);
char	*ft_itoa(int n, int c);
char	*ft_itox(unsigned int n, char c);
char	*ft_strdup(const char *string);
char	*ft_strjoin(char *string1, char *string2);
char	*ft_uitoa(unsigned int n);
char	*ft_space(int num);
char	*ft_zero(int num);
int		ft_star(int num);
int		ft_atoi(char **str);
int		ft_check_all(char c);
int		ft_free(char **ptr);
int		ft_is_flage(char c);
int		ft_isdigit(int c);
int		ft_printf(const char *p, ...);
int		ft_putstr(char *str);
size_t	ft_strlen(char *str);

#endif