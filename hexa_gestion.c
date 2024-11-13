/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:24:44 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/15 14:24:44 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_ox(t_arg *arg, long nbr)
{
	int	i;

	i = 0;
	if (in_str(arg->sign, '#') != -1 && nbr != 0)
	{
		if (arg->flags == 'x')
			i += write(1, "0x", 2);
		else if (arg->flags == 'X')
			i += write(1, "0X", 2);
	}
	return (i);
}

int	give_indice(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	putnbr_hexa(long unsigned int nbr, char *base, t_arg *arg)
{
	long unsigned int		base_nb;

	base_nb = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_nb)
	{
		putnbr_hexa(nbr / base_nb, base, arg);
		nbr = nbr % base_nb;
	}
	write(1, &base[nbr], 1);
}

int	hexa_len(long unsigned int nbr, t_arg *arg)
{
	long	i;

	i = 1;
	if (arg->precision != 0 && nbr == 0)
		i = 0;
	while (nbr >= (long unsigned int)power(16, i) && power(16, i) != 0)
		i++;
	if (nbr != 0 && in_str(arg->sign, '#') != -1)
		i = i + 2;
	return (i);
}
