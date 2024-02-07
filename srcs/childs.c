/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:40 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/18 14:09:21 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*get_command(t_exec exec, char **argv, int pos)
{
	char	*tmp;
	char	*path;
	int		exists;

	while (*(exec.cmd_paths))
	{
		tmp = ft_strjoin("/", exec.cmd_args[0]);
		path = ft_strjoin(*(exec.cmd_paths), tmp);
		if (!tmp || !path)
			error_msg(7, 0);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			exists = 1;
			if (access(path, X_OK) == 0)
				return (path);
			error_msg(10, argv[pos]);
		}
		(exec.cmd_paths)++;
		free(path);
	}
	error_msg(9, argv[pos]);
	return (0);
}

int	check_absolute_path(char *cmd, char **argv)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
			return (1);
		else
			error_msg(10, argv[3]);
	}
	return (0);
}

void	first_child(char **argv, t_exec exec, char **envp)
{
	int		original_stdout;

	input_check(argv, &exec, 1);
	original_stdout = dup(STDOUT_FILENO);
	exec.cmd_args = ft_split(argv[2], ' ');
	if (check_absolute_path(argv[2], argv))
		exec.cmd = argv[2];
	else
		exec.cmd = get_command(exec, argv, 2);
	dup2(exec.infile, STDIN_FILENO);
	dup2(exec.pipe_end[1], STDOUT_FILENO);
	close(exec.pipe_end[0]);
	close(exec.pipe_end[1]);
	execve(exec.cmd, exec.cmd_args, envp);
	dup2(original_stdout, STDOUT_FILENO);
	error_msg(8, 0);
}

void	second_child(char **argv, t_exec exec, char **envp)
{
	int		original_stdout;

	input_check(argv, &exec, 2);
	original_stdout = dup(STDOUT_FILENO);
	exec.cmd_args = ft_split(argv[3], ' ');
	if (check_absolute_path(argv[3], argv))
		exec.cmd = argv[3];
	else
		exec.cmd = get_command(exec, argv, 3);
	dup2(exec.pipe_end[0], STDIN_FILENO);
	dup2(exec.outfile, STDOUT_FILENO);
	close(exec.pipe_end[0]);
	close(exec.pipe_end[1]);
	execve(exec.cmd, exec.cmd_args, envp);
	dup2(original_stdout, STDOUT_FILENO);
	error_msg(8, 0);
}
