/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:31:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 16:00:12 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_hook(vars.win, 2, 1L << 0, e_key_down, &vars);
	mlx_hook(vars.win, 4, 1L << 2, win_close_mouse, &vars);
	//mlx_loop_hook(vars.mlx, render_next_frame, &img);
	mlx_loop(vars.mlx);
	return (0);
}
