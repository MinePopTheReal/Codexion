NAME := codexion

BUILDDIR := .build

SRCS_DIR := coders/srcs
OBJS_DIR := $(BUILDDIR)/objs
DEPS_DIR := $(BUILDDIR)/deps

BASE_NAME := create_coders_list \
			create_dongles_list \
			init \
			init_routine \
			mutex_init \
			shared_init \
			join_threads \
			start_threads \
			init_queues \
			start_sim \
			codexion \
			is_burnout \
			is_finish \
			monitor \
			parsing \
			is_valid_number \
			set_value \
			append_both \
			append_queue \
			first_pop_queue \
			free_queue \
			last_coder \
			new_node \
			reorganize_queue \
			priority \
			swap_coder \
			actions \
			can_i_take \
			check_couldown \
			compile \
			debug \
			get_first_second \
			is_done \
			refactor \
			release_dongle \
			routine \
			take_dongles \
			wait_dongle \
			get_curr_time_from_start \
			smart_sleep \
			get_is_run \
			print_state \
			print_error \
			clean_sim \
			free_mutex \
			clean_mutexs \
			ft_atoi \
			get_sim_is_ready \
			ft_isdigit \
			cleanup

VPATH := $(SRCS_DIR): \
		$(SRCS_DIR)/actions: \
		$(SRCS_DIR)/clean: \
		$(SRCS_DIR)/entities: \
		$(SRCS_DIR)/get: \
		$(SRCS_DIR)/init \
		$(SRCS_DIR)/main: \
		$(SRCS_DIR)/monitor: \
		$(SRCS_DIR)/parsing: \
		$(SRCS_DIR)/print: \
		$(SRCS_DIR)/queue: \
		$(SRCS_DIR)/routine: \
		$(SRCS_DIR)/time:
SRCS := $(addsuffix .c, $(BASE_NAME))
OBJS := $(addprefix $(OBJS_DIR)/, $(addsuffix .o, $(BASE_NAME)))
DEPS := $(addprefix $(DEPS_DIR)/, $(addsuffix .d, $(BASE_NAME)))

DEPS_FLAGS := -MD -MF
CFLAGS := -Wall -Wextra -Werror -pthread -Icoders/includes

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