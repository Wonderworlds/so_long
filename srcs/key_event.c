/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:41:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 15:55:51 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_close_key(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
	}
	return (0);
}

int	e_key_down(int keycode, t_vars *vars)
{
	ft_printf("\nkeycode : %i", keycode);
	if (win_close_key(keycode, vars) == 1)
		return (-1);
	return (0);
}
