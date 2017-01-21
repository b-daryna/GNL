# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 17:36:07 by dbessmer          #+#    #+#              #
#    Updated: 2016/12/22 11:31:40 by dbessmer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror
SRC =	ft_atoi.c \
		ft_itoa.c \
		ft_put{char,str,endl,nbr}.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_mem{set,cpy,ccpy,move,chr,cmp,alloc,del}.c \
		ft_bzero.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strsub.c \
		ft_strdel.c \
		ft_strnew.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strsplit.c \
		ft_to{lower,upper}.c \
		ft_is{alpha,digit,alnum,ascii,print}.c \
		ft_lst{new,map,iter,delone,del,add}.c \
		ft_lst_push_back.c \
		ft_intsize.c \
		ft_max.c \

OBJ = $(SRC:.c=.o)

HEADER = libft.h

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
