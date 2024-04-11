/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:49:38 by marvin            #+#    #+#             */
/*   Updated: 2024/03/30 19:49:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "../../printf/libft/libft.h"
#include "../../get_next_line/get_next_line.h"

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_free("No se ha podido encontran un puntero mlx", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	(game->map.columns+1) * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_free("No se ha podido crear la ventana", game);
	}
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game);

void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_new_sprite(mlx, "images/wall.xpm", game);
	game->floor = ft_new_sprite(mlx, "images/fondo.xpm", game);
	game->item = ft_new_sprite(mlx, "images/item.xpm", game);
	game->player = ft_new_sprite(mlx, "images/player.xpm", game);;
	game->exit = ft_new_sprite(mlx, "images/scape.xpm", game);
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	image;

	image.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &image.x, &image.y);
	if (image.xpm_ptr == NULL)
		ft_error_free("Error al cargar la imagen", game);
	return (image);
}