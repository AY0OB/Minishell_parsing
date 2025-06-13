/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 03:02:53 by amairia           #+#    #+#             */
/*   Updated: 2025/06/13 11:48:02 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*get_env(char *str, int i, int end_quote)
{
	int		j;
	char	*pre_env;
	char	*env_value;

	j = 0;
	i++;
	while (str[i] && (str[i] < 9 || str[i] > 13)
		&& str[i] != 32 && i < end_quote
		&& str[i] != '\'' && str[i] != '$')
	{
		i++;
		j++;
	}
	pre_env = ft_calloc(sizeof(char), j + 1);
	i = i - j;
	j = 0;
	while (str[i] && (str[i] < 9 || str[i] > 13)
		&& str[i] != 32 && i < end_quote
		&& str[i] != '\'' && str[i] != '$')
		pre_env[j++] = str[i++];
	env_value = getenv((const char *)pre_env);
	free(pre_env);
	return (env_value);
}

static int	pos_end_quote(t_pars *lst, int i)
{
	int	j;

	j = 0;
	while (i >= lst->tab[j])
	{
		j += 2;
	}
	return (lst->tab[j]);
}

static int	verif_in_quote(t_pars *lst, int i)
{
	size_t	len;
	size_t	j;

	len = ft_strlen((const char *)lst->content);
	j = 0;
	while (j + 1 < len - 1)
	{
		if (i >= lst->tab[j] && i < lst->tab[j + 1])
			return (-1);
		if (i >= lst->tab[j + 1])
			return (1);
		j += 2;
	}
	return (1);
}

static void	check_env(t_pars *lst, int len_base)
{
	char	*env_var;
	int		i;
	int		end_quote;
	t_env	info;

	i = 0;
	env_var = NULL;
	while (lst->content[i])
	{
		if (lst->content[i] == '$' && lst->content[i + 1] != '?'
			&& lst->content[i + 1] != 0 && lst->content[i + 1] != 32
			&& (lst->content[i + 1] < 9 || lst->content[i + 1] > 13)
			&& verif_in_quote(lst, i) != -1)
		{
			end_quote = pos_end_quote(lst, i);
			env_var = get_env(lst->content, i, end_quote);
			info.i = i;
			info.end_quote = end_quote;
			info.len_base = len_base;
			add_env(lst, env_var, &info);
			i = 0;
		}
		else
			i++;
	}
}

void	pars_env(t_pars **lst)
{
	t_pars	*lst_tmp;
	int		len_content_base;

	lst_tmp = *lst;
	len_content_base = 0;
	while (lst_tmp)
	{
		if (lst_tmp->tab[1] != 0)
		{
			len_content_base = ft_strlen(lst_tmp->content);
			check_env(lst_tmp, len_content_base);
		}
		lst_tmp = lst_tmp->next;
	}
}
