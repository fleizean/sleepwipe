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

/* ------------------------- */
/*         Structers         */

/* Storage and router structer */
typedef struct	cmd_router {
	char*	cmd_name;
	char*	cmd_description;
	void	(*f)(char*);
}				c_list;

/* Client input structer */
typedef struct cmd_list {
	char*	cmd_act_flag;
	char*	cmd_name;
	int		cmd_act_input;
}				t_list;

/* Global variable */
t_list	cmd_list;

/* ------------------------- */
/*         Functions         */

/* cmd_help.c */
void	print_usage();

/* utils.c */
char    **ft_split(char *str);

/* fetchdata.c */
char	*fetchDataFromGithubRestAPI();

/* cmd_time.c */
void		t_sleep(char *str);

/* cmd_router.c */
int		cmd_router(char *cmd_str);

/* cmd_parser.c */
char	*cmd_parser(char **cmd_line);

/* get_next_line.c */
int		get_next_line(int fd, char **line);
/* ------------------------- */
