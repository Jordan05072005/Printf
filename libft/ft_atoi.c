/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:06:17 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/10 13:06:17 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	res;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
/*
#include <stdio.h>
int main(void)
{
    printf("%d\n",ft_atoi("      -54de5"));
    printf("%d\n",ft_atoi("      -y54de5"));
    printf("%d\n", ft_atoi("    \n  -54de5"));
    printf("%d\n", ft_atoi("      ---54de5"));
    printf("%d\n", ft_atoi("      +54de5"));
    printf("%d\n", ft_atoi("      54de5"));
    printf("%d\n", ft_atoi("      -54de5"));
    printf("%d\n", ft_atoi("      0de5"));

}*/