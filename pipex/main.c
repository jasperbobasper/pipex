/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 12:39:43 by jpfannku          #+#    #+#             */
/*   Updated: 2021/09/14 19:35:05 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	infd;
	int	outfd;

	if (argc < 5)
		exit_msg("Pipex usage: ./pipex infile 'cmd1' 'cmd2' outfile\n");
	infd = open(argv[1], O_RDWR);
	if (infd < 0)
	{
		perror("Pipex");
		exit(0);
	}
	outfd = open(argv[4], O_RDWR);
	if (outfd < 0)
	{
		perror("Pipex");
		exit(0);
	}
	pipex(argv, envp, infd, outfd);
	return (0);
}
