F_NONE			= \033[37;0m
F_BOLD			= \033[1m
F_ORANGE		= \033[38m
F_RED			= \033[31m
F_YELLOW		= \033[33m
F_GREEN			= \033[32m
F_CYAN			= \033[36m
F_BLUE			= \033[34m


ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

CC			= @gcc
CFLAGS		= -Wall -Wextra -Werror -g -fPIC
LIGHTFLAGS	= -Wall -Wextra -Werror -g

NAME		= libft_malloc_$(HOSTTYPE).so
TEST		= test_malloc

SRCS		= malloc.c realloc.c free.c utils.c display.c mini_libft.c
SRCS_TEST	= test.c
INCLUDES	= libft_malloc.h

OBJ			= $(SRCS:.c=.o)


all: $(NAME)


$(NAME): $(OBJ) $(INCLUDES)
	@$(CC) -shared -o $(NAME) $(OBJ)
	ln -fs $(NAME) libft_malloc.so
	@echo "$(F_GREEN)$(F_BOLD) $(NAME) library is compiled.$(F_NONE)"

test:
	@$(CC) $(LIGHTFLAGS) $(SRCS_TEST) -L. -lft_malloc -o $(TEST) $(OBJ_TEST)
	export LD_LIBRARY_PATH=.
	@echo "$(F_GREEN)$(F_BOLD) $(TEST) is compiled.$(F_NONE)"

clean:
	@rm -rf $(OBJ) 
	@echo "$(F_CYAN)$(F_BOLD) .o files successfully deleted.$(F_NONE)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf libft_malloc.so
	@rm -rf test_malloc
	@echo "$(F_CYAN)$(F_BOLD) $(NAME) library successfully deleted.$(F_NONE)"

re: fclean all

.PHONY: all clean fclean re test