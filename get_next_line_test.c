/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:54:32 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/31 17:52:52 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	char	**line;
	size_t	line_num;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		line_num = 0;
		line = (char **)ft_memalloc(sizeof(*line));
		while ((get_next_line(fd, line) > 0))
		{
			ft_putnbr(++line_num);
			ft_putstr(": ");
			ft_putendl(*line);
		}
	}
	return (0);
}
