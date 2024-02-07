/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:34:47 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/18 14:27:54 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
/*
pipe ends:
fd[0] read end
fd[1] write end
*/

char	*find_path(char **envp, char **argv)
{
	while (ft_strncmp("PATH", *envp, 4))
	{
		envp++;
		if (!envp || !*envp)
		{
			write(2, "Pipex: ", 7);
			write(2, argv[2], ft_strlen(argv[2]));
			write(2, ": command not found\n", 20);
			write(2, "Pipex: ", 7);
			write(2, argv[3], ft_strlen(argv[3]));
			write(2, ": command not found\n", 20);
			exit(127);
		}
	}
	return (*envp + 5);
}

int	main(int argc, char **argv, char **envp)
{
	t_exec	exec;
	int		ret;

	if (argc != 5)
		error_msg(1, 0);
	if (pipe(exec.pipe_end) == -1)
		error_msg(5, 0);
	exec.path = find_path(envp, argv);
	exec.cmd_paths = ft_split(exec.path, ':');
	exec.pid1 = fork();
	if (exec.pid1 < 0)
		error_msg(6, 0);
	if (exec.pid1 == 0)
		first_child(argv, exec, envp);
	exec.pid2 = fork();
	if (exec.pid2 < 0)
		error_msg(6, 0);
	if (exec.pid2 == 0)
		second_child(argv, exec, envp);
	close(exec.pipe_end[0]);
	close(exec.pipe_end[1]);
	waitpid(exec.pid1, NULL, 0);
	waitpid(exec.pid2, &ret, 0);
	exit(WEXITSTATUS(ret));
}
