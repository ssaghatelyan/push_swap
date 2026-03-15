NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = main.c \
algorithms/simple_sort.c \
algorithms/sort_2.c \
algorithms/sort_3.c \
operations/operation.c \
operations/opr_push.c \
operations/opr_rotate.c \
operations/opr_rev_rotate.c \
operations/opr_swap.c \
parsing/pars.c \
parsing/pars_utils.c \
stack/stack_utils.c \
utils/compute_disorder.c \
utils/find_min.c \
utils/get_position.c \
utils/index_stack.c \
utils/is_sorted.c \
utils/rotate_to_top.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re