/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcattini <dcattini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:16:30 by dcattini          #+#    #+#             */
/*   Updated: 2022/06/23 20:35:51 by dcattini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	int			flag;
	int			totalsize;

	totalsize = 0;
	line = NULL;
	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
		return (line);
	while (1)
	{
		flag = 1;
		if (!buffer[0])
		{
			flag = read(fd, buffer, BUFFER_SIZE);
		}
		totalsize += search_for_size(buffer, '\n');
		if (flag > 0)
		{
			line = join_buffer(line, buffer, totalsize);
		}
		if (flag <= 0 || search_breakline(buffer) == 1)
			break ;
	}
	return (line);
}

/*int	main(void)
{
	int		fd;
 	char	*s;

 	s = NULL;
 	fd = open("Notas.txt", O_RDONLY);
 	if ((fd) == -1)
 	{
 		printf("file opening failed\n");
 		exit(0);
 	}
 	s = get_next_line(fd);
 	while (s)
 	{
 		printf("%s", s);
 		if (s)
 			free(s);
 		s = get_next_line(fd);
 	}
 	return (0);
}*/