# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hman <hman@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/17 13:47:57 by hakaman       #+#    #+#                  #
#    Updated: 2021/03/15 17:59:11 by hman          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

# library libft
LIBFT = libft.a
LIBFT_DIR = libft

# the source, object and header files and it's directories
INCLUDE_DIR = include
SRC_DIR = src
SRC_FILES = $(addprefix $(SRC_DIR)/,\
	ft_printf.c \
	ft_conversion_builder.c \
	ft_print_conv_elem.c \
	ft_printf_utils.c \
	ft_conv_c.c \
	ft_conv_s.c \
	ft_conv_p.c \
	ft_conv_d_i.c \
	ft_conv_u.c \
	ft_conv_x_X.c \
	ft_conv_percent.c)
OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	cd $(LIBFT_DIR)/ && make
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	ar -crs $(NAME) $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#The $(info) makes sure that the output of $(shell) will not be expanded
#into the makefile. It will be redirected into stdout.
	$(info $(shell mkdir -p obj))
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@ 

clean:
	cd $(LIBFT_DIR)/ && make clean
	rm -f $(OBJ_FILES)

fclean: clean
	cd $(LIBFT_DIR)/ && make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
