/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:31:26 by svalenti          #+#    #+#             */
/*   Updated: 2021/03/03 19:15:52 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->add + (y * data->len + x * (data->pixel / 8));
    *(unsigned int*)dst = color;
}

int	main(void)
{
	void 	*mlx;
	void 	*ide_win;
	t_data 	*img;

	mlx = mlx_init();
	ide_win = mlx_new_window(mlx, 1920, 1080, "game");
	img->img = mlx_new_image(mlx, 1920, 1080);
	img->add = mlx_get_data_addr(img->img, &img->pixel, &img->len, &img->endian);
	my_mlx_pixel_put(img, 5, 5, 0x00FF0000);
    mlx_put_image_to_window(mlx, ide_win, img->img, 0, 0);
	mlx_loop(mlx);
}
