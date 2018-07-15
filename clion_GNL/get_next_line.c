
#include "get_next_line.h"

t_gnl				*ft_create_chained_list(t_gnl *list, int fd)
{
	char	*data;

	data = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!data)
        return (NULL);
	data[BUFF_SIZE] = '\0';
	if (!list)
	{
		list = (t_gnl*)ft_lstnew(data, (BUFF_SIZE + 1));
		list->size = fd;
	}
	free(data);
	return (list);
}

t_gnl				*ft_return_list_by_fd(t_gnl *current, int fd)
{
	char	*data;

	data = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!data)
        return (NULL);
	data[BUFF_SIZE] = '\0';
	while (current->size != fd && current->next)
		current = current->next;
	if (current->size != fd)
	{
		current->next = (t_gnl*)ft_lstnew(data, (BUFF_SIZE + 1));
		current = current->next;
		current->size = fd;
	}
	free(data);
	return (current);
}

char				*ft_read_file(char *str, t_gnl *current, char *clear)
{
	int				rd;

	rd = 0;
	while (!ft_strchr(str, '\n')
		&& (rd = read(current->size, current->content, BUFF_SIZE)) > 0)
//If str is empty (new list) - strjoin buf until we meet NL char
//If str has something (existing list) - we copy new content only if there is no NL char, if it is we return string
	{
		current->content[rd] = '\0';
		clear = str;
		str = ft_strjoin(str, current->content);
		free(clear);
	}
	if (rd == -1)
		return (NULL);
	return (str);
}

int					ft_copy_line(char *str, char *clear, char **line)
{
	if (!ft_strchr(str, '\n'))
//Case for last line in file
	{
		if (ft_strlen(str) > 0)
//Copy last line from file to line
		{
			clear = str;
			*line = ft_strdup(str);
			free(clear);
			return (1);
		}
		else
//Reading has been completed str = strdup(""), nothing so we finish
			return (0);
	}
	*line = ft_strsub(str, 0, (ft_strchr(str, '\n') - str));
//Copy from string start to line until EOL char
	free(str);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*current;
	char			*str;
	char			*nl;
	char			*clear;

	clear = NULL;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
        return (-1);
	list = ft_create_chained_list(list, fd);
//Create new chained list or return existing one
	current = list;
//Pointer to chained list we didnt use
	if ((current = ft_return_list_by_fd(current, fd)) && !current)
//Return list with same fd or create new one
        return (-1);
	if (!(nl = ft_strchr(current->content, '\n')))
//If new list - create string for str
//If existing list - create string with part after NL char (skip previous line)
//If last line for second time, we make str = ""
        str = ft_strdup("");
	else
	{
		*nl = ' ';
		str = ft_strdup(nl + 1);
	}
	if (!(str = ft_read_file(str, current, clear)))
//If new list - str = string until NL char (first line in file)
//If existing list - str = string from previous NL char to EOF or EOL (next line)
		return (-1);
	if (ft_copy_line(str, clear, line) == 0)
//Copy to line and return 1 or nothing to copy and return 0
		return (0);
	return (1);
}

int     main(void)
{
    char    **line;
    int     fd;

    fd = 0;
    line = malloc(sizeof(char*));
    if ((fd = open("Hello", O_RDONLY)) == -1)
    {
        ft_putstr("Open error");
        return (1);
    }
    ft_putnbr(get_next_line(fd, line));
    ft_putstr(*line);
    ft_putnbr(get_next_line(fd, line));
    ft_putstr(*line);
    ft_putnbr(get_next_line(fd, line));
    ft_putstr(*line);
	ft_putnbr(get_next_line(fd, line));
	ft_putstr(*line);
    if (close(fd) < 0)
    {
        ft_putstr("Close error");
        return (1);
    }
    return (0);
}
