/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:54:32 by jkauppi           #+#    #+#             */
/*   Updated: 2019/11/23 15:23:50 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
/*
static void ft_simple_string_1()
{
        char    *line;
        int             out;
        int             p[2];
        int             fd;

        out = dup(1);
        pipe(p);

        fd = 1;
        dup2(p[1], fd);
        write(fd, "mnopqrstuvwxyzab", 16);
        close(p[1]);
        dup2(out, fd);
        get_next_line(p[0], &line);
		ft_putendl(line);
}

static void ft_simple_string_2()
{
        char    *line;
        int             out;
        int             p[2];
        int             fd;

        out = dup(1);
        pipe(p);

        fd = 1;
        dup2(p[1], fd);
        write(fd, "abcdefgh\n", 9);
        write(fd, "ijklmnop\n", 9);
        close(p[1]);
        dup2(out, fd);
        get_next_line(p[0], &line);
		ft_putendl(line);
        get_next_line(p[0], &line);
		ft_putendl(line);
}
*/
int			main(int argc, char **argv)
{
	int		file;
	char	*line;

	if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		while (get_next_line(file, &line) == 1)
			ft_putendl(line);
	}
	if (argc == 3)
	{
		file = open(argv[2], O_RDONLY);
		while (get_next_line(file, &line) == 1)
			;
	}
	return (0);
}

