SRCS	= main.c\
		  tuples_utils.c\
		  tuples_utils2.c\
		  tuples_utils3.c\
		  f_equal.c\
		  minilibx_initialize.c\
		  minilibx_end.c\
		  minilibx_color_utils.c\
		  hook.c\
		  keypress.c\
		  tuples_colors_ops.c\
		  get_trgb_from_color.c\
		  matrices_utils.c\
		  matrices_utils2.c\
		  matrices_utils3.c\
		  matrices_utils4.c\
		  multiply_matrix_by_tuple.c\
		  ray_utils.c\
		  intersection_utils.c\
		  intersection_utils2.c\
		  intersection_utils3.c\
		  ft_atof.c\
		  check_file.c\
		  check_file2.c\
		  check_file3.c\
		  error_exit.c\
		  get_normal.c\
		  get_reflected_vector.c\
		  get_lighting_color.c\
		  free.c\
		  file_to_data.c\
		  file_to_data2.c\
		  transform_elements.c\
		  transform_camera.c\
		  free_data.c\
		  intersect_world.c\
		  view_transform.c\
		  camera_utils.c\
		  render.c\
		  is_shadowed.c\
		  create_material_and_set_transformation.c\
		  adjust_color_overflow.c\
		  color_at.c\
		  #render_sphere.c\

SRCS_B	= 

CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=thread

LIBS 	= -lmlx -lX11 -lm -lXext

HDR_DIR = includes/
SRC_DIR = src/
OBJ_DIR = obj/
LFT_PATH 	= ./libft/

OBJS	= $(addprefix $(OBJ_DIR), $(notdir $(SRCS:.c=.o)))
OBJS_B	= $(SRCS_B:.c=.o)

LIBFT 		= $(LFT_PATH)libft.a

PROG_NAME= miniRT

NAME	= $(PROG_NAME).a
NAME_B	= $(PROG_NAME)_bonus.a

#HDR	= $(PROG_NAME).h
HDR	= *.h

RM	= rm -f

all:   $(NAME)

bonus: $(NAME_B)

$(NAME): $(OBJS) $(HDR_DIR)$(HDR) $(LIBFT)
	$(RM) main_bonus.o
	ar -crs $(NAME) $(OBJS)
	$(RM) $(PROG_NAME)
#	clang -fsanitize=thread $(NAME) -o $(PROG_NAME)
	gcc $(NAME) -L $(LFT_PATH) -lft $(LIBS)  -o $(PROG_NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR_DIR)$(HDR)
#	clang $(CFLAGS) -c $< -o $@
	mkdir -p $(OBJ_DIR)
	gcc -I $(HDR_DIR) $(CFLAGS) -c $< -o $@

$(LIBFT): 
	@printf "\n$(GR)Generating Libft...$(RC)\n"
	@make -C $(LFT_PATH)
	@printf "$(GR)Libft created!$(RC)\n\n"

$(NAME_B): $(OBJS_B) $(HDR_DIR)$(HDR)
	$(RM) main.o
	ar -crs $(NAME_B) $(OBJS_B)
	$(RM) $(PROG_NAME)
	gcc $(NAME_B) -o $(PROG_NAME)

clean:
	@printf "\n$(YE)Cleaning all object files from libft...$(RC)\n"
	@make clean -C $(LFT_PATH)
	@printf "$(GR)Libft objects removed!$(RC)\n\n"
	$(RM) libft/libft.a
#	$(RM) $(OBJS)
#   $(RM) $(OBJS_B)
	$(RM) $(OBJ_DIR)*
	rmdir $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_B)
	$(RM) $(PROG_NAME)

re: fclean all

.PHONY: clean fclean re all bonus
