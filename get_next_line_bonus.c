/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:15:46 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/12/28 00:18:10 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*return_value(char **s)
{
	char	*res;
	int		i;
	char	*str;

	i = 0;
	if (!*s)
		return (NULL);
	str = *s;
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	res = ft_strdup(str, i);
	*s = ft_strdup(str + i, ft_strlen(str + i));
	return (free(str), str = NULL, res);
}

char	*get_next_line(int fd)
{
	static char	*res[OPEN_MAX];
	char		*buff;
	ssize_t		byte_read;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
	{
		if (fd >= 0 && fd <= OPEN_MAX)
			return (free(res[fd]), res[fd] = NULL, NULL);
		return (NULL);
	}
	buff = (char *)malloc(sizeof (char) * ((size_t)BUFFER_SIZE + 1));
	if (!buff)
		return (free(res[fd]), res[fd] = NULL, NULL);
	byte_read = 8;
	while (byte_read > 0)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(buff), buff = NULL, NULL);
		buff[byte_read] = '\0';
		res[fd] = ft_join(res[fd], buff);
		if (chec_new_line(res[fd]))
			break ;
	}
	return (free(buff), buff = NULL, return_value(&res[fd]));
}
