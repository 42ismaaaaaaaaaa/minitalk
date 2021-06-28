# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iouali <iouali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 16:18:33 by iouali            #+#    #+#              #
#    Updated: 2021/06/28 16:34:36 by iouali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      =   gcc

CFLAGS  = -Wall -Wextra -Werror

NAME_1 = server
NAME_O_SERVER = server.o
NAME_SERVER = server.c 

NAME_CLIENT = client.c
NAME_O_CLIENT = client.o
NAME_2 = client

OBJS    =   ${SRCS:.c=.o}

RM      = rm -f

all:        ${NAME_1} ${NAME_2}

${NAME_1}: 	${NAME_O_SERVER}
			${CC} ${CFLAGS} -o ${NAME_1} ${NAME_O_SERVER}

${NAME_2}:  ${NAME_O_CLIENT}
			${CC} ${CFLAGS} -o ${NAME_2} ${NAME_O_CLIENT}

clean:
			${RM} ${NAME_O_CLIENT} ${NAME_O_SERVER}

fclean:     clean
			${RM} ${NAME_1} ${NAME_2}

re:         fclean all

.PHONY:     all clean fclean re
