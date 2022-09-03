# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 18:21:42 by duzun             #+#    #+#              #
#    Updated: 2022/09/03 05:05:28 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	server
NAME2			=	client
NAMEB			=	server_bonus
NAMEB2			=	client_bonus
CFLAG			=	-Weror -Wall -Wextra -I.

CC				=	gcc
RM				=	rm -f

SRCS			=	ft_print.c \
					server.c

SRCS2			=	ft_print.c \
					client.c

SRCSB			=	ft_print.c \
					server_bonus.c

SRCSB2			=	ft_print.c \
					client_bonus.c

					 
OBJS			= $(SRCS:%.c=%.o)
OBJS2			= $(SRCS2:%.c=%.o)
OBJSB			= $(SRCSB:%.c=%.o)
OBJSB2			= $(SRCSB2:%.c=%.o)

all:			$(NAME) $(NAME2) $(NAMEB) $(NAMEB2) 

$(NAME):		$(OBJS)
				$(CC) $(CFLAG) $(OBJS) -o $(NAME)
				
$(NAME2):		$(OBJS2)
				$(CC) $(CFLAG) $(OBJS2) -o $(NAME2)
				
$(NAMEB):		$(OBJSB)
				$(CC) $(CFLAG) $(OBJSB) -o $(NAMEB)
				
$(NAMEB2):		$(OBJSB2)
				$(CC) $(CFLAG) $(OBJSB2) -o $(NAMEB2)				
clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS2)
				$(RM) $(OBJSB)
				$(RM) $(OBJSB2)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(NAME2)
				$(RM) $(NAMEB)
				$(RM) $(NAMEB2)

re:				fclean all

.PHONY:			all clean fclean re