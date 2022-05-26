/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:36:20 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 15:57:22 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_close_mouse(int button, int x, int y, t_vars *vars)
{
	ft_printf("\nkeycode : %i\n\tx : %i\n\ty : %i", button, x, y);
	return (0);
}
