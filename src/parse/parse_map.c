/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasanca <sasanca@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:18:18 by sasanca           #+#    #+#             */
/*   Updated: 2024/02/03 15:18:19 by sasanca          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	ft_check_y_axis(t_cub *cub, size_t y, size_t x)
{
	size_t	i;

	i = y;
	while (cub->map[i])
	{
		if (cub->map[i][x] == '1')
			break ;
		else if (cub->map[i][x] != ' ')
			return (0);
		i++;
	}
	i = y;
	while (cub->map[i])
	{
		if (cub->map[i][x] == '1')
			break ;
		else if (cub->map[i][x] != ' ')
			return (0);
		if (i == 0)
			break ;
		i--;
	}
	return (1);
}

int	ft_check_x_axis(t_cub *cub, size_t y, size_t x)
{
	size_t	j;

	j = x;
	while (j < cub->map_w)
	{
		if (cub->map[y][j] == '1')
			break ;
		else if (cub->map[y][j] != ' ')
			return (0);
		j++;
	}
	j = x;
	while (j)
	{
		if (cub->map[y][j] == '1')
			break ;
		else if (cub->map[y][j] != ' ')
			return (0);
		if (j == 0)
			break ;
		j--;
	}
	return (1);
}

int	ft_check_closed(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if ((i == 0 || j == 0 || i == cub->map_h - 1 || j == cub->map_w - 1)
				&& !(cub->map[i][j] == '1' || cub->map[i][j] == ' '))
				return (err("Error\nMap not closed"));
			if (cub->map[i][j] == ' ')
			{
				if (!ft_check_y_axis(cub, i, j) || !ft_check_x_axis(cub, i, j))
					return (err("Error\nMap not closed"));
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_resize_map(t_cub *cub)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = -1;
	while (cub->map[++i])
	{
		if (ft_strlen(cub->map[i]) == cub->map_w)
			continue ;
		tmp = ft_calloc(cub->map_w + 1, sizeof(char));
		j = -1;
		while (cub->map[i][++j])
			tmp[j] = cub->map[i][j];
		while (j < cub->map_w)
			tmp[j++] = ' ';
		tmp[j] = 0;
		free(cub->map[i]);
		cub->map[i] = tmp;
	}
}
