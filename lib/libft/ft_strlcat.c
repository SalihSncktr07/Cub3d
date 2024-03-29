/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasanca <sasanca@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:36:46 by sasanca           #+#    #+#             */
/*   Updated: 2024/02/03 15:20:03 by sasanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	x = ft_strlen(dst);
	y = 0;
	while (src[y] && x < dstsize - 1)
		dst[x++] = src[y++];
	dst[x] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[y]));
}
