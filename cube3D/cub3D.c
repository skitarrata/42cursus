/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:31:26 by svalenti          #+#    #+#             */
/*   Updated: 2021/03/10 15:48:01 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int map[mapR][mapC] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

static void ft_calcolate(t_pos *pos)
{
	int x = 0;

	while (x <= resolutionX)
	{
		pos->cameraX = 2 * x / (double)resolutionX - 1; //posizione della telecamera per ottenere sul lato destro 1, 0 al centro, -1 a sinistra
    	pos->rayDirX = pos->dirX + pos->pianoX * pos->cameraX; //calcola posizione del raggio
    	pos->rayDirY = pos->dirY + pos->pianoY * pos->cameraX;

    	pos->mapX = (int)pos->posX;  //casella della mappa in cui ci troviamo (iniziamo ovviamente dalla posizione iniziale)
    	pos->mapY = (int)pos->posY;

		pos->deltaDistX = (pos->rayDirY == 0) ? 0 : ((pos->rayDirX == 0) ? 1 : fabs (1 / pos->rayDirX)); //controllo la posizione dei raggi nei casi limiti, altrimenti effettuo il
		pos->deltaDistY = (pos->rayDirX == 0) ? 0 : ((pos->rayDirY == 0) ? 1 : fabs (1 / pos->rayDirY)); //teorema di pitagora per i raggi con angoli variabili

		//calcolo delle componenti e delle distanze tra raggio e primo lato che incontra
		if (pos->rayDirX < 0)
      	{
        	pos->stepX = -1; //se la componente del raggio e negativa sara negativo
        	pos->sideDistX = (pos->posX - pos->mapX) * pos->deltaDistX; //calcolo distanza
      	}
      	else
      	{
        	pos->stepX = 1; //altrimenti positiva, idem per y
        	pos->sideDistX = (pos->mapX + 1.0 - pos->posX) * pos->deltaDistX;
      	}
      	if (pos->rayDirY < 0)
      	{
        	pos->stepY = -1;
        	pos->sideDistY = (pos->posY - pos->mapY) * pos->deltaDistY;
      	}
      	else
      	{
        	pos->stepY = 1;
        	pos->sideDistY = (pos->mapY + 1.0 - pos->posY) * pos->deltaDistY;
      	}

		//DDA incrementa il raggio di 1 quadrato ogni volta che non incontra un muro
		int	hit;

		hit = 0;
    	while (hit == 0)
      	{
        	if(pos->sideDistX < pos->sideDistY)
        	{
          		pos->sideDistX += pos->deltaDistX; //sommo le distanze trovate su X che non hanno muri
				pos->mapX += pos->stepX; //incrementiamo la casella in base al passo
				pos->side = 0; //se side e 0 e usciamo dal ciclo, significa che il muro trovato si trova sul lato x
        	}
        	else
        	{
          		pos->sideDistY += pos->deltaDistY;
          		pos->mapY += pos->stepY;
          		pos->side = 1; //se side e 1 e usciamo dal ciclo, significa che il muro trovato si trova sul lato y
        	}
        	if(map[pos->mapX][pos->mapY] > 0) //quando incontro un muro esco dal ciclo
				hit = 1;
		}
		if (pos->side == 0)
			pos->perpWallDist = (pos->mapX - pos->posX + (1 - pos->stepX) / 2) / pos->rayDirX;
      	else
			pos->perpWallDist = (pos->mapY - pos->posY + (1 - pos->stepY) / 2) / pos->rayDirY;

		pos->lineHeight = (int) (resolutionY / pos->perpWallDist); // calcola il pixel più basso e più alto per riempire la striscia corrente
       	pos->drawStart = -pos->lineHeight / 2 + resolutionY / 2; 
		if (pos->drawStart < 0)
			pos->drawStart = 0; 
		pos->drawEnd = pos->lineHeight / 2 + resolutionY / 2; 
      	if (pos->drawEnd >= resolutionY)
			pos->drawEnd = resolutionY - 1;
		x++;
	}
}

void	first_pos(t_pos *pos)
{
	pos->posX = 5;
	pos->posY = 7;
	pos->dirX = -1;
	pos->dirY = 0;
	pos->pianoX = 0;
	pos->pianoY = 0.66;
	ft_calcolate(pos);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->add + (y * data->len + x * (data->pixel / 8));
    *(unsigned int*)dst = color;
}

static void	move_W(t_pos *pos)
{
	if (map[(int)(pos->posX + pos->dirX)] [(int)pos->posY] == 0)
		pos->posX += pos->dirX;
    if (map[(int)pos->posX] [(int)(pos->posY + pos->dirY)] == 0)
		pos->posY += pos->dirY;
	printf("%f\n", pos->posX);
	printf("%f\n", pos->posY);
}

static void	move_S(t_pos *pos)
{
	if (map[(int)(pos->posX - pos->dirX)] [(int)pos->posY] == 0)
		pos->posX -= pos->dirX;
    if (map[(int)pos->posX] [(int)(pos->posY - pos->dirY)] == 0)
		pos->posY -= pos->dirY;
}

static void	move_A(t_pos *pos)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = pos->dirX;
    pos->dirX = pos->dirX * cos(3.0) - pos->dirY * sin(3.0);
    pos->dirY = oldDirX * sin(3.0) + pos->dirY * cos(3.0);
    oldPlaneX = pos->pianoX;
    pos->pianoX = pos->pianoX * cos(3.0) - pos->pianoY * sin(3.0);
    pos->pianoY = oldPlaneX * sin(3.0) + pos->pianoY * cos(3.0);
}

static void	move_D(t_pos *pos)
{
	double oldDirX;
	double oldPlaneX;

	oldDirX = pos->dirX;
    pos->dirX = pos->dirX * cos(-3.0) - pos->dirY * sin(-3.0);
    pos->dirY = oldDirX * sin(-3.0) + pos->dirY * cos(-3.0);
    oldPlaneX = pos->pianoX;
    pos->pianoX = pos->pianoX * cos(-3.0) - pos->pianoY * sin(-3.0);
    pos->pianoY = oldPlaneX * sin(-3.0) + pos->pianoY * cos(-3.0);
}

int	press_button(int button, t_pos *pos, t_data *img)
{
	if (button == 53)
	{
		mlx_destroy_window(img->mlx, img->ide_win);
		return (0);
	}
	// mi muovo nella mappa
	if (button == 13)
		move_W(pos);
	else if (button == 0)
		move_A(pos);
	else if (button == 1)
		move_S(pos);
	else if (button == 2)
		move_D(pos);
	ft_calcolate(pos);
	printf("%d\n", button);
	return (1);
}

int	main (void)
{
	t_data 	img;
	t_pos	pos;

	img.mlx = mlx_init();
	img.ide_win = mlx_new_window(img.mlx, resolutionX, resolutionY, "game");
	first_pos(&pos);
	mlx_key_hook(img.ide_win, press_button, &img);
	mlx_loop(img.mlx);

	//printf("%s\n", "casa");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	//img.add = mlx_get_data_addr(img.img, &img.pixel, &img.len, &img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    //mlx_put_image_to_window(mlx, ide_win, img.img, 0, 0);
	return (0);
}
