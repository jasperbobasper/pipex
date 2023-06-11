/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 12:23:36 by jpfannku          #+#    #+#             */
/*   Updated: 2021/09/14 12:55:39 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*cmdpathfind(char **envp, char *cmd)
{
	char	**paths;
	char	*cmddest;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 6) == NULL)
		i++;
	paths = ft_split(envp[i], ':');
	if (!paths)
		exit_msg("Pipex: Paths not found\n");
	cmddest = cmdtest(paths, cmd);
	if (!cmddest)
		exit_msg("Pipex: Command not found\n");
	return (cmddest);
}

char	*cmdtest(char **paths, char *cmd)
{
	int		i;
	char	*cmddest;

	i = 0;
	while (paths[i] != NULL)
	{
		cmddest = ft_strjoin(paths[i], cmd);
		if (!cmddest)
			return (NULL);
		if (access(cmddest, F_OK) == -1)
		{
			free(cmddest);
			i++;
		}
		else
		{
			free_array(paths);
			return (cmddest);
		}
	}
	free_array(paths);
	exit_msg("Pipex: Command not found\n");
	return (NULL);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
}

void	exit_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(0);
}
