/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 19:59:57 by amairia           #+#    #+#             */
/*   Updated: 2024/10/15 16:21:08 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_strlen_split(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

/*Count the number of words separated by c in the string s
 * Return value : int = nb_mot
 */
static int	count_nbwords(const char *s, char c)
{
	int	cpt;
	int	i;

	cpt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			while (s[i] && c == s[i])
				i++;
		else
		{
			while (s[i] && c != s[i])
				i++;
			cpt++;
		}
	}
	return (cpt);
}

/*Secure the allocation maked by calloc
 * Return valule : 1 if the fonction make change and 0 if not
 */
static size_t	secur_res(char **res)
{
	if (!*res)
	{
		while (*res)
			free(*res++);
		free(res);
		return (1);
	}
	return (0);
}

/*Calloc the right memory size to welcome a certain
 * number of word in a chain of character chain
 * Return value : char ** = res calloc
 */
static char	**set_res(const char *s, char c, int cpt)
{
	char	**res;
	size_t	i;
	size_t	j;

	res = ft_calloc(sizeof(char *), cpt + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		res[j] = ft_calloc(ft_strlen_split(s + i, c) + 1, sizeof(char));
		if (secur_res(res))
			return (NULL);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	if (!s)
		return (NULL);
	res = set_res(s, c, count_nbwords(s, c));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (s[k])
	{
		j = 0;
		while (s[k] == c && s[k])
			k++;
		while (s[k] && s[k] != c)
			res[i][j++] = s[k++];
		i++;
	}
	return (res);
}
