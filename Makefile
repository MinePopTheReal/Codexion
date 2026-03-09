NAME := codexion

BUILDDIR := .build
SRCSDIR := srcs
OBJSDIR := $(BUILDDIR)/objs
DEPSDIR := $(BUILDDIR)/deps

SRCS := codexion.c \
		parsing.c
OBJS := $(patsubst $(SRCSDIR)/%.c, $(OBJSDIR)/%.o,$(SRCSDIR)/$(SRCS))
DEPS := $(patsubst $(SRCSDIR)/%.c,$(DEPSDIR)/%.d,$(SRCSDIR)/$(SRCS))

DEPS_FLAGS := -MD -MF
CFLAGS := -Wall -Wextra -Werror -pthread -Icoders -g3 # remove -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJSDIR):
	mkdir -p $@
$(DEPSDIR):
	mkdir -p $@

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c Makefile | $(DEPSDIR) $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(DEPS_FLAGS) $(DEPSDIR)/$*.d

clean:
	$(RM) -rf $(BUILDDIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
