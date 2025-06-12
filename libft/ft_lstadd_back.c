/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:09:50 by amairia           #+#    #+#             */
/*   Updated: 2025/05/19 18:07:49 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstadd_back(t_pars **lst, t_pars *new)
{
	t_pars	*tmp;

	if (!lst || !new)
		return (-1);
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
	new->prev = tmp;
	return (0);
}
