/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:26:40 by digulraj          #+#    #+#             */
/*   Updated: 2025/07/21 16:52:13 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int colour)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->addr + offset) = colour;
}
/*
static void	mandel_or_julia(t_complex z, t_complex c, t_fractol fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->real = fractol->julia_x;
		c->i = fractol->julia_y;
	}
	else
	{
		c->real = z->real;
		c->i = z->i;
	}
}*/

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			j;
	int			colour;

	z.real = 0.0;
	z.i = 0.0;
	j = 0;
	c.real = map(x, -2, 2, WIDTH - 1) * fractol->zoom + fractol->shift_x;
	c.i = map(y, 2, -2, HEIGHT - 1) * fractol->zoom + fractol->shift_y;

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
