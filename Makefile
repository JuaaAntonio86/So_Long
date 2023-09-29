# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-anm <juan-anm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 16:17:44 by juanantonio       #+#    #+#              #
#    Updated: 2023/09/29 14:28:08 by juan-anm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -MMD 

SRC = 	src/main.c src/map_check.c src/path_find.c src/events.c \
		src/plot_map.c src/move.c

OBJS = $(SRC:.c=.o)
DEPS = $(SRC:.c=.d)

RM = rm -rf

MLX = Libs/mlx
LIBFT = Libs/MyLibft
LIBS = Libs/MyLibft/libft.a Libs/mlx/libmlx.a


GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

$(OBJ_DIR)%.o: $(SRC_DIR)%.c Makefile
	@$(CC) $(CFLAGS) -g -I./ -c $< -o $@

all:
	@$(MAKE) -C $(LIBFT) --no-print-directory
	@$(MAKE) -C $(MLX) --no-print-directory
	@$(MAKE) $(NAME) --no-print-directory
	

$(NAME):: $(OBJS)
	
	@$(CC) -framework OpenGL -framework Appkit $(CFLAGS) $(OBJS) $(LIBS) -o $@
	@echo "$(GREEN)so_long compiled$(NC)"

$(NAME)::
	@echo -n

clean:
	@$(RM) $(OBJS) $(DEPS) --no-print-directory
	@$(MAKE) clean -C  $(MLX) --no-print-directory
	@$(MAKE) clean -C  $(LIBFT) --no-print-directory
	@echo "$(GREEN)All Files Deleted Successfully$(NC)"

fclean: clean
	@$(RM) $(NAME) $(LIBS) 

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)