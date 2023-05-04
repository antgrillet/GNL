/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrillet <anto73grillet@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:48:59 by agrillet          #+#    #+#             */
/*   Updated: 2023/05/04 10:37:36 by agrillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int		buffer;
	char	*memory;
	
	buffer = 10;
	memory = malloc(sizeof(char) * 11);
	printf("%zd",read(fd, &memory, buffer));
	printf("%s", memory);
	return(memory);
}