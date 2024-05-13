/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:07:37 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/12/28 00:10:06 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_value(char **s)
{
	char	*res;
	int		i;
	char	*str;

	i = 0;
	if (!*s || !s)
		return (NULL);
	str = *s;
	while (*(str + i) != '\n' && *(str + i))
		i++;
	if (*(str + i) == '\n')
		i++;
	res = ft_strdup(str, i);
	*s = ft_strdup(str + i, ft_strlen(str + i));
	return (free(str), str = NULL, res);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*buff;
	ssize_t		byte_read ;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (free(res), res = NULL, NULL);
	buff = (char *)malloc(sizeof (char) * ((size_t)BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	byte_read = 9;
	while (byte_read > 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buff), buff = NULL, NULL);
		buff[byte_read] = '\0';
		res = ft_join(res, buff);
		if (chec_new_line(res))
			break ;
	}
	return (free(buff), buff = NULL, return_value(&res));
}
