/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:38:15 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/29 21:03:06 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

#include<stdio.h>


static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = -1;
	j = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		res[i] = s1[i];
	while (s2[j] != 0)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

int	ft_is_newline(char	*buf)
{
	int	i;

	i = 0;
	if (buf == NULL)
		return (0);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

char	*ft_rtn_line(char	*buf)
{
	char	*rtn_line;
	int		count;
	int		asg;

	count = 0;
	asg = 0;
	if (buf[count] == 0)
		return (NULL);
	while (buf[count] != '\0' && buf[count] != '\n')
		count++;
	rtn_line = malloc(sizeof(char) * (count + ft_is_newline(buf) + 1));
	while (buf[asg] != '\0' && buf[asg] != '\n')
	{
		rtn_line[asg] = buf[asg];
		asg++;
	}
	if (buf[asg] == '\n')
		rtn_line[asg++] = '\n';
	rtn_line[asg] = '\0';
	return (rtn_line);
}

char	*ft_to_nextline(char	*buf)
{
	char	*new_buf;
	int		count;
	int		asg;

	count = 0;
	while (buf[count] != 0 && buf[count] != '\n')
		count++;
	if (buf == NULL || buf[count] == 0)
	{
		free (buf);
		return (NULL);
	}
	new_buf = malloc(sizeof(char) * (ft_strlen(buf) - count + 1));
	if (new_buf == NULL)
		return (NULL);
	count++;
	asg = 0;
	while (buf[count] != '\0')
		new_buf[asg++] = buf[count++];
	new_buf[asg] = '\0';
	free(buf);
	return (new_buf);
}
