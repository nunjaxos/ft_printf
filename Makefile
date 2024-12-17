SRCS =	ft_pos_putnbr.c  ft_putchar.c  ft_putnbr.c  print_pointer.c\
		ft_puthex.c   ft_putstr.c ft_printf.c \

OBJS =	$(SRCS:.c=.o)

CC =	cc

CFLAGS =	-Wall -Wextra -Werror

RM =	rm -f

AR =	ar

ARF =	-rc

NAME =	libftprintf.a

all: $(NAME)

$(NAME)	:	$(OBJS)

%.o : %.c
			$(CC) -c  $(CFLAGS) $<
			$(AR) $(ARF) $(NAME) $@

clean:
			$(RM) $(OBJS)

fclean:	clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re