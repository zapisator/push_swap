# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 11:10:49 by ftothmur          #+#    #+#              #
#    Updated: 2019/10/07 19:00:50 by ftothmur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------MISC--------------------------------------#
.PHONY:				all lib clean clean_this fclean fclean_this re

NAME			=	$(NAME_DIR)push_swap
LIB				=	libft.a
HEADER			=	$(NAME_HDR_DIR)checker.h
#---------------------------------DIRECTORIES----------------------------------#
NAME_DIR		=	../
LIB_DIR			=	../libft/
LIB_HDR_DIR		=	../libft/
NAME_HDR_DIR	=	../includes/
SRC_CALC_DIR	=	./
SRC_UTIL_DIR	=	../utils/
#---------------------------------SOURCE_FILES---------------------------------#
SRC_CALC		=	push_swap.c make_calculations.c calculations.c \
					common_initial_push_to_b.c operation_counter.c
SRC_UTIL		=	print.c make_stacks.c fill_nbrs.c check_input.c \
					commands.c command_dispatcher.c
SRC				=	$(addprefix $(SRC_UTIL_DIR), $(SRC_UTIL)) \
					$(addprefix $(SRC_CALC_DIR), $(SRC_CALC))
OBJ				=	$(SRC:.c=.o)
#-------------------------------COMPILER_OPTIONS-------------------------------#
LIB_FLAGS		=	-L $(LIB_DIR) -lft
LIB_HDR_FLAGS	=	-I $(LIB_HDR_DIR)
NAME_HDR_FLAGS	=	-I $(NAME_HDR_DIR)
LLVM_FLAGS		=	-Wall -Wextra -Werror
DEBUG_FLAG		=	-g
OUT_NAME_FLAG	=	-o
OBJ_FLAG		=	-c
ifeq ($(DEBUG), 0)
	CC_FLAGS	=	$(LLVM_FLAGS) $(DEBUG_FLAG)
else
	CC_FLAGS	=	$(LLVM_FLAGS)
endif
#------------------------------------RULES-------------------------------------#
all:				$(NAME)

$(NAME):			$(HEADER) $(LIB_DIR)$(LIB) $(OBJ)
					gcc $(OUT_NAME_FLAG) $@ \
	$(OBJ) \
	$(LIB_HDR_FLAGS) $(NAME_HDR_FLAGS) \
	$(LIB_FLAGS) $(CC_FLAGS)

%.o:				%.c
					gcc $(OBJ_FLAG) $(CC_FLAGS) $^ \
	$(NAME_HDR_FLAGS) $(LIB_HDR_FLAGS) -o $@

$(LIB_DIR)$(LIB):	lib

lib:
					make -C $(LIB_DIR)

clean:
					/bin/rm -f $(OBJ)
					make clean -C $(LIB_DIR)

clean_this:
					/bin/rm -f $(OBJ)

fclean:				clean
					/bin/rm -f $(NAME)
					make fclean -C $(LIB_DIR)

fclean_this:		clean_this
					/bin/rm -f $(NAME)

re:					fclean all
