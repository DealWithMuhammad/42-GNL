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
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

size_t ft_strlen(const char *s);                                // Needed for string length calculation
void *ft_memcpy(void *dst, const void *src, size_t n);          // Needed for copying of strings
char *ft_substr(char const *s, unsigned int start, size_t len); // Needed to extract from the `stash`, a portion of the string up to the `\n` character, and the remaining portion
char *ft_strdup(const char *str);                               // Needed for copying of strings
char *ft_strjoin(char *s1, char *s2);                           // Needed to join the "leftovers" in `stash` from the previously read `\n`, to the characters next read
char *ft_process_line(char **stash);                            // Needed to process lines read and extract a line up to the `\n`
char *read_from_fd(int fd);                                     // Needed to retrieve data read from the file descriptor
char *get_next_line(int fd);
char *get_next_line_helper(char **stash, int fd); //  Main function that will return a line extracted from a file

#endif
