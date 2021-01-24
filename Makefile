# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 13:22:17 by ctirions          #+#    #+#              #
#    Updated: 2021/01/24 13:27:24 by ctirions         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
RESET		= $(shell tput -Txterm sgr0)

SRCS	=	$(shell ls src/ | grep -E ".+\.c")

OBJS	=	$(addprefix src/, ${SRCS:.c=.o})

NAME	=	libftprintf.a

LIBFT	=	./libft

.c.o:		
			@gcc -Wall -Wextra -Werror -c -I./ $< -o ${<:.c=.o}
			@echo "${LIGHTPURPLE}Compilation : $< --> .o${RESET}"

$(NAME):	${OBJS}
			@make full -C $(LIBFT)
			@cp libft/libft.a ./$(NAME)
			@ar -rcs ${NAME} ${OBJS}
			@ranlib $(NAME)
			@echo "${GREEN}Library done !${RESET}"

all:		${NAME}

me:			all clean

clean:
			@rm -f ${OBJS}
			@make clean -C $(LIBFT)
			@echo "${RED}Clean done !${RESET}"

fclean:		clean
			@rm -f ${NAME}
			@make fclean -C $(LIBFT)
			@echo "${RED}Fclean done !${RESET}"

re:			fclean all

.PHONY:		all clean fclean re
