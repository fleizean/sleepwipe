#include "../includes/sleepwipe.h"

int cmd_router(t_list cmd_str)
{
    c_list  _commands[4];

    _commands[0] = (c_list){'t', "Prevent the computer sleep feature for a certain period of time.", t_sleep};
    _commands[1] = (c_list){'p', "Prevent the computer sleep feature for a certain period of process time.", p_sleep};
    _commands[2] = (c_list){'k', "Do not block the computer sleep feature unless you click on some specific keys of the keyboard and the mouse.", k_sleep};
    _commands[3] = (c_list){0, NULL, NULL};

    for (int i = 0; _commands[i].cmd_name != 0; i++) {
        if (_commands[i].cmd_name == cmd_str.cmd_name) {
            if (_commands[i].cmd_function(cmd_str) == -1){
                printf("%sTime you gave has expired.%s\n", BOLDGREEN, RESET);
                exit(1);
            }
        }
    }
    // ...
    return 1;
}