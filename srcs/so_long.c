/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:31:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/27 15:30:42 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_solong **vars)
{
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	mlx_destroy_display((*vars)->mlx);
	free((*vars)->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_solong	*vars;
	int			fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	vars = malloc(sizeof(t_solong));
	if (!vars)
		return (0);
	vars->map = ft_split(read_fd(fd), '\n');
	vars->x = ft_strlen(vars->map[0]);
	int	i = 0;
	while (vars->map[i])
		i++;
	vars->y = i;
	vars->count = 0;
	vars->mult = 50;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH * vars->x,
				HEIGHT * vars->y, "so_long");
	ft_init_tex(&vars);
	ft_init_img(&vars);
	vars->anim_count = 0;
	vars->anim_enemy = 0;
	vars->anim_player = 0;
	mlx_key_hook(vars->win, e_key_down, &vars);
	mlx_hook(vars->win, 17, 1L << 17, red_cross_close, &vars);
	mlx_loop_hook(vars->mlx, ft_anim, &vars);
	mlx_loop(vars->mlx);
	ft_close(&vars);
	free(vars);
	return (0);
}
