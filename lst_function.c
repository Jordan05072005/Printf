/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:30:02 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/15 17:30:02 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*lst_new(char *sign, int *space, char flags, int point)
{
	t_arg	*new;

	new = malloc(sizeof(t_arg));
	new->space = malloc(sizeof(int) * 3);
	new->sign = malloc(sizeof(char) * 5);
	if (new == NULL || new->space == NULL)
		return (NULL);
	new->flags = flags;
	if (sign)
	{
		new->sign[0] = sign[0];
		new->sign[1] = sign[1];
		new->sign[2] = sign[2];
		new->sign[3] = sign[3];
		new->sign[4] = '\0';
	}
	if (space)
	{
		new->space[0] = space[0];
		new->space[1] = space[1];
		new->space[2] = 0;
	}
	new->point = point;
	new->next = NULL;
	return (new);
}

t_arg	*last_lst(t_arg *arg)
{
	if (!arg)
		return (arg);
	while (arg->next != NULL && arg)
		arg = arg->next;
	return (arg);
}

void	add_back(t_arg **arg, t_arg *new)
{
	if (*arg)
		last_lst(*arg)->next = new;
	else
		*arg = new;
}
