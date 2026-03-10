NAME := codexion

BUILDDIR := .build
SRCS_DIR := srcs
OBJS_DIR := $(BUILDDIR)/objs
DEPS_DIR := $(BUILDDIR)/deps

BASE_NAME := codexion parsing
SRCS := $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(BASE_NAME)))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(BASE_NAME)))
DEPS := $(addprefix $(DEPS_DIR)/, $(addsuffix .d, $(BASE_NAME)))

DEPS_FLAGS := -MD -MF
CFLAGS := -Wall -Wextra -Werror -pthread -Icoders -g3 # remove -g3

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR) $(DEPS_DIR):
	mkdir -p $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c Makefile | $(DEPS_DIR) $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(DEPS_FLAGS) $(DEPS_DIR)/$*.d

clean:
	$(RM) -rf $(BUILDDIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
