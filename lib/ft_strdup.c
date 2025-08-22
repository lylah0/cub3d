/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:27:20 by moni              #+#    #+#             */
/*   Updated: 2025/08/22 14:51:50 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copie colle avec malloc
// char	*ft_strdup(const char *src)
// {
// 	int		i;
// 	int		len;
// 	char	*dest;

// 	i = 0;
// 	len = ft_strlen(src);
// 	dest = (char *) malloc((len + 1) * sizeof(char));
// 	if (!dest)
// 		return (NULL);
// 	while (src[i] != 0)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	dest[i] = 0;
// 	return (dest);
// }
