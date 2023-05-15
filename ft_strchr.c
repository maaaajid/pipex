/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouaa <aelbouaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 04:32:08 by aelbouaa          #+#    #+#             */
/*   Updated: 2023/02/07 21:39:45 by aelbouaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

char	*ft_strchr(const char *s, int c	)
{
	int		x;
	char	*ss;

	if (!s)
		return (NULL);
	x = 0;
	ss = (char *)s;
	if ((char)c == '\0')
		return (ss + ft_strlen(ss));
	while (ss[x])
	{
		if (ss[x] == (char)c)
			return (&ss[x]);
		x++;
	}
	return (NULL);
}
