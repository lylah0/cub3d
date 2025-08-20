# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/20 16:50:37 by lylrandr          #+#    #+#              #
#    Updated: 2025/08/20 16:50:38 by lylrandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

SRC_DIR = src
SRC = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJDIR = obj
OBJS = $(SRC:$(SRC_DIR)/%.c=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)

# Gestion de libft
LIBFT_PATH = lib
LIBFT = $(LIBFT_PATH)/libft.a

# Détection OS pour MLX
UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)   # macOS
MLX_DIR   = minilibx-mac
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MLX_LIB   = $(MLX_DIR)/libmlx.a
else                      # Linux
MLX_DIR   = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_LIB   = $(MLX_DIR)/libmlx.a
endif

# Includes (projet + MLX)
CFLAGS  += -Iinclude -I$(MLX_DIR)
LDFLAGS += $(MLX_FLAGS)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	@$(CC) $(OBJS) -o $@ $(CFLAGS) -L$(LIBFT_PATH) -lft $(LDFLAGS)

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_PATH)

$(MLX_LIB):
	@$(MAKE) -s -C $(MLX_DIR)

$(OBJDIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -MMD -c $< -o $@

-include $(DEPS)

clean:
	@rm -f $(OBJS) $(DEPS)
	@$(MAKE) clean -s -C $(LIBFT_PATH)
	@[ -d "$(MLX_DIR)" ] && $(MAKE) clean -s -C $(MLX_DIR) || true

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@$(MAKE) fclean -s -C $(LIBFT_PATH)

re: fclean all

leaks: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(NAME)

.PHONY: all clean fclean re leaks helgrind
