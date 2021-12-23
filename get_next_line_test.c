/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:54:32 by jkauppi           #+#    #+#             */
/*   Updated: 2021/12/20 19:44:02 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <assert.h>
#include <stdio.h>

static void simple_string()
{
	char 	*line;
	int		out;
	int		p[2];
	int		fd;
	int		gnl_ret;

	out = dup(1);
	pipe(p);

	fd = 1;
	dup2(p[1], fd);
	// write(fd, "abc\n\n", 5);
	// write(fd, "abc\n", 4);
	// write(fd, "abc", 3);
	write(fd, "This is the first line\nThis is the second one\nThis is the third\nThis is the last", 83);
	close(p[1]);
	dup2(out, fd);

	/* Read abc and new line */
	gnl_ret = get_next_line(p[0], &line);
	// gnl_ret = get_next_line(42, &line);
    printf("%s\n", line);
	assert(gnl_ret == 1);
	// assert(strcmp(line, "abc") == 0);

	/* Read new line */
	gnl_ret = get_next_line(p[0], &line);
	// assert(gnl_ret == 1);
	// assert(gnl_ret == 0);
	// assert(line == NULL || *line == '\0');

	/* Read again, but meet EOF */
	gnl_ret = get_next_line(p[0], &line);
	// assert(gnl_ret == 0);
	// assert(line == NULL || *line == '\0');

	/* Let's do it once again */
	gnl_ret = get_next_line(p[0], &line);
	gnl_ret = get_next_line(p[0], &line);
	gnl_ret = get_next_line(p[0], &line);
	gnl_ret = get_next_line(p[0], &line);
	gnl_ret = get_next_line(p[0], &line);
	// assert(gnl_ret == 0);
	// assert(line == NULL || *line == '\0');
}

// static void simple_string_1()
// {
// 	char 	*line;
// 	int		out;
// 	int		p[2];
// 	int		fd;
// 	int		ret;

// 	out = dup(1);
// 	pipe(p);

// 	fd = 1;
// 	dup2(p[1], fd);
// 	write(fd, "abcd\n", 5);
// 	write(fd, "efgh\n", 5);
// 	close(p[1]);
// 	dup2(out, fd);
// 	get_next_line(p[0], &line);
// 	assert(strcmp(line, "abcd") == 0);
// 	get_next_line(p[0], &line);
// 	assert(strcmp(line, "efgh") == 0);
// 	ret = get_next_line(p[0], &line);
// 	assert(ret == 0);
// }

// static void simple_string_2(void)
// {
// 	char 	*line;
// 	int		out;
// 	int		p[2];
// 	int		fd;
// 	int		ret;

// 	out = dup(1);
// 	pipe(p);

// 	fd = 1;
// 	dup2(p[1], fd);
// 	write(fd, "1nopqrst\n", 9);
// 	write(fd, "2nopqrst\n", 9);
// 	write(fd, "3nopqrst\n", 9);
// 	write(fd, "4nopqrst", 8);
// 	close(p[1]);
// 	dup2(out, fd);
// 	ret = get_next_line(p[0], &line);
// 	printf("%s (%d)\n", line, ret);
// 	assert(strcmp(line, "1nopqrst") == 0);
// 	ft_strdel(&line);
// 	ret = get_next_line(p[0], &line);
// 	printf("%s (%d)\n", line, ret);
// 	ft_strdel(&line);
// 	ret = get_next_line(p[0], &line);
// 	printf("%s (%d)\n", line, ret);
// 	ft_strdel(&line);
// 	ret = get_next_line(p[0], &line);
// 	printf("%s (%d)\n", line, ret);
// 	ft_strdel(&line);
// 	ret = get_next_line(p[0], &line);
// 	printf("%s (%d)\n", line, ret);
// 	ft_strdel(&line);
// }


/*
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

    if (argc == 1)
	{
        simple_string();
        // simple_string_1();
	}
	else if (argc == 2)
	{
		file = open(argv[1], O_RDONLY);
		while (get_next_line(file, &line) == 1)
		{
			ft_putendl(line);
			ft_strdel(&line);
		}
		ft_strdel(&line);
	}
	else if (argc == 3)
	{
		file = open(argv[1], O_RDONLY);
		while (get_next_line(file, &line) == 1)
			;
	}
	return (0);
}
