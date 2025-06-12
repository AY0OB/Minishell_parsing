/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 05:47:01 by amairia           #+#    #+#             */
/*   Updated: 2025/06/12 19:57:05 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	size_new_content(char *str, char *env_var, int i, int end_quote)
{
	int	j;
	int	len;
	int	check;

	j = 0;
	len = 0;
	check = 1;
	while (str[j])
	{
		if (j == i && check)
		{
			j++;
			while (str[j] && (str[j] < 9 || str[j] > 13) && str[j] != 32
				&& j < end_quote && str[j] != '\'' && str[j] != '$')
				j++;
		}
		else
		{
			j++;
			len++;
		}
	}
	if (env_var)
		len += ft_strlen((const char *)env_var);
	return (len);
}

static char	*feed_new_content(char *str,
		char *env_var, int i, int end_quote)
{
	char		*n_content;
	int			end_env_int;
	int			check;
	t_envbis	info;

	n_content = ft_calloc(sizeof(char),
			size_new_content(str, env_var, i, end_quote) + 2);
	check = 1;
	info = set_envbis();
	while (str[info.j] && n_content)
	{
		if (info.j == i && check)
		{
			end_env_int = end_env(str, info, end_quote);
			while (str[info.j] && info.j < end_env_int)
				info.j++;
			check = 0;
			if (env_var)
				while (env_var[info.l])
					n_content[info.k++] = env_var[info.l++];
		}
		else
			n_content[info.k++] = str[info.j++];
	}
	return (n_content);
}
/*
static void	incr_tab_bis(t_pars *lst, int pos, int len, int len_bis)
{

}
*/
static void	incr_tab(t_pars *lst, char *n_content, int pos, int len_base)
{
	int	len_c;
	int	len_nc;
	int	i;

	len_c = ft_strlen(lst->content);
	len_nc = ft_strlen(n_content);
	i = 1;
	if (len_c != 0 && len_c <= len_nc)
	{
		if (lst->tab[0] >= pos)
			lst->tab[0] += (len_nc - len_c);
		while (i < len_base)
		{
			if (lst->tab[i] >= pos)
				lst->tab[i] += (len_nc - len_c);
			i++;
		}
	}
	else if (len_nc != 0 && len_nc <= len_c)
	{
		if (lst->tab[0] >= pos)
			lst->tab[0] -= (len_c - len_nc);
		while (i < len_base)
		{
			if (lst->tab[i] >= pos)
				lst->tab[i] -= (len_c - len_nc);
			i++;
		}
	}
}

void	add_env(t_pars *lst, char *env_var, t_env *info)
{
	char	*n_content;

	n_content = NULL;
	n_content = feed_new_content(lst->content, env_var, info->i,
			info->end_quote);
	incr_tab(lst, n_content, info->i, info->len_base);
	free(lst->content);
	lst->content = n_content;
}
