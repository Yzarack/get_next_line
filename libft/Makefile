# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 17:06:40 by jthierce          #+#    #+#              #
#    Updated: 2018/12/06 16:12:12 by jthierce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILE = ft_atoi.c\
	   ft_bzero.c\
	   ft_isalnum.c\
	   ft_isalpha.c\
	   ft_isascii.c\
	   ft_isdigit.c\
	   ft_isprint.c\
	   ft_memalloc.c\
	   ft_memccpy.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_memcpy.c\
	   ft_memmove.c\
	   ft_memset.c\
	   ft_strcat.c\
	   ft_strchr.c\
	   ft_strclr.c\
	   ft_strcpy.c\
	   ft_strdup.c\
	   ft_strdel.c\
	   ft_strequ.c\
	   ft_striter.c\
	   ft_striteri.c\
	   ft_strlcat.c\
	   ft_strmap.c\
	   ft_strmapi.c\
	   ft_strncat.c\
	   ft_strncpy.c\
	   ft_strnequ.c\
	   ft_strnew.c\
	   ft_strnstr.c\
	   ft_strrchr.c\
	   ft_strstr.c\
	   ft_tolower.c\
	   ft_toupper.c\
	   ft_strlen.c\
	   ft_strsub.c\
	   ft_strtrim.c\
	   ft_strsplit.c\
	   ft_strncmp.c\
	   ft_strjoin.c\
	   ft_strcmp.c\
	   ft_putstr_fd.c\
	   ft_putstr.c\
	   ft_putnbr_fd.c\
	   ft_putnbr.c\
	   ft_putendl_fd.c\
	   ft_putendl.c\
	   ft_putchar_fd.c\
	   ft_putchar.c\
	   ft_memdel.c\
	   ft_lstnew.c\
	   ft_lstmap.c\
	   ft_lstiter.c\
	   ft_lstdelone.c\
	   ft_lstdel.c\
	   ft_lstadd.c\
	   ft_itoa.c\
	   ft_chainlistlen.c\
	   ft_lstaddend.c\
	   ft_strreversesplit.c\
	   ft_puttab.c\
	   ft_realloc.c
OBJ = $(FILE:.c=.o)
FLAG = -Wextra -Werror -Wall

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ):
	gcc $(FLAG) -c $(FILE)

.PHONY: fclean all clean re

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)
