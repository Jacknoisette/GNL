/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 09:13:55 by jdhallen          #+#    #+#             */
/*   Updated: 2024/10/30 09:13:56 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETNEXTLINE
# define GETNEXTLINE
#ifndef BUFFER_SIZE
# define BUFFERSIZE 1024
#endif
#	include <unistd.h>
#	include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_subcpy(char *dest, const char *src, size_t start);

#endif