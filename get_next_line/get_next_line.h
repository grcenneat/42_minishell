/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahkim <nahkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 16:57:38 by nahkim            #+#    #+#             */
/*   Updated: 2020/06/16 19:29:48 by nahkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFSIZE 128

# include <unistd.h>
# include <stdlib.h>

int		ft_strnlen(char *str);

char	*ft_strnjoin(char *s1, char *s2);
char	*ft_strndup(char *str, int size);
char	*ft_strnchr(char *s, char target);
void	ft_strcpy(char *dest, char *src, int size);

int		to_line(char **line, char *nl, char **fd_set, char *tmp_buff);
int		get_next_line(int fd, char **line);

#endif
