/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:39:15 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/28 17:26:21 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_struct(void *mlx, void *ptr, char type)
{
	if (type == 'I' && ptr && mlx)
		mlx_destroy_image(mlx, ptr);
	else if (type == 'W' && ptr && mlx)
		mlx_destroy_window(mlx, ptr);
	else if (type == 'M' && mlx)
		mlx_destroy_display(mlx);
	else if (type == 'P' && ptr)
		free(ptr);
}

int	red_cross_close(t_solong **vars)
{
	mlx_loop_end((*vars)->mlx);
	return (0);
}

static int	ft_close_img(t_solong **vars, int i)
{
	free_struct((*vars)->mlx, (*vars)->bg, 'I');
	free_struct((*vars)->mlx, (*vars)->exit, 'I');
	free_struct((*vars)->mlx, (*vars)->wall, 'I');
	free_struct((*vars)->mlx, (*vars)->chest, 'I');
	while (++i < 10)
		free_struct((*vars)->mlx, (*vars)->cd[i], 'I');
	i = -1;
	while (++i < 8)
		free_struct((*vars)->mlx, (*vars)->player[i], 'I');
	i = -1;
	while (++i < 4)
		free_struct((*vars)->mlx, (*vars)->enemy[i], 'I');
	return (0);
}

int	ft_close(t_solong **vars, char type)
{
	int	i;

	ft_close_img(vars, -1);
	i = 0;
	if ((*vars)->map)
		while ((*vars)->map[i])
			free_struct(NULL, (*vars)->map[i++], 'P');
	free_struct(NULL, (*vars)->map, 'P');
	free_struct(NULL, (*vars)->str, 'P');
	free_struct((*vars)->mlx, (*vars)->win, 'W');
	free_struct((*vars)->mlx, NULL, 'M');
	if (type != 'E')
		ft_printf(COLOR_YELLOW "\rSteps : %i\n" COLOR_YELLOW, (*vars)->count);
	free_struct(NULL, (*vars)->mlx, 'P');
	free_struct(NULL, (*vars), 'P');
	return (0);
}
