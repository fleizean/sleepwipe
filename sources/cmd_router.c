#include "../includes/sleepwipe.h"

int cmd_router(t_list* cmd_str)
{
    c_list  _commands[10];

    _commands[0] = (c_list){"-time", "Prevent the computer sleep feature for a certain period of time.", t_sleep};
    _commands[1] = (c_list){"-t", "Prevent the computer sleep feature for a certain period of process time.", t_sleep};
    _commands[2] = (c_list){"-process", "Prevent the computer sleep feature for a certain period of time.", p_sleep};
    _commands[3] = (c_list){"-p", "Prevent the computer sleep feature for a certain period of process time.", p_sleep};
    _commands[4] = (c_list){"-mouse", "Prevent the computer sleep feature for a certain period of time.", k_sleep};
    _commands[5] = (c_list){"-m", "Prevent the computer sleep feature for a certain period of process time.", k_sleep};
    _commands[6] = (c_list){"-keyboard", "Prevent the computer sleep feature for a certain period of time.", k_sleep};
    _commands[7] = (c_list){"-key", "Prevent the computer sleep feature for a certain period of process time.", k_sleep};
    _commands[8] = (c_list){"-k", "Prevent the computer sleep feature for a certain period of time.", k_sleep};
    _commands[9] = (c_list){0, NULL, NULL};

    for (int i = 0; _commands[i].cmd_name != 0; i++) {
        if (strcmp(_commands[i].cmd_name, cmd_str->cmd_name) == 0) {
            
            if (_commands[i].cmd_function(cmd_str) == -1){
                
                return 1;
            }
        }
    }
    // ...
    return -1;
}