/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:50:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 15:45:35 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include "../libft/Include/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*state;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
}				t_vars;

//COLOR
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		rainbow(t_vars *vars);

//EVENTS
//KEY
int		e_key_down(int keycode, t_vars *vars);
//MOUSE
int		win_close_mouse(int button, int x, int y, t_vars *vars);

#endif