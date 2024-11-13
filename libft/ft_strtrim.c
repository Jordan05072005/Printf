/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:08:37 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/10 13:08:37 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	find_start(const char *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && is_set(s1[i], set))
		i++;
	return (i);
}

static size_t	find_end(const char *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0 && is_set(s1[i], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*dest;

	i = 0;
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * ((end - start) + 2));
	if (dest == NULL)
		return (NULL);
	while (start + i <= end)
	{
		dest[i] = s1[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int main(void)
{
	printf("%s\n", ft_strtrim("tttttttttttje suis tt", ""));
}*/