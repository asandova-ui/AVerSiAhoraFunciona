/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandova <asandova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 18:55:18 by marvin            #+#    #+#             */
/*   Updated: 2024/03/27 11:34:48 by asandova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_prog(char *map, t_game *game)
{
	ft_init_map(game, map);
	ft_init_vars(game);
	ft_check_map(game);
	check_route(game);
	ft_init_map(game, map);
	ft_init_mlx(game);
	ft_init_sprites(game);
	ft_print_map(game);
	mlx_key_hook(game->win_ptr, ft_handle_input, game);
	mlx_hook(game->win_ptr, 17, 0, ft_close_game, game);
	//mlx_hook(game->win_ptr, 17, 0, ft_print_map, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all_allocated_memory(game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	arg_checker(argc, argv, game);
	start_prog(argv[1], game);
	return (0);
}
