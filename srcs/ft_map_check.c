/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:55:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/27 22:42:24 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_realloc(char *s1, char *s2, size_t len_s1, size_t len_s2)
{
	char	*result;
	size_t	i;

	result = malloc((len_s1 + len_s2 + 1) * sizeof(*result));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		result[i] = s1[i];
		i++;
	}
	free(s1);
	while (len_s2--)
		result[i++] = *(s2++);
	result[i] = '\0';
	return (result);
}

char	*read_fd(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*str;
	int		r;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	r = read(fd, buffer, BUFFER_SIZE);
	if (r <= 0)
		return (NULL);
	while (r > 0)
	{
		str = ft_realloc(str, buffer, ft_strlen(str), (size_t)r);
		if (!str)
			return (NULL);
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 0)
			return (NULL);
	}
	return (str);
}
