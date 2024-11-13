/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 12:41:30 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/12 12:41:30 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*cpy;
	int		i;

	cpy = lst;
	i = 0;
	while (cpy != NULL)
	{
		cpy = cpy->next;
		i++;
	}
	return (i);
}
