/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:13:12 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/30 09:13:20 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char	*buffer[BUFFERSIZE] = {0};
	ssize_t readbyte;
	char *store;
	size_t	i;
	
	i = 0;
	if (ft_strchr(buffer, '\n') != NULL)
	{
		store = (char *)malloc((strendl(buffer) + 1) * sizeof(char));
		if (store == NULL)
			return (NULL);
		while (buffer[i] != 'n')
			store[i++] == buffer[i];
		ft_subcpy(buffer, buffer, i);
		return (store[i] = '\0', store);
	}
	readbyte = read(fd, *buffer, BUFFERSIZE);
	if (readbyte == 0 || readbyte == -1)
		return (NULL);
	if (readbyte < BUFFERSIZE)
	{
	}
}



ssize_t strendl(char *buf)
{
	int	i;

	i = 0;
	while(i != '\n')
		i++;
	return (i);
}