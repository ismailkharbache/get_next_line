/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:28:03 by ikharbac          #+#    #+#             */
/*   Updated: 2021/12/18 15:51:39 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(char *str, int fd)
{
	int		r;
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];

	r = 1;
	if (!str)
		str = ft_strdup("");
	while (!ft_strchr(str, '\n') && (r != 0))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			free(str);
			str = NULL;
			return (0);
		}	
		buf[r] = '\0';
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	return (str);
}

char	*ft_check(int fd, char *str)
{
	if (fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	return (str);
}

char	*get_rest(char *str)
{
	char	*rest;

	rest = ft_strdup(ft_strchr(str, '\n') + 1);
	free(str);
	return (rest);
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*line;

	str[fd] = ft_check(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	if (ft_strlen(str[fd]) > 0 && !ft_strchr(str[fd], '\n'))
	{
		line = ft_strdup(str[fd]);
		ft_free(&str[fd]);
		return (line);
	}
	else if (ft_strchr(str[fd], '\n'))
	{
		line = ft_substr(str[fd], 0, ft_strchr(str[fd], '\n') - str[fd] + 1);
		if (*(ft_strchr(str[fd], '\n') + 1) != '\0')
			str[fd] = get_rest(str[fd]);
		else
			ft_free(&str[fd]);
		return (line);
	}
	ft_free(&str[fd]);
	return (0);
}
// int main ()
// {
// 	char *str;
// 	int fd;
// 	int df;
// 	fd = open("text.txt",O_RDONLY);
// 	df = open("text1.txt",O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(df));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(df));
// }
