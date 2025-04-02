/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhahmad <muhahmad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:49:06 by muhahmad          #+#    #+#             */
/*   Updated: 2025/03/28 15:35:00 by muhahmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
size_t ft_strlen(const char *s)
{
    size_t i;

    if (!s)
        return (0);
    i = 0;
    while (s[i] != '\0')
        i++;

    return (i);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i;

    i = 0;
    if (dst == NULL && src == NULL)
        return (NULL);
    while (i < n)
    {
        ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
        i++;
    }
    return (dst);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub;
    size_t i;
    size_t s_len;

    if (!s)
        return (NULL);
    s_len = ft_strlen(s);
    if (start >= s_len)
        return (ft_strdup(""));
    if (len > s_len - start)
        len = s_len - start;
    sub = (char *)malloc((len + 1) * sizeof(char));
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len && s[start + i])
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}

char *ft_strdup(const char *str)
{
    size_t len;
    char *dup;

    if (!str)
        return (ft_strdup(""));
    len = ft_strlen(str);
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (!dup)
        return (NULL);
    ft_memcpy(dup, str, len);
    dup[len] = '\0';
    return (dup);
}

char *ft_strjoin(char *s1, char *s2)
{
    char *join;
    size_t len1;
    size_t len2;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (!join)
        return (NULL);
    ft_memcpy(join, s1, len1);
    ft_memcpy(join + len1, s2, len2);
    join[len1 + len2] = '\0';
    return (join);
}

char *ft_process_line(char **stash)
{
    char *line;
    char *temp;
    size_t len;

    if (!*stash || !**stash)
        return (NULL);

    len = 0;
    while ((*stash)[len] && (*stash)[len] != '\n')
        len++;

    if ((*stash)[len] == '\n')
    {
        line = ft_substr(*stash, 0, len + 1); // Include '\n'
        if ((*stash)[len + 1])                // If there's content after newline
            temp = ft_strdup(*stash + len + 1);
        else
            temp = ft_strdup("");

        free(*stash);
        *stash = temp;
        return (line);
    }

    return (NULL);
}

char *read_from_fd(int fd)
{
    char *buffer;
    ssize_t bytes_read;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
    {
        free(buffer);
        return (NULL);
    }

    buffer[bytes_read] = '\0';
    return (buffer);
}

// int main(void)
// {
//     char *stash;
//     char *line;

//     // Test 1: Normal string with newline
//     stash = ft_strdup("Hello\nWorld");
//     line = ft_process_line(&stash);
//     printf("Line: %s\n", line);   // Expected: "Hello"
//     printf("Stash: %s\n", stash); // Expected: "World"
//     free(line);
//     free(stash);

//     // Test 2: String without newline
//     stash = ft_strdup("Test");
//     line = ft_process_line(&stash);
//     printf("Line: %s\n", line);   // Expected: "Test"
//     printf("Stash: %s\n", stash); // Expected: ""
//     free(line);
//     free(stash);

//     // Test 3: Empty string
//     stash = ft_strdup("");
//     line = ft_process_line(&stash);
//     printf("Line: %s\n", line);   // Expected: ""
//     printf("Stash: %s\n", stash); // Expected: ""
//     free(line);
//     free(stash);

//     return (0);
// }