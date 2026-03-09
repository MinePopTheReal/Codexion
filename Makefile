NAME := codexion
BUILDDIR := .build
SRCSDIR := srcs
OBJSDIR := $(BUILDDIR)/objs
DEPSDIR := $(BUILDDIR)/deps

SRCS := main.c
OBJS := $(patsubst $(SRCSDIR)/%.c, $(OBJSDIR)/%.o,$(SRCSDIR)/$(SRCS))
DEPS := $(patsubst $(SRCSDIR)/%.c,$(DEPSDIR)/%.d,$(SRCSDIR)/$(SRCS))

DEPS_FLAGS := -MD -MF
CFLAGS := -Wall -Wextra -Werror -pthread -g3 -Icoders # remove -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BUILDDIR):
	mkdir -p $@
	mkdir -p $(OBJSDIR)
	mkdir -p $(DEPSDIR)

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c Makefile | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(DEPS_FLAGS) $(DEPSDIR)/$*.d

clean:
	$(RM) -rf $(BUILDDIR)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)
