/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:42:25 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/28 16:39:25 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_anim_e(t_solong **vars)
{
	int	i;
	int	j;

	i = -1;
	while ((*vars)->map[++i])
	{
		j = -1;
		while ((*vars)->map[i][++j] != '\0')
		{
			if ((*vars)->map[i][j] == 'N')
			{
				mlx_put_image_to_window((*vars)->mlx, (*vars)->win,
					(*vars)->enemy[(*vars)->anim_enemy],
					j * WIDTH, i * HEIGHT);
				if ((*vars)->anim_enemy >= 3)
					(*vars)->anim_enemy = -1;
				(*vars)->anim_enemy++;
			}
		}
	}
}

static void	ft_anim_change(t_solong **vars)
{
	ft_anim_e(vars);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win,
		(*vars)->player[(*vars)->anim_player],
		(*vars)->p_pos[0] * WIDTH, (*vars)->p_pos[1] * HEIGHT);
	if ((*vars)->anim_player >= 7)
		(*vars)->anim_player = -1;
	(*vars)->anim_player++;
}

int	ft_anim(t_solong **vars)
{
	(*vars)->anim_count++;
	(*vars)->enemy_count++;
	if ((*vars)->anim_count == -1)
	{
		(*vars)->anim_count = 0;
		(*vars)->anim_player = 0;
		(*vars)->anim_enemy = 0;
	}
	else if ((*vars)->anim_count == ANIM_RATE)
	{
		(*vars)->anim_count = 1;
		ft_anim_change(vars);
	}
	if ((*vars)->enemy_count == MOVE_ENEMY)
	{
		(*vars)->enemy_count = 0;
		ft_move_npc(vars);
	}
	return (0);
}
