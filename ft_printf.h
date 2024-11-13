/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jguaglio <guaglio.jordan@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 23:01:26 by jguaglio          #+#    #+#             */
/*   Updated: 2024/09/12 23:01:26 by jguaglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define HEXALOWERCASE "0123456789abcdef"
# define HEXAUPPERCASE "0123456789ABCDEF"
# define FLAGS_IMPLEMENT "csdiuxXp%"
# define INT_FLAGS "diu"

typedef struct s_arg
{
	char			*str;
	int				space;
	int				size;
	int				size_abs;
	int				precision;
	char			sign[7];
	char			flags;
	struct s_arg	*next;
}	t_arg;

// hexa_gestion.c
void	putnbr_hexa(long unsigned int nb, char *base, t_arg *arg);
int		hexa_len(long unsigned int nbr, t_arg *arg);
int		put_ox(t_arg *arg);

//lst_function.c
t_arg	*lst_new(char *sign, int space, char flags, int precision);
t_arg	*last_lst(t_arg *arg);
void	add_back(t_arg **arg, t_arg *new);

//utils.c
int		in_str(char *str, char c);
int		putchar_n(int n, char w, int lock);
int		ft_abs(int nb);
long	power(int nb, long pow);

//ft_itoa_unsigned.c
char	*ft_unsigned_itoa(unsigned int n);

// type_gestion.c
t_arg	*type_gestion(char const *str, int	*nbr);
int		p_valid(char c);

//set_params_arg.c
void	set_param_int(long nbr, t_arg **arg);
void	set_param_str(char *str, t_arg **arg);
void	set_param_char(char c, t_arg **arg);
void	set_param_void(void *adrr, t_arg **arg);

// display.c
int		display(const char *str, int i, size_t *size);
void	display_int(long nbr, t_arg *arg, size_t *size);
size_t	display_char(char c, t_arg *arg);
size_t	display_str(char *str, t_arg *arg);
size_t	display_void(void *adrr, t_arg *arg);

//free.c
void	free_arg(t_arg *arg);

//ft_printf.c
int		ft_printf(const char *format, ...);

#endif