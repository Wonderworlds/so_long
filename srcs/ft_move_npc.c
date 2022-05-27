/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_npc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:16:50 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/27 19:27:49 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static int  ft_check_npc(t_solong **vars, int x, int y)
{
	if ((*vars)->map[x][y] == '1')
		return (0);
	if ((*vars)->map[x][y] == 'C')
		return (0);
	if ((*vars)->map[x][y] == 'E')
		return (0);
	if ((*vars)->map[x][y] == 'N')
		return (0);
	if ((*vars)->map[x][y] == 'P')
	{
		ft_printf(COLOR_RED "DEATH!\n" COLOR_RED);
		mlx_loop_end((*vars)->mlx);
		return (0);
	}
	return (1);
}

static int ft_dir_npc(t_solong **vars, int x, int y)
{
	int	i;

	i = 0;
    if (ft_check_npc(vars, x, y + 1))
		(*vars)->map[x][y + 1] = 'N';
	else
	{
		while ((*vars)->map[x][++i])
		{
			if ((*vars)->map[x][i] == '0')
			{
				(*vars)->map[x][i] = 'N';
				break ;
			}
		}
	}
	(*vars)->map[x][y] = '0';
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win,
			(*vars)->bg, y * WIDTH, x * HEIGHT);
	return (0);
}

int ft_move_npc(t_solong **vars)
{
    int	i;
	int	j;
	int	c;
	t_coord	enemy[1000];

	c = 0;
	i = -1;
	while ((*vars)->map[++i])
	{
		j = -1;
		while ((*vars)->map[i][++j] != '\0')
		{
			if ((*vars)->map[i][j] == 'N')
			{
				enemy[c].x = i;
				enemy[c++].y = j;
			}
		}
	}
	while (--c >= 0)
		ft_dir_npc(vars, enemy[c].x, enemy[c].y);
    return (0);
}
