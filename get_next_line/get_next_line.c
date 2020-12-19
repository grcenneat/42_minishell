/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nahkim <nahkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 16:56:21 by nahkim            #+#    #+#             */
/*   Updated: 2020/06/16 18:03:46 by nahkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	to_line(char **line, char *nl, char **buff, char *tmp_buff)
{
	char *tmp;

	if (tmp_buff != NULL)
		free(tmp_buff);
	if (nl != NULL)
	{
		*line = ft_strndup(*buff, (nl - *buff));
		tmp = ft_strndup(nl + 1, ft_strnlen(nl + 1));
		free(*buff);
		*buff = tmp;
		return (1);
	}
	if (*buff != NULL)
	{
		*line = *buff;
		*buff = NULL;
	}
	else
		*line = ft_strndup("", 1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buff;
	int			rd_size;
	char		*nl;
	char		*tmp;
	char		*tmp2;

	if (fd < 0 || BUFFSIZE <= 0 || !line)
		return (-1);
	if ((tmp = (char *)malloc(BUFFSIZE + 1)) == NULL)
		return (-1);
	while ((nl = ft_strnchr(buff, '\n')) == 0
			&& (rd_size = read(fd, tmp, BUFFSIZE)) > 0)
	{
		tmp[rd_size] = '\0';
		tmp2 = (buff == NULL) ? ft_strndup(tmp, rd_size) : ft_strnjoin(buff, tmp);
		if (buff != NULL)
			free(buff);
		buff = tmp2;
	}
	if (rd_size < 0)
	{
		free(tmp);
		return (-1);
	}
	return (to_line(line, nl, &buff, tmp));
}
