#include "../includes/sleepwipe.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t		len_s1;
	size_t		len_s2;
	char		*str;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (strdup(s2));
	else if (!s2)
		return (strdup(s1));
	len_s1 = strlen(s1);
	len_s2 = strlen(s2);
	str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	memcpy(str, s1, len_s1);
	free(s1);
	memcpy(str + len_s1, s2, len_s2);
	str[len_s1 + len_s2] = 0;
	return (str);
}

static int	chk_newline(char *temp)
{
	int				i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	sep_line(char **temp, char **line, int is_line)
{
	char			*ptr;

	(*temp)[is_line] = '\0';
	*line = strdup(*temp);
	if (!(*line))
		return (-1);
	ptr = strdup(*temp + is_line + 1);
	if (!ptr)
		return (-1);
	free(*temp);
	*temp = ptr;
	return (1);
}

static int	return_remain(char **temp, char **line, int read_size)
{
	int				i;

	if (read_size < 0)
		return (-1);
	if (*temp && chk_newline(*temp) >= 0)
	{
		i = chk_newline(*temp);
		return (sep_line(temp, line, i));
	}
	else if (*temp)
	{
		*line = *temp;
		*temp = 0;
		return (0);
	}
	*line = strdup("");
	if (!(*line))
		return (-1);
	return (0);
}

static int	temp_str(char *temp[], char *buffer, int *is_line, int fd)
{
	temp[fd] = ft_strjoin_free(temp[fd], buffer);
	if (!(temp[fd]))
		return (1);
	*is_line = chk_newline(temp[fd]);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int				is_line;
	int				read_size;
	char			*buffer;
	static char		*temp[256];

	if ((fd < 0) || !line || (1024 <= 0))
		return (-1);
	buffer = (char *)malloc(sizeof(char) * (1024 + 1));
	if (!buffer)
		return (-1);
	read_size = read(fd, buffer, 1024);
	while (read_size > 0)
	{
		buffer[read_size] = '\0';
		if (temp_str(temp, buffer, &is_line, fd))
			return (-1);
		if (is_line >= 0)
		{
			free(buffer);
			return (sep_line(&temp[fd], line, is_line));
		}
		read_size = read(fd, buffer, 1024);
	}
	free(buffer);
	return (return_remain(&temp[fd], line, read_size));
}