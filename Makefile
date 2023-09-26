# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 16:17:44 by juanantonio       #+#    #+#              #
#    Updated: 2023/09/26 17:03:35 by juanantonio      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -MMD

SRC = src/so_long.c

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
	@$(CC) $(CFLAGS) -I./ -c $< -o $@

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
	@echo "$(RED)\ndestruction successful\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(LIBS) 

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)