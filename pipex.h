/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:50:01 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/05/13 01:26:26 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>

char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c	);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *str, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_free(char **path, int x);
void	envcheck(char **envp, int ac, char *file);
void	ft_free2(char **path);
int		accpath(char **thepath, char *cmd);
char	*acceses(char *cmd);

#endif