/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 12:04:36 by dbessmer          #+#    #+#             */
/*   Updated: 2017/01/13 13:31:13 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*write_to_stat(char *stat)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (stat[i] != '\n')
		i++;
	i++;
	while (stat[i] != '\0')
		stat[j++] = stat[i++];
	stat[j] = '\0';
	return (stat);
}

char	*ft_read_from_stat(char *stat)
{
	int		i;
	char	*tmp;

	i = 0;
	while (stat[i] != '\n' && stat[i] != '\0')
		i++;
	tmp = ft_strnew(i);
	ft_strncpy(tmp, stat, i);
	return (tmp);
}

char	*ft_read(int fd, char **line, char *stat, int *value)
{
	long	i;
	int		ret;
	char	*buf;
	char	*tmp;

	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		i = 0;
		tmp = ft_strnew(BUFF_SIZE);
		while (*buf != '\n' && *buf != '\0' && i < BUFF_SIZE)
			tmp[i++] = *buf++;
		tmp[i] = '\0';
		*line = ft_strjoin(*line, tmp);
		if (*buf++ == '\n')
		{
			stat[0] = '\0';
			ft_strncat(stat, buf, (BUFF_SIZE - i + 1));
			*value = 1;
			return (stat);
		}
	}
	if (ret == -1)
		*value = -1;
	return (stat);
}

int		get_next_line(const int fd, char **line)
{
	int			i;
	static char	stat[BUFF_SIZE + 1];

	i = 0;
	*line = ft_strnew(BUFF_SIZE);
	if (stat[0])
	{
		*line = ft_read_from_stat(stat);
		while (stat[i] != '\0')
		{
			if (stat[i++] == '\n')
			{
				ft_strcpy(stat, write_to_stat(stat));
				return (1);
			}
		}
		stat[0] = '\0';
	}
	i = 0;
	ft_strcpy(stat, ft_read(fd, line, stat, &i));
	if (i == 1)
		return (1);
	if (i == -1)
		return (-1);
	return (0);
}
