SRCS= ft_printf.c display.c hexa_gestion.c type_gestion.c lst_function.c utils.c set_params_args.c\
	ft_unsigned_itoa.c free.c ./libft/ft_putnbr_fd.c ./libft/ft_itoa.c ./libft/ft_strlen.c \
	./libft/ft_putstr_fd.c ./libft/ft_strchr.c ./libft/ft_isdigit.c \
	./libft/ft_atoi.c 
OBJS = $(SRCS:.c=.o)

BONUS= ft_printf.c display.c hexa_gestion.c type_gestion.c lst_function.c utils.c set_params_args.c\
	ft_unsigned_itoa.c ./libft/ft_putnbr_fd.c ./libft/ft_itoa.c ./libft/ft_strlen.c \
	./libft/ft_putstr_fd.c ./libft/ft_strchr.c ./libft/ft_isdigit.c \
	./libft/ft_atoi.c 
BONUS_OBJS= $(BONUS:.c=.o)

CC= clang
RM= rm -f
CFLAGS= -Wall -Wextra -Werror -I.

NAME= libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean : 
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
		$(RM) $(NAME)

re :fclean $(NAME)

bonus : $(OBJS)
		ar rcs $(NAME) $(OBJS)

.PHONY:	all clean fclean re bonus
