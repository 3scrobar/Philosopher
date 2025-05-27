# 📌 Variables de compilation
NAME        = philo
CC          = clang
FLAG        = -Wall -Wextra -Werror -fsanitize=thread
DEBUG_FLAG  = -Wall -Wextra -Werror -g
THREAD_F    = -lpthread

# 📁 Fichiers source et répertoires
C_FILE      = main.c philosopher.c function.c liste.c protect.c routine.c monitoring.c
C_DIR       = ./src/
SRC         = $(addprefix $(C_DIR), $(C_FILE))
OBJ_DIR     = obj
OBJ         = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

# 📚 Includes
INCLUDE     = philo.h
I_DIR       = ./include/

# 🎨 Couleurs
GREEN       = \033[0;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
RED         = \033[0;31m
RESET       = \033[0m

# 🔧 Compilation des .c en .o dans obj/
$(OBJ_DIR)/%.o: $(C_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)🔧  Compilation de $<...$(RESET)"
	@$(CC) $(FLAG) -I$(I_DIR) -c $< -o $@

# 🚀 Build
all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(BLUE)🚀  Linking...$(RESET)"
	@$(CC) $(FLAG) $(OBJ) $(THREAD_F) -o $(NAME)
	@echo "$(GREEN)✅  Build terminé : ./$(NAME)$(RESET)"

# 🐛 Debug build
debug:
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)🐞  Compilation en mode debug...$(RESET)"
	@$(CC) $(DEBUG_FLAG) -I$(I_DIR) $(SRC) -o $(NAME) $(THREAD_F)
	@echo "$(GREEN)✅  Build debug terminé$(RESET)"

# 🧹 Nettoyage
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)🧹  .o supprimés.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  Binaire supprimé.$(RESET)"

re: fclean all

.PHONY: all clean fclean re debug valgrind
