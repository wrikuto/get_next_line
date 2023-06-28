/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:17:59 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/28 20:47:33 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_read(int fd, char *buf)
{
	char	*read_buf;
	int		read_byte;

	read_byte = 1;
	read_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_buf == NULL)
		return (NULL);
	while (!ft_is_new(buf) && read_byte != 0)
	{
		read_byte = read(fd, read_buf, BUFFER_SIZE);
		if (read_byte <= -1)
		{
			free(buf);
			free(read_buf);
			return (NULL);
		}
		read_buf[read_byte] = '\0';
		buf = ft_strjoin(buf, read_buf);
	}
	free(read_buf);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*sentence;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_read(fd, buf);
	if (buf == NULL)
		return (NULL);
	sentence = ft_new_sentence(buf);
	buf = ft_newbuf(buf);
	return (sentence);
}

// --------------------------------

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	line = "";
// 	fd = open("test.txt", O_RDONLY);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("> %s", line);
// 		free(line);
// 	}
// 	return (0);
// }
