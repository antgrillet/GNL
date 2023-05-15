/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrillet <anto73grillet@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:48:59 by agrillet          #+#    #+#             */
/*   Updated: 2023/05/11 20:24:15 by agrillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buffer;
	int			i;
	char		*line;
	int			read_number;
	
	i = 0;
	if(fd < 0 || BUFFER_SIZE < 0)
		return(NULL);
	read_number = read_and_stash(fd, buffer);
	
}

char	*read_and_line(int fd, char *buffer)
{
	int		count;
	char	*line;
	char	*stash[BUFFER_SIZE + 1];
	
	line = buffer;
	while (1)
	{
		count = read(fd, stash, BUFFER_SIZE);
		if (count < 0)
			return(NULL);
		stash[count] = '\0';
		if(ft_strchr(stash, '\n'))
		{
			stash = clean_stash(stash, buffer);
		}
	}
	
}

char	*clean_stash(char *stash, char *buffer)
{
	int index;

	index = 0;
	while (stash)
	{
		/* code */
	}
	
}
