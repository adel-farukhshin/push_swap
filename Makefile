
NAME = push_swap
BONUSNAME = my_checker

SRCS =	ft_atoi.c ft_isdigit.c push_swap.c check.c stack.c list_functions.c \
		s_printf.c check_sort.c sort.c cmds1.c cmds2.c fill_b.c perform.c score.c sort_five.c \

SRCSB = checker.c check.c ft_atoi.c ft_isdigit.c stack.c list_functions.c s_printf.c \


OBJS = $(addprefix $(OBJSDIR),$(SRCS:.c=.o))
OBJSB = $(addprefix $(BONUSDIR),$(SRCSB:.c=.o))


CFLAGS = -Wall -Wextra -Werror

D_FILES = ${patsubst %.c,%.d,${SRCS}}
D_FILESB = ${patsubst %.c,%.d,${SRCSB}}

LIBDIR = "../ft_printf"
LIB = "ftprintf"

SRCSDIR = ./srcs/
OBJSDIR = ./objs/
INCSDIR = ./incs/
BONUSDIR = ./bonus/

HEADER = push_swap.h

${OBJSDIR}%.o : ${SRCSDIR}%.c
	cc ${CFLAGS} -c $< -I${INCSDIR} -o $@ -MMD

${BONUSSDIR}%.o : ${BONUSDIR}%.c
	cc ${CFLAGS} -c $< -I${BONUSDIR} -o $@ -MMD

all : ${NAME}

${NAME} : ${OBJS} 
	${CC} ${LDFLAGS} $^ -o $@ -L. -l${LIB}

bonus : ${OBJSB}
	${CC} ${LDFLAGS} $^ -o ${BONUSNAME} -L. -l${LIB}


include ${wildcard ${D_FILES}}
include ${wildcard ${D_FILESB}}

clean :
	rm -f ${OBJS} $(addprefix $(OBJSDIR),$(D_FILES))
	rm -f ${OBJSB} $(addprefix $(BONUSDIR),$(D_FILESB))
	
fclean : clean
	rm -f ${NAME}
	rm -f ${BONUSNAME}
		
re: fclean all

.PHONY: all clean fclean re bonus
