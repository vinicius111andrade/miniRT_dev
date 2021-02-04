/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-melo <vde-melo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:14:05 by vde-melo          #+#    #+#             */
/*   Updated: 2020/11/27 23:07:19 by vde-melo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*gnl_calloc(size_t count, size_t size)
{
	char		*ptr;
	int			len;
	int			i;

	i = 0;
	ptr = (char *)malloc(count * size);
	len = count * size;
	if (!ptr)
		return (0);
	while (len)
	{
		ptr[i] = 0;
		i++;
		len--;
	}
	return (ptr);
}

void	ft_delstr(char **c)
{
	if (c != 0)
	{
		free(*c);
		*c = 0;
	}
}

int		copy_line(char **line, char **s, int fd)
{
	int			i;
	char		*aux;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_substr(s[fd], 0, i);
		aux = ft_strdup(&s[fd][i + 1]);
		free(s[fd]);
		s[fd] = aux;
		if (s[fd][0] == '\0')
			ft_delstr(&s[fd]);
	}
	else
	{
		*line = ft_strdup(s[fd]);
		ft_delstr(&s[fd]);
		return (0);
	}
	return (1);
}

int		check_read(int reading, char **line, char **s, int fd)
{
	if (reading < 0)
		return (-1);
	if (reading == 0 && s[fd] == 0)
	{
		*line = ft_calloc(1, 1);
		return (0);
	}
	return (copy_line(line, s, fd));
}

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*s[OPEN_MAX];
	char		*aux;
	int			reading;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	while ((reading = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[reading] = 0;
		if (s[fd] == 0)
			s[fd] = ft_strdup(buffer);
		else
		{
			aux = ft_strjoin(s[fd], buffer);
			free(s[fd]);
			s[fd] = aux;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	ft_delstr(&buffer);
	return (check_read(reading, line, s, fd));
}
