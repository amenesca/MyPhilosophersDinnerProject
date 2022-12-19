# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amenesca <amenesca@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 18:31:35 by amenesca          #+#    #+#              #
#    Updated: 2022/12/19 18:31:37 by amenesca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS		= ./srcs/main.c ./srcs/threat_args.c ./srcs/functionaux.c ./srcs/routine.c ./srcs/tasks.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Wextra -Werror

PTRHEAD		= -pthread

RM			= rm -rf

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./includes

$(NAME):	$(OBJS)
			cc $(CFLAGS) $(PTHREAD) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
