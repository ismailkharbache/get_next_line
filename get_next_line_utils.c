/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikharbac <ikharbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:45:30 by ikharbac          #+#    #+#             */
/*   Updated: 2021/12/18 15:45:44 by ikharbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen (s))
		p = (char *)malloc(sizeof(*s) * (len + 1));
	else
		p = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!p)
		return (NULL);
	while (s[i])
	{
		if (s[start] && j < len)
			p[j++] = s[start++];
		i++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != (unsigned char)c))
	{
		s++;
	}
	if (*s == (unsigned char)c)
	{
		return ((char *)s);
	}
	return ((char *) NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	size_t	i;

	if (s1 != NULL && s2 != NULL )
		i = (ft_strlen(s1)) + (ft_strlen(s2));
	else
		return (0);
	p = (char *)malloc(i + 1);
	if (!p)
		return (0);
	while (*s1)
		*p++ = *s1++;
	while (*s2)
		*p++ = *s2++;
	*p = '\0';
	return (p - i);
}

char	*ft_strdup(char *s)
{
	int		count;
	int		i;
	char	*p;

	i = 0;
	count = ft_strlen(s) + 1;
	p = malloc(count * sizeof(char));
	if (!p)
		return (0);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
