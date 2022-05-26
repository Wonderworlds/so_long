/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:31:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 15:18:38 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*state;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
}				t_vars;

int	win_close_key(int keycode, t_vars *vars)
{
	ft_printf("\nkeycode : %i", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		//free(vars->mlx);
		//free(vars->win);
	}
	return (0);
}
int	win_close_mouse(int button, int x, int y, t_vars *vars)
{
	ft_printf("\nkeycode : %i\n\tx : %i\n\ty : %i", button, x, y);
	//if (keycode == 65307)
	//	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	e_key_down(int keycode, t_vars *vars)
{
	ft_printf("\nkeycode : %i", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		//free(vars->mlx);
		//free(vars->win);
		return (0);
	}
	ft_printf("\nimg state : %s", vars->img.state);
	if (!ft_strncmp(vars->img.state, "RED", ft_strlen(vars->img.state)))
	{
		ft_printf("\nHERE");

		for (int i = 100; i < 400; i++)
		{
			for (int j = 100; j < 400; j++)
			{
				my_mlx_pixel_put(&vars->img, i, j, 0x000000FF);
				my_mlx_pixel_put(&vars->img, j, i, 0x000000FF);
			}
		}
		vars->img.state = "BLUE";
	}
	else if (!ft_strncmp(vars->img.state, "BLUE", ft_strlen(vars->img.state)))
	{
		for (int i = 100; i < 400; i++)
		{
			for (int j = 100; j < 400; j++)
			{
				my_mlx_pixel_put(&vars->img, i, j, 0x0000FF00);
				my_mlx_pixel_put(&vars->img, j, i, 0x0000FF00);
			}
		}
				vars->img.state = "GREEN";
	}
	else if (!ft_strncmp(vars->img.state, "GREEN", ft_strlen(vars->img.state)))
	{
		for (int i = 100; i < 400; i++)
		{
			for (int j = 100; j < 400; j++)
			{
				my_mlx_pixel_put(&vars->img, i, j, 0x00FF0000);
				my_mlx_pixel_put(&vars->img, j, i, 0x00FF0000);
			}
		}
		vars->img.state = "RED";
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return(0);
}


int	main(void)
{
	t_vars	vars;
	t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "so_long");
	img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int i = 100; i < 400; i++)
	{
		for (int j = 100; j < 400; j++)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			my_mlx_pixel_put(&img, j, i, 0x00FF0000);
		}
		img.state = "RED";

	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	vars.img = img;
	mlx_hook(vars.win, 2, 1L<<0, e_key_down, &vars);
	mlx_hook(vars.win, 4, 1L<<2, win_close_mouse, &vars);
	//mlx_loop_hook(vars.mlx, render_next_frame, &img);
	mlx_loop(vars.mlx);
	return (0);
}