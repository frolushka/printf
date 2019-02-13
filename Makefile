# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbednar <sbednar@student.fr.42>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/31 20:35:25 by sbednar           #+#    #+#              #
#    Updated: 2019/01/08 16:34:24 by sbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

SRC_DIR		=	./src
OBJ_DIR		=	./obj
INC_DIR		=	./inc

SRC_FT_DIR	=	$(addprefix $(SRC_DIR)/,libft)

SRC_FT		=	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strdup.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strnchr.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_memalloc.c \
				ft_memdel.c \
				ft_strnew.c \
				ft_strdel.c \
				ft_strclr.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_strsub.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strsplit.c \
				ft_itoa.c \
				ft_ltoa.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstadd_back.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_islower.c \
				ft_isupper.c \
				ft_isstn.c \
				ft_putwchar.c \
				ft_putwchar_fd.c \
				ft_strallcpy.c \
				ft_nbrlen.c \
				ft_wordlen.c \
				ft_wordscnt.c \
				ft_strsfree.c \
				ft_lstdels.c \
				ft_lstdelones.c \
				ft_ultoa_base.c \
				ft_strlow.c \
				get_next_line.c
OBJ_FT		=	$(addprefix $(OBJ_DIR)/,$(SRC_FT:.c=.o))

SRC			= 	ft_printf.c \
				parse_convers.c \
				parse_flags.c \
				print_percent.c \
				print_char.c \
				print_string.c \
				print_address.c \
				print_null.c \
				print_number.c \
				print_unumber.c \
				print_wchar.c \
				print_wstring.c
OBJ			=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC			=	gcc
#CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		=	-g

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FT) $(OBJ)
	ar rcs $(NAME) $(OBJ_FT) $(OBJ)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_FT_DIR)/%.c
	$(CC) -o3 $(CFLAGS) -I$(INC_DIR) -o $@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	$(CC) -o3 $(CFLAGS) -I$(INC_DIR) -o $@ -c $<

debug: all
	$(CC) $(CFLAGS) src/main.c -I$(INC_DIR) -L. -lftprintf

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -rf a.out.dSYM
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re