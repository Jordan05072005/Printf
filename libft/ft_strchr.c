/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:07:49 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/10 13:07:49 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(s))
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i++;
	}
	return ((void *) 0);
}

/*
#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_strchr("je sus", 'i'));
	printf("%s\n", ft_strchr("je suis", 'i'));
	printf("%s", ft_strchr("je siuis", 'i'));
	return (1);
}*/