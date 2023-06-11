/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:04:57 by jpfannku          #+#    #+#             */
/*   Updated: 2021/09/14 17:08:07 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;
	int		x;
	int		y;

	x = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)ft_calloc(size + 2, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[x] != 0)
	{
		str[x] = s1[x];
		x++;
	}
	str[x] = '/';
	x++;
	y = 0;
	while (s2[y] != 0)
	{
		str[x] = s2[y];
		x++;
		y++;
	}
	return (str);
}
