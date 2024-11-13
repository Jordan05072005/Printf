/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_gestion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:56:48 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/19 23:56:48 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_valide_argument(char *str)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	while (str[i] && !p_valid(str[i]) && str[i] != '.')
		i++;
	while (str[i] && (str[i] == '.' || ft_isdigit(str[i])))
	{
		if (str[i] == '.')
			point++;
		i++;
	}
	if (p_valid(str[i]) && point <= 1)
		return (1);
	return (-1);
}

int	gestion_precision(char **str)
{
	int	precision;

	precision = 0;
	(*str)++;
	if (*str[0] == '*')
		return (-1);
	precision = ft_atoi(*str);
	while (ft_isdigit(*str[0]))
		(*str)++;
	return (precision);
}

int	gestion_space(char **str, t_arg **temp)
{
	int	space;
	int	i;

	i = 5;
	if (in_str(*str, ' ') != -1)
		(*temp)->sign[i++] = ' ';
	while (!ft_isdigit(*str[0]) && !p_valid(*str[0]))
	{
		if (*str[0] == '.')
			return (0);
		(*str)++;
	}
	space = ft_atoi(*str);
	if (*str[0] == '0')
		(*temp)->sign[i++] = '0';
	(*temp)->sign[i++] = '\0';
	while (ft_isdigit(*str[0]))
		(*str)++;
	return (space);
}

t_arg	*parameter_arguments(char **str, t_arg *val)
{
	t_arg	*temp;

	(*str)++;
	if (is_valide_argument(*str))
	{
		temp = lst_new(NULL, 0, 0, 0);
		temp->sign[0] = in_str(*str, '+');
		temp->sign[1] = in_str(*str, '-');
		temp->sign[2] = in_str(*str, '#');
		temp->sign[3] = in_str(*str, '.');
		temp->sign[4] = in_str(*str, '*');
		temp->sign[5] = '\0';
		temp->space = gestion_space(str, &temp);
		if (in_str(temp->sign, '.') != -1)
			temp->precision = gestion_precision(str);
		while (*str[0] && !p_valid(*str[0]))
			(*str)++;
		val = lst_new(temp->sign, temp->space, *str[0], temp->precision);
		(*str)++;
		free(temp);
		return (val);
	}
	return (0);
}

t_arg	*type_gestion(char const *str, int	*nbr)
{
	t_arg	*arg;
	t_arg	*val;
	char	*pt_str;

	arg = NULL;
	pt_str = ft_strchr(str, '%');
	(*nbr) = 1;
	while (pt_str != NULL)
	{
		val = NULL;
		val = parameter_arguments(&pt_str, val);
		if (!val)
			val = lst_new(0, 0, '0', 0);
		(*nbr)++;
		add_back(&arg, val);
		pt_str = ft_strchr(pt_str, '%');
	}
	val = lst_new(0, 0, '0', 0);
	add_back(&arg, val);
	return (arg);
}
