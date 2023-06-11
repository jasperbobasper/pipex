/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_split.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jpfannku <jpfannku@student.42wolfsburg.	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/09/10 15:38:57 by jpfannku		  #+#	#+#			 */
/*   Updated: 2021/09/10 16:55:30 by jpfannku		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "pipex.h"

static size_t	skip_c(char const *s, char c, size_t i)
{
	size_t	count;

	count = 0;
	while (s[i] == c)
	{
		i++;
		count++;
	}
	return (count);
}

static void	ft_free(char **array, int i)
{
	i--;
	while (i != 0)
	{
		free(array[i]);
		i--;
	}
	free(array);
	exit_msg("Pipex: failed to create array");
}

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s[0])
		return (0);
	if (s[0] == c)
		i += skip_c(s, c, i);
	while (s[i])
	{
		if (s[i] == c)
		{
			i += skip_c(s, c, i);
			count++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static char	*get_substr(char const *s, char c, size_t *i)
{
	size_t	count;
	char	*substr;

	count = 0;
	substr = 0;
	while (s[*i] != c && s[*i])
	{
		if (s[*i + 1] == c || s[*i + 1] == '\0')
		{
			substr = (char *)malloc(sizeof(char) * (count + 2));
			if (!substr)
				return (NULL);
			ft_strlcpy(substr, &s[*i - count], count + 2);
			*i += skip_c(s, c, *i + 1);
			return (substr);
		}
		else
			(*i)++;
		count++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**end_array;

	i = 0;
	j = 0;
	i += skip_c(s, c, i);
	end_array = (char **)malloc(sizeof(char *) * ((word_count(s, c) + 1)));
	if (!end_array)
		return (NULL);
	while (j < word_count(s, c))
	{
		end_array[j] = get_substr(s, c, &i);
		if (!end_array[j])
			ft_free(end_array, j);
		i++;
		j++;
	}
	end_array[j] = NULL;
	return (end_array);
}
