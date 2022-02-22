# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas-ma <lucas-ma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 15:07:52 by lucas-ma          #+#    #+#              #
#    Updated: 2022/02/22 16:12:14 by lucas-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################ PROGRAM ################

NAME    =        push_swap
NAME_BONUS =	 checker

################ TERMINAL ###############

RMV        =        rm -f
MKD        =        mkdir
PRT        =        printf
MKE        =        make
CPY        =        cp

################# COLORS ################

--GRN    =        \033[32m
--RED    =        \033[31m
--WHT    =        \033[39m

################# DIRS ##################

_SRC    =        src/
_OBJ 	=		 obj/
_LIB    =        libs/
_BIN    =        ./

############### COMPILER ################

CC        =        gcc
CF        =        -Wall -Werror -Wextra

################ FILES ##################

SRCS    =        $(_SRC)ps_main.c
SRCS_BONUS	=	 $(_SRC)checker.c $(_SRC)checker_moves.c $(_SRC)get_next_line.c $(_SRC)get_next_line_utils.c
OBJS    =        $(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS))
OBJS_BONUS	=	 $(patsubst $(_SRC)%.c,$(_OBJ)%.o,$(SRCS_BONUS))
DEPS    =        libft.a libps.a
LIBS    =        -lft -lps

################ RULES ##################

all: deps $(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CF) -c $< -o $@

$(_BIN)$(NAME): deps $(OBJS)
	$(CC) $(CF) $(LIBS) $(OBJS) -o $@ -L $(_LIB)

bonus: deps $(OBJS_BONUS) all
	$(CC) $(CF) $(LIBS) $(OBJS_BONUS) -o $(NAME_BONUS) -L $(_LIB)

################ DEPS ###################

deps: $(DEPS)

libft.a:
	$(MKE) bonus -C libft/

libps.a:
	$(MKE) libps.a -C src/

############## STRUCTURE ################

$(_OBJ):
	$(MKD) $(_OBJ)

$(_LIB):
	$(MKD) $(_LIB)

$(_SRC):
	$(MKD) $(_SRC)

$(_BIN):
	$(MKD) $(_BIN)

################### CLEAN ###############

clean:
	$(RMV) -r $(_OBJ)

fclean: clean
	$(RMV) -r $(NAME)
	$(RMV) -r $(NAME_BONUS)
	$(RMV) -r $(_LIB)

re: fclean all

rebonus: fclean bonus

.PHONY: all deps clean fclean re 
