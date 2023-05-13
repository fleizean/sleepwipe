#include "../includes/sleepwipe.h"

int p_sleep(t_list *cmd) {
    pid_t pid = cmd->cmd_act_input;

    IOPMAssertionID assertionID;
    IOPMAssertionCreateWithName(kIOPMAssertionTypeNoIdleSleep,
                                kIOPMAssertionLevelOn,
                                CFSTR("Uyutmayı Engelle"),
                                &assertionID);

    while (1) {
        if (kill(pid, 0) == -1) {
            printf("Process %d has terminated.\n", pid);
            break;
        } else {
            printf("Process %d is still running.\n", pid);
            sleep(1);
        }
    }
    return(-1);
}
