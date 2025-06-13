/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:52:12 by amairia           #+#    #+#             */
/*   Updated: 2025/06/13 12:14:08 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>

typedef struct s_content
{
	char	quote;
	int		i;
	int		j;
	int		k;
	int		inclu_quote;
}			t_content;

typedef struct s_tab
{
	char	quote;
	int		i;
	int		j;
	int		in_quote;
	int		tab_i;
	int		loc_quote;
}			t_tab;

typedef struct s_env
{
	int	i;
	int	end_quote;
	int	len_base;
}		t_env;

typedef struct s_envbis
{
	int	j;
	int	k;
	int	l;
}		t_envbis;

int			first_pars(char *line);
int			check_quote(char *line);

int			parsing(char *line, t_pars **lst);
int			verif_token(char *line, int i);

int			feed_lst_content(t_pars **lst, char *line, int *i);
void		set_index(char *line, int *i, int *size, char quote);
void		set_index_bis(char *line, int *i, int *size);
void		feed_lst_type(t_pars *lst, int is_token);

int			set_int_quote(t_pars *lst, char *line, int i, int j);
int			*tmp_index(int i);

void		pars_env(t_pars **lst);
void		add_env(t_pars *lst, char *env_var, t_env *info);

t_envbis	set_envbis(void);
int			end_env(char *str, t_envbis info, int end_quote);

void		normalization(t_pars **lst);

void		skip_space(char *str, int *i);

void		clear_all(t_all *all, char *line);

#endif
