# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 11:42:13 by asfletch          #+#    #+#              #
#    Updated: 2023/12/06 16:19:52 by asfletch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = \
	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c ft_memset.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_strchr.c ft_strdup.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c \
	ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putendl_fd.c ft_putnbr_fd.c ft_printf/ft_printf.c \
	ft_printf/printf_special.c ft_printf/printf_utils.c ft_printf/custom_utils.c \

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c ft_lstsize.c \
	ft_lstdelone.c ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstnth.c\

BONUS_OBJS = $(BONUS:.c=.o)
CC = 	gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = 	$(SRCS:.c=.o)
RM = 	rm -f

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

bonus: $(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re
