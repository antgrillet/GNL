/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrillet <anto73grillet@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:48:59 by agrillet          #+#    #+#             */
/*   Updated: 2023/05/17 11:39:56 by agrillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	
	if(fd < 0 || BUFFER_SIZE < 0)
		return(NULL);
	if(!buffer)
	{
		buffer = ft_strdup("");
	}
	line = read_and_line(fd, buffer);
	return(line);
}

char	*read_and_line(int fd, char *buffer)
{
	int		count;
	char	*line;
	char	*stash;
	
	line = ft_strdup(buffer);
	printf("%s", line);
	stash = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (1)
	{
		count = read(fd, stash, BUFFER_SIZE);
		/*printf("%s\n", stash);*/
		if (count < 0)
			return(NULL);
		/*printf("%d" , count);*/
		if(ft_strchr(stash, '\n'))
		{
			buffer = ft_strchr(stash, '\n');
			stash = ft_strdup(clean_stash(stash));
			/*printf("%s", buffer);*/
			line = ft_strjoin(line, stash);
			break;
			
		}
		else
			line = ft_strjoin(line, stash);
	}
	free(stash);
	return(line);
}

char	*clean_stash(char *stash)
{
	int index;

	index = 0;
	while (stash[index])
	{
		if (stash[index] == '\n')
			break;
		index++;
	}
	return(ft_substr(stash, 0, index));
}
