# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/05 11:10:49 by ftothmur          #+#    #+#              #
#    Updated: 2019/10/07 19:24:28 by ftothmur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------MISC--------------------------------------#
.PHONY:				all lib clean cleanm clean_lib fclean re re_lib re_all

NAME			=	../checker
LIB				=	libft.a
HEADER			=	$(NAME_HDR_DIR)checker.h
#---------------------------------DIRECTORIES----------------------------------#
NAME_DIR		=	../
LIB_DIR			=	../libft/
LIB_HDR_DIR		=	../libft/
NAME_HDR_DIR	=	../includes/
SRC_CHR_DIR		=	./
SRC_UTIL_DIR	=	../utils/
#---------------------------------SOURCE_FILES---------------------------------#
SRC_CHR			=	checker.c fill_instructions.c visualizer.c
SRC_UTIL		=	print.c make_stacks.c fill_nbrs.c check_input.c \
					commands.c command_dispatcher.c
SRC				=	$(addprefix $(SRC_UTIL_DIR), $(SRC_UTIL)) \
					$(addprefix $(SRC_CHR_DIR), $(SRC_CHR)) 
OBJ				=	$(SRC:.c=.o)
#-------------------------------COMPILER_OPTIONS-------------------------------#
LIB_FLAGS		=	-L $(LIB_DIR) -lft
LIB_HDR_FLAGS	=	-I $(LIB_HDR_DIR)
NAME_HDR_FLAGS	=	-I $(NAME_HDR_DIR)
LLVM_FLAGS		=	-Wall -Wextra -Werror
ifeq ($(DEBUG), 0)
	CC_FLAGS	=	$(LLVM_FLAGS) -g 
else
	CC_FLAGS	=	$(LLVM_FLAGS)
endif
#------------------------------------RULES-------------------------------------#
all:				$(NAME)

$(NAME):			$(HEADER) $(LIB_DIR)$(LIB) $(OBJ)
					gcc -o $@ \
	$(OBJ) \
	$(LIB_HDR_FLAGS) $(NAME_HDR_FLAGS) \
	$(LIB_FLAGS) $(CC_FLAGS)

%.o:				%.c
					gcc -c $(CC_FLAGS) $^ \
	$(NAME_HDR_FLAGS) $(LIB_HDR_FLAGS) -o $@

$(LIB_DIR)$(LIB):	lib

lib:
					make -C $(LIB_DIR)

clean:
					/bin/rm -f $(OBJ)
					make clean -C $(LIB_DIR)

fclean:				clean
					/bin/rm -f $(NAME)
					make fclean -C $(LIB_DIR)

re:					fclean all
