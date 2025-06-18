/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:47:30 by amairia           #+#    #+#             */
/*   Updated: 2025/06/18 14:27:36 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	feed_not_token(t_pars *lst)
{
	if (lst->prev == NULL)
		lst->type = COMMAND;
	else
	{
		if (lst->prev->type == PIPE || lst->prev->type == COMMAND
			|| lst->prev->type == FILE_)
			lst->type = COMMAND;
		if (lst->prev->type == REDIR_IN || lst->prev->type == REDIR_OUT
			|| lst->prev->type == APNDMOD)
			lst->type = FILE_;
		if (lst->prev->type == HERE_DOC)
			lst->type = DOC_STOP;
	}
}

void	feed_lst_type(t_pars *lst, int is_token)
{
	if (is_token == 1)
		lst->type = REDIR_IN;
	if (is_token == 2)
		lst->type = REDIR_OUT;
	if (is_token == 3)
		lst->type = APNDMOD;
	if (is_token == 4)
		lst->type = HERE_DOC;
	if (is_token == 5)
		lst->type = PIPE;
	if (is_token == -1)
	{
		feed_not_token(lst);
	}
}
