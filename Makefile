SRCS	= main.c\
		  tuples_utils.c\
		  tuples_utils2.c\
		  f_equal.c\

SRCS_B	= 

CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=thread

HDR_DIR = includes/
SRC_DIR = src/
OBJ_DIR = obj/

OBJS	= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
OBJS_B	= $(SRCS_B:.c=.o)

PROG_NAME= miniRT

NAME	= $(PROG_NAME).a
NAME_B	= $(PROG_NAME)_bonus.a

HDR	= $(PROG_NAME).h

RM	= rm -f

all:   $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS) $(HDR_DIR)$(HDR)
	$(RM) main_bonus.o
	ar -crs $(NAME) $(OBJS)
	$(RM) $(PROG_NAME)
#	clang -fsanitize=thread $(NAME) -o $(PROG_NAME)
	gcc $(NAME) -o $(PROG_NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR_DIR)$(HDR)
#	clang $(CFLAGS) -c $< -o $@
	mkdir -p $(OBJ_DIR)
	gcc -I $(HDR_DIR) $(CFLAGS) -c $< -o $@

$(NAME_B): $(OBJS_B) $(HDR_DIR)$(HDR)
	$(RM) main.o
	ar -crs $(NAME_B) $(OBJS_B)
	$(RM) $(PROG_NAME)
	gcc $(NAME_B) -o $(PROG_NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJS_B)
	rmdir $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)
	$(RM) $(PROG_NAME)

re: fclean all

.PHONY: clean fclean re all bonus
