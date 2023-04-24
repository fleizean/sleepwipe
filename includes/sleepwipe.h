#pragma once

# include <CoreFoundation/CoreFoundation.h>
# include <IOKit/IOKitLib.h>
# include <IOKit/pwr_mgt/IOPMLib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "color.h"
# include <stdlib.h>
# include <sys/utsname.h>

typedef struct	cmd_list {
	char*	cmd_name;
	char*	cmd_description;
	void	(*cmd_func)(void);
	void	*next;
}				c_list;