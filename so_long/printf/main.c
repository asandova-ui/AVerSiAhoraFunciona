/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:09:22 by asandova            #+#    #+#             */
/*   Updated: 2023/10/02 16:22:08 by asandova           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/ft_printf.h"

int	main(void)
{
	int	cant;

	cant = ft_printf(" %d ", 123);
	printf("Numero de caracteres que escribo: %d", cant);
	return (0);
}
