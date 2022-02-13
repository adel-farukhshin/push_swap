
NAME = push_swap

SRCS =	ft_atoi.c ft_isdigit.c push_swap.c check.c stack.c list_functions.c\

OBJS = ${patsubst %.c,%.o,${SRCS}}


D_FILES = ${patsubst %.c,%.d,${SRCS}}


FLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

%.o : %.c
	cc ${FLAGS} -c $< -o $@ -MMD

all : ${NAME}

bonus : ${OBJSB}
	ar rc ${NAME} $?

${NAME} : ${OBJS} 
	${CC} ${LDFLAGS} $^ -o $@



include ${wildcard ${D_FILES}}
include ${wildcard ${D_FILESB}}

clean :
	rm -f ${OBJS} ${D_FILES}
	rm -f ${OBJSB} ${D_FILESB}
	
fclean : clean
	rm -f ${NAME}
		
re: fclean all

.PHONY: all clean fclean re bonus
