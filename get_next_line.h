/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhahmad <muhahmad@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:49:15 by muhahmad          #+#    #+#             */
/*   Updated: 2025/03/27 14:49:18 by muhahmad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42 // Set a default buffer size in case it is not set at compile time
#endif

size_t ft_strlen(const char *s);
void *ft_memcpy(void *dst, const void *src, size_t n);          // Called by `ft_substr()`
char *ft_substr(char const *s, unsigned int start, size_t len); // Needed to extract from the `stash`, a portion of the string up to the `\n` character, and the remaining portion
char *ft_strdup(const char *str);                               // Needed for copying of strings
char *ft_strjoin(char *s1, char *s2);                           // Needed to join the "leftovers" in `stash` from the previously read `\n`, to the characters next read
char *process_line(char **stash);                               // Needed to process lines read and extract a line up to the `\n`
char *read_from_fd(int fd);                                     // Needed to retrieve data read from the file descriptor
char *get_next_line(int fd);                                    // Our main function that will return a line extracted from a file

#endif
