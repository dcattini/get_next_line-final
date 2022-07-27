/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcattini <dcattini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:11:00 by dcattini          #+#    #+#             */
/*   Updated: 2022/06/23 20:35:07 by dcattini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

char	*get_next_line(int fd);
char	*join_buffer(char *line, const char *buffer, int totalsize);

int		search_for_size(const char *buffer, int chr);
int		search_breakline(char *buffer);

#endif
