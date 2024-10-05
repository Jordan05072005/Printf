/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 23:32:51 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/19 23:32:51 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	gestion_print(const char *format, va_list ap, int nbr_arg, t_arg *arg)
{
	int	i;

	i = 0;
	while (nbr_arg--)
	{
		i = display(format, i);
		if (arg->flags == 'd' || arg->flags == 'i')
			display_int(va_arg(ap, int), arg);
		else if (arg->flags == 'x' || arg->flags == 'X' || arg->flags == 'u')
			display_int(va_arg(ap, unsigned int), arg);
		else if (arg->flags == 'c')
			display_char(va_arg(ap, int), arg);
		else if (arg->flags == 's')
			display_str(va_arg(ap, char *), arg);
		else if (arg->flags == 'p')
			display_void(va_arg(ap, void *), arg);
		else if (arg->flags == '%')
			write(1, "%", 1);
		if (arg->flags != '0')
			arg = arg->next;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_arg	*arg;
	int		nbr_arg;
	t_arg	*cpy_arg;

	va_start(ap, format);
	arg = type_gestion(format, &nbr_arg);
	cpy_arg = arg;
	gestion_print(format, ap, nbr_arg, arg);
	free_arg(cpy_arg);
	va_end(ap);
	return (1);
}
