/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 21:21:35 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/05/13 01:21:10 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	checkpath(char *path, char *pa, char *file)
{
	int		x;
	int		i;

	x = 0;
	if (ft_strnstr(path, "!path", ft_strlen(path)))
		x++;
	if (ft_strnstr(pa, "!path", ft_strlen(pa)))
	{	
		i = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (i < 0)
			write(1, "outfile does not open", 22);
		close(i);
		x++;
	}
	i = 0;
	while (x > 0)
	{
		write(2, "command not found\n", 19);
		x--;
		i++;
	}
	if (i == 2)
		exit (127);
}

char	*findpath(char *cmd, char **envp)
{
	char	*acc;
	char	*path;
	char	**thepath;
	int		x;

	x = 0;
	acc = acceses(cmd);
	if (acc)
		return (acc);
	while (!ft_strnstr(envp[x], "PATH=/", ft_strlen(envp[x])))
		x++;
	path = ft_strchr(envp[x], '/');
	thepath = ft_split(path, ':');
	x = accpath(thepath, cmd);
	if (access(thepath[x], X_OK) == -1 || cmd[0] == '\0' || cmd[0] == ' '
		|| ft_strnstr(thepath[x], "//", ft_strlen(thepath[x])))
		return (ft_free2(thepath), "!path");
	path = ft_free(thepath, x);
	return (path);
}

void	in_file(int *fds, char *path, char **arg, char *file)
{
	int	fd;
	int	exe;

	close(fds[0]);
	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		(perror(file), exit(1));
	dup2(fd, 0);
	close(fd);
	dup2(fds[1], 1);
	exe = execve(path, arg, NULL);
	if (exe == -1)
		exit(127);
}

void	out_file(int *fds, char *path, char **arg, char *file)
{
	int		fd;
	int		exe;

	close(fds[1]);
	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)
		(write(2, "outfile doesn't open", 21), exit(1));
	dup2(fd, 1);
	close(fd);
	dup2(fds[0], 0);
	exe = execve(path, arg, NULL);
	if (exe == -1)
		exit(127);
}

int	main(int ac, char **av, char **envp)
{
	char	*path[2];
	char	**arg;
	int		fds[2];
	int		id[2];

	envcheck(envp, ac, av[4]);
	path[0] = findpath(av[2], envp);
	path[1] = findpath(av[3], envp);
	checkpath(path[0], path[1], av[4]);
	if (pipe(fds) == -1)
		(perror("pipe doesn't work"), exit(EXIT_FAILURE));
	id[0] = fork();
	if (id[0] == 0)
	{
		arg = ft_split(av[2], ' ');
		in_file(fds, path[0], arg, av[1]);
	}
	arg = ft_split(av[3], ' ');
	out_file(fds, path[1], arg, av[4]);
}
