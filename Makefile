# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 12:19:53 by jvalkama          #+#    #+#              #
#    Updated: 2025/05/13 15:29:53 by jvalkama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= minisynth

SRCDIR			:= srcs

SRCS			:= $(wildcard $(SRCDIR)/*.c)
OBJS			:= $(SRCS:%.c=%.o)

COMPILER		:= cc
CFLAGS			:= -Wall -Wextra -Werror

INC_DIR			:= includes
MINIAUDIO_PATH		:= $(INC_DIR)/miniaudio
MINIAUDIO_C		:= $(MINIAUDIO_PATH)/miniaudio.c
MINIAUDIO_O		:= $(MINIAUDIO_PATH)/miniaudio.o

INCLUDE			:= -I includes -I $(MINIAUDIO_PATH)

RM				:= rm -f

all:			$(NAME)

$(MINIAUDIO_PATH):
				git clone https://github.com/mackron/miniaudio.git $(MINIAUDIO_PATH)

$(MINIAUDIO_O):		$(MINIAUDIO_C) $(MINIAUDIO_PATH)
				$(COMPILER) $(CFLAGS) -c $< -o $@ -g

$(NAME):		$(OBJS) $(MINIAUDIO_O)
				@echo "Linking $@"
				$(COMPILER) $(CFLAGS) $(OBJS) $(MINIAUDIO_O) -o $@ -g

%.o:			%.c $(MINIAUDIO_PATH)
				@echo "Compiling $<"
				$(COMPILER) $(CFLAGS) $(INCLUDE) -c $< -o $@ -g

clean:
				@echo "Cleaning object files"
				@$(RM) $(OBJS)

fclean:			clean
				@echo "Cleaning executables & object files"
				@$(RM) $(NAME)

fclean-all:		fclean
				@$(RM) -rf $(MINIAUDIO_PATH)

re:				fclean-all all

.PHONY: all clean fclean fclean-all re
