/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasanca <sasanca@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:17:46 by sasanca           #+#    #+#             */
/*   Updated: 2024/02/03 15:17:47 by sasanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_set_dir_2(t_cub *prog)
{
	if (prog->starting_way == 'W')
	{
		prog->params->plane.x = 0.66;
		prog->params->plane.y = 0;
		prog->params->dir.x = 0;
		prog->params->dir.y = -1;
	}
	else if (prog->starting_way == 'N')
	{
		prog->params->plane.x = 0;
		prog->params->plane.y = 0.66;
		prog->params->dir.x = 1;
		prog->params->dir.y = 0;
	}
}

void	ft_set_dir(t_cub *prog)
{
	if (prog->starting_way == 'E')
	{
		prog->params->plane.x = -0.66;
		prog->params->plane.y = 0;
		prog->params->dir.x = 0;
		prog->params->dir.y = 1;
	}
	else if (prog->starting_way == 'S')
	{
		prog->params->plane.x = 0;
		prog->params->plane.y = -0.66;
		prog->params->dir.x = -1;
		prog->params->dir.y = 0;
	}
	else
		ft_set_dir_2(prog);
}

int	ft_init_params(t_cub *prog)
{
	prog->params = ft_calloc(1, sizeof(t_render));
	if (!prog->params)
		return (0);
	prog->no_path = NULL;
	prog->so_path = NULL;
	prog->we_path = NULL;
	prog->ea_path = NULL;
	prog->f_color[0] = 256;
	prog->f_color[1] = 256;
	prog->f_color[2] = 256;
	prog->c_color[0] = 256;
	prog->c_color[1] = 256;
	prog->c_color[2] = 256;
	return (1);
}

int	ft_init_prog(t_cub *prog)
{
	prog->map = ft_calloc(1, sizeof(char *));
	if (!prog->map)
		return (0);
	prog->map[0] = NULL;
	prog->map_w = 0;
	prog->map_h = 0;
	prog->starting_way = 0;
	prog->pos.y = 0;
	prog->pos.x = 0;
	prog->keys.w = 0;
	prog->keys.a = 0;
	prog->keys.s = 0;
	prog->keys.d = 0;
	prog->keys.left = 0;
	prog->keys.right = 0;
	return (ft_init_params(prog));
}

int	main(int argc, char **argv)
{
	t_cub	prog;

	if (argc != 2)
		err("Error\nMap path is not specified");
	if (!ft_init_prog(&prog))
		err("Error\nInit error");
	prog.mlx = mlx_init();
	if (!ft_check_file_extension(argv[1]) || !ft_parse_file(argv[1], &prog))
	{
		ft_free_cub(&prog);
		free(prog.mlx);
		exit(1);
	}
	prog.win = mlx_new_window(prog.mlx, WIDTH, HEIGHT, "cub3d");
	mlx_hook(prog.win, 2, 1L << 0, ft_hooks_press, &prog);
	mlx_hook(prog.win, 3, 1L << 1, ft_hooks_release, &prog);
	mlx_hook(prog.win, 17, (1L << 17), ft_close, &prog);
	prog.img.img = mlx_new_image(prog.mlx, WIDTH, HEIGHT);
	prog.img.addr = mlx_get_data_addr(prog.img.img, &(prog.img.bits_per_pixel),
			&(prog.img.line_length), &(prog.img.endian));
	init_textures(&prog);
	ft_set_dir(&prog);
	mlx_loop_hook(prog.mlx, ft_start, &prog);
	mlx_loop(prog.mlx);
	return (0);
}
