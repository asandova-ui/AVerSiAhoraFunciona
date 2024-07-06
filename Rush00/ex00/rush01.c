/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanz-pa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:22:02 by psanz-pa          #+#    #+#             */
/*   Updated: 2024/07/06 08:52:42 by psanz-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	extremo_superior(int n_columnas, int y)
{
	while (y <= n_columnas)
	{
		if (y == 1)
			ft_putchar('/');
		else if (y != n_columnas)
			ft_putchar('*');
		else if (y == n_columnas)
			ft_putchar('\\');
		y++;
	}
}

void	extremo_inferior(int n_columnas, int y)
{
	while (y <= n_columnas)
	{
		if (y == 1)
			ft_putchar('\\');
		else if (y != n_columnas)
			ft_putchar('*');
		else if (y == n_columnas)
			ft_putchar('/');
		y++;
	}
}

void	cuerpo(int n_columnas, int y)
{
	while (y <= n_columnas)
	{
		if (y == 1)
			ft_putchar('*');
		else if (y != n_columnas)
			ft_putchar(' ');
		else if (y == n_columnas)
			ft_putchar('*');
		y++;
	}
}

void	rush(int n_columnas, int n_filas)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	if ((n_columnas > 0) && (n_filas > 0))
	{
		extremo_superior(n_columnas, y);
		ft_putchar('\n');
		if (n_filas > 2)
		{
			x = x + 2;
			while (x <= n_filas)
			{
				y = 1;
				cuerpo(n_columnas, y);
				ft_putchar('\n');
				x++;
			}
		}
		if (n_filas >= 2)
		{
			y = 1;
			extremo_inferior(n_columnas, y);
			ft_putchar('\n');
		}
	}
	if (n_filas <= 0)
	{
		write(1, "¿Qué haces poniendo 0 filas, crack?", 38);
		ft_putchar('\n');
	}
	if (n_columnas <= 0)
	{
		write(1, "¿Qué haces poniendo 0 columnas, crack?", 41);
		ft_putchar('\n');
	}
	if ((n_filas <= 0) && (n_columnas <= 0))
	{
		write(1, "No intentes buscar errores anda", 31);
		ft_putchar('\n');
	}
}

