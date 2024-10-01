MAKEFLAGS += -s
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

NAMES = philo
SOURCES = philo_int_main.c utils.c error_managment.c init_control.c \
          thread_creation.c project_manager.c philos_routine.c \
          philo_eating.c philo_eating_helper.c utils2.c
SRCDIR = .  
BUILDDIR = build
SUCCESS_ICON = ✅
REMOVING_ICON = 🛠️ 
OBJECTS = $(SOURCES:%.c=$(BUILDDIR)/%.o)  
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAMES) credit

$(NAMES): $(OBJECTS)
	@echo "$(GREEN)Linking $(NAMES)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@echo "$(GREEN)Build completed successfully$(RESET) $(SUCCESS_ICON)"

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(BUILDDIR) 
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning build files...$(RESET)"
	@rm -rf $(BUILDDIR)

fclean: clean
	@echo "$(RED)Removing executable...$(RESET) $(REMOVING_ICON)"
	@rm -f $(NAMES)

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
