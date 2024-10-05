/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_itoa.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jguaglio <guaglio.jordan@gmail.com>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/09/10 12:23:47 by jguaglio		  #+#	#+#			 */
/*   Updated: 2024/09/10 12:23:47 by jguaglio		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	if (n == -2147483648)
		return (2 + int_len(n / -10));
	if (n < 0)
		return (1 + int_len(-n));
	if (n > 9)
		return (1 + int_len(n / 10));
	return (1);
}

static void	fullfill(char *nbr, int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		nbr[i++] = '-';
		nbr[i++] = '8';
		n = n / -10;
	}
	if (n < 0)
	{
		nbr[i++] = '-';
		n = -n;
	}
	while (n > 9)
	{
		nbr[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	nbr[i] = n + '0';
	nbr[i + 1] = '\0';
}

static	void	reverse(char *nbr, int n)
{
	int		i;
	int		max;
	char	temp;

	max = int_len(n) - 1;
	if (n > 0)
		i = 0;
	else
		i = 1;
	while (i < max)
	{
		temp = nbr[i];
		nbr[i] = nbr[max];
		nbr[max] = temp;
		i++;
		max--;
	}
}

char	*ft_itoa(int n)
{
	char	*nbr;

	nbr = malloc(sizeof(char) * (int_len(n) + 1));
	if (nbr == NULL)
		return (NULL);
	fullfill(nbr, n);
	reverse(nbr, n);
	return (nbr);
}

/*
int	main(void)
{
	printf("%s",ft_itoa(0));
}*/	