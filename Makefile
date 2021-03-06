NAME = 42sh

TESTING = shell42.test

CC = gcc

SRC_DIR = src

CFLAGS  = -Wall -Werror -Wextra -g
#-fsanitize=address

INCL = -I incl

MINILIB = ./mini_lib/

SRC_DIR = srcs
SRC_FILES = main.c          \
			cd.c            \
			dispatch.c      \
			echo.c          \
			env.c           \
			inhibitors.c    \
			init.c          \
			jobs.c          \
			logical.c       \
			pipes.c         \
			redirect.c      \
			scripts.c       \
			quit.c          \
			print.c         \
			parser.c        \
			subshell.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

RM = rm -fr

$(NAME):
		$(MAKE) -C $(MINILIB) re
		$(CC) $(CFLAGS) $(INCL) $(SRC) $(MINILIB)/mini_lib.a -o $(NAME)

$(TESTING):
		$(MAKE) -C $(MINILIB) re
		$(CC) $(CFLAGS) $(INCL) $(SRC) $(MINILIB)/mini_lib.a -D TESTING -o $(NAME)

all: $(NAME)

test: $(TESTING)

clean:
		$(RM) $(OBJDIR)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)