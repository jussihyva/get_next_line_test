/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:54:32 by jkauppi           #+#    #+#             */
/*   Updated: 2019/11/14 12:20:59 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

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
//		ft_putendl(line);
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
//		ft_putendl(line);
        get_next_line(p[0], &line);
//		ft_putendl(line);
}

int			main(int argc, char **argv)
{
	size_t		line_num;
	int			index;
	int			fd_array[FD_SIZE];
	char		**line_buffer[FD_SIZE];
	int			are_lines;
	int			ret;

	ft_simple_string_1();
	ft_simple_string_2();
	ft_memset(fd_array, 0, FD_SIZE);
	index = 0;
	while (index < FD_SIZE)
	{
		fd_array[index] = -1;
		index++;
	}
	if (argc > 1)
	{
		index = 0;
		while (++index < argc)
		{
			fd_array[index - 1] = open(argv[index], O_RDONLY);
			if (fd_array[index - 1] == -1)
				fd_array[index - 1] = atoi(argv[index]);
			line_buffer[index - 1] = (char **)ft_memalloc(sizeof(*line_buffer));
		}
	}
	else
	{
		index = 1;
		fd_array[index - 1] = 0;
		line_buffer[index - 1] = (char **)ft_memalloc(sizeof(*line_buffer));
	}
	line_num = 0;
	are_lines = 1;
	while (are_lines)
	{
		are_lines = 0;
		index = 0;
		line_num++;
		while (index < FD_SIZE)
		{
			if (fd_array[index] != -1)
			{
				if ((ret = get_next_line(fd_array[index], line_buffer[index])) > 0)
				{
					ft_putnbr(ret);
					ft_putstr(": ");
					ft_putendl(*line_buffer[index]);
//					ft_strdel(*line_buffer + index);
					are_lines = 1;
				}
				else
				{
					ft_putnbr(ret);
					ft_putstr(": ");
					ft_putchar('\n');
					fd_array[index] = -1;
				}
			}
			index++;
		}
	}
//	while (1 == 1)
//	{
//		continue ;
//	}
	ft_simple_string_1();
	ft_simple_string_2();
	return (0);
}
