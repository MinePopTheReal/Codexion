#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_parsing_val
{
    size_t number_of_coder;
    size_t time_to_burnout;
    size_t time_to_compile;
    size_t time_to_debug;
    size_t time_to_refactor;
    size_t number_of_compiles;
    size_t dongle_cooldown;
    char *scheduler;
} t_parsing_val;

t_parsing_val parsing(int argc, char **argv);

#endif