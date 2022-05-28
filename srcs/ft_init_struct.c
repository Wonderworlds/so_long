/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:19:57 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/28 17:41:20 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_get_map(char *path)
{
	int		fd;
	int		len;
	char	*tmp;

	len = ft_strlen(path);
	if (path[len - 1] != 'r' || path[len - 2] != 'e' || path[len - 3] != 'b'
		|| path[len - 4] != '.')
	{
		ft_printf(COLOR_RED"Error\nInvalid extension\n"COLOR_RED);
		return (NULL);
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(COLOR_RED"Error\nInvalid file\n"COLOR_RED);
		return (NULL);
	}
	tmp = read_fd(fd);
	close(fd);
	return (tmp);
}

static int	ft_init1(t_solong **vars)
{
	int	i;

	(*vars)->x = ft_strlen((*vars)->map[0]);
	i = 0;
	while ((*vars)->map[i])
		i++;
	(*vars)->y = i;
	if (!ft_valid_map(vars))
		return (0);
	(*vars)->count = 0;
	(*vars)->c_count = 0;
	(*vars)->anim_count = 0;
	(*vars)->enemy_count = 0;
	(*vars)->anim_enemy = 0;
	(*vars)->anim_player = 0;
	(*vars)->mlx = mlx_init();
	if (!(*vars)->mlx)
		return (0);
	(*vars)->win = mlx_new_window((*vars)->mlx, WIDTH * (*vars)->x,
			HEIGHT * (*vars)->y, "so_long");
	if (!(*vars)->win)
		return (0);
	return (1);
}

int	ft_init(t_solong **vars, char *path)
{
	(*vars)->str = ft_get_map(path);
	if (!(*vars)->str)
		return (0);
	(*vars)->map = ft_split((*vars)->str, '\n');
	if (!(*vars)->map)
		return (0);
	if (!ft_init1(vars))
		return (0);
	if (!ft_init_tex(vars))
		return (0);
	if (!ft_init_img(vars))
		return (0);
	return (1);
}
