/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 00:38:43 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/20 00:38:43 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_arg(t_arg *arg)
{
	t_arg	*cpy;

	while (arg)
	{
		free(arg->space);
		free(arg->sign);
		if (arg->flags == 'u' || arg->flags == 'd' || arg->flags == 'i')
			free(arg->str);
		else if (arg->flags == 'x' || arg->flags == 'X')
			free(arg->str);
		cpy = arg;
		arg = arg->next;
		free(cpy);
	}
	free(arg);
}
