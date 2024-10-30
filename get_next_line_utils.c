/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:13:44 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/30 09:13:45 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((unsigned char)c == '\0')
	{
		while (s[i] != '\0')
			i++;
		return ((char *)s + i);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

void	ft_subcpy(char **dest, const char *src, size_t start)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = start;
	while (src[j] != '\0')
		(*dest)[i++] = src[j++];
}