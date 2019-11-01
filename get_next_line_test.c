/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:54:32 by jkauppi           #+#    #+#             */
/*   Updated: 2019/11/01 13:20:30 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int			main(int argc, char **argv)
{
	char		**line;
	size_t		line_num;
	int			index;
	int			fd_array[FD_SIZE];
	char		**line_buffer[FD_SIZE];
	int			are_lines;

	if (argc > 1)
	{
		index = 0;
		ft_memset(fd_array, 0, FD_SIZE);
		while (++index < argc)
		{
			fd_array[index - 1] = open(argv[index], O_RDONLY);
			line = (char **)ft_memalloc(sizeof(*line));
			line_buffer[index - 1] = (char **)ft_memalloc(sizeof(**line_buffer));
		}
		line_num = 0;
		are_lines = 1;
		while (are_lines)
		{
			are_lines = 0;
			index = 0;
			line_num++;
			while (index < FD_SIZE && fd_array[index])
			{
				if ((get_next_line(fd_array[index], line_buffer[index]) > 0))
				{
					ft_putnbr(line_num);
					ft_putstr(": ");
					ft_putendl(*line_buffer[index]);
					are_lines = 1;
				}
				else
					fd_array[index] = 0;
				index++;
			}
		}
	}
	return (0);
}
