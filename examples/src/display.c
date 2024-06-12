/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetitco <apetitco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:02:08 by apetitco          #+#    #+#             */
/*   Updated: 2024/06/12 16:30:11 by apetitco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/examples.h"

void	ft_free_textures(t_data *data)
{
	free(data->textures);
//	free(data->textures[1]);
//	free(data->textures[2]);
//	free(data->textures[3]);
}

void	ft_load_textures(t_data *data)
{
	data->textures[0].image = mlx_xpm_file_to_image(data->mlx_ptr, "../assets/back.xpm", &data->textures[0].width, &data->textures[0].height);
	data->textures[1].image = mlx_xpm_file_to_image(data->mlx_ptr, "../assets/front.xpm", &data->textures[1].width, &data->textures[1].height);
	data->textures[2].image = mlx_xpm_file_to_image(data->mlx_ptr, "../assets/left.xpm", &data->textures[2].width, &data->textures[2].height);
	data->textures[3].image = mlx_xpm_file_to_image(data->mlx_ptr, "../assets/right.xpm", &data->textures[3].width, &data->textures[3].height);
}

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int	ft_test_displaying(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "hi :)");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	ft_load_textures(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[0].image, 50, 50);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[1].image, 150, 50);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[2].image, 250, 50);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.textures[3].image, 350, 50);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	ft_free_textures(&data);
	return (0);
}