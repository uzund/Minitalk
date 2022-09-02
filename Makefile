# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: duzun <davut@uzun.ist>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/02 18:21:42 by duzun             #+#    #+#              #
#    Updated: 2022/09/03 00:04:11 by duzun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minitalk.a

CFLAG			=	-Weror -Wall -Wextra -I.

CC				=	gcc
RM				=	rm -f

SRCS			=	ft_print.c \
					server.c

SRCS2			=	ft_print.c \
					client.c

					 
OBJS			= $(SRCS:.c=.o)
OBJS2			= $(SRCS2:.C=.0)

$(NAME):		$(OBJS)
				ar rc $(NAME) $(OBJS)
				
$(NAME2):		$(OBJS2)
				ar rc $(NAME2) $(OBJS2) 
			
all:			$(NAME) $(NAME2)

clean:
				$(RM) $(OBJS)
				$(RM) $(OBJS2)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(NAME2)

re:				fclean $(NAME) $(NAME2)

.PHONY:			all clean fclean re
