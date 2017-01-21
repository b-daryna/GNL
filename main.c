/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbessmer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 09:53:24 by dbessmer          #+#    #+#             */
/*   Updated: 2017/01/20 12:38:54 by dbessmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <regex.h>
# include <assert.h>

int		main(int argc, char **argv)
{
        int fd;
        char *str;


       // fd = 0;
       fd = open(argv[1], O_RDONLY);
      //  while (get_next_line(fd, &str) == 1)
        //        printf("%s\n", str);
        get_next_line(fd, &str);
        printf("%s---\n", str);

        printf("%i", strcmp(str, "oiuytrew"));
   //     get_next_line(fd, &str);

        /*
        char      *line;
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
        printf("%i\n",strcmp(line, "abcdefgh"));
        printf("%s\n", line);
        get_next_line(p[0], &line);
        printf("%i\n",strcmp(line, "ijklmnop"));
        printf("%s\n", line);
        */
        return (0);
}
