# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aprosper <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/31 11:19:15 by aprosper          #+#    #+#              #
#    Updated: 2022/07/31 11:19:30 by aprosper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Werror -Wall -Wextra

INCLUDES = srcs/minitalk.h

LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)

SRCS = \
	srcs/server.c \
	srcs/client.c

OBJS = ${SRCS:c=o}

all : $(LIBFT) $(SERVER) $(CLIENT)

$(SERVER) : srcs/server.o
	$(CC) $(CFLAGS) srcs/server.c $(LIBFT_FILE) -o $@

$(CLIENT) : srcs/client.o
	$(CC) $(CFLAGS) srcs/client.c $(LIBFT_FILE) -o $@

srcs/%server.o : srcs/server.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

srcs/%client.o : srcs/client.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

clean :
	@rm -f $(OBJS)
	@make clean -C libft

fclean : clean
	@rm -f client
	@rm -f server

big_clean : fclean $(LIBFT_FILE)_fclean

re : big_clean all


# Libft
$(LIBFT) : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make -C $(LIBFT_DIR)

$(LIBFT_FILE)_fclean :
	@make -C $(LIBFT_DIR) fclean

.PHONY : all clean fclean big_clean re
