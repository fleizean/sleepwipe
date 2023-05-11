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
# include <ctype.h>

/* ------------------------- */
/*         Structers         */

/* Client input structer */
typedef struct _cmd_list {
	bool	cmd_act_flag;
	char*	cmd_name;
	int		cmd_act_input;
}			t_list;

/* Storage and router structer */
typedef struct	_cmd_router {
	char*	cmd_name;
	char*	cmd_description;
	int		(*cmd_function)(t_list*);
}			c_list;

typedef struct _act_namelist {
    const char* act_name;
} a_list;

typedef struct _cmd_namelist {
    const char* cmd_name;
} m_list;

/* Global variable
t_list	cmd_list; */

/* ------------------------- */
/*         Functions         */

/* cmd_help.c */
void	print_usage();

/* utils.c */
char	**ft_split(char *str);

/* fetchdata.c */
char	*fetchDataFromGithubRestAPI();

/* commands */
int		t_sleep(t_list *cmd);
int		p_sleep(t_list *cmd);
int		k_sleep(t_list *cmd);

/* cmd_router.c */
int		cmd_router(t_list* cmd_lst);
/* cmd_parser.c */
void	cmd_parser(char **av, t_list *cmd_str);
void 	cmd_checkselect(char *act, char *name, char *input, t_list	*cmd);
int		isOk(char *act, char *name, t_list *cmd);
/* get_next_line.c */
int		get_next_line(int fd, char **line);
char	*ft_strdup(char *str);
char	*trim(char *s);
/* ------------------------- */
