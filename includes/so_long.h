/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:50:56 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/28 18:21:25 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# include "../libft/Include/libft.h"

# define COLOR_RED     "\x1b[31m"
# define COLOR_GREEN   "\x1b[32m"
# define COLOR_YELLOW  "\x1b[33m"

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
# define ANIM_RATE 12000
# define MOVE_ENEMY 120000

typedef struct s_solong {
	void	*mlx;
	void	*win;
	char	**map;
	char	*str;
	int		x;
	int		y;
	int		width;
	int		height;
	int		count;
	int		c_count;
	int		anim_count;
	int		enemy_count;
	int		anim_player;
	int		anim_enemy;
	int		p_pos[2];
	void	*bg;
	void	*chest;
	void	*exit;
	void	*wall;
	void	*player[8];
	void	*enemy[4];
	void	*cd[10];
}				t_solong;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

char	*read_fd(int fd);
int		ft_push_cd(t_solong **vars, int count);
int		ft_close(t_solong **vars, char type);
int		ft_init(t_solong **vars, char *path);
int		ft_init_tex(t_solong **vars);
int		ft_init_img(t_solong **vars);
int		ft_anim(t_solong **vars);
int		e_key_down(int keycode, t_solong **vars);
int		ft_move_p(t_solong **vars, int x, int y);
int		ft_move_npc(t_solong **vars);
int		red_cross_close(t_solong **vars);
int		ft_valid_map(t_solong **vars);

#endif