/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:38:15 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/28 21:06:51 by wrikuto          ###   ########.fr       */
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

// This func checks if the sentence stored in buf contains a character '\n'.
// if it does, it returns 1.
int	ft_is_new(char	*buf)
{
	int	i;

	i = -1;
	if (buf == NULL || buf[i] == '\0')
		return (0);
	while (buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

// This func create new sentence from buf.
char	*ft_rtn_sentence(char	*buf)
{
	char	*sentence;
	int		i;
	int		j;
	int		is_new;

	i = 0;
	j = 0;
	is_new = ft_is_new(buf);
	if (buf == NULL || buf[i] == '\0')
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	sentence = malloc(sizeof(char) * (i + is_new + 1));
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		sentence[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		sentence[i + 1] = '\n';
	sentence[i] = '\0';
	return (sentence);
}

// This func
char	*ft_nextbuf(char	*buf)
{
	char	*new_buf;
	int		i;
	int		j;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf == NULL || buf[i] == '\0')
	{
		free (buf);
		return (NULL);
	}
	new_buf = malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (new_buf == NULL)
		return (NULL);
	i++;
	j = 0;
	while (buf[i] != NULL)
		new_buf[j++] = buf[i++];
	new_buf[j] = '\0';
	free(buf);
	return (new_buf);
}
