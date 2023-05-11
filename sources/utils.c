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

char	*ft_strdup(char *str)
{
	size_t	i;
	char	*p1;
	size_t	index;

	index = 0;
	i = strlen(str);
	p1 = malloc(sizeof(char) * (i + 1));
	if (!p1)
		return (NULL);
	while (str[index])
	{
		p1[index] = str[index];
		index++;
	}
	p1[index] = '\0';
	return (p1);
}

char* trim(char *s)
{
    int i;

    while (isspace (*s)) s++;
    for (i = strlen (s) - 1; (isspace (s[i])); i--);
    s[i + 1] = '\0';
    
    char* trimmed_str = malloc(strlen(s) + 1);
    strcpy(trimmed_str, s);
    
    return trimmed_str;
}