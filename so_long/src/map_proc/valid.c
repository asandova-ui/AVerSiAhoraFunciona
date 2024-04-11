/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:14:25 by marvin            #+#    #+#             */
/*   Updated: 2024/04/04 18:14:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../printf/libft/libft.h"
#include "../../get_next_line/get_next_line.h"

static void	floodfill(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->columns || y < 0 || y >= map->rows || map->full[y][x] == '1' || map->full[y][x] == 'F')
		return;
	if (map->full[y][x] == 'E')
	{
		map->full[y][x] = 'F';
		return;
	}
	map->full[y][x] = 'F';
	floodfill(map, x, y - 1); // Arriba
	floodfill(map, x, y + 1); // Abajo
	floodfill(map, x - 1, y); // Izquierda
	floodfill(map, x + 1, y); // Derecha
}


int	check_route(t_game *game)
{
	int	x, y;

	x = game->map.player.x;
	y = game->map.player.y;

	floodfill(&game->map, x, y);

	for (int i = 0; i < game->map.rows; i++) {
		for (int j = 0; j < game->map.columns; j++) {
			if (game->map.full[i][j] == 'P' || game->map.full[i][j] == 'E' || game->map.full[i][j] == 'C') {
				ft_error_free("Mapa imposible de ganar", game);
				return (0);
			}
		}
	}
	return (0);
}
