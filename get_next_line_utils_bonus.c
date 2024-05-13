/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:18:59 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/12/28 00:26:12 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	chec_new_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s, int len)
{
	char	*res;
	int		i;

	if (!s || !len)
		return (NULL);
	res = (char *)malloc(sizeof (char) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s2 || !s1)
	{
		if (s1)
			return (ft_strdup(s1, ft_strlen(s1)));
		else if (s2)
			return (ft_strdup(s2, ft_strlen(s2)));
		else
			return (NULL);
	}
	res = (char *)malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (free(s1), s1 = NULL, NULL);
	i = 0;
	j = 0;
	while (s1[i])
		res[j++] = s1[i++];
	i = 0;
	while (s2[i])
		res[j++] = s2[i++];
	res[j] = '\0';
	return (free(s1), s1 = NULL, res);
}
