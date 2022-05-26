/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:41:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 22:13:32 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	e_key_down(int keycode, t_solong **vars)
{
	ft_printf("\nkeycode : %i", keycode);
	if (keycode == EVENT_ESC)
	{
		mlx_loop_end((*vars)->mlx);
	}
	if (keycode == EVENT_W)
	{
		mlx_loop_end((*vars)->mlx);
	}
	if (keycode == EVENT_A)
	{
		mlx_loop_end((*vars)->mlx);
	}
	if (keycode == EVENT_S)
	{
		mlx_loop_end((*vars)->mlx);
	}
	if (keycode == EVENT_D)
	{
		mlx_loop_end((*vars)->mlx);
	}
	return (0);
}
