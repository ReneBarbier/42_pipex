/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:35:51 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/15 15:50:02 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

typedef struct s_exec
{
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		infile;
	int		outfile;
	int		pipe_end[2];
	int		pid1;
	int		pid2;
}	t_exec;

void	input_check(char **argv, t_exec *exec, int child);
void	error_msg(int err_type, char *name);
void	put_exitcode(int err_type);
void	first_child(char **argv, t_exec exec, char **envp);
void	second_child(char **argv, t_exec exec, char **envp);

#endif