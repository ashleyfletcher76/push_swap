# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 13:45:54 by asfletch          #+#    #+#              #
#    Updated: 2023/12/06 15:52:23 by asfletch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

LIBFT		= ft_libft
LIBFT_LIB	= $(LIBFT)/libft.a
SRCS		= src/push_swap.c src/init_and_begin_check.c \
			utils/check_file.c utils/error_and_free.c utils/reference_stack.c \
			moves/swap.c moves/push.c moves/rotate.c moves/reverse_rotate.c \
			sort_utils/check_if_sorted.c sort/sort_list.c sort/initial_phase.c \
			sort/second_phase.c sort/third_phase.c sort_utils/small_numbers.c \
			sort_utils/sorting_utils.c sort_utils/find_pivots.c \

CC			= 	gcc
CFLAGS		= -Wall -Wextra -Werror -g -I header -I libft
OBJS		= 	$(SRCS:.c=.o)
RM			= 	rm -f

all: $(NAME)

$(LIBFT_LIB):
			make -C $(LIBFT)
			make -C $(LIBFT) bonus

$(NAME): $(LIBFT_LIB) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

clean:
		$(RM) $(OBJS)
		make -C $(LIBFT) clean

fclean: clean
		$(RM) $(NAME)
		make -C $(LIBFT) fclean

re:		fclean all

.PHONY: all clean fclean re
