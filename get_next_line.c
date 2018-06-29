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

int     get_next_line(const int fd, char **line)
{
    int     rd;
    char    buf[BUFF_SIZE + 1];

    rd = 0;
    while (rd = read(fd, buf, BUFF_SIZE))
    {
        buf[rd] = '\0';
    }

    return ();
}

int     main(int ac, char **av)
{
    int     fd;
    char    buf[10];

    fd = open("42", O_RDONLY);
    if (fd == -1)
    {
        ft_putendl("Open failed (-1)");
        return (-1);
    }
    get_next_line(fd, buf);

/*   while (rd = read(fd, buf, BUFF_SIZE))
    {
        buf[rd] = '\0';
        ft_putnbr(rd);
        write(1, "\n", 1);
        ft_putstr(buf);
    }
*/



    if (close(fd) == -1)
    {
        ft_putendl("Close failed (-1)");
        return (1);
    }
    return (0);
}
