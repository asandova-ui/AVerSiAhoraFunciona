/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:42:11 by asandova            #+#    #+#             */
/*   Updated: 2023/10/01 13:12:32 by asandova           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		c;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen2(s1) + ft_strlen2(s2) + 1));
	if (!str)
		return (remix_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen2(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr2(char *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!str)
		return (NULL);
	if (start > ft_strlen2(str))
	{
		res = (char *)malloc(sizeof(char));
		if (!res)
			return (NULL);
		*res = '\0';
		return (res);
	}
	if (ft_strlen2(str) - start < len)
		len = ft_strlen2(str) - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen2(str) && i < len && str[start])
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}

char	*ft_strchr2(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] == (char)c)
			return (&((char *)str)[i]);
	if (str[i] == (char)c)
		return (&((char *)str)[i]);
	return (0);
}

char	*ft_strdup2(char *str)
{
	char	*ret;
	int		i;

	ret = (char *)malloc(sizeof(char) * (ft_strlen2(str) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (str[++i])
		ret[i] = str[i];
	ret[i] = '\0';
	return (ret);
}
