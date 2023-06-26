/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:17:59 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/26 22:49:38 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_read(int fd, char *buf)
{
	char	*buf_size;
	int		read_byte;

	read_byte = 1;
	but_size = malloc(sizeof(char) * (BUFFER_SIZE + 1));
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_read(fd, buf);
	if (buf == NULL)
		return (NULL);
	line = 
}

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open("test.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("> %s", line);
		free(line);
	}
	return (0);
}
