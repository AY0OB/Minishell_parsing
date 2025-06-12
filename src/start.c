/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:27:25 by amairia           #+#    #+#             */
/*   Updated: 2025/06/12 19:54:18 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	compare_line_set(const char *line, char *line_set, int i, int j)
{
	if (j == 4)
	{
		if ((line_set[0] == 'e' && line_set[1] == 'x'
				&& line_set[2] == 'i' && line_set[3] == 't')
			&& (((line[i] >= 9 && line[i] <= 13) || line[i] == 32)
				|| line[i] == '\n' || !line[i]))
			return (0);
	}
	return (1);
}

static int	test_end(const char *line)
{
	char	*line_set;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!line)
		return (0);
	line_set = ft_calloc(sizeof(char), 4);
	while (line[i] && j < 4)
	{
		if ((line[i] < 9 || line[i] > 13) && line[i] != 32)
		{
			line_set[j] = line[i];
			j++;
		}
		i++;
	}
	j = compare_line_set(line, line_set, i, j);
	free(line_set);
	return (j);
}

static int	set_list(t_pars ***lst)
{
	*lst = NULL;
	*lst = malloc(sizeof(t_pars *));
	if (!(*lst))
	{
		ft_printf("Alloc error\n");
		return (-1);
	}
	**lst = NULL;
	return (0);
}

static t_all	*set_struct(void)
{
	t_all	*all;
	t_pars	**lst;
	t_data	data;

	all = malloc(sizeof(t_all));
	if (!all)
	{
		ft_printf("Alloc error\n");
		return (NULL);
	}
	if (set_list(&lst) == -1)
		return (NULL);
	all->lst = lst;
	data.std_err = 0;
	data.file = 1;
	all->data = data;
	return (all);
}

int	main(void)
{
	char	*line;
	t_all	*all;
	//char	buffer[PATH_MAX];

	all = set_struct();
	if (!all)
		return (-1);
	while (1) //(getcwd(buffer, PATH_MAX) != NULL)
	{
		line = readline("minishell ");
		if (line)
			add_history((const char *)line);
		if (test_end((const char *)line) != 1)
			break ;
		if (first_pars(line) == 1 && check_quote(line) == 1)
		{
			parsing(line, all->lst);
			/*fonction exec*/
		}
		if (line)
			free(line);
		ft_lstclear(all->lst);
		if (set_list(&(all->lst)) == -1)
			return (-1);
		//ft_lstlast(*lst);
	}
	clear_all(all, line);
}
