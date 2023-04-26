#include "../includes/sleepwipe.h"

int cmd_router(char *cmd_str)
{
    c_list  _commands[3];

    _commands[0] = (c_list){"t", "...", t_sleep};
    _commands[1] = (c_list){"p", "...", t_sleep};
    _commands[2] = (c_list){NULL, NULL, NULL};

    // ...
}