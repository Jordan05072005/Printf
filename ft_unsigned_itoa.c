/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:16:20 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/19 15:16:20 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigned_int_len(unsigned int n)
{
	if (n > 9)
		return (1 + unsigned_int_len(n / 10));
	return (1);
}

static void	fullfill(char *nbr, unsigned int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		nbr[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	nbr[i] = n + '0';
	nbr[i + 1] = '\0';
}

static	void	reverse(char *nbr,	unsigned int n)
{
	int		i;
	int		max;
	char	temp;

	max = unsigned_int_len(n) - 1;
	i = 0;
	while (i < max)
	{
		temp = nbr[i];
		nbr[i] = nbr[max];
		nbr[max] = temp;
		i++;
		max--;
	}
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*nbr;

	nbr = malloc(sizeof(char) * (unsigned_int_len(n) + 1));
	if (nbr == NULL)
		return (NULL);
	fullfill(nbr, n);
	reverse(nbr, n);
	return (nbr);
}
