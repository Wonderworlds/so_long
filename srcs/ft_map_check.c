/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:55:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/28 17:18:04 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_str_valid_char(char *str, char *validchar)
{
	int	i;

	while (*str)
	{
		i = -1;
		while (validchar[++i])
		{
			if (*str == validchar[i])
				break ;
		}
		if (validchar[i] == '\0')
			return (0);
		str++;
	}
	return (1);
}

static int	ft_valid_map1(t_solong **vars, char *str, int i, int *epc)
{
	if (ft_strlen(str) != (size_t)(*vars)->x)
		ft_printf(COLOR_RED"Error\nmap not rectangular\n"COLOR_RED);
	else if (!ft_str_valid_char(str, "10ENPC"))
		ft_printf(COLOR_RED"Error\nChar not valid\n"COLOR_RED);
	else if ((i == 0 || i == (*vars)->y - 1) && !ft_str_valid_char(str, "1"))
		ft_printf(COLOR_RED"Error\nmap not closed\n"COLOR_RED);
	else if (str[0] != '1' || str[(*vars)->x - 1] != '1')
		ft_printf(COLOR_RED"Error\nmap not closed\n"COLOR_RED);
	else
	{
		while (*str)
		{
			if (*str == 'E')
				epc[0] += 1;
			if (*str == 'P')
				epc[1] += 1;
			if (*str == 'C')
				epc[2] += 1;
			str++;
		}
		return (1);
	}
	return (0);
}

int	ft_valid_map(t_solong **vars)
{
	int	i;
	int	epc[3];

	i = -1;
	while (++i < 3)
		epc[i] = 0;
	i = -1;
	while ((*vars)->map[++i])
	{
		if (!ft_valid_map1(vars, (*vars)->map[i], i, epc))
			return (0);
	}
	if (epc[0] == 0 || epc[1] == 0 || epc[2] == 0)
	{
		ft_printf(COLOR_RED"Error\nMap missing E, P or C\n"COLOR_RED);
		return (0);
	}
	else if (epc[1] > 1)
	{
		ft_printf(COLOR_RED"Error\nToo many P\n"COLOR_RED);
		return (0);
	}
	return (1);
}
