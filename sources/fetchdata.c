#include "../includes/sleepwipe.h"

char* fetchDataFromGithubRestAPI()
{
	int		fd;
	char	*line;

	system("/bin/bash scripts/githubapi.sh");
	fd = open("scripts/apiresult.txt", O_RDONLY);
	if (fd < 0)
		return NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if(!line)
			return NULL;
		else
			break;
	}
	return line;
}
