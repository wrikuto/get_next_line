/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:38:15 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/27 20:47:15 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_is_newline(char	*buf)
{
	int	i;

	i = -1;
	if (buf == NULL || buf[i] == NULL)
		return (NULL);
	while (buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

char	*ft_new_sentence(char	*buf)
{
	char	*sentence;
	int		i;
	int		j;
	int		is_new;

	i = 0;
	j = 0;
	is_new = ft_is_newline(buf);
	if (buf == NULL || buf[i] == NULL)
		return (NULL);
	while (buf[i] != NULL && buf[i] != '\n')
		i++;
	sentence = malloc(sizeof(char) * (i + is_new + 1));
	while (buf[i] != NULL && buf[i] != '\n')
	{
		sentence[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		sentence[i + 1] = '\n';
	sentence[i] = '\0';
	return (sentence);
}

char	*new_buf(char	*buf)
{
	char	*new_buf;
	int		i;
	int		j;
	int		bufsize;

	i = 0;
	j = 0;
	while (buf[i] != NULL && buf[i] != '\n')
		i++;
	if (buf == NULL || buf[i] == NULL)
	{
		free (buf);
		return (NULL);
	}
	bufsize = strlen(buf);
	new_buf = malloc(sizeof(char) * (bufsize - i + 1));
}