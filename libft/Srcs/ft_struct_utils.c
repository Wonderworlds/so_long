/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmauguin <fmauguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:51:00 by fmauguin          #+#    #+#             */
/*   Updated: 2022/05/25 16:37:06 by fmauguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	init_flags(t_strlist *lst)
{
	if (!lst)
		return ;
	lst->str = 0;
	lst->form = 0;
	lst->type = 0;
	lst->hash = 0;
	lst->zero = 0;
	lst->min = 0;
	lst->blank = 0;
	lst->plus = 0;
	lst->dot = 0;
	lst->width = 0;
}

int	check_f(t_strlist *lst)
{
	lst->type = lst->str[ft_strlen(lst->str) - 1];
	lst->form = 1;
	return (1);
}
