/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:18:27 by lylrandr          #+#    #+#             */
/*   Updated: 2025/08/22 14:49:47 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_fill_line(char **stash, char *buffer, int i)
{
	char	*line;
	char	*new_stash;

	line = malloc(sizeof(char) * (i + 1));
	if (!line)
	{
		free(stash);
		free(buffer);
		return (NULL);
	}
	ft_strlcpy(line, *stash, i + 1);
	new_stash = ft_strdup(&(*stash)[i]);
	free(*stash);
	*stash = new_stash;
	return (line);
}

char	*ft_end_fd(char **stash, char *buffer, int count)
{
	char	*line;
	int		i;

	if (count == -1)
	{
		if (*stash)
			free(*stash);
		*stash = NULL;
		free(buffer);
		return (NULL);
	}
	free(buffer);
	if (*stash && **stash)
	{
		i = ft_isnewline(*stash);
		if (i > 0)
			return (ft_fill_line(stash, NULL, i));
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	free(*stash);
	*stash = NULL;
	return (NULL);
}

static char	*ft_strjoin_free(char *stash, char *buffer)
{
	char	*new_str;

	new_str = ft_strjoin(stash, buffer);
	if (stash)
		free(stash);
	return (new_str);
}

char	*ft_create_stash(int fd, char *buffer, int count)
{
	int			i;
	char		*line;
	static char	*stash;

	while (count > 0)
	{
		buffer[count] = '\0';
		stash = ft_strjoin_free(stash, buffer);
		if (!stash)
			return (free(buffer), NULL);
		i = ft_isnewline(stash);
		if (i > 0)
		{
			line = ft_fill_line(&stash, buffer, i);
			free(buffer);
			return (line);
		}
		count = read(fd, buffer, BUFFER_SIZE);
	}
	line = ft_end_fd(&stash, buffer, count);
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;
	int		count;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	count = read(fd, buffer, BUFFER_SIZE);
	line = ft_create_stash(fd, buffer, count);
	return (line);
}
