NAME = minitalk
CLIENT = client
SERVER = server

CFLAGS = -Wall -Wextra -Werror 

SRC_SRV = src/server.c 
SRC_CLNT = src/client.c 
	
OBJS_SRV = $(SRC_SRV:.c=.o) 
DEPS_SRV = $(SRC_SRV:.c=.d)

OBJS_CLT = $(SRC_CLNT:.c=.o) 
DEPS_CLT = $(SRC_CLNT:.c=.d)

RM = rm -f

MTLK = libs/mini_talk.h
LIBFT_DIR = libs/MyLibft
LIBFT =  libs/MyLibft/libft.a
LIBS = $(MTLK) ##$(LIBFT)
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m

%.o: %.c $(MTLK) Makefile
	@$(CC) $(CFLAGS) -MMD -g -I./ -c $< -o $@

all:
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) $(SERVER)
	@$(MAKE) $(CLIENT)
	

$(SERVER):: $(OBJS_SRV)
	@$(CC) $(OBJS_SRV) $(LIBFT) -o $@
	@echo "$(GREEN)Server compiled$(NC)"

$(CLIENT):: $(OBJS_CLT)
	@$(CC) $(OBJS_CLT) $(LIBFT) -o $@
	@echo "$(GREEN)Client compiled$(NC)"

$(NAME)::
	@echo -n
	
clean:
	@$(RM) $(OBJS_SRV) $(DEPS_SRV) $(OBJS_CLT) $(DEPS_CLT) $(OBJBONUS) $(DEPBONUS)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(RED)\nCleaned all files succesfully\n$(NC)"

fclean: clean
	@$(RM) $(NAME) $(SERVER) $(CLIENT) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
-include $(DEPBONUS)
