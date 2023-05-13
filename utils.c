/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:04:31 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/12 19:30:32 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	s = malloc(count * size);
	if (s == NULL)
		return (s);
	ft_memset(s, '\0', (size * count));
	return (s);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned int)c;
		i++;
	}
	return (b);
}

//size_t	ft_strlen(const char *s)
//{
//	int	i;

//	i = 0;
//	while (s[i])
//		i++;
//	return (i);
//}

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	int				j;
	unsigned char	ch;

	i = 0;
	j = 0;
	ch = (unsigned char)c;
	while (str[i])
	{
		if (str[i] == ch)
			j = i;
		i++;
	}
	if (str[i] == '\0' && ch == 0)
		return ((char *)str + i);
	else if (j > 0 || (j == 0 && str[j] == ch))
		return ((char *)str + j);
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
