/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 00:23:13 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/18 00:23:13 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_valid(char c)
{
	int	i;

	i = 0;
	while (FLAGS_IMPLEMENT[i])
	{
		if (FLAGS_IMPLEMENT[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !p_valid(str[i]))
	{
		if (str[i] == c)
			return (c);
		i++;
	}
	return (-1);
}

int	putchar_n(int n, char w, int lock)
{
	int	i;

	i = 0;
	if (lock)
	{
		while (i < n)
		{
			write(1, &w, 1);
			i++;
		}
	}
	return (i);
}

int	ft_abs(int nb)
{
	if (nb == -2147483648)
		return (147483648);
	if (nb < 0)
		return (-nb);
	return (nb);
}

long	power(int nb, long pow)
{
	if (pow < 0)
		return (-1);
	if (pow == 0)
		return (1);
	return (nb * power(nb, pow - 1));
}
