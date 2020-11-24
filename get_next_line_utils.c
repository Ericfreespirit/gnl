/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eriling <eriling@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 09:58:29 by eriling           #+#    #+#             */
/*   Updated: 2020/11/17 11:45:11 by eriling          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ss;
	unsigned int	i;

	i = 0;
	if (!s || !(ss = malloc(sizeof(*ss) * (len + 1))))
		return (NULL);
	if (start < len)
	{
		while (s[start] && i < len)
			ss[i++] = s[start++];
	}
	ss[i] = '\0';
	return (ss);
}
size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*new_s;

	i = 0;
	while (s[i])
		i++;
	if (!(new_s = malloc(sizeof(*new_s) * (i + 1))))
		return (NULL);
	new_s[i] = '\0';
	i = 0;
	while (s[i])
	{
		new_s[i] = s[i];
		i++;
	}
	return (new_s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = malloc(sizeof(*dst) * (len + 1))))
		return (NULL);
	while (s1[i])
		dst[j++] = s1[i++];
	i = 0;
	while (s2[i])
		dst[j++] = s2[i++];
	dst[j] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ss;
	size_t	i;

	i = 0;
	ss = (char *)s;
	while (i <= ft_strlen(ss))
	{
		if (ss[i] == (char)c)
			return (&ss[i]);
		i++;
	}
	return (NULL);
}
void	ft_free_str(char **s)
{
	if (s != NULL && *s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}