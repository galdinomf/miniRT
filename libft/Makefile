SRCS_DIR=
SRCS	= ft_putnbr_fd.c\
	  ft_putendl_fd.c\
	  ft_putstr_fd.c\
	  ft_putchar_fd.c\
	  ft_striteri.c\
	  ft_strmapi.c\
	  ft_itoa.c\
	  ft_split.c\
	  ft_strtrim.c\
	  ft_strjoin.c\
	  ft_substr.c\
	  ft_strdup.c\
	  ft_calloc.c\
	  ft_atoi.c\
	  ft_strnstr.c\
	  ft_memcmp.c\
	  ft_memchr.c\
	  ft_strncmp.c\
	  ft_strnrcmp.c\
	  ft_strrchr.c\
	  ft_strchr.c\
	  ft_tolower.c\
	  ft_toupper.c\
	  ft_strlcat.c\
	  ft_strlcpy.c\
	  ft_memmove.c\
	  ft_memcpy.c\
	  ft_bzero.c\
	  ft_memset.c\
	  ft_isprint.c\
	  ft_isascii.c\
	  ft_isalnum.c\
	  ft_isdigit.c\
	  ft_isalpha.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_strcmp.c\
	  ft_strlen.c\
	  ft_swap.c\
	  ft_get_next_line.c\
	  ft_get_next_line_utils.c\
	  ft_lstnew.c\
	  ft_lstsize.c\
	  ft_lstclear.c\
	  ft_lstadd_back.c\
	  ft_lstlast.c\
	  ft_lstdelone.c\

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(addprefix $(SRCS_DIR), $(SRCS:.c=.o))

B_DIR	=

SRCS_B	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
	  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS_B	= $(addprefix $(B_DIR), $(SRCS_B:.c=.o))

NAME	= libft.a

HDR	= libft.h

RM	= rm -f

all:	$(NAME)

$(NAME): $(OBJS) $(HDR)
	ar -crs $(NAME) $(OBJS)

%.o: %.c $(HDR_DIR)$(HDR)
	gcc $(CFLAGS) -c $< -o $@

so:
	gcc -nostartfiles -fPIC $(CFLAGS) $(addprefix $(SRCS_DIR), $(SRCS))
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_B)

bonus: $(OBJS_B) $(HDR)
	ar -crs $(NAME) $(OBJS_B)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus
