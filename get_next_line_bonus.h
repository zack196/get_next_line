/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:26:48 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/12/28 01:09:41 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 2
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*return_value(char **s);
char	*get_next_line(int fd);
int		chec_new_line(char *s);
char	*ft_strdup(char *s, int len);
int		ft_strlen(char *s);
char	*ft_join(char *s1, char *s2);

#endif
