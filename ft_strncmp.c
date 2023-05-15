/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:21:50 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/02/07 22:10:47 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			x;
	unsigned char	*s;
	unsigned char	*ss;

	s = (unsigned char *)s1;
	ss = (unsigned char *)s2;
	x = 0;
	if (n == 0)
		return (0);
	while (x < n - 1 && s[x] && ss[x])
	{
		if (s[x] != ss[x])
			return (s[x] - ss[x]);
		x++;
	}
	if ((s[x] == '\0') && (ss[x] == '\0'))
		return (s[x] - ss[x]);
	return (s[x] - ss[x]);
}
