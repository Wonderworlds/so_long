/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:37:07 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 16:28:58 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


static void	square_color(t_vars *vars, int start, int end, int color)
{
	for (int i = start; i < end; i++)
	{
		for (int j = start; j < end; j++)
		{
			my_mlx_pixel_put(&vars->img, i, j, color);
			my_mlx_pixel_put(&vars->img, j, i, color);
		}
	}
}

int	rainbow(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, 500, 500);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	if (!ft_strncmp(vars->img.state, "RED", ft_strlen(vars->img.state)))
	{
		square_color(vars, 100, 400, 0x000000FF);
		vars->img.state = "BLUE";
	}
	else if (!ft_strncmp(vars->img.state, "BLUE", ft_strlen(vars->img.state)))
	{
		square_color(vars, 100, 400, 0x0000FF00);
		vars->img.state = "GREEN";
	}
	else if (!ft_strncmp(vars->img.state, "GREEN", ft_strlen(vars->img.state)))
	{
		square_color(vars, 100, 400, 0x00FF0000);
		vars->img.state = "RED";
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
