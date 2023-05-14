#include "../includes/sleepwipe.h"

void	print_usage()
{
	char			*title;
	struct utsname	unameData;
	int				result = uname(&unameData);

	title = fetchDataFromGithubRestAPI();
	if (result != -1)
	{
		fprintf(stderr, "[GNU %s, version %s]\n",getenv("0"), unameData.version);
		fprintf(stderr, "\n%sNAME%s\n",BLUE,RESET);
		fprintf(stderr, "		sleepwipe -- prevent the system from sleeping on behalf of a utility\n");
		fprintf(stderr, "%sSYNOPSIS\n%s",BLUE,RESET);
		fprintf(stderr, "		sleepwipe [-a] [-t timeout]\n");
		fprintf(stderr, "%sDESCRIPTION\n%s",BLUE,RESET);
		fprintf(stderr, "		sleepwipe prevents the system from going to sleep based on specific events.\n"
						"		If no events are specified, the sleep prevention is activated indefinitely.\n"
						"		A helper event can be specified to perform actions based on that event; for example,\n"
						"		waiting for the exit status of a given process ID and reactivating sleep when it exits.\n");
		fprintf(stderr, "		Available options:\n");
		fprintf(stderr, "		-t		This event prevents the system from going to sleep for the given value (in seconds).\n"
						"				It returns an error if no value is specified.\n");
		fprintf(stderr, "		-p		This event prevents the system from going to sleep until the given process ID exits.\n"
						"				If no process ID is specified, an error is thrown.\n");
		fprintf(stderr, "		-k		Do not block the computer sleep feature unless you click on some specific keys of\n"
						"				the keyboard and the mouse.\n");
		fprintf(stderr, "%sCurrently Unavailable\n%s",BLUE,RESET);
		fprintf(stderr, "		-k, key, keyboard\n");
		fprintf(stderr, "%sLast Update\n%s",BLUE,RESET);
		fprintf(stderr, "		%s\n", title); // on progress
	}
	free(title);
}