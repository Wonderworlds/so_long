/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:04:18 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 18:10:41 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_tex(t_vars **vars, char *path, int tex_width, int tex_height)
{


	ft_printf("\npath = %s", path);
	(*vars)->sprite = mlx_xpm_file_to_image((*vars)->mlx, path, &tex_width, &tex_height);
	if (!(*vars)->sprite)
	{
		ft_printf("\n img load fail");
		return (0);
	}
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->sprite, 300, 300);
	return (1);
}
