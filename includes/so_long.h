/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:50:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/26 18:06:07 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include "../libft/Include/libft.h"

# define EVENT_W 119
# define EVENT_A 97
# define EVENT_S 115
# define EVENT_D 100
# define EVENT_ESC 65307

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
	void	*sprite;
}				t_vars;

//COLOR
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		rainbow(t_vars *vars);
//TEXTURES
int		display_tex(t_vars **vars, char *path, int tex_width, int tex_height);
//EVENTS
//KEY
int		e_key_down(int keycode, t_vars **vars);
//MOUSE
//WINDOW
int		ft_close(t_vars **vars, int x);
int		red_cross_close(t_vars **vars);


#endif