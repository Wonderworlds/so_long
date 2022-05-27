/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:13:53 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/27 11:47:18 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int	ft_push_cd(t_solong **vars, int count)
{
	char	*num;
	int		i;

	i = 0;
	num = ft_itoa((*vars)->count);
	if (!num)
		return (0);
	while(num[i])
	{
		i++;
	}
	free(num);
}

int	ft_push_img(t_solong **vars, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->wall, (x * WIDTH), (y * HEIGHT));
	if (c == '0')
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->bg, x * WIDTH, y * HEIGHT);
	if (c == 'E')
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->exit, x * WIDTH, y * HEIGHT);
	if (c == 'C')
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->chest,x * WIDTH, y * HEIGHT);
	if (c == 'N')
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->enemy[0], x * WIDTH, y * HEIGHT);
	if (c == 'P')
		mlx_put_image_to_window((*vars)->mlx, (*vars)->win, (*vars)->player[0], x * WIDTH, y * HEIGHT);
	return (0);
}

int	ft_init_img(t_solong **vars)
{
	int	i;
	int	j;

	i = 0;
	while ((*vars)->map[i])
	{
		j = 0;
		while ((*vars)->map[i][j] != '\0')
		{
			ft_push_img(vars, (*vars)->map[i][j], j, i);
			j++;
		}
		i++;
	}
	return (0);
}