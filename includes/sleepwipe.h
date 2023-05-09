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

/* Client input structer */
typedef struct _cmd_list {
	bool	cmd_act_flag;
	char	cmd_name;
	int		cmd_act_input;
}		t_list;

/* Storage and router structer */
typedef struct	_cmd_router {
	char	cmd_name;
	char*	cmd_description;
	int		(*cmd_function)(t_list);
}				c_list;

/* Global variable
t_list	cmd_list; */

/* ------------------------- */
/*         Functions         */

/* cmd_help.c */
void	print_usage();

/* utils.c */
char    **ft_split(char *str);

/* fetchdata.c */
char	*fetchDataFromGithubRestAPI();

/* commands */
int	t_sleep(t_list cmd);
int p_sleep(t_list cmd);
int k_sleep(t_list cmd);

/* cmd_router.c */
int		cmd_router(t_list cmd_str);

/* cmd_parser.c */
void	cmd_parser(int ac, char **av);

/* get_next_line.c */
int		get_next_line(int fd, char **line);
/* ------------------------- */
