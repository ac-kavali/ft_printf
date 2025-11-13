# **************************************************************************** #
#                               ft_printf                                      #
#***************************************************************************** #
NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -f

SRCS = ft_printf.c \
       ft_parse_format.c \
       ft_print_char.c \
       ft_print_string.c \
       ft_print_int.c \
       ft_print_unsigned.c \
       ft_print_lhex.c \
       ft_print_uhex.c \
       ft_print_ptr.c \
       ft_print_percent.c \
       ptr_width.c \
       ptr_width_zero.c \
       ptr_minus_width.c \
       ft_isflag.c \
	ft_putchar.c \
	ft_putnbr.c

OBJS = $(SRCS:.c=.o)

HEADER = libftprintf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
