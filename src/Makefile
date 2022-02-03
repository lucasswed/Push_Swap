# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 11:11:06 by lucas-ma          #+#    #+#              #
#    Updated: 2022/02/03 12:25:29 by lucas-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------ LIBRARY NAME ----------------------------------#

NAME	= libps.a

#----------------------------- COMMAND LINES ----------------------------------#

RM	= rm -rf
MV	= mv
MKD	= mkdir
CPY	= cp
PRINT	= printf

#------------------------------ DIRECTORIES -----------------------------------#

_SRC	=
_OBJ	=	../obj/
_LIBS	=	../libs/

#-------------------------------- COMPILER ------------------------------------#

CC	= gcc
CF	= -Wall -Wextra -Werror
AR	= ar rcs

#---------------------------------- FILES -------------------------------------#

FILES	=	algo2.c algo3.c algo5.c algo100.c ps_errors.c ps_pmoves.c ps_smoves.c ps_rmoves.c\
			algo4.c

SRCS	=		$(addprefix $(_SRC), $(FILES))
OBJS	=		$(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS))

#---------------------------------- RULES -------------------------------------#

all: $(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CF) -c $< -o $@

$(NAME): $(_LIBS) $(_LIBS)$(NAME)
$(_LIBS)$(NAME): $(_OBJ) $(OBJS)
	$(AR) $(_LIBS)$(NAME) $(OBJS)

#---------------------------- DIRECTORIES CREATION ---------------------------#

$(_OBJ):
	$(MKD) $(_OBJ)

$(_LIBS):
	$(MKD) $(_LIBS)

$(_SRC):
	$(MKD) $(_SRC)

#---------------------------------- CLEAN ------------------------------------#

clean:
		@$(RM) $(_OBJ)$(OBJS)

fclean: clean
		@$(RM) $(_LIBS)$(NAME)

#---------------------------------- REST -------------------------------------#

re:	fclean all

.PHONY: all clean fclean re