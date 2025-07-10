/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:27:21 by digulraj          #+#    #+#             */
/*   Updated: 2025/07/07 20:34:24 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>

# define ERRMSG "Please enter either \"./fractol mandelbrot\" or \"./fractol julia <value 1> <value 2>\""
# define WIDTH 800
# define HEIGHT 800
// Standard Colors
# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define YELLOW      0xFFFF00
# define CYAN        0x00FFFF
# define MAGENTA     0xFF00FF
# define GRAY        0x808080
// Psychedelic / Vibrant Colors
# define NEON_PINK       0xFF6EC7
# define NEON_GREEN      0x39FF14
# define NEON_BLUE       0x1B03A3
# define ELECTRIC_PURPLE 0xBF00FF
# define HOT_PINK        0xFF69B4
# define LIME            0xBFFF00
# define ORANGE          0xFFA500
# define VIOLET          0x8F00FF
# define TURQUOISE       0x40E0D0
# define PSYCHEDELIC_RAINBOW 0xFF66FF  // Bright pinkish rainbow


typedef struct s_img 
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_fractol 
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	esc_value;
	int		iters;
}				t_fractol;

typedef struct s_complex 
{
	double	real;
	double	i;
}				t_complex;


int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		fractol_init(t_fractol *fractol);
double		map(double u_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		render_fractol(t_fractol *fractol);
void		data_init(t_fractol *fractol);
#endif