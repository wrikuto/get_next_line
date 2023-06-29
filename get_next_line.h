/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrikuto <wrikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:28:55 by wrikuto           #+#    #+#             */
/*   Updated: 2023/06/29 11:00:55 by wrikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include<unistd.h>
# include<stdlib.h>
# include<stddef.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_is_newline(char	*buf);
char	*ft_rtn_line(char	*buf);
char	*ft_to_nextline(char	*buf);



#endif