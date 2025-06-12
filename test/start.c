/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:20:53 by amairia           #+#    #+#             */
/*   Updated: 2025/04/22 16:45:41 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <unistd.h>

void	do_cmd(char *line)
{
	int	i;

	i = 0;
	ft_printf("ur cmd is : ");
	while (line[i])
	{
		write(1, &line[i], 1);
		i++;
	}
}

int	test_end(const char *line)
{
	char	line_set[4];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && j < 4)
	{
		if (line[i] != ' ')
		{
			line_set[j] = line[i];
			j++;
		}
		i++;
	}
	if (j == 4)
	{
		if (line_set[0] == 'e' && line_set[1] == 'x' \
			&& line_set[2] == 'i' && line_set[3] == 't')
		{
			return (0);
		}
	}
	return (1);
}

int	main(void)
{
	char	*line;
	char	buffer[PATH_MAX];

	if (getcwd(buffer, PATH_MAX) == NULL)
		exit(0);
	line = NULL;
	ft_printf("%s ", buffer);
	line = get_next_line(0);
	while (test_end((const char *)line) && (getcwd(buffer, PATH_MAX) != NULL))
	{
		//do_cmd(line);
		system(line);
		free(line);
		ft_printf("%s ", buffer);
		line = get_next_line(0);
	}
	free(line);
}
