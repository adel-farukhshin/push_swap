
NAME = push_swap

SRCS =	ft_atoi.c ft_isdigit.c push_swap.c check.c stack.c list_functions.c \
		s_printf.c check_sort.c sort.c cmds1.c fill_b.c perform.c score.c sort_five.c \
		check_dup_l.c

OBJS = ${patsubst %.c,%.o,${SRCS}}


D_FILES = ${patsubst %.c,%.d,${SRCS}}

LIBDIR = "../ft_printf"
LIB = "ftprintf"

FLAGS = -Wall -Wextra -Werror

HEADER = push_swap.h

%.o : %.c
	cc ${FLAGS} -c $< -o $@ -MMD

all : ${NAME}

bonus : ${OBJSB}
	ar rc ${NAME} $?

${NAME} : ${OBJS} 
	${CC} ${LDFLAGS} $^ -o $@ -L. -l${LIB}



include ${wildcard ${D_FILES}}
include ${wildcard ${D_FILESB}}

clean :
	rm -f ${OBJS} ${D_FILES}
	rm -f ${OBJSB} ${D_FILESB}
	
fclean : clean
	rm -f ${NAME}
		
re: fclean all

.PHONY: all clean fclean re bonus
