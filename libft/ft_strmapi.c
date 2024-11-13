/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:08:14 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/10 13:08:14 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*strfinal;
	int		i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	strfinal = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (strfinal == NULL)
		return (NULL);
	while (s[i])
	{
		strfinal[i] = f(i, s[i]);
		i++;
	}
	strfinal[i] = '\0';
	return (strfinal);
}
