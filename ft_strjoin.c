/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:28:45 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/02/07 21:42:09 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*m;
	size_t	x;
	size_t	z;

	if (!s1 || !s2)
		return (NULL);
	x = ft_strlen(s1) + ft_strlen(s2) +2;
	z = 0;
	m = (char *)malloc(x * sizeof(char));
	if (!m)
		return (NULL);
	x = 0;
	while (s1[x] != '\0')
	{
		m[x] = s1[x];
		x++;
	}
	m[x] = '/';
	x++;
	while (s2[z] != '\0' && s2[z] != ' ')
		m[x++] = s2[z++];
		m[x] = '\0';
	return (free(s1), m);
}
