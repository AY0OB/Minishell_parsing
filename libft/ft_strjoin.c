/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:30:40 by amairia           #+#    #+#             */
/*   Updated: 2024/10/14 21:21:11 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*feed_res(char *res, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] || s2[j])
	{
		if (s1[i])
			i++;
		if (s2[j])
			j++;
	}
	res = ft_calloc(i + j + 1, sizeof(char));
	if (!res)
		return (NULL);
	return (feed_res(res, s1, s2));
}
