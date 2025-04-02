/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhahmad <muhahmad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:49:09 by muhahmad          #+#    #+#             */
/*   Updated: 2025/03/27 14:49:10 by muhahmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *get_next_line_helper(char **stash, int fd)
{
    char *tmp_stash;
    char *line_read;
    char *line;

    line = ft_process_line(stash);
    if (line)
        return (line);
    line_read = read_from_fd(fd);
    if (!line_read)
    {
        line = ft_strdup(*stash);
        free(*stash);
        *stash = (NULL);
        if (*line)
            return (line);
        free(line);
        return (NULL);
    }
    tmp_stash = ft_strjoin(*stash, line_read);
    free(*stash);
    *stash = tmp_stash;
    free(line_read);
    return (get_next_line_helper(stash, fd));
}

char *get_next_line(int fd)
{
    static char *stash;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    if (!stash)
        stash = ft_strdup("");
    return (get_next_line_helper(&stash, fd));
}

// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("text.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }

//     close(fd);
//     return (0);
// }
