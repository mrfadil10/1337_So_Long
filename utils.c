/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfadil <mfadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:04:31 by mfadil            #+#    #+#             */
/*   Updated: 2023/05/15 14:29:16 by mfadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	s = malloc(count * size);
	if (!s)
		ft_error("Error: malloc error!", __FILE__, __LINE__);
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

void	ft_putnbr_fd(int nb, int fd)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
	}
	if (nb < 10)
	{
		c = (nb + '0');
		write(2, &c, 1);
	}
	else
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putnbr_fd((nb % 10), fd);
	}
}
