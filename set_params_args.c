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

void	set_param_int2(t_arg **arg);

void	set_param_int(long nbr, t_arg **arg)
{
	if ((*arg)->flags == 'u')
		(*arg)->str = ft_unsigned_itoa((unsigned int)nbr);
	else
		(*arg)->str = ft_itoa(ft_abs(nbr));
	if (in_str(INT_FLAGS, (*arg)->flags, NULL) != -1)
		(*arg)->size = ft_strlen((*arg)->str);
	else
		(*arg)->size = hexa_len(nbr, (*arg));
	if (nbr == -2147483648 && in_str(INT_FLAGS, (*arg)->flags, NULL) != -1)
		(*arg)->size++;
	(*arg)->size_abs = (*arg)->size;
	if (nbr < 0)
		(*arg)->size++;
	set_param_int2(arg);
}

void	set_param_int2(t_arg **arg)
{
	if (in_str((*arg)->sign, '.', &p_valid) == -1)
		(*arg)->nbr_zero = (*arg)->point - (*arg)->size;
	else
		(*arg)->nbr_zero = (*arg)->point - (*arg)->size_abs;
	if ((*arg)->nbr_zero <= 0)
		(*arg)->nbr_zero = 0;
	if ((*arg)->point < (*arg)->size_abs
		&& in_str((*arg)->sign, '.', &p_valid) != -1)
		(*arg)->point = 0;
	if (in_str((*arg)->sign, '.', &p_valid) != -1 || (*arg)->point != 0)
		(*arg)->space[2] = ((*arg)->space[1])
			- ((*arg)->nbr_zero + (*arg)->size);
	else if ((*arg)->space[1] > (*arg)->space[0])
		(*arg)->space[2] = (*arg)->space[1] - (*arg)->size;
	else
		(*arg)->space[2] = (*arg)->space[0];
	if (in_str((*arg)->sign, '+', &p_valid) != -1)
		(*arg)->space[2]--;
}

void	set_param_str(char *str, t_arg **arg)
{
	if (str)
		(*arg)->str = str;
	else
		(*arg)->str = "(null)";
	(*arg)->size = (int)ft_strlen((*arg)->str);
	if (!str)
		if ((*arg)->point < (*arg)->size)
			(*arg)->point = 0;
	if ((*arg)->point > (*arg)->size)
		(*arg)->point = (*arg)->size;
	if (in_str((*arg)->sign, '.', &p_valid) == -1)
		(*arg)->space[2] = (*arg)->space[1] - ((*arg)->size);
	else
		(*arg)->space[2] = (*arg)->space[1] - (*arg)->point;
}

void	set_param_char(char c, t_arg **arg)
{
	(void)c;
	(*arg)->space[2] = (*arg)->space[1] - 1;
}

void	set_param_void(void *adrr, t_arg **arg)
{
	(*arg)->size = hexa_len((long unsigned int)adrr, *arg) + 2;
	if (adrr == NULL)
	{
		(*arg)->size = (int)ft_strlen("(nil)");
		if ((*arg)->point < (*arg)->size)
			(*arg)->point = 0;
	}
	if ((*arg)->point > (*arg)->size)
		(*arg)->point = (*arg)->size;
	if (in_str((*arg)->sign, '.', &p_valid) == -1)
		(*arg)->space[2] = (*arg)->space[1] - ((*arg)->size);
	else
		(*arg)->space[2] = (*arg)->space[1] - (*arg)->point;
}
