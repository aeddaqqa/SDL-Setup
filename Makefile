# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/25 10:38:14 by ayagoumi          #+#    #+#              #
#    Updated: 2021/01/09 09:21:55 by aeddaqqa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Executable / Libraries.

RM              = rm -rf
SDL             = libSDL2.a
TTF             = libsdl2_ttf.a
IMG				= libSDL2_image.a
MIX				= libSDL2_mixer.a
FT              = libft.a
LFTDIR			= libft
NAME            = sdl 
###########################shell 
WITH 			= $(shell tput cols)
HEIGHT			= $(shell tput lines)

BLACK        	:= $(shell tput -Txterm setaf 0)
RED          	:= $(shell tput -Txterm setaf 1)
GREEN        	:= $(shell tput -Txterm setaf 2)
YELLOW       	:= $(shell tput -Txterm setaf 3)
LIGHTPURPLE  	:= $(shell tput -Txterm setaf 4)
PURPLE       	:= $(shell tput -Txterm setaf 5)
BLUE         	:= $(shell tput -Txterm setaf 6)
WHITE        	:= $(shell tput -Txterm setaf 7)
RESET         	:= $(shell tput -Txterm setaf 9)
SPACE			:= $(shell tput -Txterm cup 20  50)
############################
INCSDIR 		:= includes
INCSDIR 		+= $(LFTDIR)
############################
SRCSDIR 		= srcs
OBJSDIR 		= objs
############################
CHILDDIR        := core
CHILDDIR		+= algebr_lin
CHILDDIR        += render
CHILDDIR        += setup
CHILDDIR        += update
###########################
INCS            := includes/setup.h
INCS            += includes/render.h
INCS            += includes/process_input.h
INCS            += includes/headers.h
INCS            += includes/define.h
INCS            += includes/structers.h
INCS            += includes/update.h
INCS			+= srcs/algebr_lin/alg.h
############################################
SRC             := core/main.c
SRC             += algebr_lin/vect3_utilfun.c
SRC             += algebr_lin/vect3_utilfunc.c
SRC             += render/main_render.c
SRC             += setup/main_setup.c
SRC             += update/main_update.c
SRC             += update/main_input.c
#############################################
UNAME := $(shell uname -s)

ifeq ($(UNAME), Darwin)
	LSDLDIR     = $(HOME)/.brew/Cellar/sdl2/2.0.14_1/lib
	LTTFDIR     = $(HOME)/.brew/Cellar/sdl2_ttf/2.0.15/lib
	LIMGDIR 	= $(HOME)/.brew/Cellar/sdl2_image/2.0.5/lib
	MIXRDIR		= $(HOME)/.brew/Cellar/sdl2_mixer/2.0.4/lib
	INCSDIR     += $(HOME)/.brew/Cellar/sdl2/2.0.14_1/include/SDL2
	INCSDIR     += $(HOME)/.brew/Cellar/sdl2_ttf/2.0.15/include/SDL2
	INCSDIR		+= $(HOME)/.brew/Cellar/sdl2_image/2.0.5/include/SDL2
	INCSDIR		+= $(HOME)/.brew/Cellar/sdl2_mixer/2.0.4/include/SDL2
else
	SDL       = libSDL2.a
	TTF       = libSDL2_ttf.a
	IMG       = libSDL2_image.a
	MIX		  = libSDL2_mixer.a
	LULIBS    = /usr/lib/x86_64-linux-gnu/
	LUINCS    = /usr/include/
	LTTFDIR	  = $(LULIBS)
	LSDLDIR	  = $(LULIBS)
	LIMGDIR	  = $(LULIBS)
	MIXRDIR	  = $(LULIBS)
	INCSDIR	  = $(LUINCS)/SDL2 
endif
########################################3Linked libraries at compile time.
LIBS			:= -L$(LSDLDIR) -lSDL2
LIBS			+= -L$(LTTFDIR) -lSDL2_ttf
LIBS			+= -L$(LIMGDIR) -lSDL2_image
LIBS			+= -L$(MIXRDIR) -lSDL2_mixer
LIBS			+= -L$(LFTDIR) -lft
LIBS			+= -lm
LIBS			+= -lz
LTTF			= $(LTTFDIR)/$(TTF)
LFT				= $(LFTDIR)/$(FT)
LSDL			= $(LSDLDIR)/$(SDL)
LTTF			= $(LTTFDIR)/$(TTF)
LIMG			= $(LIMGDIR)/$(IMG)
LMIXR			= $(MIXRDIR)/$(MIX)
D_SRCS           = $(addsuffix /, $(SRCSDIR))
DI_SRCS			 = $(foreach dir,$(CHILDDIR),$(D_SRCS)$(dir))
D_OBJS           = $(addsuffix /, $(OBJSDIR))
C_OBJS           = $(addprefix $(D_OBJS),  $(SRC:.c=.o))
C_INCS           = $(foreach include, $(INCSDIR), -I$(include))
C_CHILDDIR       = $(foreach dir, $(CHILDDIR),$(D_OBJS)$(dir))
CC              = gcc

# Compilation flags.

CFLAGS          = $(C_INCS) -Wall -Wextra -Werror
#----------------->>>>>>>>>>>>>>>>START<<<<<<<<<<<<<-------------------#

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@echo "$(PURPLE)**********>>>Compiling : $(RESET) $(LIGHTPURPLE)" $<
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJSDIR) $(C_CHILDDIR) $(NAME)


$(NAME):  $(LFT)  $(LSDL) $(LIMG) $(LTTF) $(LMIXR)  $(C_OBJS)
	@echo "$(RED)\n***********>>>Building : $(RESET)$(NAME) $(YELLOW)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(C_OBJS) $(LIBS)

print-%  : ; @echo $* = $($*)

####  make libft

$(LFT):
	@make -sC $(LFTDIR)

### creating files for object.o
$(LSDL):
	@echo "$(GREEN)***   Installing library sdl2   ...  ***\n$(RESET)"
	@brew install sdl2 > /dev/null 2>&1;

$(LTTF):
	@echo "$(GREEN)***   Installing library sdl2_ttf   ...  ***\n$(RESET)"
	@brew install sdl2_ttf > /dev/null 2>&1;

$(LIMG):
	@echo "$(GREEN)***   Installing library sdl2_image    ...  ***\n$(RESET)"
	@brew install sdl2_image > /dev/null 2>&1;
$(LMIXR):
	@echo "$(GREEN)***   Installing library sdl2_mixer    ...  ***\n$(RESET)"
	@brew install sdl2_mixer > /dev/null 2>&1;

$(OBJSDIR):
	@mkdir -p $(OBJSDIR)

$(C_CHILDDIR):
	@mkdir -p $(C_CHILDDIR)

clean:
	@make -sC $(LFTDIR) clean
	@echo "$(GREEN)**********   Deleting all object **********\n$(RESET)"
	@$(RM) $(C_OBJS)

fclean: clean
	@make -sC $(LFTDIR) fclean
	@echo "$(GREEN)**********   Done  **********\n$(RESET)"
	@$(RM) $(NAME)
	@$(RM) $(OBJSDIR)

re: fclean all
.PHONY: all clean fclean re
