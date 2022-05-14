# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 16:43:24 by jmolvaut          #+#    #+#              #
#    Updated: 2022/01/26 08:43:18by jmolvaut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

all:		${NAME}
# **************************************************************************** #
#                                   DIRS                                       #
# **************************************************************************** #
SRC_DIR		= ./srcs/
OBJ_DIR		= ./objs/
# **************************************************************************** #
#                                   FILES                                      #
# **************************************************************************** #
SRC 		= ft_argp_printf.c \
			  ft_args_printf.c \
			  ft_atoi_base.c \
			  ft_atoi.c \
			  ft_bzero.c \
			  ft_calloc.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_itoa.c \
			  ft_lstlast.c \
			  ft_lstadd_front.c \
			  ft_lstadd_back.c \
			  ft_lstclear.c \
			  ft_lstdelone.c \
			  ft_lstiter.c \
			  ft_lstmap.c \
			  ft_lstn.c \
			  ft_lstnew.c \
			  ft_lstsize.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_numlen.c \
			  ft_printf.c \
			  ft_putchar_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_putnbri_base_fd.c \
			  ft_putstr_fd.c \
			  ft_putstri_fd.c \
			  ft_putuli_base_fd.c \
			  ft_putunbr_fd.c \
			  ft_split.c \
			  ft_strchr.c \
			  ft_strdup.c \
			  ft_striteri.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strmapi.c \
			  ft_strncmp.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_strtoi.c \
			  ft_strtrim.c \
			  ft_substr.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_unumlen.c \
			  ft_wordcount.c \
			  get_next_line_utils.c \
			  get_next_line.c

SRCS		= ${addprefix ${SRC_DIR}, ${SRC}}
OBJS		= ${addprefix ${OBJ_DIR}, ${SRC:.c=.o}}
# **************************************************************************** #
#                                COMPILATION                                   #
# **************************************************************************** #
CC 			= clang

# * FLAGS ***************************** #
CFLAGS 		= -Wall -Wextra -Werror
# ************************************* #

${OBJ_DIR}%.o: ${SRC_DIR}%.c
			@${ECHO} -ne "${CLR_LINE}Compiling $<\r"
			@${CC} ${CFLAGS} -c $< -o $@
# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #
ECHO		= /bin/echo
CLR_LINE	= \033[2K

${NAME}:	${OBJ_DIR} ${OBJS}
			@ar rcs ${NAME} ${OBJS}
			@${ECHO} -e "${CLR_LINE}Libft compiled."

${OBJ_DIR}:
			@mkdir ${OBJ_DIR}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean ${NAME}
# **************************************************************************** #
#                                                                              #
# **************************************************************************** #
.PHONY: 	all clean fclean re
