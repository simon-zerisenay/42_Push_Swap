# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: szerisen <szerisen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 15:48:15 by szerisen          #+#    #+#              #
#    Updated: 2023/03/25 15:57:09 by szerisen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

MANDATORY_SRCS = ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c  ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c\
					ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c\
					ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_calloc.c ft_strdup.c\
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
					ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c utils.c ft_printf.c get_next_line.c \
					get_next_line_utils.c 
		
BONUS_SRCS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c 	


M_OBJS = $(MANDATORY_SRCS:.c=.o)
B_OBJS = $(BONUS_SRCS:.c=.o)

LIBCR   = ar -rc
CC      = cc
RM      = rm -f
CFLAGS  = -Wall -Wextra -Werror 

all: $(NAME)

.c.o: 
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME): $(M_OBJS)
	@$(LIBCR) $(NAME) $(M_OBJS)
	
clean:
	@$(RM) $(M_OBJS) $(B_OBJS)

fclean: clean
		@$(RM) $(NAME)

re: fclean  all

bonus: $(M_OBJS) $(B_OBJS)
	$(LIBCR) $(NAME) $(M_OBJS) $(B_OBJS)
