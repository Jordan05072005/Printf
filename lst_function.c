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

t_arg	*lst_new(char *sign, int space, char flags, int precision)
{
	t_arg	*new;
	int		i;

	i = -1;
	new = malloc(sizeof(t_arg));
	if (new == NULL)
		return (NULL);
	new->flags = flags;
	while (sign && sign[++i])
		new->sign[i] = sign[i];
	new->str = NULL;
	new->sign[i] = '\0';
	new->space = space;
	new->precision = precision;
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
