/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:55:28 by amairia           #+#    #+#             */
/*   Updated: 2024/10/15 16:11:11 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/* Check if th caractere c is in s
 * Return value : 1 if yes and 0 if no
 */
static size_t	check_in(char const c, char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*res;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && check_in(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && check_in(s1[end], set))
		end--;
	res = (char *)ft_calloc(end - start + 2, sizeof(char));
	if (!res)
		return (res);
	i = 0;
	while (s1[start + i] && start + i - 1 < end)
	{
		res[i] = s1[i + start];
		i++;
	}
	return (res);
}
