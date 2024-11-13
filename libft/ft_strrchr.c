/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:08:27 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/10 13:08:27 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pt_res;

	pt_res = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			pt_res = ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		pt_res = ((char *)s);
	return (pt_res);
}

/*
#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_strrchr("je sus", 'i'));
	printf("%s\n", ft_strrchr("je suis", 'i'));
	printf("%s", ft_strrchr("je siuis", 'i'));
	return (1);
}*/