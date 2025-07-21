/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:45:48 by digulraj          #+#    #+#             */
/*   Updated: 2025/07/21 15:51:23 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	else if (keysym == XK_KP_Add)
		fractol->iters += 10;
	else if (keysym == XK_KP_Subtract)
		fractol->iters -= 10;
	else if (keysym == XK_Left)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_Page_Down)
		fractol->zoom *= 0.95;
	else if (keysym == XK_Page_Up)
		fractol->zoom *= 1.05;
	render_fractol(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void) x;
	(void) y;
	if (button == Button5)
		fractol->zoom *= 0.95;
	else if (button == Button4)
		fractol->zoom *= 1.05;
	render_fractol(fractol);
	return (0);
}

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
	return (0);
}
