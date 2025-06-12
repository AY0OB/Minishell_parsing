/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:57:38 by amairia           #+#    #+#             */
/*   Updated: 2025/06/12 17:02:20 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_pars	*ft_lstnew(char *content)
{
	t_pars	*mylist;

	mylist = malloc(sizeof(t_pars));
	if (!mylist)
	{
		ft_printf("Alloc error\n");
		return (NULL);
	}
	mylist->content = content;
	mylist->type = NONE;
	mylist->tab = NULL;
	mylist->norm = 0;
	mylist->prev = NULL;
	mylist->next = NULL;
	return (mylist);
}
