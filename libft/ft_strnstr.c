/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:08:21 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/10 13:08:21 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	while (str[i] != '\0' && i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (str[i + j] == to_find[j]
				&& (i + j) < len && str[i + j] && to_find[j])
			{
				j++;
			}
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_strnstr("je me nomme Jordan", "Jordan", 30));
	printf("%s\n", ft_strnstr("je me nomme Jordan", "Jordan", 2));
	printf("%s\n", ft_strnstr("je me nomme Jordan", "Jordan", 16));
	printf("%s\n", ft_strnstr("je me nomme Jordan", "Jordan", 15));
}*/