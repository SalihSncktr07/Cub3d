/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasanca <sasanca@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:18:28 by sasanca           #+#    #+#             */
/*   Updated: 2024/02/03 15:18:29 by sasanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	load_textures(t_cub *prog, t_text *texture, char *path)
{
	if (!path || ft_strlen(path) == 0)
		return (0);
	texture->img.img = mlx_xpm_file_to_image(prog->mlx,
			path, &texture->w, &texture->h);
	if (texture->img.img == NULL)
		return (0);
	texture->img.addr = mlx_get_data_addr(texture->img.img,
			&texture->img.bits_per_pixel, &texture->img.line_length,
			&texture->img.endian);
	if (texture->img.addr == NULL)
		return (0);
	return (1);
}

void	init_textures(t_cub *prog)
{
	if (!load_textures(prog, &prog->tex[0], prog->no_path)
		|| !load_textures(prog, &prog->tex[1], prog->so_path)
		|| !load_textures(prog, &prog->tex[2], prog->we_path)
		|| !load_textures(prog, &prog->tex[3], prog->ea_path))
	{
		return ;
	}
}
