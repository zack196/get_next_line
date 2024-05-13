/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:10:55 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/12/28 01:10:11 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

ma
# include <unistd.h>
# include <stdlib.h>

char	*return_value(char **s);
char	*get_next_line(int fd);
int		chec_new_line(char *s);
char	*ft_strdup(char *s, int len);
int		ft_strlen(char *s);
char	*ft_join(char *s1, char *s2);

#endif
