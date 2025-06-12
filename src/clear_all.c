/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:48:47 by amairia           #+#    #+#             */
/*   Updated: 2025/06/12 19:53:28 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	clear_all(t_all *all, char *line)
{
	if (line)
		free(line);
	ft_lstclear(all->lst);
	clear_history();
	free(all);
}
