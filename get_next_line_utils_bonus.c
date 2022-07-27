/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcattini <dcattini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:16:56 by dcattini          #+#    #+#             */
/*   Updated: 2022/06/23 20:35:06 by dcattini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	search_for_size(const char *buffer, int chr)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == chr)
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

char	*join_buffer(char *line, const char *buffer, int totalsize)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = malloc((totalsize + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (line != NULL && line[i] != '\0')
	{
		temp[i] = line[i];
		i++;
	}
	while (buffer && buffer[j])
	{
		temp[i++] = buffer[j];
		if (buffer[j] == '\n')
			break ;
		j++;
	}
	temp[i] = '\0';
	if (line)
		free(line);
	return (temp);
}

int	search_breakline(char *buffer)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (buffer[i])
	{
		if (flag == 0 && buffer[i] == '\n')
			flag = 1;
		else if (flag == 1)
			buffer[j++] = buffer[i];
		buffer[i++] = 0;
	}
	return (flag);
}
