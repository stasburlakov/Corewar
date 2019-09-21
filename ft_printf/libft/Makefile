# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljonnel- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/02 17:43:31 by ljonnel-          #+#    #+#              #
#    Updated: 2019/02/20 10:00:33 by ljonnel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#*FLAGS = -Wall -Wextra -Werror*#

HEADER = libft

LIBFILES = $(SRC:.c=.o)

SRC = *.c

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) -c $(SRC) -I $(HEADER)
		@ar rc $(NAME) $(LIBFILES)
		@ranlib $(NAME)

clean:
		@rm -f $(LIBFILES)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re