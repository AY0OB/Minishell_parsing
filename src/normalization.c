/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:57:41 by amairia           #+#    #+#             */
/*   Updated: 2025/06/03 19:14:14 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	norm_cmd(t_pars **lst, int *i)
{
	t_pars	*lst_tmp;

	if (!lst || !(*lst))
		return ;
	lst_tmp = *lst;
	while (lst_tmp && lst_tmp->type != PIPE)
	{
		if (lst_tmp->norm == 0)
		{
			lst_tmp->norm = *i;
			++*i;
		}
		lst_tmp = lst_tmp->next;
	}
	if (lst_tmp && lst_tmp->norm == 0)
	{
		lst_tmp->norm = *i;
		++*i;
	}
	else if (lst_tmp)
	{
		lst_tmp = lst_tmp->next;
		norm_cmd(&lst_tmp, i);
	}
}

static void	norm_redir(t_pars **lst, int *i)
{
	t_pars	*lst_tmp;

	if (!lst || !(*lst))
		return ;
	lst_tmp = *lst;
	while (lst_tmp && lst_tmp->type != PIPE)
	{
		if ((lst_tmp->type == FILE_ || lst_tmp->type == DOC_STOP)
			&& lst_tmp->norm == 0)
		{
			lst_tmp->norm = *i;
			lst_tmp->prev->norm = *i + 1;
			*i = *i + 2;
		}
		lst_tmp = lst_tmp->next;
	}
	if (lst_tmp && lst_tmp->norm != 0)
	{
		lst_tmp = lst_tmp->next;
		norm_redir(&lst_tmp, i);
	}
}

static int	check_end(t_pars **lst)
{
	t_pars	*lst_tmp;

	if (!lst || !(*lst))
		return (0);
	lst_tmp = *lst;
	while (lst_tmp)
	{
		if (lst_tmp->norm == 0)
			return (-1);
		lst_tmp = lst_tmp->next;
	}
	return (0);
}

void	normalization(t_pars **lst)
{
	int		i;

	i = 1;
	while (check_end(lst) == -1)
	{
		norm_redir(lst, &i);
		norm_cmd(lst, &i);
	}
}
