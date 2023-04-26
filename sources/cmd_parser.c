#include "../includes/sleepwipe.h"

char *cmd_parser(char **cmd_line)
{
	char*	cmd_tmpactflag;
	char*	cmd_tmpname;
	int		cmd_actinput;
	int		i;
	int		j;
	int		k;
	int		l;

	j = 0;
	i = 1;
	k = 0;
	l = 0;
	/* while(cmd_line[i][j] != NULL)
	{
		if(cmd_line[i][j] <= 32 && cmd_line[i][j] == '-' && cmd_line[i][j])
			j++;
		if(cmd_line[i][j] > 32 && cmd_line[i][j])
			cmd_tmpname[k++] = cmd_line[i][j++];
	} */
}