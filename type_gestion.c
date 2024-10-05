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

int	*gestion_space(char **str)
{
	int	*space;
	int	l;

	space = malloc(sizeof(int) * 2);
	l = 1;
	space[0] = 0;
	space[1] = 0;
	while (*str[0] && p_valid(*str[0]) == 0 && *str[0] != '.')
	{
		if (*str[0] == '0' && in_str(*str, '.', &p_valid) == -1 && l)
			return (space);
		if (*str[0] == 32)
			space[0] = 1;
		if (ft_isdigit(*str[0]))
		{
			l = 0;
			space[1] = (space[1] * 10) + (*str[0] - '0');
		}
		(*str)++;
	}
	if (*str[0] == '.')
		(*str)++;
	return (space);
}

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

t_arg	*parameter_arguments(char **str, t_arg *val)
{
	t_arg	*temp;

	temp = malloc(sizeof(t_arg));
	temp->sign = malloc(sizeof(char) * 5);
	(*str)++;
	if (is_valide_argument(*str))
	{
		temp->sign[0] = in_str(*str, '+', &p_valid);
		temp->sign[1] = in_str(*str, '-', &p_valid);
		temp->sign[3] = in_str(*str, '#', &p_valid);
		temp->sign[2] = in_str(*str, '.', &p_valid);
		temp->sign[4] = '\0';
		temp->space = gestion_space(str);
		temp->point = ft_atoi(*str);
		while (*str[0] && !p_valid(*str[0]))
			(*str)++;
		val = lst_new(temp->sign, temp->space, *str[0], temp->point);
		(*str)++;
		free(temp->space);
		free(temp->sign);
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
		if (val != NULL)
		{
			(*nbr)++;
			add_back(&arg, val);
		}
		pt_str = ft_strchr(pt_str, '%');
	}
	val = lst_new(0, NULL, '0', 0);
	add_back(&arg, val);
	return (arg);
}
