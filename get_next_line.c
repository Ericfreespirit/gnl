/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:09:28 by eriling           #+#    #+#             */
/*   Updated: 2020/11/24 17:41:01 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static int	save_line(char **str, char **line)
{
	int		l;
	char	*tmp;

	l = 0;
	while ((*str)[l] != '\n' && (*str)[l] != '\0')
		l++;
	if ((*str)[l] == '\n')
	{
		*line = ft_substr(*str, 0, l);
		tmp = ft_strdup(&((*str)[l + 1]));
		ft_free_str(str);
		*str = tmp;
		if ((**str) == '\0')
			ft_free_str(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_free_str(str);
	}
	return (1);
}

static int	filter(char **str, int fd, char **line, int r)
{
	if (r == 0 && !str[fd])
		return (0);
	else if (r < 0)
		return (-1);
	return (save_line(&str[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			r;
	char		*tmp;
	static char	*str[4096];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || !line)
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (!str[fd])
		{
			str[fd] = ft_strdup(buff);
		}
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
		if (ft_strchr(str[fd], '\n'))
		{
			break ;
		}
	}
	return (filter(str, fd, line, r));
}

int		main(void)
{
	char	*line;
	int		file;
	int		file2;
	int		res;

	file = open("./test1.txt", O_RDONLY);
	res = 1;
	while (res > 0)
	{
		res = get_next_line(file, &line);
		if (res != -1)
		{
			printf(res ? "%s\n" : "%s", line);
			free(line);
		}
		else
		{
			printf("error -1");
			return (0);
		}
	}
	close(file);
	return (0);
}
