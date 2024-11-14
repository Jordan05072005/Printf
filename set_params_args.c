/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:50:50 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/19 23:50:50 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_param_int2(long nbr, t_arg **arg)
{
	(*arg)->precision = (*arg)->precision - (*arg)->size_abs;
	if ((*arg)->precision < 0)
		(*arg)->precision = 0;
	(*arg)->space -= ((*arg)->size + (*arg)->precision);
	if ((*arg)->space < 1 && in_str((*arg)->sign, ' ') != -1 && nbr >= 0)
		(*arg)->space = 1;
	if (in_str((*arg)->sign, '+') != -1)
		(*arg)->space--;
	if (nbr == 0 && in_str((*arg)->sign, '.') != -1)
		(*arg)->flags = -1;
}

void	set_param_int(long nbr, t_arg **arg)
{
	if ((*arg)->flags == 'u')
		(*arg)->str = ft_unsigned_itoa((unsigned int)nbr);
	else
		(*arg)->str = ft_itoa(nbr);
	if (ft_strchr(INT_FLAGS, (*arg)->flags) != NULL)
		(*arg)->size = ft_strlen((*arg)->str);
	else
		(*arg)->size = hexa_len(nbr, (*arg));
	if (in_str((*arg)->sign, '.') != -1 && nbr == 0)
		(*arg)->size = 0;
	(*arg)->size_abs = (*arg)->size;
	if (nbr < 0)
		(*arg)->size_abs--;
	set_param_int2(nbr, arg);
}

void	set_param_str(char *str, t_arg **arg)
{
	if (str)
		(*arg)->str = str;
	else
		(*arg)->str = "(null)";
	(*arg)->size = (int)ft_strlen((*arg)->str);
	if (!str)
		if ((*arg)->precision < (*arg)->size && in_str((*arg)->sign, '.') != -1)
			(*arg)->size = 0;
	if ((*arg)->precision < (*arg)->size && in_str((*arg)->sign, '.') != -1)
		(*arg)->size = (*arg)->precision;
	((*arg)->space) -= (*arg)->size;
}

void	set_param_char(char c, t_arg **arg)
{
	(void)c;
	(*arg)->space -= 1;
}

void	set_param_void(void *adrr, t_arg **arg)
{
	(*arg)->size = hexa_len((long unsigned int)adrr, *arg) + 2;
	if (adrr == NULL)
	{
		(*arg)->size = (int)ft_strlen("(nil)");
		if ((*arg)->precision < (*arg)->size && in_str((*arg)->sign, '.') != -1)
			(*arg)->size = 0;
	}
	if ((*arg)->precision > (*arg)->size && in_str((*arg)->sign, '.') != -1)
		(*arg)->precision = 0;
	if (in_str((*arg)->sign, '.') == -1)
		(*arg)->space = (*arg)->space - ((*arg)->size);
	else
		(*arg)->space = (*arg)->space - (*arg)->precision;
}
