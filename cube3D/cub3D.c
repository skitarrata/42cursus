/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalenti <svalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:31:26 by svalenti          #+#    #+#             */
/*   Updated: 2021/03/24 20:47:11 by svalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int map[mapR][mapC]=
{
  {8,8,8,8,8,8,8,8,8,8,8,4,4,6,4,4,6,4,6,4,4,4,6,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,6},
  {8,0,3,3,0,0,0,0,0,8,8,4,0,0,0,0,0,0,0,0,0,0,0,4},
  {8,0,0,0,0,0,0,0,0,0,8,4,0,0,0,0,0,6,6,6,0,6,4,6},
  {8,8,8,8,0,8,8,8,8,8,8,4,4,4,4,4,4,6,0,0,0,0,0,6},
  {7,7,7,7,0,7,7,7,7,0,8,0,8,0,8,0,8,4,0,4,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,0,0,0,0,0,6},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,0,0,0,0,4},
  {7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,6,0,6,0,6,0,6},
  {7,7,0,0,0,0,0,0,7,8,0,8,0,8,0,8,8,6,4,6,0,6,6,6},
  {7,7,7,7,0,7,7,7,7,8,8,4,0,6,8,4,8,3,3,3,0,3,3,3},
  {2,2,2,2,0,2,2,2,2,4,6,4,0,0,6,0,6,3,0,0,0,0,0,3},
  {2,2,0,0,0,0,0,2,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {2,0,0,0,0,0,0,0,2,4,0,0,0,0,0,0,4,3,0,0,0,0,0,3},
  {1,0,0,0,0,0,0,0,1,4,4,4,4,4,6,0,6,3,3,0,0,0,3,3},
  {2,0,0,0,0,0,0,0,2,2,2,1,2,2,2,6,6,0,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,9,5,0,5,0,5,0,5},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5},
  {2,0,0,0,0,0,0,0,2,0,0,0,0,0,2,5,0,5,0,5,0,5,0,5},
  {2,2,0,0,0,0,0,2,2,2,0,0,0,2,2,0,5,0,5,0,0,0,5,5},
  {2,2,2,2,1,2,2,2,2,2,2,1,2,2,2,5,5,5,5,5,5,5,5,5}
};

t_sprite sprite[numSprites] =
{
  {20.5, 11.5, 10}, //green light in front of playerstart
  //green lights in every room
  {18.5,4.5, 10},
  {10.0,4.5, 10},
  {10.0,12.5,10},
  {3.5, 6.5, 10},
  {3.5, 20.5,10},
  {3.5, 14.5,10},
  {14.5,20.5,10},

  //row of pillars in front of wall: fisheye test
  {18.5, 10.5, 9},
  {18.5, 11.5, 9},
  {18.5, 12.5, 9},

  //some barrels around the map
  {21.5, 1.5, 8},
  {15.5, 1.5, 8},
  {16.0, 1.8, 8},
  {16.2, 1.2, 8},
  {3.5,  2.5, 8},
  {9.5, 15.5, 8},
  {10.0, 15.1,8},
  {10.5, 15.8,8},
};

double ZBuffer[resolutionX];

//arrays used to sort the sprites
int spriteOrder[numSprites];
double spriteDistance[numSprites];

void scambia(double *a, double *b)
{
	double temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void scambia_2(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void sortSprites(int *order, double *dist, int amount)
{
	int i = 0;
	int j = amount - 1;

	while (i < amount - 1)
	{
		while (j > i)
		{
			if (order[j] < order[j - 1])
			{
				scambia_2(&order[j], &order[j - 1]);
			}
			j--;
		}
		i++;
	}

	i = 0;
	j = amount - 1;
	while (i < amount - 1)
	{
		while (j > i)
		{
			if (dist[j] < dist[j - 1])
				scambia(&dist[j], &dist[j - 1]);
			j--;
		}
		i++;
	}
}


unsigned int buf[64][64];

void	my_mlx_pixel_put(t_pos *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void ft_calcolate(t_pos *pos)
{
	int x = 0;
	int y = 0;
	load_tex(pos);

/* 	while (++y < resolutionY / 2 + 1)
	{
		//rayDir per il raggio più a sinistra (x = 0) e il raggio più a destra (x = resolutionX)
		pos->rayDirX0 = pos->dirX - pos->pianoX;
    	pos->rayDirY0 = pos->dirY - pos->pianoY;
    	pos->rayDirX1 = pos->dirX + pos->pianoX;
    	pos->rayDirY1 = pos->dirY + pos->pianoY;

		 //Posizione y corrente rispetto al centro dello schermo (l'orizzonte)
		int p = y - resolutionY / 2;

		//Posizione verticale della telecamera.
		float posZ = 0.5 * resolutionY;

		//Distanza orizzontale dalla telecamera al pavimento per la riga corrente.
    	//0,5 è la posizione z esattamente al centro tra il pavimento e il soffitto.
    	float rowDistance = posZ / p;

		//calcola il vettore di passo del mondo reale che dobbiamo aggiungere per ogni x (parallelo al piano della telecamera)
		//l'aggiunta passo dopo passo evita moltiplicazioni con un peso nel loop interno
		float floorStepX = rowDistance * (pos->rayDirX1 - pos->rayDirX0) / resolutionX;
		float floorStepY = rowDistance * (pos->rayDirY1 - pos->rayDirY0) / resolutionX;

 		//coordinate del mondo reale della colonna più a sinistra. Questo verrà aggiornato man mano che ci spostiamo a destra.
		float floorX = pos->posX + rowDistance * pos->rayDirX0;
		float floorY = pos->posY + rowDistance * pos->rayDirY0;

		while (++x < resolutionX)
		{
			//il coord della cella viene semplicemente ottenuto dalle parti intere di floorX e floorY
        	int cellX = (int)floorX;
			int cellY = (int)floorY;

			//ottiene la coordinata della texture
			int tx = (int) (64 * (floorX - cellX)) & (64 - 1);
			int ty = (int) (64 * (floorY - cellY)) & (64 - 1);

			floorX += floorStepX;
			floorY += floorStepY;

        	// scegli la texture e disegna il pixel
        	int floorTexture = 3;
        	int ceilingTexture = 6;

			pos->addr[(resolutionY * x) + (4 * y)] = pos->strutex[6].addrestex[(4 * pos->strutex[6].texHeight * ty) + (4 * tx)];
			pos->addr[(resolutionY * x) + (4 * y) + 1] = pos->strutex[6].addrestex[(4 * pos->strutex[6].texHeight * ty) + (4 * tx) + 1];
			pos->addr[(resolutionY * x) + (4 * y) + 2] = pos->strutex[6].addrestex[(4 * pos->strutex[6].texHeight * ty) + (4 * tx) + 2];
		}
		//mlx_put_image_to_window(pos->mlx, pos->ide_win, pos->img, 0, 0);
	}
	x = 0; */
	while (x < resolutionX)
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
		int side; //ci serve per capire su quale lato abbiamo colpito il muro

		hit = 0;
    	while (hit == 0)
      	{
        	if(pos->sideDistX < pos->sideDistY)
        	{
          		pos->sideDistX += pos->deltaDistX; //sommo le distanze trovate su X che non hanno muri
				pos->mapX += pos->stepX; //incrementiamo la casella in base al passo
				side = 0; //se side e 0 e usciamo dal ciclo, significa che il muro trovato si trova sul lato x
        	}
        	else
        	{ 
          		pos->sideDistY += pos->deltaDistY;
          		pos->mapY += pos->stepY;
          		side = 1; //se side e 1 e usciamo dal ciclo, significa che il muro trovato si trova sul lato y
        	}
        	if(map[pos->mapX][pos->mapY] > 0 && !(map[pos->mapX][pos->mapY] >= 9 && map[pos->mapX][pos->mapY] <= 11)) //quando incontro un muro esco dal ciclo
				hit = 1;
		}
		if (side == 0)
			pos->perpWallDist = (pos->mapX - pos->posX + (1 - pos->stepX) / 2) / pos->rayDirX;
      	else
			pos->perpWallDist = (pos->mapY - pos->posY + (1 - pos->stepY) / 2) / pos->rayDirY;

		int lineHeight; // lunghezza da disegnare
		lineHeight = (int) (resolutionY / pos->perpWallDist); // calcola il pixel più basso e più alto per riempire la striscia corrente
       	pos->drawStart = -lineHeight / 2 + resolutionY / 2; 
		if (pos->drawStart < 0)
			pos->drawStart = 0; 
		pos->drawEnd = lineHeight / 2 + resolutionY / 2; 
      	if (pos->drawEnd >= resolutionY)
			pos->drawEnd = resolutionY - 1;
		
		ft_floor_tex(pos, x);
		int texNum = map[pos->mapX][pos->mapY] - 1; //valore delle texture ,per richiamarle
		//if (texNum >= 8 && texNum <= 10)
			//texNum = -1;
		double wallX; //valore esatto del muro quando é stato colpito
		if(side == 0)
			wallX = pos->posY + pos->perpWallDist * pos->rayDirY;
		else
			wallX = pos->posX + pos->perpWallDist * pos->rayDirX; 
		wallX -= floor(wallX);


		int texX = (int)(wallX * (double)pos->strutex[texNum].texWidth); //è la coordinata x della texture, e questa è calcolata da wallX
		if (side == 0 && pos->rayDirX > 0)
			texX = pos->strutex[texNum].texWidth - texX - 1;
		if (side == 1 && pos->rayDirY < 0)
			texX = pos->strutex[texNum].texWidth - texX - 1;

		y = pos->drawStart;
		double step = 1.0 * pos->strutex[texNum].texHeight / lineHeight; //step indica di quanto aumentare le coordinate della texture per ogni pixel nelle coordinate verticali dello schermo
	  	double texPos = (pos->drawStart - resolutionY / 2 + lineHeight / 2) * step; // Coordinata della texture iniziale
		while (y < pos->drawEnd)
		{
			int texY = (int)texPos & (pos->strutex[texNum].texHeight - 1); //trasformo la texture posizione Y in intero, in caso di overflow faccio texH -1
			texPos += step;
			if (side == 0)
			{
				pos->addr[(4 * resolutionX * y) + (4 * x)] = pos->strutex[texNum].addrestex[(4 * pos->strutex[texNum].texWidth * texY) + (4 * texX)];
				pos->addr[(4 * resolutionX * y) + (4 * x) + 1] = pos->strutex[texNum].addrestex[(4 * pos->strutex[texNum].texWidth * texY) + (4 * texX) + 1];
				pos->addr[(4 * resolutionX * y) + (4 * x) + 2] = pos->strutex[texNum].addrestex[(4 * pos->strutex[texNum].texWidth * texY) + (4 * texX) + 2];
			}
			else
			{
				pos->addr[(4 * resolutionX * y) + (4 * x)] = pos->strutex[texNum].addrestex[(4 * pos->strutex[texNum].texWidth * texY) + (4 * texX)] >> 1 & 8355711;
				pos->addr[(4 * resolutionX * y) + (4 * x) + 1] = pos->strutex[texNum].addrestex[(4 * pos->strutex[texNum].texWidth * texY) + (4 * texX) + 1] >> 1 & 8355711;
				pos->addr[(4 * resolutionX * y) + (4 * x) + 2] = pos->strutex[texNum].addrestex[(4 * pos->strutex[texNum].texWidth * texY) + (4 * texX) + 2] >> 1 & 8355711;
			}
			y++;
		}
		ZBuffer[x] = pos->perpWallDist;
		x++;
	}
	//mlx_put_image_to_window(pos->mlx, pos->ide_win, pos->img, 0, 0);

	int i = 0;
	while (i < numSprites)
	{
		spriteOrder[i] = i;
		spriteDistance[i] = ((pos->posX - sprite[i].x) * (pos->posX - sprite[i].x) + (pos->posY - sprite[i].y) * (pos->posY - sprite[i].y));
		i++;
	}
	sortSprites(spriteOrder, spriteDistance, numSprites);

	i = 0;
	while (i < numSprites)
	{
		//int texNum = map[pos->mapX][pos->mapY] - 1;
		//if (!(texNum >= 8 && texNum <= 10))
			//return ;
		double spriteX = sprite[spriteOrder[i]].x - pos->posX;
		double spriteY = sprite[spriteOrder[i]].y - pos->posY;


		double invDet = 1.0 / (pos->pianoX * pos->dirY - pos->dirX * pos->pianoY); //required for correct matrix multiplication

		double transformX = invDet * (pos->dirY * spriteX - pos->dirX * spriteY);
		double transformY = invDet * (-pos->pianoY * spriteX + pos->pianoX * spriteY); //this is actually the depth inside the screen, that what Z is in 3D

		int spriteScreenX = (int)((resolutionX / 2) * (1 + transformX / transformY));

		      //calculate height of the sprite on screen
		int spriteHeight = abs((int)(resolutionY / (transformY))); //using 'transformY' instead of the real distance prevents fisheye
      	//calculate lowest and highest pixel to fill in current stripe
      	int drawStartY = -spriteHeight / 2 + resolutionY / 2;
      	if(drawStartY < 0)
			drawStartY = 0;
      	int drawEndY = spriteHeight / 2 + resolutionY / 2;
     	if(drawEndY >= resolutionY)
			drawEndY = resolutionY - 1;

      //calculate width of the sprite
      	int spriteWidth = abs((int)(resolutionY / (transformY)));
      	int drawStartX = -spriteWidth / 2 + spriteScreenX;
      	if(drawStartX < 0)
			drawStartX = 0;
      	int drawEndX = spriteWidth / 2 + spriteScreenX;
      	if(drawEndX >= resolutionX) 
			drawEndX = resolutionX - 1;
		
		int stripe = drawStartX;
		while (stripe < drawEndX)
		{
			int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;
			if(transformY > 0 && stripe > 0 && stripe < resolutionX && transformY < ZBuffer[stripe])
			{
				int z = drawStartY;
				while (z < drawEndY)
				{
					int d = (z) * 256 - resolutionY * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
					int texY = ((d * 64) / spriteHeight) / 256;
					if (pos->strutex[sprite[spriteOrder[i]].texture].addrestex[(4 * pos->strutex[sprite[spriteOrder[i]].texture].texWidth * texY) + (4 * texX)] != (char)0x00 ||
						pos->strutex[sprite[spriteOrder[i]].texture].addrestex[(4 * pos->strutex[sprite[spriteOrder[i]].texture].texWidth * texY) + (4 * texX) + 1] != (char)0x00 ||
						pos->strutex[sprite[spriteOrder[i]].texture].addrestex[(4 * pos->strutex[sprite[spriteOrder[i]].texture].texWidth * texY) + (4 * texX) + 2] != (char)0x00)
					{
						pos->addr[(4 * resolutionX * z) + (4 * stripe)] = pos->strutex[sprite[spriteOrder[i]].texture].addrestex[(4 * pos->strutex[sprite[spriteOrder[i]].texture].texWidth * texY) + (4 * texX)];
						pos->addr[(4 * resolutionX * z) + (4 * stripe) + 1] = pos->strutex[sprite[spriteOrder[i]].texture].addrestex[(4 * pos->strutex[sprite[spriteOrder[i]].texture].texWidth * texY) + (4 * texX) + 1];
						pos->addr[(4 * resolutionX * z) + (4 * stripe) + 2] = pos->strutex[sprite[spriteOrder[i]].texture].addrestex[(4 * pos->strutex[sprite[spriteOrder[i]].texture].texWidth * texY) + (4 * texX) + 2];
					}
/* 					pos->addr[(4 * resolutionX * z) + (4 * stripe)] = pos->strutex[sprite[spriteOrder[i]].texture].addrestex[(4 * pos->strutex[sprite[spriteOrder[i]].texture].texWidth * texY) + (4 * texX)];
					pos->addr[(4 * resolutionX * z) + (4 * stripe) + 1] = pos->strutex[sprite[spriteOrder[i]].texture].addrestex[(4 * pos->strutex[sprite[spriteOrder[i]].texture].texWidth * texY) + (4 * texX) + 1];
					pos->addr[(4 * resolutionX * z) + (4 * stripe) + 2] = pos->strutex[sprite[spriteOrder[i]].texture].addrestex[(4 * pos->strutex[sprite[spriteOrder[i]].texture].texWidth * texY) + (4 * texX) + 2]; */
					z++;
				}
				//mlx_put_image_to_window(pos->mlx, pos->ide_win, pos->img, 0, 0);
			}
			stripe++;
		}
		mlx_put_image_to_window(pos->mlx, pos->ide_win, pos->img, 0, 0);
		i++;
	}
	clear_textures(pos);
}

void	first_pos(t_pos *pos)
{
	int i = 0;

	pos->posX = 22;
	pos->posY = 12;
	pos->dirX = -1;
	pos->dirY = 0;
	pos->pianoX = 0;
	pos->pianoY = 0.66;

	while (i < 100)
		pos->keyboard[i++] = 0;
	ft_calcolate(pos);
}

int	main (int argc, char *argv[])
{
	t_pos	pos;

	pos.mlx = mlx_init();
	pos.ide_win = mlx_new_window(pos.mlx, resolutionX, resolutionY, "cub3D");
	pos.img = mlx_new_image(pos.mlx, resolutionX, resolutionY);
    pos.addr = mlx_get_data_addr(pos.img, &pos.bits_per_pixel, &pos.line_length, &pos.endian);
	first_pos(&pos);
	mlx_hook(pos.ide_win, 2, (1L << 0), ft_key_hit, &pos);
	mlx_hook(pos.ide_win, 3, (1L << 1), ft_key_release, &pos);
	mlx_loop_hook(pos.mlx, press_button, &pos);
	mlx_loop(pos.mlx);
	return (0);
}
