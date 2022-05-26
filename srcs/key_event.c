/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:41:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 17:48:56 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_close_key(int keycode, t_vars *vars)
{
	if (keycode == EVENT_ESC)
	{
		mlx_loop_end(vars->mlx);
		return (-1);
	}
	return (0);
}

int	e_key_down(int keycode, t_vars **vars)
{
	ft_printf("\nkeycode : %i", keycode);
	if (keycode == EVENT_ESC)
	{
		mlx_loop_end((*vars)->mlx);
	}
	return (0);
}
