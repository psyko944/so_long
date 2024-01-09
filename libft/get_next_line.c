/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:17:18 by mekherbo          #+#    #+#             */
/*   Updated: 2023/12/07 16:39:38 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_new_save(char *save)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (save[i])
		str[j++] = save[i++];
	str[j] = '\0';
	free(save);
	return (str);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*next;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0))
		return (NULL);
	next = ft_read(fd, next);
	if (!next)
		return (NULL);
	line = ft_get_line(next);
	next = ft_new_save(next);
	return (line);
}

char	*ft_read(int fd, char *save)
{
	char	*buffer;
	ssize_t	rv;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	rv = BUFFER_SIZE;
	while (rv > 0 && !ft_strchr(save, '\n'))
	{
		rv = read(fd, buffer, BUFFER_SIZE);
		if (rv == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rv] = '\0';
		save = ft_strjoin2(save, buffer);
	}
	free(buffer);
	return (save);
}
