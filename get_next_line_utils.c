/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrillet <anto73grillet@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:22:20 by agrillet          #+#    #+#             */
/*   Updated: 2023/05/17 15:02:08 by agrillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 ||!s2)
		return (NULL);
	s3 = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[(i + j)] = s2[j];
		j++;
	}
	return (s3[i + j] = '\0', s3);
}

size_t	ft_strlen(const char *c)
{
	size_t	a;

	a = 0;
	while (c[a] != '\0')
	{
		a += 1;
	}
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	else if (len > ft_strlen(s + start))
		s2 = malloc(sizeof(char) * (ft_strlen(s + start) + 1));
	else
		s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (i < len && s[start])
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i + 1]);
		i++;
	}
	if (str[i] == (char)c)
	{
		return (&str[i + 1]);
	}
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*duplication;

	i = 0;
	duplication = (char *)malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (duplication == NULL)
		return (NULL);
	else
	{
		while (i < ft_strlen((char *)s))
		{
			duplication[i] = s[i];
			i++;
		}
		duplication[i] = '\0';
	}
	return (duplication);
}
