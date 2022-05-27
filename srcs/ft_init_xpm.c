/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_xpm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 23:45:03 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/27 23:19:19 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_init_bg(t_solong **vars)
{
	(*vars)->bg = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/background.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->exit = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/exit.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->wall = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/obstacle.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->chest = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/chest.xpm", &(*vars)->width, &(*vars)->height);
	if (!(*vars)->bg || !(*vars)->wall || !(*vars)->exit || !(*vars)->chest)
		return (0);
	return (1);
}

static int	ft_init_player(t_solong **vars)
{
	int	i;

	(*vars)->player[0] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/p/p1.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->player[1] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/p/p2.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->player[2] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/p/p3.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->player[3] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/p/p4.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->player[4] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/p/p5.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->player[5] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/p/p6.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->player[6] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/p/p7.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->player[7] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/p/p8.xpm", &(*vars)->width, &(*vars)->height);
	i = 0;
	while (i < 8)
		if (!(*vars)->player[i++])
			return (0);
	return (1);
}

static int	ft_init_enemy(t_solong **vars)
{
	int	i;

	(*vars)->enemy[0] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/e/e1.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->enemy[1] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/e/e2.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->enemy[2] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/e/e3.xpm", &(*vars)->width, &(*vars)->height);
	(*vars)->enemy[3] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/e/e4.xpm", &(*vars)->width, &(*vars)->height);
	i = 0;
	while (i < 4)
		if (!(*vars)->enemy[i++])
			return (0);
	return (1);
}

static int	ft_init_cd(t_solong **vars, int w, int h, int i)
{
	(*vars)->cd[0] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/cd/0.xpm", &w, &h);
	(*vars)->cd[1] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/cd/1.xpm", &w, &h);
	(*vars)->cd[2] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/cd/2.xpm", &w, &h);
	(*vars)->cd[3] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/cd/3.xpm", &w, &h);
	(*vars)->cd[4] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/cd/4.xpm", &w, &h);
	(*vars)->cd[5] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/cd/5.xpm", &w, &h);
	(*vars)->cd[6] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/cd/6.xpm", &w, &h);
	(*vars)->cd[7] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/cd/7.xpm", &w, &h);
	(*vars)->cd[8] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/cd/8.xpm", &w, &h);
	(*vars)->cd[9] = mlx_xpm_file_to_image((*vars)->mlx,
			"./textures/cd/9.xpm", &w, &h);
	while (i < 10)
		if (!(*vars)->cd[i++])
			return (0);
	return (1);
}

int	ft_init_tex(t_solong **vars)
{
	if (!ft_init_bg(vars))
		return (0);
	if (!ft_init_player(vars))
		return (0);
	if (!ft_init_enemy(vars))
		return (0);
	ft_putstr_fd("HERE\n", 1);
	if (!ft_init_cd(vars, 22, 24, 0))
		return (0);
	ft_putstr_fd("HERE\n", 1);
	return (1);
}
