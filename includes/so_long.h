/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:50:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/27 00:23:11 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# include "../libft/Include/libft.h"

# define EVENT_W 119
# define EVENT_A 97
# define EVENT_S 115
# define EVENT_D 100
# define EVENT_ESC 65307

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define HEIGHT 50
# define WIDTH 50

typedef struct s_solong {
	void	*mlx;
	void	*win;
	char	**map;
	int		x;
	int		y;
	int		width;
	int		height;
	void	*bg;
	void	*chest;
	void	*exit;
	void	*wall;
	void	*player[8];
	void	*enemy[4];
}				t_solong;

char    *read_fd(int fd);

//COLOR
int		rainbow(t_solong *vars);
//TEXTURES
int	ft_init_tex(t_solong **vars);
int	ft_init_img(t_solong **vars);

//EVENTS
//KEY
int		e_key_down(int keycode, t_solong **vars);
//MOUSE
//WINDOW
int		ft_close(t_solong **vars);
int		red_cross_close(t_solong **vars);


#endif