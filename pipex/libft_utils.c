/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfannku <jpfannku@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 11:51:09 by jpfannku          #+#    #+#             */
/*   Updated: 2021/09/14 17:08:13 by jpfannku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	i;
	size_t	ii;

	if (substr[0] == 0)
		return ((char *)str);
	i = 0;
	while (i < n && str[i])
	{
		ii = 0;
		while (str[i + ii] == substr[ii] && (i + ii) < n && str[i + ii])
		{
			ii++;
			if (substr[ii] == 0)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t n, size_t size)
{
	size_t	i;
	size_t	sz;
	char	*str;

	i = 0;
	sz = n * size;
	str = malloc(sz);
	if (!str)
		return (NULL);
	while (i < sz)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

size_t	ft_strlen(const char *src)
{
	size_t	y;

	y = 0;
	while (src[y] != 0)
	{
		y++;
	}
	return (y);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	x;

	x = 0;
	while (s[x] != 0)
	{
		write(fd, &s[x], 1);
		x++;
	}
}

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	srclength;

	i = 0;
	srclength = ft_strlen((char *)src);
	if (destsize == 0)
	{
		return (srclength);
	}
	if (destsize > 0)
	{
		while (src[i] != '\0' && i < (destsize - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srclength);
}
