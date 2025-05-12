# **************************************************************************** #
#                                  VARIABLES                                  #
# **************************************************************************** #

NAME		:= philo
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iinclude
SRC_DIR		:= src
OBJ_DIR		:= obj
INC_DIR		:= include

SRC			:= $(wildcard $(SRC_DIR)/*.c)
OBJ			:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

HEADER		:= $(INC_DIR)/philo.h

# Couleurs
GREEN		:= \033[0;32m
RED			:= \033[0;31m
YELLOW		:= \033[1;33m
BLUE		:= \033[0;34m
NC			:= \033[0m

# Emojis
COMP_EMOJI	:= 🔧
OK_EMOJI	:= ✅
CLEAN_EMOJI	:= 🧹
RE_EMOJI	:= 🔁
FIRE_EMOJI	:= 🔥

# **************************************************************************** #
#                                  COMMANDS                                   #
# **************************************************************************** #

$(NAME): $(OBJ)
	@echo -e "$(BLUE)$(COMP_EMOJI) Linking...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo -e "$(GREEN)$(OK_EMOJI) Compilation successful!$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@echo -e "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #
#                                   RULES                                     #
# **************************************************************************** #

all:
	@echo -e "$(FIRE_EMOJI) $(YELLOW)Building project...$(NC)"
	@$(MAKE) $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo -e "$(CLEAN_EMOJI) $(RED)Objects cleaned.$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(CLEAN_EMOJI) $(RED)Binary cleaned.$(NC)"

re:
	@echo -e "$(RE_EMOJI) $(YELLOW)Recompiling...$(NC)"
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
