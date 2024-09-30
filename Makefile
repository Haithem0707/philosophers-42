
MAKEFLAGS += -s
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

TARGET = philo
TARGET_BONUS = philo_bonus
SOURCES = philo/philo_int_main.c philo/utils.c philo/error_managment.c philo/init_control.c philo/thread_creation.c philo/project_manager.c \
		  philo/philos_routine.c
BSOURCES = philo_bonus/philo_int_main.c philo_bonus/utils.c philo_bonus/error_managment.c philo_bonus/init_control.c \
			philo_bonus/program_clean_up.c philo_bonus/philos_routine.c 
SRCDIR = philo/
BSRCDIR = philo_bonus/
BUILDDIR = philo/build
BBUILDDIR = philo_bonus/build
SUCCESS_ICON = ✅
REMOVING_ICON = 🛠️ 
OBJECTS = $(SOURCES:$(SRCDIR)%.c=$(BUILDDIR)/%.o)
BOBJECTS = $(BSOURCES:$(BSRCDIR)%.c=$(BBUILDDIR)/%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread

all: $(TARGET) credit

$(TARGET): $(OBJECTS)
	@echo "$(GREEN)Linking $(TARGET)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $@/philo
	@echo "$(GREEN)Build completed successfully$(RESET) $(SUCCESS_ICON)"

bonus:$(BOBJECTS) 
	@echo "$(GREEN)Linking $(TARGET)...$(RESET)"
	@$(CC) $(CFLAGS) $(BOBJECTS) -o ${BSRCDIR}/philo_bonus
	@echo "$(GREEN)Build completed successfully$(RESET) $(SUCCESS_ICON)"
	@$(MAKE) credit
$(BUILDDIR)/%.o: $(SRCDIR)%.c
	@mkdir -p $(BUILDDIR) 
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
$(BBUILDDIR)/%.o: $(BSRCDIR)%.c
	@mkdir -p $(BBUILDDIR) 
	@echo "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@echo "$(RED)Cleaning build files...$(RESET)"
	@rm -rf $(BUILDDIR)
	@rm -rf $(BBUILDDIR)
fclean: clean
	@echo "$(RED)Removing executable...$(RESET) $(REMOVING_ICON)"
	@rm -f philo/$(TARGET)
	@rm -f philo_bonus/$(TARGET)

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