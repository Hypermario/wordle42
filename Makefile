# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmolvaut <jmolvaut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 12:55:14 by jmolvaut          #+#    #+#              #
#    Updated: 2022/05/14 16:39:10 by jmolvaut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= wordle
# **************************************************************************** #
#                                   DIRS                                       #
# **************************************************************************** #
SRC_DIR		= ./srcs/
OBJ_DIR		= ./objs/
SCRIPTS		= ./scripts
# **************************************************************************** #
#                                   FILES                                      #
# **************************************************************************** #
SRC 		= main.c parsing.c image.c events.c render.c utils.c word.c		\
			  dict.c 														\

SRCS		= ${addprefix ${SRC_DIR}, ${SRC}}
OBJS		= ${addprefix ${OBJ_DIR}, ${SRC:.c=.o}}
# **************************************************************************** #
#                                COMPILATION                                   #
# **************************************************************************** #
CC			= clang

# * FLAGS ***************************** #
CFLAGS		= -Wall -Wextra -Werror
LIBS		= -lXext -lX11 -lm -L${LIBFT} -lft -L${LIBMLX} -lmlx
INCLUDES	= -I${LIBFT_SRCS} -I${LIBMLX_SRCS}
# ************************************* #

${OBJ_DIR}%.o: ${SRC_DIR}%.c
			@${ECHO} -ne "${CLR_LINE}Compiling $<\r"
			@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
# **************************************************************************** #
#                                   GLOBAL                                     #
# **************************************************************************** #
all:		${LIBFTA} ${LIBMLXA} ${NAME}

clean:
			@${RM} ${OBJS} ${OBJS_BONUS}
			@make -sC ${LIBFT} clean
			@make -sC ${LIBMLX} clean
			@${ECHO} "Cleaned all .o files."

fclean:
			@${RM} ${OBJS} ${OBJS_BONUS}
			@make -sC ${LIBFT} clean
			@make -sC ${LIBMLX} clean
			@${RM} ${NAME_B} ${NAME} ${LIBFTA} ${LIBMLXA}
			@${ECHO} "Cleaned all files."

re:			fclean all
# **************************************************************************** #
#                                   LIBFT                                      #
# **************************************************************************** #
LIBFT		= ./libft
LIBFT_SRCS	= ${LIBFT}/srcs
LIBFTA		= ${LIBFT}/libft.a

${LIBFTA}:
			@make -sC ${LIBFT}
# **************************************************************************** #
#                                  LIBMLX                                      #
# **************************************************************************** #
LIBMLX		= ./mlx_linux
LIBMLX_SRCS	= ${LIBMLX}
LIBMLXA		= ${LIBMLX}/libmlx_Linux.a

${LIBMLXA}:
			@make -sC ${LIBMLX}
# **************************************************************************** #
#                                    NAME                                      #
# **************************************************************************** #
${OBJ_DIR}:
			@mkdir ${OBJ_DIR}

${NAME}:	${OBJ_DIR} ${LIBFTA} ${LIBMLXA} ${OBJS}
			@${CC} ${CFLAGS} ${INCLUDES} -o ${NAME} ${OBJS} ${LIBS}
			@${ECHO} -e "${CLR_LINE}${NAME} compiled."

${NAME}_clean:
			@${RM} ${OBJS}
			@${ECHO} "Cleaned ${NAME} .o files."

${NAME}_fclean:
			@${RM} ${OBJS} ${NAME} ${LIBFTA} ${LIBMLXA}
			@${ECHO} "Cleaned ${NAME} files."

${NAME}_re:	${NAME}_fclean ${NAME}
# **************************************************************************** #
#                                   MISC                                       #
# **************************************************************************** #
ECHO		= /bin/echo
CLR_LINE	= \033[2K

debug:		${LIBFTA}
			${CC} ${CFLAGS} -g3 ${INCLUDES} -o ${NAME} ${SRCS} ${LIBS}
			lldb ${NAME}

git:		fclean
			@bash ~/shell_scripts/speedgit.sh
# **************************************************************************** #
#                                                                              #
# **************************************************************************** #
.PHONY: 	all clean fclean re debug git
