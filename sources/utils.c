#include "../includes/sleepwipe.h"

char    **ft_split(char *str)
{
    int i;
    int k;
    int j;
    char **split;

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