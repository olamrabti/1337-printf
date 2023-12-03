# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:19:37 by olamrabt          #+#    #+#              #
#    Updated: 2023/12/03 18:36:42 by olamrabt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_helpers.c ft_printf.c

NAME = libftprintf.a

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME) clean #hna clean thyd mn b3d

$(NAME): $(OBJS)
	ar -r $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	cc $(FLAGS) -c $<
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean re fclean
