/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:07:59 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/10 13:07:59 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;
	int		j;	

	i = 0;
	j = 0;
	dest = (char *)malloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*
int main()
{
	printf("%s\n", ft_strjoin("", ""));
	printf("%s\n", ft_strjoin("je suis", " un gars"));
	printf("%s\n", ft_strjoin("je", ""));
	printf("%s\n", ft_strjoin("", "tu"));
}*/