/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:26:40 by digulraj          #+#    #+#             */
/*   Updated: 2025/10/16 21:32:53 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int colour)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = colour;
}

static void	select_fractol(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->real = fractol->julia_x;
		c->i = fractol->julia_y;
	}
	else if (!ft_strncmp(fractol->name, "mandelbrot", 10))
	{
		c->real = z->real;
		c->i = z->i;
	}
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			j;
	int			colour;

	j = 0;
	z.real = map(x, -2, 2, WIDTH) / fractol->zoom + fractol->shift_x;
	z.i = map(y, 2, -2, HEIGHT) / fractol->zoom + fractol->shift_y;
	select_fractol(&z, &c, fractol);
	while (j < fractol->iters)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.i * z.i) > fractol->esc_value)
		{
			colour = (int)map(j, WHITE, BLACK, fractol->iters);
			my_pixel_put(x, y, &fractol->img, colour);
			return ;
		}
		j++;
	}
	my_pixel_put(x, y, &fractol->img, WHITE);
}

void	render_fractol(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (HEIGHT > y)
	{
		x = 0;
		while (WIDTH > x)
		{
			handle_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
