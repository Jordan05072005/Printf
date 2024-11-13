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

size_t	gestion_print(const char *format, va_list ap, int nbr_arg, t_arg *arg)
{
	size_t	size[2];

	size[0] = 0;
	size[1] = 0;
	while (nbr_arg--)
	{
		size[0] = display(format, size[0], &(size[1]));
		if (arg->precision == -1)
			(arg->next)->precision = va_arg(ap, int);
		else if (arg->flags == 'd' || arg->flags == 'i')
			display_int(va_arg(ap, int), arg, &(size[1]));
		else if (arg->flags == 'x' || arg->flags == 'X' || arg->flags == 'u')
			display_int(va_arg(ap, unsigned int), arg, &(size[1]));
		else if (arg->flags == 'c')
			size[1] += display_char(va_arg(ap, int), arg);
		else if (arg->flags == 's')
			size[1] += display_str(va_arg(ap, char *), arg);
		else if (arg->flags == 'p')
			size[1] += display_void(va_arg(ap, void *), arg);
		else if (arg->flags == '%')
			size[1] += write(1, "%", 1);
		if (arg->flags != '0')
			arg = arg->next;
	}
	return (size[1]);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_arg	*arg;
	int		nbr_arg;
	t_arg	*cpy_arg;
	int		size;

	va_start(ap, format);
	arg = type_gestion(format, &nbr_arg);
	cpy_arg = arg;
	size = gestion_print(format, ap, nbr_arg, arg);
	free_arg(cpy_arg);
	va_end(ap);
	return (size);
}
