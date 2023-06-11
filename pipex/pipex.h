/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:11:40 by jpfannku          #+#    #+#             */
/*   Updated: 2021/09/14 17:11:05 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

void		pipex(char **argv, char **envp, int infd, int outfd);
void		out_process(int fdpipe[2], int outfd, char *cmdpath, char**cmdargs);
void		in_process(int fdpipe[2], int infd, char *cmdpath, char**cmdargs);
char		*cmdtest(char **paths, char *cmd);
char		*cmdpathfind(char **envp, char *cmd);
size_t		ft_strlen(const char *src);
void		*ft_calloc(size_t n, size_t size);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strnstr(const char *str, const char *substr, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		free_array(char **array);
void		exit_msg(char *msg);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);

#endif
