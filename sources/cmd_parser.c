#include "../includes/sleepwipe.h"

int isOk(char *act, char *name, t_list *cmd)
{
    int lflag;

    lflag = 0;
    a_list act_list[4];
    act_list[0] = (a_list){"-action"};
    act_list[1] = (a_list){"-act"};
    act_list[2] = (a_list){"-a"};
    act_list[3] = (a_list){NULL};

    m_list cmdlist[10];
    cmdlist[0] = (m_list){"-keyboard"};
    cmdlist[1] = (m_list){"-key"};
    cmdlist[2] = (m_list){"-k"};
    cmdlist[3] = (m_list){"-mouse"};
    cmdlist[4] = (m_list){"-m"};
    cmdlist[5] = (m_list){"-time"};
    cmdlist[6] = (m_list){"-t"};
    cmdlist[7] = (m_list){"-process"};
    cmdlist[8] = (m_list){"-p"};
    cmdlist[9] = (m_list){NULL};
    for (int i = 0; act_list[i].act_name != NULL; i++) {
        if (strcmp(act_list[i].act_name, act) == 0) {
            cmd->cmd_act_flag = true;
        }
    }
    for (int i = 0; cmdlist[i].cmd_name != NULL; i++) {
        if (strcmp(cmdlist[i].cmd_name, name) == 0) {
            cmd->cmd_name = name;
            lflag = 1;
        }
    }
    
    if(lflag == 1 && cmd->cmd_act_flag == true)
        return 1;
    else{
        print_usage();
        exit(1);
    }
    return -1;
}

void cmd_checkselect(char *act, char *name, char *input, t_list	*cmd)
{
	if(isOk(act, name, cmd) == 1){
        cmd->cmd_act_input = atoi(input);
    }
    else
        exit(1);
}

void cmd_parser(char **av, t_list* cmd_lst)
{
	int		i;
	char	**cmd_args;
	char	*tmp_str;
    char    *tmp_trim;

    cmd_lst->cmd_act_flag = false;
	cmd_args = (char **)malloc(sizeof(char *) * 4);
	i = 0;
	if (!cmd_args)
		exit(1);
	for (i = 0; i < 3; i++) {
        tmp_trim = trim(av[i]);
		tmp_str = ft_strdup(tmp_trim);
        cmd_args[i] = malloc(strlen(tmp_str) + 1);
        if (cmd_args[i] == NULL)
            exit(1);
        strcpy(cmd_args[i], tmp_str);
        free(tmp_trim);
		free(tmp_str);
    }
	cmd_args[3] = NULL; 
	if(cmd_args[0] && cmd_args[1] && cmd_args[2])
		cmd_checkselect(cmd_args[0], cmd_args[1], cmd_args[2], cmd_lst);
    else
        exit(1);
    if(cmd_router(cmd_lst) == 1){
        printf("%sTime you gave has expired.%s\n", BOLDGREEN, RESET);
        for (int j = 0; j < 3; j++)
            free(cmd_args[j]);
        free(cmd_args);
        exit(1);
    }
}