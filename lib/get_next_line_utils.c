/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:46:39 by lylrandr          #+#    #+#             */
/*   Updated: 2025/08/20 18:09:14 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		x;
	char	*str;

	if (!s1)
		i = 0;
	else
		i = gnl_ft_strlen(s1);
	str = malloc(sizeof(char) * (i + gnl_ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	x = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[x])
	{
		str[i + x] = s2[x];
		x++;
	}
	str[i + x] = '\0';
	return (str);
}

char	*gnl_ft_strdup(char *s1)
{
	int		i;
	char	*str;

	i = gnl_ft_strlen(s1);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = '\0';
	return (str);
}

int	ft_isnewline(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		return (i + 1);
	else
		return (0);
}

char	*gnl_ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
