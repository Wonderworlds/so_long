/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:31:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 18:12:35 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_vars **vars, int x)
{
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	mlx_destroy_display((*vars)->mlx);
	//free(vars->mlx);
	return (0);
}

int	main(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (0);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 500, 500, "so_long");
	display_tex(&vars, "./textures/ghost-sprite/down1.xpm", 32, 48);
	mlx_key_hook(vars->win, e_key_down, &vars);
	mlx_hook(vars->win, 17, 1L << 17, red_cross_close, &vars);
	//mlx_loop_hook(vars.mlx, render_next_frame, &img);
	mlx_loop(vars->mlx);
	ft_close(&vars, 0);
	return (0);
}
