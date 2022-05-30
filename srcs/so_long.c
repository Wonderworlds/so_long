/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:31:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/30 16:05:12 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_solong	*vars;

	if (ac != 2)
	{
		ft_printf(COLOR_RED"Error\nMap missing\n"COLOR_RED);
		return (0);
	}
	vars = malloc(sizeof(t_solong));
	if (!vars)
		return (0);
	if (!ft_init(&vars, av[1]))
	{
		ft_close(&vars, 'E');
		return (0);
	}
	mlx_key_hook(vars->win, e_key_down, &vars);
	mlx_hook(vars->win, 17, 1L << 17, red_cross_close, &vars);
	mlx_loop_hook(vars->mlx, ft_anim, &vars);
	mlx_loop(vars->mlx);
	ft_close(&vars, 'W');
	return (EXIT_SUCCESS);
}
