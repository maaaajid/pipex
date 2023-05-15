/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:02:38 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/02/08 02:57:02 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

static void	free_arrays(char **error, int i)
{
	int	x;

	x = 0;
	while (x < i)
		free(error[x++]);
	free(error);
}

static int	contword(char const *s, char c)
{
	size_t	z;

	z = 0;
	if (!s)
		return (0);
	if (*s != c)
		z++;
	while (*s != '\0')
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
			if (*s == '\0')
				return (z);
			z++;
		}
		s++;
	}
	return (z);
}

static void	putarrey(char **arrays, char const *s, char c)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		j = i;
		while (s[i] && s[i] != c)
			i++;
		arrays[x] = ft_substr(s, j, i - j);
		if (! arrays[x])
			free_arrays(arrays, x);
		x++;
	}
	arrays[x] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arrays;

	if (!s)
		return (NULL);
	arrays = (char **)malloc((contword(s, c) + 1) * sizeof(char *));
	if (!arrays)
		return (NULL);
	putarrey(arrays, s, c);
	return (arrays);
}
