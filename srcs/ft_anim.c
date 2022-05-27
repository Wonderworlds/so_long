/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_anim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:42:25 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/27 16:02:18 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_anim_change(t_solong **vars)
{
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win,
		(*vars)->enemy[(*vars)->anim_enemy],
		(*vars)->e_pos[0] * WIDTH, (*vars)->e_pos[1] * HEIGHT);
	if ((*vars)->anim_enemy >= 3)
		(*vars)->anim_enemy = 0;
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win,
		(*vars)->player[(*vars)->anim_player],
		(*vars)->p_pos[0] * WIDTH, (*vars)->p_pos[1] * HEIGHT);
	if ((*vars)->anim_player >= 7)
		(*vars)->anim_player = -1;
	(*vars)->anim_player++;
	(*vars)->anim_enemy++;
}

int ft_anim(t_solong **vars)
{
	(*vars)->anim_count++;
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
    return (0);
}