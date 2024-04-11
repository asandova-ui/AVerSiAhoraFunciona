/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>              +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:55:29 by asandova            #+#    #+#           */
/*   Updated: 2023/09/18 17:55:29 by asandova           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *hayt_stack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!needle[i])
		return ((char *)hayt_stack);
	while (i < len && hayt_stack[i])
	{
		if (hayt_stack[i] == needle[0])
		{
			j = 1;
			while (needle[j] && hayt_stack[i + j] == needle[j] && (i + j) < len)
				j++;
			if (needle[j] == '\0')
				return ((char *)hayt_stack + i);
		}
		i++;
	}
	return (0);
}
