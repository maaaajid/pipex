/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:28:59 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/05/13 01:24:23 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_free2(char **path)
{
	int	x;

	x = 0;
	while (path[x])
	{
		free(path[x]);
		x++;
	}
	free(path);
}

char	*ft_free(char **path, int x)
{
	int		i;
	char	*pat;

	i = 0;
	pat = ft_strdup(path[x]);
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
	return (pat);
}

int	accpath(char **thepath, char *cmd)
{
	int	x;

	x = 0;
	while (thepath[x])
	{
		thepath[x] = ft_strjoin(thepath[x], cmd);
		if (access(thepath[x], X_OK) == 0)
			break ;
		x++;
	}
	return (x);
}

char	*acceses(char *cmd)
{
	char	**thepath;

	thepath = ft_split(cmd, ' ');
	if (access(thepath[0], X_OK) == 0)
	{
		if (thepath[0][0] == '.' || thepath[0][0] == '/')
			return (ft_free(thepath, 0));
	}
	ft_free2(thepath);
	return (NULL);
}

void	envcheck(char **envp, int ac, char *file)
{
	int	i;

	i = 0;
	if (ac != 5)
		(write(2, "!!! wrong number of arguments\n", 30), exit (2));
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=/", ft_strlen(envp[i])))
			break ;
		i++;
	}
	if (envp[i])
		return ;
	i = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (i < 0)
		write(1, "outfile does not open", 22);
	write(1, "command not found\n", 19);
	write(1, "command not found\n", 19);
	exit (127);
}
