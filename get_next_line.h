/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:38:26 by dbessmer          #+#    #+#             */
/*   Updated: 2017/01/13 13:31:21 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#include "./libft/libft.h"
# define BUFF_SIZE  10

char	*write_to_stat(char *stat);
char	*ft_read_from_stat(char *stat);
char	*ft_read(int fd, char **line, char *stat, int *value);
int		get_next_line(const int fd, char **line);

#endif
