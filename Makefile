
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

TARGET = philo
TARGET_BONUS = philo_bonus
SOURCES = philo/philo_int_main.c philo/utils.c philo/error_managment.c philo/init_control.c philo/thread_creation.c philo/project_manager.c \
		  philo/philos_routine.c
SRCDIR = philo/
BUILDDIR = philo/build

SUCCESS_ICON = ✅
REMOVING_ICON = 🛠️ 
OBJECTS = $(SOURCES:$(SRCDIR)%.c=$(BUILDDIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread

all: $(TARGET) credit

$(TARGET): $(OBJECTS)
	@echo "$(GREEN)Linking $(TARGET)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@/philo
	@echo "$(GREEN)Build completed successfully$(RESET) $(SUCCESS_ICON)"

$(BUILDDIR)/%.o: $(SRCDIR)%.c
	@mkdir -p $(BUILDDIR) 
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning build files...$(RESET)"
	@rm -rf $(BUILDDIR)

fclean: clean
	@echo "$(RED)Removing executable...$(RESET) $(REMOVING_ICON)"
	@rm -f philo/$(TARGET)

re: fclean all

.PHONY: all clean fclean re

credit:
	@echo "▀██▀▀█▄  ▀██       ██  ▀██                                  ▀██"
	@echo " ██   ██  ██ ▄▄   ▄▄▄   ██    ▄▄▄    ▄▄▄▄    ▄▄▄   ▄▄▄ ▄▄▄   ██ ▄▄     ▄▄▄▄  ▄▄▄ ▄▄   ▄▄▄▄"
	@echo " ██▄▄▄█▀  ██▀ ██   ██   ██  ▄█  ▀█▄ ██▄ ▀  ▄█  ▀█▄  ██▀  ██  ██▀ ██  ▄█▄▄▄██  ██▀ ▀▀ ██▄ ▀"
	@echo " ██       ██  ██   ██   ██  ██   ██ ▄ ▀█▄▄ ██   ██  ██    █  ██  ██  ██       ██     ▄ ▀█▄▄"
	@echo "▄██▄     ▄██▄ ██▄ ▄██▄ ▄██▄  ▀█▄▄█▀ █▀▄▄█▀  ▀█▄▄█▀  ██▄▄▄▀  ▄██▄ ██▄  ▀█▄▄▄▀ ▄██▄    █▀▄▄█▀"
	@echo "                                                    ██"
	@echo "         Made with love by : \033[1;91mhbendjab\033[m                 ▀▀▀▀"