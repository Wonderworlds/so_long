/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:04:18 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/27 00:18:01 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	display_tex(t_solong **vars, char *path)
{


	ft_printf("\npath = %s", path);
	(*vars)->bg = mlx_xpm_file_to_image((*vars)->mlx, path,
			&(*vars)->width, &(*vars)->height);
	if (!(*vars)->bg)
	{
		ft_printf("\n img load fail");
		return (0);
	}
	mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->bg, 300, 300);
	return (1);
}
