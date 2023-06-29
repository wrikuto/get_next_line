/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:17:59 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/29 11:00:49 by wrikuto          ###   ########.fr       */
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
	char		*rtn_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_read(fd, buf);
	if (buf == NULL)
		return (NULL);
	rtn_line = ft_rtn_line(buf);
	buf = ft_to_nextline(buf);
	return (rtn_line);
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
