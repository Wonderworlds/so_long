/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 13:41:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/27 11:44:25 by fmauguin         ###   ########.fr       */
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
		ft_push_cd(vars, ++(*vars)->count);
	}
	if (keycode == EVENT_A)
	{
		ft_push_cd(vars, ++(*vars)->count);
	}
	if (keycode == EVENT_S)
	{
		ft_push_cd(vars, ++(*vars)->count);
	}
	if (keycode == EVENT_D)
	{
		ft_push_cd(vars, ++(*vars)->count);
	}
	return (0);
}
