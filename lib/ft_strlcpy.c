/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:34:25 by moni              #+#    #+#             */
/*   Updated: 2025/08/22 14:52:13 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copie une chaîne de caractères d'une source vers une destination en évitant
// les problèmes de dépassement de mémoire.
// size_t	ft_strlcpy(char *dest, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	src_len;

// 	src_len = 0;
// 	while (src[src_len])
// 		src_len++;
// 	if (size == 0)
// 		return (src_len);
// 	i = 0;
// 	while (src[i] && i < size - 1)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (src_len);
// }
