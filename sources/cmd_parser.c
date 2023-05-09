#include "../includes/sleepwipe.h"

void cmd_parser(int ac,char **av)//./sleepwipe -act -t 100
{
	t_list cmd;
	int c;

	while ((c = getopt(ac, av, "at:")) != -1)
    {
        switch (c)
        {
            case 'a':
                cmd.cmd_act_flag = true;
                break;
            case 't':
            case 'p':
            case 'k':
                cmd.cmd_act_input = atoi(optarg);
				cmd.cmd_name = c;
                break;
			
            default:
                print_usage();
                exit(EXIT_FAILURE);
        }
	}
	if((cmd.cmd_act_flag != true) || !(cmd.cmd_act_input >= 1 && cmd.cmd_act_input <= 2147483647)){
		print_usage();
		exit(EXIT_FAILURE);
	}
	if (cmd_router(cmd) != 1)
		exit(EXIT_FAILURE);
}