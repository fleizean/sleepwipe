#include "../includes/sleepwipe.h"

int p_sleep(t_list *cmd) {
    // p_sleep fonksiyonunun işlevselliği
    if(kill(cmd->cmd_act_input, 0) == 0)
        printf("Process is active\n");
    else
        exit(1);
    return 0;
}
