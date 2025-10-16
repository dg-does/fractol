/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:26:41 by digulraj          #+#    #+#             */
/*   Updated: 2025/10/16 21:41:09 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		if (!ft_strncmp(argv[1], "julia", 5))
		{
			fractol.julia_x = atodbl(argv[2]);
			fractol.julia_y = atodbl(argv[3]);
		}
		fractol.name = argv[1];
		fractol_init(&fractol);
		render_fractol(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		perror("Enter \"./fractol mandelbrot\" or \"./fractol julia <real> <i>\"");
		exit(EXIT_FAILURE);
	}
}
