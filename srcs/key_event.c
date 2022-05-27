/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:41:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/27 18:50:17 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_move(t_solong **vars, int x, int y)
{
	if ((*vars)->map[y][x] == '1')
		return (0);
	if ((*vars)->map[y][x] == 'C')
		(*vars)->c_count--;
	if ((*vars)->map[y][x] == 'E')
	{
		if ((*vars)->c_count == 0)
		{
			ft_printf(COLOR_GREEN "Congrats!\n" COLOR_GREEN);
			mlx_loop_end((*vars)->mlx);
		}
		return (0);
	}
	if ((*vars)->map[y][x] == 'N')
	{
		ft_printf(COLOR_RED "DEATH!\n" COLOR_RED);
		mlx_loop_end((*vars)->mlx);
		return (0);
	}
	return (1);
}

int	ft_move_p(t_solong **vars, int x, int y)
{
	if (!ft_check_move(vars, x, y))
		return (0);
	ft_push_cd(vars, ++(*vars)->count);
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->bg,
			(*vars)->p_pos[0] * WIDTH, (*vars)->p_pos[1] * HEIGHT);
	(*vars)->map[(*vars)->p_pos[1]][(*vars)->p_pos[0]] = '0';
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win,
				(*vars)->player[(*vars)->anim_player], x * WIDTH, y * HEIGHT);
	(*vars)->p_pos[0] = x;
	(*vars)->p_pos[1] = y;
	(*vars)->map[y][x] = 'P';
	return (1);
}

int	e_key_down(int keycode, t_solong **vars)
{
	if (keycode == EVENT_ESC)
		mlx_loop_end((*vars)->mlx);
	if (keycode == EVENT_W)
		ft_move_p(vars, (*vars)->p_pos[0], (*vars)->p_pos[1] - 1);
	if (keycode == EVENT_A)
		ft_move_p(vars, (*vars)->p_pos[0] - 1, (*vars)->p_pos[1]);
	if (keycode == EVENT_S)
		ft_move_p(vars, (*vars)->p_pos[0], (*vars)->p_pos[1] + 1);
	if (keycode == EVENT_D)
		ft_move_p(vars, (*vars)->p_pos[0] + 1, (*vars)->p_pos[1]);
	return (0);
}
