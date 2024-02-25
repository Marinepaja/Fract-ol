NAME = fractol

SRC_DIR = ./src/

SRC = maths.c fractol.c main.c window.c mlx.c draw.c utils.c

SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = ./src/

OBJ = $(SRC:.c=.o)

OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

CC = cc

CFLAGS = -Wall -Wextra #-MMD -MF #-Werror -g3

RM_FLAGS = -f

#####	LIBFT  #####
LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

######	MLX   ######
MLX_FLAGS = -lX11 -lXext -lmlx

MLX_PATH = ./minilibx-linux

MLX = $(MLX_PATH)/libmlx.a

#####	RULES   #####
all: $(NAME) fractol.h

$(NAME): $(OBJS) $(MLX) $(LIBFT) fractol.h
	@$(CC) $(CFLAGS) -L$(MLX_PATH) $^ $(MLX_FLAGS) -lm -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c fractol.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "making libft..."
	@make -sC $(LIBFTDIR)
	@echo "Done !"

$(MLX):
	@echo "making MinilibX..."
	@make -sC $(MLX_PATH)
	@echo "Done !"

clean:
	@echo "cleaning libft..."
	@make -sC $(LIBFTDIR) clean
	@echo "cleaning MinilibX..."
	@make -sC $(MLX_PATH) clean
	@echo "cleaning .o files..."
	@rm $(RM_FLAGS) $(OBJS)
	@echo "Project cleaned !"

fclean: clean
	@echo "cleaning executable and libft.a"
	@make -sC $(LIBFTDIR) fclean
	@rm $(RM_FLAGS) $(NAME)
	@echo "Project fully cleaned"

re: fclean all

.PHONY: all clean fclean