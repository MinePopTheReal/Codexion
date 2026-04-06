NAME := codexion

BUILDDIR := .build
SRCS_DIR := srcs
OBJS_DIR := $(BUILDDIR)/objs
DEPS_DIR := $(BUILDDIR)/deps


BASENAME_PARSING := parsing print_error
BASENAME_CODERS := coders
BASENAME_MONITOR := monitor
BASENAME_ROUTINE := actions compile debug refactor routine taken_dongles utils
OTHER_FILE_BASENAME := codexion utils waiting_queue
BASE_NAME := $(BASENAME_PARSING) $(BASENAME_CODERS) $(BASENAME_MONITOR) $(BASENAME_ROUTINE) $(OTHER_FILE_BASENAME)

SRCS_BASENAME := \
	$(addprefix $(SRCS_DIR)/parsing/, $(BASENAME_PARSING)) \
	$(addprefix $(SRCS_DIR)/coders/, $(BASENAME_CODERS)) \
	$(addprefix $(SRCS_DIR)/monitor/, $(BASENAME_MONITOR)) \
	$(addprefix $(SRCS_DIR)/routine/, $(BASENAME_ROUTINE)) \
	$(addprefix $(SRCS_DIR)/other/, $(OTHER_FILE_BASENAME))

SRCS := $(addsuffix .c, $(SRCS_BASENAME))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(SRCS_BASENAME)))
DEPS := $(addprefix $(DEPS_DIR)/, $(addsuffix .d, $(SRCS_BASENAME)))

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