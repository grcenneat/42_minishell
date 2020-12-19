/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjung <hjung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 02:12:16 by hjung             #+#    #+#             */
/*   Updated: 2020/04/19 11:25:34 by hjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		w_cnt(const char *str, char c)
{
	int i;
	int word_cnt;

	i = 0;
	word_cnt = 0;
	while (str[i] != '\0')
	{
		if (((i == 0) && (str[i] != c)) || ((str[i] != c) && (str[i - 1] == c)))
			word_cnt++;
		i++;
	}
	return (word_cnt + 1);
}

int		ft_word_len(const char *word, char c)
{
	int i;

	i = 0;
	while ((word[i] != c) && (word[i] != '\0'))
		i++;
	return (i);
}

int		ft_add(const char *str, char c, char *res)
{
	int i;

	i = 0;
	while ((str[i] != c) && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (i);
}

void	ft_increment(char letter, int *i)
{
	if (letter != '\0')
		*i += 1;
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		line;

	i = 0;
	line = 0;
	if (s == 0 || (res = (char **)malloc(sizeof(char *) * w_cnt(s, c))) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (((i == 0) && (s[i] != c)) || ((s[i] != c) && (s[i - 1] == c)))
		{
			if ((res[line] = (char *)malloc(ft_word_len(&s[i], c) + 1)) == NULL)
			{
				while (--line >= 0)
					free(res[line]);
				return (NULL);
			}
			i += ft_add(&s[i], c, res[line]);
			line++;
		}
		ft_increment(s[i], &i);
	}
	res[line] = 0;
	return (res);
}
