# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/14 16:41:18 by lheteau           #+#    #+#              #
#    Updated: 2026/03/17 17:01:38 by lheteau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .SILENT: passer sous silent les commandes
.SILENT:
NAME_CLIENT		= client
NAME_SERVER		= server

CC = cc
SRC_SERVER = src_server/main_ser.c
SRC_CLIENT = src_client/main_client.c
OBJ_DIR = obj
OBJ_SERVER = $(addprefix $(OBJ_DIR)/,$(SRC_SERVER:.c=.o))
OBJ_CLIENT = $(addprefix $(OBJ_DIR)/,$(SRC_CLIENT:.c=.o))
CFLAGS = -Wall -Wextra -Werror -g
# -MMP pour eviter les make re et remake les fichiers modifies


LIBFT_DIR = includes/libft
FT_PRINTF_DIR = includes/ft_printf

LIBFT     = $(LIBFT_DIR)/libft.a
FT_PRINTF       = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME_SERVER) $(NAME_CLIENT)


$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)


$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(FT_PRINTF) $(LIBFT) -o $(NAME_SERVER)
	@echo "*******************"
	@echo "  SERVER COMPILE   "
	@echo "*******************"

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF)
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(FT_PRINTF) $(LIBFT) -o $(NAME_CLIENT)
	@echo "*******************"
	@echo "  CLIENT COMPILE   "
	@echo "*******************"

$(OBJ_DIR)/src_server/%.o: src_server/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@ 

$(OBJ_DIR)/src_client/%.o: src_client/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR) -c $< -o $@ 


clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJ_CLIENT)
	rm -f $(OBJ_SERVER)
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME_SERVER)
	rm -f $(NAME_CLIENT)

re: fclean all

.PHONY: all clean fclean re