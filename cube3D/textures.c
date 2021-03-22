
#include "cub3D.h"

void	clear_textures(t_pos *pos)
{
	int i = 0;
	while (i < TEXUR)
	{
		if (pos->strutex[i].tex)
			mlx_destroy_image(pos->mlx, pos->strutex[i].tex);
		pos->strutex[i].tex = NULL;
		pos->strutex[i].addrestex = NULL;
		i++;
	}
}

static void load_tex(t_pos *pos)
{
	pos->strutex[0].tex = mlx_xpm_file_to_image(pos->mlx, "./texture/eagle.xpm", &pos->strutex[0].texWidth, &pos->strutex[0].texHeight);
	pos->strutex[0].addrestex = mlx_get_data_addr(pos->strutex[0].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);

	pos->strutex[1].tex= mlx_xpm_file_to_image(pos->mlx, "./texture/wall_4.xpm", &pos->strutex[1].texWidth, &pos->strutex[1].texHeight);
	pos->strutex[1].addrestex = mlx_get_data_addr(pos->strutex[1].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);

	pos->strutex[2].tex = mlx_xpm_file_to_image(pos->mlx, "./texture/purplestone.xpm", &pos->strutex[2].texWidth, &pos->strutex[2].texHeight);
	pos->strutex[2].addrestex = mlx_get_data_addr(pos->strutex[2].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);

	pos->strutex[3].tex = mlx_xpm_file_to_image(pos->mlx, "./texture/wall_3.xpm", &pos->strutex[3].texWidth, &pos->strutex[3].texHeight);
	pos->strutex[3].addrestex = mlx_get_data_addr(pos->strutex[3].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);

	pos->strutex[4].tex = mlx_xpm_file_to_image(pos->mlx, "./texture/bluestone.xpm", &pos->strutex[4].texWidth, &pos->strutex[4].texHeight);
	pos->strutex[4].addrestex = mlx_get_data_addr(pos->strutex[4].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);

	pos->strutex[5].tex = mlx_xpm_file_to_image(pos->mlx, "./texture/wall_2.xpm", &pos->strutex[5].texWidth, &pos->strutex[5].texHeight);
	pos->strutex[5].addrestex = mlx_get_data_addr(pos->strutex[5].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);

	pos->strutex[6].tex = mlx_xpm_file_to_image(pos->mlx, "./texture/wood.xpm", &pos->strutex[6].texWidth, &pos->strutex[6].texHeight);
	pos->strutex[6].addrestex = mlx_get_data_addr(pos->strutex[6].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);
	
	pos->strutex[7].tex = mlx_xpm_file_to_image(pos->mlx, "./texture/wall_1.xpm", &pos->strutex[7].texWidth, &pos->strutex[7].texHeight);
	pos->strutex[7].addrestex = mlx_get_data_addr(pos->strutex[7].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);

	pos->strutex[8].tex = mlx_xpm_file_to_image(pos->mlx, "./texture/sprite_1.xpm", &pos->strutex[8].texWidth, &pos->strutex[8].texHeight);
	pos->strutex[8].addrestex = mlx_get_data_addr(pos->strutex[8].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);

	pos->strutex[9].tex = mlx_xpm_file_to_image(pos->mlx, "./texture/sprite_2.xpm", &pos->strutex[9].texWidth, &pos->strutex[9].texHeight);
	pos->strutex[9].addrestex = mlx_get_data_addr(pos->strutex[9].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);
	
	pos->strutex[10].tex = mlx_xpm_file_to_image(pos->mlx, "./texture/sprite_3.xpm", &pos->strutex[10].texWidth, &pos->strutex[10].texHeight);
	pos->strutex[10].addrestex = mlx_get_data_addr(pos->strutex[10].tex, &pos->bits_per_pixel, &pos->line_length, &pos->endian);
}

void ft_floor_tex(t_pos *pos, int x)
{
	int y = 0;
	pos->addr = mlx_get_data_addr(pos->img, &pos->bits_per_pixel, &pos->line_length, &pos->endian);
	while (y < pos->drawStart)
		my_mlx_pixel_put(pos, x, y++, 0x009C9C9C);
	y = pos->drawEnd;
	while (y < resolutionY)
		my_mlx_pixel_put(pos, x, y++, 0x00BA926C);
}