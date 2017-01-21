/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 10:37:39 by dbessmer          #+#    #+#             */
/*   Updated: 2017/01/20 12:56:48 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

static char	*ft_join(char *s, char *s2)
{
        size_t	i;
        size_t	j;
        char	*str;
        size_t	len;

        i = 0;
        j = 0;
        len = ft_strlen(s) + ft_strlen(s2);
        str = (char*)malloc(sizeof(char) * (len + 1));
        if (!str)
                return (0);
        while (s[j] != '\0')
                str[i++] = s[j++];
        j = 0;
        while (s2[j] != '\0')
                str[i++] = s2[j++];
        str[i] = '\0';
        free(s);
        free(s2);
        return (str);
}

static int    write_to_stat_or_return(char *stat, char *buf, int i, int num)
{
        if (num < 0)
        {
                free(buf);
                return (-1);
        }
        i++;
        stat[0] = '\0';
        ft_strcpy(stat, &buf[i]);
        free(buf);
        return (1);
}

static int    ft_read(char **line, char *stat, int fd)
{
        int 	i;
        int		j;
        int     num;
        char    *buf;
        char	*tmp;

        i = 0;
        buf = ft_strnew(BUFF_SIZE);
        while ((num = read(fd, buf, BUFF_SIZE)))
        {
                i = 0;
                j = 0;
                if (num == -1)
                        return (write_to_stat_or_return(stat, buf, i, num));
                tmp = ft_strnew(BUFF_SIZE);
                while (buf[i] != '\n' && buf[i] != '\0' && i < num)
                        tmp[j++] = buf[i++];
                *line = ft_join(*line, tmp);
                if (buf[i] == '\n')
                        return (write_to_stat_or_return(stat, buf, i, num));
        }
        free(buf);
        if (i > 0 && i <= BUFF_SIZE)
                return (1);
        return (0);
}

int	get_next_line(const int fd, char **line)
{
        int		i;
        static char	stat[BUFF_SIZE];
        char		*tmp;

        i = 0;
        if (!line || fd < 0 || !(*line = ft_strnew(BUFF_SIZE)))
                return (-1);
        if (stat[0])
        {
                while (stat[i] != '\n' && stat[i] != '\0')
                        i++;
                tmp = ft_strnew(i);
                ft_strncat(tmp, stat, i);
                *line = ft_join(*line, tmp);
                if (stat[i] == '\n')
                {
                        ft_strcpy(stat, &stat[++i]);
                        return (1);
                }
                stat[0] = '\0';
        }
        i = ft_read(line, stat, fd);
        return (i);
}
