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

int	in_str(char *str, char c, int (*f)(char))
{
	int	i;

	i = 0;
	if (f)
	{
		while (str[i] && !f(str[i]))
		{
			if (str[i] == c)
				return (c);
			i++;
		}
	}
	else
	{
		while (str[i])
		{
			if (str[i] == c)
				return (c);
			i++;
		}
	}
	return (-1);
}

void	putchar_n(int n, char w, int lock)
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
}

void	ft_putstr_arg(char *s, int fd, t_arg *arg)
{
	if (in_str(arg->sign, '.', &p_valid) != -1 || arg->point != 0)
		write(fd, s, (arg->point));
	else
		write(fd, s, ft_strlen(s));
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
