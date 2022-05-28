/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:39:15 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/28 15:49:42 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	red_cross_close(t_solong **vars)
{
	mlx_loop_end((*vars)->mlx);
	return (0);
}

static int	ft_close_img(t_solong **vars, int i)
{
	mlx_destroy_image((*vars)->mlx, (*vars)->bg);
	mlx_destroy_image((*vars)->mlx, (*vars)->exit);
	mlx_destroy_image((*vars)->mlx, (*vars)->wall);
	mlx_destroy_image((*vars)->mlx, (*vars)->chest);
	while (i < 10)
		mlx_destroy_image((*vars)->mlx, (*vars)->cd[i++]);
	i = 0;
	while (i < 8)
		mlx_destroy_image((*vars)->mlx, (*vars)->player[i++]);
	i = 0;
	while (i < 4)
		mlx_destroy_image((*vars)->mlx, (*vars)->enemy[i++]);
	return (0);
}

int	ft_close(t_solong **vars)
{
	int	i;

	ft_close_img(vars, 0);
	i = 0;
	while ((*vars)->map[i])
		free((*vars)->map[i++]);
	free((*vars)->map);
	free((*vars)->str);
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	mlx_destroy_display((*vars)->mlx);
	ft_printf(COLOR_YELLOW "\rSteps : %i\n" COLOR_YELLOW,
		(*vars)->count);
	free((*vars)->mlx);
	free(*vars);
	return (0);
}
