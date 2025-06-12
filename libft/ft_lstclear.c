/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:46:39 by amairia           #+#    #+#             */
/*   Updated: 2025/06/06 10:16:23 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_pars **lst)
{
	t_pars	*tmp_next;

	if (!lst)
		return ;
	if (*lst)
	{
		while (*lst)
		{
			tmp_next = (*lst)->next;
			if ((*lst)->content)
				free((*lst)->content);
			if ((*lst)->tab)
				free((*lst)->tab);
			free(*lst);
			*lst = tmp_next;
		}
	}
	free(lst);
}
