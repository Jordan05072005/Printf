/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:06:51 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/13 15:06:51 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display(const char *str, int i)
{
	while (str[i] && str[i] != '%')
	{
		write(1, &str[i], 1);
		i++;
	}
	i++;
	while (str[i] && p_valid(str[i]) == 0)
		i++;
	return (i + 1);
}

void	display_int(long nbr, t_arg *arg)
{
	set_param_int(nbr, &arg);
	if (nbr == 0 && in_str(arg->sign, '.', &p_valid) != -1 && arg->point == 0)
	{
		putchar_n(arg->space[1], ' ', 1);
		return ;
	}
	putchar_n(arg->space[2], ' ', (in_str(arg->sign, '-', &p_valid) == -1));
	if (nbr < 0)
		write(1, "-", 1);
	put_ox(arg);
	if (in_str(arg->sign, '.', &p_valid) != -1 || arg->point != 0)
		putchar_n(arg->nbr_zero, '0', 1);
	if (in_str(arg->sign, '+', &p_valid) != -1)
		write(1, "+", 1);
	if ((arg->flags == 'd' || arg->flags == 'i') && nbr == -2147483648)
		write(1, "2", 1);
	if (arg->flags == 'd' || arg->flags == 'i')
		ft_putstr_fd(arg->str, 1);
	else if (arg->flags == 'u')
		ft_putstr_fd(arg->str, 1);
	else if (arg->flags == 'x' && (arg->nbr_zero == 0 || nbr != 0))
		putnbr_hexa(nbr, HEXALOWERCASE, arg);
	else if (arg->flags == 'X' && (arg->nbr_zero == 0 || nbr != 0))
		putnbr_hexa(nbr, HEXAUPPERCASE, arg);
	putchar_n(arg->space[2], ' ', (in_str(arg->sign, '-', &p_valid) != -1));
}

void	display_char(char c, t_arg *arg)
{
	set_param_char(c, &arg);
	putchar_n(arg->space[2], ' ', (in_str(arg->sign, '-', &p_valid) == -1));
	write(1, &c, 1);
	putchar_n(arg->space[2], ' ', (in_str(arg->sign, '-', &p_valid) != -1));
}

void	display_str(char *str, t_arg *arg)
{
	set_param_str(str, &arg);
	putchar_n(arg->space[2], ' ', (in_str(arg->sign, '-', &p_valid) == -1));
	ft_putstr_arg(arg->str, 1, arg);
	putchar_n(arg->space[2], ' ', (in_str(arg->sign, '-', &p_valid) != -1));
}

void	display_void(void *adrr, t_arg *arg)
{
	set_param_void(adrr, &arg);
	putchar_n(arg->space[2], ' ', (in_str(arg->sign, '-', &p_valid) == -1));
	if (adrr)
	{
		ft_putstr_arg("0x", 1, arg);
		putnbr_hexa((long unsigned int)adrr, HEXALOWERCASE, arg);
	}
	else
		ft_putstr_arg("(nil)", 1, arg);
	putchar_n(arg->space[2], ' ', (in_str(arg->sign, '-', &p_valid) != -1));
}
