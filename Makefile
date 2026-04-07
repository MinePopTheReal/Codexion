NAME := codexion

BUILDDIR := .build
SRCS_DIR := srcs
OBJS_DIR := $(BUILDDIR)/objs
DEPS_DIR := $(BUILDDIR)/deps

BASE_NAME := parsing \
			print_error \
			coders \
			monitor \
			monitor_utils \
			actions \
			compile \
			debug \
			refactor \
			routine \
			taken_dongles \
			routine_utils \
			append \
			first_pop \
			free_queue \
			last_coder \
			new_node \
			codexion \
			other_utils

VPATH := $(SRCS_DIR):$(SRCS_DIR)/parsing:$(SRCS_DIR)/monitor:$(SRCS_DIR)/routine:$(SRCS_DIR)/queue:$(SRCS_DIR)/other:$(SRCS_DIR)/coders
SRCS := $(addsuffix .c, $(BASE_NAME))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(BASE_NAME)))
DEPS := $(addprefix $(DEPS_DIR)/, $(addsuffix .d, $(BASE_NAME)))

DEPS_FLAGS := -MD -MF
CFLAGS := -Wall -Wextra -Werror -pthread -Icoders -g3 # remove -g3

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR) $(DEPS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: %.c Makefile | $(DEPS_DIR) $(OBJS_DIR)
	@mkdir -p $(dir $@) $(dir $(DEPS_DIR)/$*)
	$(CC) $(CFLAGS) -c $< -o $@ $(DEPS_FLAGS) $(DEPS_DIR)/$*.d

clean:
	$(RM) -rf $(BUILDDIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)