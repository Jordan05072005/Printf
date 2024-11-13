/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:08:03 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/10 13:08:03 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lendest;

	i = 0;
	j = 0;
	lendest = ft_strlen(dst);
	while (dst[i])
		i++;
	while (src[j] && (j + i + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (size > j)
		dst[i + j] = '\0';
	if (size <= lendest)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + lendest);
}
