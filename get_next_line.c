/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrillet <anto73grillet@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:48:59 by agrillet          #+#    #+#             */
/*   Updated: 2023/05/17 15:12:46 by agrillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*stash;
	char		*line;
	
	if(fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) <= -1)
		return(NULL);
	if(!buffer)
		buffer = ft_strdup("");
	line = ft_strdup("");
	stash = read_file(fd);
	/*printf("%s", stash);*/
	buffer = ft_strjoin(buffer, stash);
	/*printf("%s", buffer);*/
	line = final_line(buffer);
	buffer = ft_strchr(buffer, '\n');
	/*printf("%s et %d", buffer, 0);*/
	free(stash);
	return(line);
}

char	*read_file(int fd)
{
	char	*tmp;
	char	*line;
	int		count;
	
	count = 0;
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = ft_strdup("");
	while(1)
	{
		count = 0;
		count = read(fd, tmp, BUFFER_SIZE);
		if(ft_strchr(tmp, '\n'))
		{
			line = ft_strdup(ft_strjoin(line ,tmp));
			line = ft_strdup(ft_strjoin(line, "\n"));
			free(tmp);
			return(line);
		}
		if(count == 0)
			break;
		line = ft_strdup(ft_strjoin(line, tmp));
		/*printf("%s\n", line);*/
	}
	/*printf("%s", line);*/
	line = ft_strjoin(line, tmp);
	free(tmp);
	return(line);
}

char	*final_line(char *buffer)
{
	int	i;
	
	i = 0;
	while (buffer[i] != '\n')
	{
		i++;
		if(!buffer[i])
			return(ft_substr(buffer, 0, i));
	}
	return(ft_substr(buffer, 0, i + 1));
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (str[i] == (char)c)
			return (&str[i - 1]);
		i--;
	}
	if (str[0] == (char)c)
		return (&str[0]);
	return (NULL);
}