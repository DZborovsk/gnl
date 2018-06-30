/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gey_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzborovk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:16:17 by dzborovk          #+#    #+#             */
/*   Updated: 2017/12/08 15:56:53 by dzborovk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFF_SIZE 2

int     ft_check_nl_and_eof(char *s, int end)
//Return -1 if there is no newline or EOF, and index of NL or EOF otherwise.
{
    int     i;
    int     loop;

    loop = end;
    i = 0;
    while (loop--)
    {
        if (s[i] == '\n')
            return (i);
        if (s[i] == '\0' && end != i)
            return (i);
        i++;
    }
    return (-1);
}

/*int     get_next_line(const int fd, char **line)
{
    int     rd;
    char    buf[BUFF_SIZE + 1];

    rd = 0;
    while (rd = read(fd, buf, BUFF_SIZE))
    {
        buf[rd] = '\0';
        ft_check_nl_and_eol(buf, rd);
    }
    return (0);
}*/

int     main(int ac, char **av)
{
    int     fd;
    char    buf[10];

/*    fd = open("42", O_RDONLY);
    if (fd == -1)
    {
        ft_putendl("Open failed (-1)");
        return (-1);
    }
*/
    //    get_next_line(fd, buf);
/*   while (rd = read(fd, buf, BUFF_SIZE))
    {
        buf[rd] = '\0';
        ft_putnbr(rd);
        write(1, "\n", 1);
        ft_putstr(buf);
    }
*/
 //   ft_putnbr(ft_check_nl_and_eof("Hello world", 5));
    ft_putstr(ft_strchr("He\nllo world!", '\n'));
    /*if (close(fd) == -1)
    {
        ft_putendl("Close failed (-1)");
        return (1);
    }*/
    return (0);
}
