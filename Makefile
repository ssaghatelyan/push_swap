NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = main.c \
algorithms/adaptive_sort.c \
algorithms/complex_sort.c \
algorithms/medium_sort.c \
algorithms/simple_sort.c \
algorithms/sort_2.c \
algorithms/sort_3.c \
algorithms/sort_5.c \
operations/operation.c \
operations/opr_push.c \
operations/opr_rotate.c \
operations/opr_rev_rotate.c \
operations/opr_swap.c \
parsing/pars.c \
parsing/pars_utils.c \
parsing/flags.c \
stack/stack_utils.c \
utils/compute_disorder.c \
utils/print_bench.c \
utils/find_min.c \
utils/get_position.c \
utils/index_stack.c \
utils/is_sorted.c \
utils/rotate_to_top.c

OBJ = $(SRC:.c=.o)

PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(PRINTF):
	make -C ft_printf

$(NAME): $(OBJ) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C ft_printf fclean

re: fclean all

.PHONY: all clean fclean re