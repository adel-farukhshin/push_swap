
NAME = push_swap

SRCS =	ft_atoi.c ft_isdigit.c push_swap.c check.c stack.c list_functions.c \
		s_printf.c check_sort.c sort.c cmds1.c cmds2.c fill_b.c perform.c score.c sort_five.c \


OBJS = $(addprefix $(OBJSDIR),$(SRCS:.c=.o))

CFLAGS = -Wall -Wextra -Werror

D_FILES = ${patsubst %.c,%.d,${SRCS}}

LIBDIR = "../ft_printf"
LIB = "ftprintf"

SRCSDIR = ./srcs/
OBJSDIR = ./objs/
INCSDIR = ./incs/

HEADER = push_swap.h

${OBJSDIR}%.o : ${SRCSDIR}%.c
	cc ${CFLAGS} -c $< -I${INCSDIR} -o $@ -MMD

all : ${NAME}

${NAME} : ${OBJS} 
	${CC} ${LDFLAGS} $^ -o $@ -L. -l${LIB}


include ${wildcard ${D_FILES}}
include ${wildcard ${D_FILESB}}

clean :
	rm -f ${OBJS} $(addprefix $(OBJSDIR),$(D_FILES))
	
fclean : clean
	rm -f ${NAME}
		
re: fclean all

.PHONY: all clean fclean re bonus
