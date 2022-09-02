# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 18:21:42 by duzun             #+#    #+#              #
#    Updated: 2022/09/03 00:27:09 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	server
NAME2			=	client
CFLAG			=	-Weror -Wall -Wextra -I.

CC				=	gcc
RM				=	rm -f

SRCS			=	ft_print.c \
					server.c

SRCS2			=	ft_print.c \
					client.c

					 
OBJS			= $(SRCS:%.c=%.o)
OBJS2			= $(SRCS2:%.c=%.o)

all:			$(NAME) $(NAME2)

$(NAME):		$(OBJS)
				$(CC) $(CFLAG) $(OBJS) -o $(NAME)
				
$(NAME2):		$(OBJS2)
				$(CC) $(CFLAG) $(OBJS2) -o $(NAME2)
clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS2)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(NAME2)

re:				fclean all

.PHONY:			all clean fclean re