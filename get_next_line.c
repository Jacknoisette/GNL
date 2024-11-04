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

static char *read_and_store(int fd, char *buffer, char *store)
{
    char *temp;
    ssize_t readbyte;

    readbyte = read(fd, buffer, BUFFER_SIZE);
    if (readbyte == -1)
        return (NULL);
    if (readbyte == 0)
        return (store);
    buffer[readbyte] = '\0';
    if (store != NULL)
    {
        temp = store;
        store = ft_strjoin(temp, buffer);
        free(temp);
    }
    else
		store = ft_strdup(buffer);
    return (store);
}

static char *extract_line(char **store)
{
    char *line;
    char *enl_pos;

    enl_pos = ft_strchr(*store, '\n');
    if (enl_pos != NULL)
    {
        line = ft_substr(*store, 0, enl_pos - *store + 1);
       * store = ft_strdup(enl_pos + 1);
    }
    else
    {
        line = ft_strdup(*store);
        *store = NULL;
    }
    return (line);
}

char *get_next_line(int fd)
{
	static char	*store;
	char	buffer[BUFFER_SIZE + 1] = {0};
	char *line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	store = read_and_store(fd, buffer, store);
	if (store != NULL)
		return (NULL);
	line = extract_line(&store);
	return (line);
}

int	main(void)
{
    char *line;
    int fd = open("file.txt", O_RDONLY);

    while ((line = get_next_line(0)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}