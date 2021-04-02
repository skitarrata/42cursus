
#include "cub3D.h"

int	ft_conversion_rgb(int t, int r, int g, int b) // da verificare
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_read_map(t_pos *pos, int fd)
{
	int		dim;
	char	*buf;
	int		i;

	i = 0;
	while (get_next_line(fd, &buf))
	{
		dim = ft_strlen(buf);
		while (buf[i] == ' ')
			i++;
		if (buf[i] >= 65 && buf[i] <= 90)
		{
			if (buf[i] == 'R')
			{
				while (i < dim)
				{
					int count = 0;

					while (buf[i] == ' ')
						i++;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 0)
						pos->resolutionX = ((pos->resolutionX * 10) + (buf[i++] - '0')); //resolution da mettere in pos
					if (pos->resolutionX)
						count = 1;
					while (buf[i] >= 48 && buf[i] <= 57 && count)
						pos->resolutionY = ((pos->resolutionY * 10) + (buf[i++] - '0'));
					i++;
				}
			}
			else if (buf[i] == 'F')
			{
				int r = 0;
				int g = 0;
				int b = 0;

				while (i < dim)
				{
					int count = 0;

					while (buf[i] == ' ' || buf[i] == ',')
						i++;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 0)
						r = ((r * 10) + (buf[i++] - '0'));
					if (r)
						count = 1;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 1)
						g = ((g * 10) + (buf[i++] - '0'));
					if (g)
						count = 2;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 1)
						b = ((b * 10) + (buf[i++] - '0'));
					i++;
				}
				pos->floor = ft_conversion_rgb(t, r, g, b); // da includere in pos o lista a parte 
			}
			else if (buf[i] == 'C')
			{
				int r = 0;
				int g = 0;
				int b = 0;

				while (i < dim)
				{
					int count = 0;

					while (buf[i] == ' ' || buf[i] == ',')
						i++;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 0)
						r = ((r * 10) + (buf[i++] - '0'));
					if (r)
						count = 1;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 1)
						g = ((g * 10) + (buf[i++] - '0'));
					if (g)
						count = 2;
					while (buf[i] >= 48 && buf[i] <= 57 && count == 1)
						b = ((b * 10) + (buf[i++] - '0'));
					i++;
				}
				pos->cel = ft_conversion_rgb(t, r, g, b); // da includere in pos o lista a parte 
			}
			else if (buf[i] == 'N' && buf[i++] == 'O')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '.' && buf[i + 1] == '/')
					pos->nametex = ft_strdup(&buf[i]); //da includere nemetex e verificare sta cosa :( vedere dove mettere il free
			}
			else if (buf[i] == 'S' && buf[i++] == 'O')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '.' && buf[i + 1] == '/')
					pos->nametex = ft_strdup(&buf[i]);
			}
			else if (buf[i] == 'W' && buf[i++] == 'E')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '.' && buf[i + 1] == '/')
					pos->nametex = ft_strdup(&buf[i]);
			}
			else if (buf[i] == 'E' && buf[i++] == 'A')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '.' && buf[i + 1] == '/')
					pos->nametex = ft_strdup(&buf[i]);
			}
			else if (buf[i] == 'S')
			{
				while (buf[i] == ' ')
					i++;
				if (buf[i] == '.' && buf[i + 1] == '/')
					pos->nameprite = ft_strdup(&buf[i]); //da includere nemesprite vedere dove mettere il free
			}
		}
	}
}

//questa roba e da includere nel main principale
int main ()
{
	int fd;

	if (!(fd = open("./map/map.cub", O_RDONLY)))
	{
		printf("\nError open\n");
		return (0);
	}
	ft_read_map(&pos, fd); //ovviamente pos al momento non c e
	close(fd);
}