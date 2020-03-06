/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynoam <ynoam@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 14:28:28 by ynoam             #+#    #+#             */
/*   Updated: 2020/03/06 22:22:05 by ynoam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_circle(int x, int y, int color, int radius)
{
	float	degree;
	int		new_x;
	int		new_y;


	degree = 0.1;
	while(degree <= 360.0)
	{
		new_x = cos(degree*(M_PI/180)) * radius;
		new_y = sin(degree*(M_PI/180)) * radius;
		mlx_pixel_put(g_s_mydata.mlx_ptr, g_s_mydata.win_ptr, x + new_x , y + new_y, color);
		degree += 0.1;
	}
}
void	ft_draw_square(int x, int y, int color, int lenth)
{
	int		new_x;
	int		new_y;
	int		new_two_y;

	new_x = x + lenth;
	new_y = y + lenth;
	new_two_y = y;
	while(x <= new_x)
	{
		y = new_two_y;
		while(y <= new_y)
		{
			mlx_pixel_put(g_s_mydata.mlx_ptr, g_s_mydata.win_ptr, x , y , color);
			y++;
		}
		x++;
	}
}

int ft_test(int key)
{
	static int x = 100;
	static int y = 100;
	int raduis = 20;
	
	if (x - raduis  < 0)
		x = raduis;
	if (y  - raduis < 0)
		y = raduis;
	mlx_clear_window(g_s_mydata.mlx_ptr, g_s_mydata.win_ptr);
	if(key == MAC_KEY_ESC)
		//if(key == 65307)
		exit(EXIT_SUCCESS);
	else if (key == MAC_KEY_LEFT)
		ft_draw_circle(x -= 10, y, GREEN, raduis);
	else if (key == MAC_KEY_RIGHT)
		ft_draw_circle(x += 10, y, GREEN, raduis);
	else if (key == MAC_KEY_DOWN)
		ft_draw_circle(x, y += 10, GREEN, raduis);
	else if (key == MAC_KEY_UP)
		ft_draw_circle(x, y -= 10, GREEN, raduis);
	else
	{
		mlx_string_put(g_s_mydata.mlx_ptr, g_s_mydata.win_ptr, key, key, 255 << 16 | 127 << 8 | 80, ft_itoa(key));
		mlx_string_put(g_s_mydata.mlx_ptr, g_s_mydata.win_ptr, key+100, key+100, 10 << 24 | 255 << 16 | 127 << 8 | 80, ft_itoa(key));
	}
	return (0);
}


int ft_mouse(int button, int x, int y)
{
	mlx_clear_window(g_s_mydata.mlx_ptr, g_s_mydata.win_ptr);
	mlx_string_put(g_s_mydata.mlx_ptr, g_s_mydata.win_ptr,200+button, 100+button, 255 << 16 | 127 << 8 | 80, ft_itoa(button));
	mlx_string_put(g_s_mydata.mlx_ptr, g_s_mydata.win_ptr,200+x, 100+x, 211 << 16 | 127 << 8 | 80, ft_itoa(x));
	mlx_string_put(g_s_mydata.mlx_ptr, g_s_mydata.win_ptr,200+y, 100+y, 143 << 16 | 127 << 8 | 80, ft_itoa(y));
	printf("button = %d ;  x = %d ;  y = %d  ;  win_ptr =  %p\n", button , x , y, g_s_mydata.win_ptr);
	return (0);
}
void ft_draw_wall(void)
{
	int i = 0;
	int j = 0;
	while(i < g_s_mydata.map_height)
	{
		j = 0;
		while (j < (int)ft_strlen(g_s_mydata.ptr_map[i]))
		{
			if (g_s_mydata.ptr_map[i][j] == '1')
				ft_draw_square(32 * j , 32 * i , GREEN, 32);
			j++;
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	if (argc == 2 || argc == 3)
	{
		//   Init data
		read_file(argv[1]);
		g_s_mydata.mlx_ptr = mlx_init();
		g_s_mydata.win_ptr = mlx_new_window(g_s_mydata.mlx_ptr, g_s_mydata.win_height, g_s_mydata.win_width, argv[0]);

		//   Init wall resolution 
		//g_s_mydata.wall_width = g_s_mydata.win_width / g_s_mydata.map_width;
		//g_s_mydata.wall_height = g_s_mydata.win_height / g_s_mydata.map_height;
		g_s_mydata.wall_width = 32;
		g_s_mydata.wall_height = 32;
		int i = 0;
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		puts(g_s_mydata.ptr_map[i++]);
		//   Init wall resolution 
		ft_draw_wall();

		mlx_key_hook(g_s_mydata.win_ptr, ft_test,  (void*)0);
		mlx_loop(g_s_mydata.mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("Error: Argument.\n", 2);
		exit(EXIT_FAILURE);
	}
	/*
	if (argc == 2)
	{
		g_s_mydata.mlx_ptr = mlx_init();
	    g_s_mydata.win_ptr = mlx_new_window(g_s_mydata.mlx_ptr, 900, 800, argv[0]);
	    mlx_string_put(g_s_mydata.mlx_ptr, g_s_mydata.win_ptr,200, 100, 255 << 16 | 127 << 8 | 80, "Read from file");
		mlx_key_hook(g_s_mydata.win_ptr, ft_test,  (void*)0);
		mlx_loop(g_s_mydata.mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	ft_putstr_fd("Error: Argument.\n", 2);
	exit(EXIT_FAILURE);
	*/
}
