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

int	display(const char *str, int i, size_t *size)
{
	while (str[i] && str[i] != '%')
	{
		write(1, &str[i], 1);
		i++;
		(*size)++;
	}
	i++;
	while (str[i] && p_valid(str[i]) == 0)
		i++;
	return (i + 1);
}

void	display_int(long nbr, t_arg *arg, size_t *size)
{
	set_param_int(nbr, &arg);
	if (in_str(arg->sign, '0') != -1 && in_str(arg->sign, '.') == -1)
	{
		arg->precision = arg->space;
		arg->space = 0;
	}
	(*size) += putchar_n(arg->space, ' ', (in_str(arg->sign, '-') == -1));
	(*size) += putchar_n(1, '-', nbr < 0);
	(*size) += putchar_n(1, '+', (in_str(arg->sign, '+') != -1) && nbr >= 0);
	put_ox(arg, nbr);
	(*size) += putchar_n(arg->precision, '0', 1);
	if (ft_strchr(INT_FLAGS, arg->flags) && nbr < 0)
		ft_putstr_fd((arg->str) + 1, 1);
	else if (ft_strchr(INT_FLAGS, arg->flags) && nbr >= 0)
		ft_putstr_fd(arg->str, 1);
	else if (arg->flags == 'x')
		putnbr_hexa(nbr, HEXALOWERCASE, arg);
	else if (arg->flags == 'X')
		putnbr_hexa(nbr, HEXAUPPERCASE, arg);
	(*size) += putchar_n(arg->space, ' ', (in_str(arg->sign, '-') != -1));
	(*size) += arg->size_abs;
}

size_t	display_char(char c, t_arg *arg)
{
	size_t	size;

	size = 0;
	set_param_char(c, &arg);
	size += putchar_n(arg->space, ' ', (in_str(arg->sign, '-') == -1));
	size += write(1, &c, 1);
	size += putchar_n(arg->space, ' ', (in_str(arg->sign, '-') != -1));
	return (size);
}

size_t	display_str(char *str, t_arg *arg)
{
	size_t	size;

	size = 0;
	set_param_str(str, &arg);
	size += putchar_n(arg->space, ' ', (in_str(arg->sign, '-') == -1));
	size += write(1, arg->str, arg->size);
	size += putchar_n(arg->space, ' ', (in_str(arg->sign, '-') != -1));
	return (size);
}

size_t	display_void(void *adrr, t_arg *arg)
{
	size_t	size;

	size = 0;
	set_param_void(adrr, &arg);
	size += putchar_n(arg->space, ' ', (in_str(arg->sign, '-') == -1));
	if (adrr)
	{
		size += write(1, "0x", 2);
		putnbr_hexa((long unsigned int)adrr, HEXALOWERCASE, arg);
		size += hexa_len((long unsigned int)adrr, arg);
	}
	else
		size += write(1, "(nil)", arg->size);
	size += putchar_n(arg->space, ' ', (in_str(arg->sign, '-') != -1));
	return (size);
}
