# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cschuijt <cschuijt@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/05/30 22:19:09 by cschuijt      #+#    #+#                  #
#    Updated: 2023/05/30 22:19:09 by cschuijt      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME 			    := account_test
UNAME_S				:= $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
	CC				:= c++
else
	CC				:= gcc
endif
ifeq ($(UNAME_S), Darwin)
	COMPIL_FLAGS	?= -Wall -Wextra -Werror -std=c++98
else
	COMPIL_FLAGS	?= -Wall -Wextra -Werror -std=c++98 -lstdc++
endif
INCLUDE_FLAGS		?= 

SOURCEFILES	:=	tests.cpp \
				Account.cpp
				

HEADER	:=	Account.hpp

OFILES	:=	$(SOURCEFILES:.cpp=.o)
# SRC_DIR	:=	src
OBJ_DIR	:=	obj
OBJS	:=	$(addprefix $(OBJ_DIR), $(addprefix /, $(OFILES)))

all : $(NAME)

$(NAME) : $(OBJS)
	@printf "$(COMP_BEFORE)$(C_LGREEN)$@$(COMP_AFTER)"
	@$(CC) $(OBJS) $(COMPIL_FLAGS) -o $@ $(INCLUDE_FLAGS)
	@printf "$(COMP_DONE)"

$(OBJ_DIR)/%.o : %.cpp $(HEADER) | $(OBJ_DIR)
	@printf "$(COMP_BEFORE)$(notdir $<)$(COMP_AFTER)"
	@$(CC) $(COMPIL_FLAGS) -o $@ -c $< $(INCLUDE_FLAGS)
	@printf "$(COMP_DONE)"

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

clean :
	@rm -rf $(OBJ_DIR)
	@printf "$(C_RED)Files cleaned\n$(C_RESET)"

fclean : clean
	@rm -f $(NAME)

re : fclean all

.phony : clean fclean all re

# Fancy shmancy

COMP_BEFORE = $(C_ORANGE)Compiling: $(C_CYAN)$(C_BOLD)
COMP_AFTER  = $(C_RESET)$(C_ORANGE)... $(C_RESET)
COMP_DONE   = $(C_GREEN)(Done!)$(C_RESET)\n

C_RED		  = \e[38;2;255;0;0m
C_ORANGE	= \e[38;2;255;128;0m
C_LGREEN	= \e[38;2;128;255;128m
C_GREEN		= \e[38;2;0;255;0m
C_CYAN		= \e[38;2;0;255;255m

C_RESET	  = \e[0m
C_BOLD	  = \e[1m
