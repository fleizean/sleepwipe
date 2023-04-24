#include "../includes/sleepwipe.h"

char    **ft_split(char *str)
{
	int		i;
	int		k;
	int		j;
	char	**split;

	i = 0;
	k = 0;
	if(!(split = (char **)malloc(sizeof(char) * 256)))
		return(NULL);
	while(str[i] <= 32)
		i++;
	while(str[i])
	{
		j = 0;
		if(!(split[k] = (char *)malloc(sizeof(char) * 4096)))
			return(NULL);
		while(str[i] > 32 && str[i])
			split[k][j++] = str[i++];
		while(str[i] <= 32 && str[i])
			i++;
		split[k][j] = '\0';
		k++;
	}
	split[k] = NULL;
	return(split);
}

void print_usage(char **av)
{
	struct utsname	unameData;
	int				result = uname(&unameData);
	if (result != -1)
	{
		fprintf(stderr, "[GNU %s, version %s]\n",getenv("0"), unameData.version);
		fprintf(stderr, "%sNAME%s",BLUE,RESET);
		fprintf(stderr, "		sleepwipe -- prevent the system from sleeping on behalf of a utility");
		fprintf(stderr, "%sSYNOPSIS\n%s",BLUE,RESET);
		fprintf(stderr, "		sleepwipe [-act] [-t timeout]");
		fprintf(stderr, "%sDESCRIPTION\n%s",BLUE,RESET);
		fprintf(stderr, "		sleepwipe prevents the system from going to sleep based on specific events.\n"
						"		If no events are specified, the sleep prevention is activated indefinitely.\n"
						"		A helper event can be specified to perform actions based on that event; for example,\n"
						"		waiting for the exit status of a given process ID and reactivating sleep when it exits.\n");
		fprintf(stderr, "		Available options:");
		fprintf(stderr, "		-t		This event prevents the system from going to sleep for the given value (in seconds).\n"
						"				It returns an error if no value is specified.\n");
		fprintf(stderr, "		-p		This event prevents the system from going to sleep until the given process ID exits.\n"
						"				If no process ID is specified, an error is thrown.\n");		
		fprintf(stderr, "%sLast Update\n%s",BLUE,RESET);
		fprintf(stderr, "		Getting shields.io json last commit"); // on progress
	}
}