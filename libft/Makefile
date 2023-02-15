F_NONE			= \033[37;0m
F_BOLD			= \033[1m
F_ORANGE		= \033[38m
F_RED			= \033[31m
F_YELLOW		= \033[33m
F_GREEN			= \033[32m
F_CYAN			= \033[36m
F_BLUE			= \033[34m

NAME	= libft.a

SRCS	= ft_atoi.c ft_bzero.c ft_calloc.c \
		  ft_isalnum.c ft_isalpha.c ft_isascii.c \
		  ft_isdigit.c ft_isprint.c ft_itoa.c \
		  ft_memchr.c ft_memcmp.c ft_memcpy.c \
		  ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		  ft_strchr.c ft_strdup.c ft_striteri.c \
		  ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		  ft_strlen.c ft_strmapi.c ft_strncmp.c \
		  ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		  ft_substr.c ft_tolower.c ft_toupper.c \
		  ft_memmove.c ft_lstlast.c

BONUS   = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		  ft_lstclear.c ft_lstiter.c ft_lstmap.c

INC		= libft.h

OBJS	= ${SRCS:.c=.o}

OBJB	= ${BONUS:.c=.o}


CC		= @gcc
CFLAGS	= -Wall -Werror -Wextra -g

AR		= @ar rc
RM		= @rm -f


${NAME}:	${OBJS} ${INC}
			${AR} ${NAME} ${OBJS}
			@echo "$(F_GREEN)$(F_BOLD) $(NAME) library is compiled.$(F_NONE)"

all:		${NAME}

bonus:		${OBJB} ${OBJS} ${INC}
			${AR} ${NAME} ${OBJS} ${OBJB}

clean:		
			${RM} ${OBJS} ${OBJB}
			@echo "$(F_CYAN)$(F_BOLD) [$(NAME)] .o files successfully deleted.$(F_NONE)"

fclean:		clean
			${RM} ${NAME}
			@echo "$(F_CYAN)$(F_BOLD) $(NAME) library successfully deleted.$(F_NONE)"

re:			fclean all

.PHONY:		all fclean clean re bonus
