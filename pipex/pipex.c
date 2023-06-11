/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:44:10 by jpfannku          #+#    #+#             */
/*   Updated: 2021/09/14 13:17:31 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	in_process(int fdpipe[2], int infd, char *cmd1, char **envp)
{
	char	*cmdpath;
	char	**cmdargs;

	cmdargs = ft_split(cmd1, ' ');
	if (!cmdargs)
		exit_msg("Pipex: Failed to assign mem\n");
	cmdpath = cmdpathfind(envp, cmdargs[0]);
	if (dup2(infd, STDIN_FILENO) == -1)
		exit_msg("Failed to connect input");
	if (dup2(fdpipe[1], STDOUT_FILENO) == -1)
		exit_msg("Failed to connect output");
	close(fdpipe[0]);
	close(fdpipe[1]);
	if (execve(cmdpath, cmdargs, NULL) < 0)
		perror("Pipex cmd 1");
}

void	out_process(int fdpipe[2], int outfd, char *cmd2, char **envp)
{
	char	*cmdpath;
	char	**cmdargs;

	cmdargs = ft_split(cmd2, ' ');
	cmdpath = cmdpathfind(envp, cmdargs[0]);
	if (dup2(fdpipe[0], STDIN_FILENO) == -1)
		exit_msg("Pipex: Failed to connect input\n");
	if (dup2(outfd, STDOUT_FILENO) == -1)
		exit_msg("Pipex: Failed to connect output\n");
	close(fdpipe[0]);
	close(fdpipe[1]);
	if (execve(cmdpath, cmdargs, NULL) < 0)
		perror("Pipex cmd 2");
}

void	pipex(char **argv, char **envp, int infd, int outfd)
{
	int		fdpipe[2];
	int		status;
	pid_t	inpid;
	pid_t	outpid;

	pipe(fdpipe);
	inpid = fork();
	if (inpid < 0)
		return (perror("Fork"));
	if (inpid == 0)
		in_process(fdpipe, infd, argv[2], envp);
	outpid = fork();
	if (outpid < 0)
		return (perror("Fork"));
	if (outpid == 0)
		out_process(fdpipe, outfd, argv[3], envp);
	close(fdpipe[0]);
	close(fdpipe[1]);
	waitpid(inpid, &status, 0);
	waitpid(outpid, &status, 0);
}
