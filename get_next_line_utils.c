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

    i = 0;
    if (!s || !(sub = malloc((len + 1) * sizeof(char))))
        return (NULL);
    while (i < len && s[start + i] != '\0')
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

    len = ft_strlen(str);
    dup = (char *)malloc((len + 1) * sizeof(char));
    if (dup == NULL)
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

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
    if (join == NULL)
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
    int len;

    len = 0;

    if (!stash && !*stash)
        return (NULL);
    while ((*stash)[len] != '\n' && (*stash)[len] != '\0')
        len++;
    line = ft_substr(*stash, 0, len);
    if ((*stash)[len] == '\n')
        len++;
    temp = ft_strdup(*stash + len);
    free(*stash);
    *stash = temp;
    return (line);
}

int main(void)
{
    char *stash;
    char *line;

    // Test 1: Normal string with newline
    stash = ft_strdup("Hello\nWorld");
    line = ft_process_line(&stash);
    printf("Line: %s\n", line);   // Expected: "Hello"
    printf("Stash: %s\n", stash); // Expected: "World"
    free(line);
    free(stash);

    // Test 2: String without newline
    stash = ft_strdup("Test");
    line = ft_process_line(&stash);
    printf("Line: %s\n", line);   // Expected: "Test"
    printf("Stash: %s\n", stash); // Expected: ""
    free(line);
    free(stash);

    // Test 3: Empty string
    stash = ft_strdup("");
    line = ft_process_line(&stash);
    printf("Line: %s\n", line);   // Expected: ""
    printf("Stash: %s\n", stash); // Expected: ""
    free(line);
    free(stash);

    return (0);
}