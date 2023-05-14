#include "../includes/sleepwipe.h"
#include <libproc.h>

int p_sleep(t_list *cmd) {
    pid_t pid = cmd->cmd_act_input;
    char name[PROC_PIDPATHINFO_MAXSIZE];
    IOPMAssertionID assertionID;
    IOPMAssertionCreateWithName(kIOPMAssertionTypeNoIdleSleep,
                                kIOPMAssertionLevelOn,
                                CFSTR("Prevent system sleep"),
                                &assertionID);
    

    while (1) 
    {
        if (kill(pid, 0) == -1) 
        {
            if (proc_name(pid, name, sizeof(name)) <= 0)
                printf("%sProcess %s%d:%s %shas terminated.%s\n",BOLDRED, BOLDGREEN, pid, name, BOLDRED,RESET);
            else
                printf("%sProcess %s%d %shas terminated.%s\n",BOLDRED, BOLDGREEN, pid, BOLDRED,RESET);
            break;
        } 
        else 
        {
            if (proc_name(pid, name, sizeof(name)) <= 0)
                printf("%sProcess %s%d %sis still running.%s\n",BOLDGREEN, BOLDRED, pid, BOLDGREEN,RESET);
            else
                printf("%sProcess %s%d:%s %sis still running.%s\n",BOLDGREEN, BOLDRED, pid,name, BOLDGREEN,RESET);
             sleep(1);
        }
    }
    return(-1);
}
