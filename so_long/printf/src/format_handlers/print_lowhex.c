/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_minushex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:38:44 by asandova            #+#    #+#             */
/*   Updated: 2023/09/29 18:31:27 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../libft/libft.h"

int	print_minushex(va_list args, int fd)
{
	char	*value;
	int		n;
	int		length;

	n = va_arg(args, unsigned int);
	value = ft_itoa_base(n, "0123456789abcdef");
	ft_putstr_fd(value, fd);
	length = ft_strlen(value);
	free((void *)value);
	return (length);
}
