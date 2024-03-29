/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasanca <sasanca@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:40:26 by sasanca           #+#    #+#             */
/*   Updated: 2024/02/03 15:20:03 by sasanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[x] != '\0')
	{
		y = 0;
		while (haystack[x + y] == needle[y] && (x + y) < len)
		{
			if (haystack[x + y] == '\0' && needle[y] == '\0')
				return ((char *)&haystack[x]);
			y++;
		}
		if (needle[y] == '\0')
			return ((char *)haystack + x);
		x++;
	}
	return (0);
}
