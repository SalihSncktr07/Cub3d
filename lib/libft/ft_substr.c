/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasanca <sasanca@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:35:51 by sasanca           #+#    #+#             */
/*   Updated: 2024/02/03 15:20:03 by sasanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_sub;
	size_t	l;

	l = ft_strlen(s);
	if (start > l)
		return (ft_strdup(""));
	if (l >= len)
		l = len;
	if (ft_strlen(s) - start < l)
		l = ft_strlen(&s[start]);
	new_sub = (char *)ft_calloc(l + 1, sizeof(char));
	if (new_sub)
		ft_strlcpy(new_sub, &s[start], l + 1);
	return (new_sub);
}
