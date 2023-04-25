#pragma once

# include <CoreFoundation/CoreFoundation.h> // ?
# include <IOKit/IOKitLib.h> // ?
# include <IOKit/pwr_mgt/IOPMLib.h> // ?
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h> // for malloc...
# include "color.h" // for colors
# include <curl/curl.h> // for pull json data
# include <stdlib.h>
# include <sys/utsname.h> // for getting some datas for iterm
# include <string.h>
# include <libxml/parser.h>
# include <libxml/tree.h>

typedef struct	cmd_list {
	char*	cmd_name;
	char*	cmd_description;
	void	(*cmd_func)(void);
	void	*next;
}				c_list;


/* cmdhelp.c */
void	print_usage();

/* utils.c */
char    **ft_split(char *str);

/* fetchdata.c */
char		*fetchDataFromGithubRestAPI();
