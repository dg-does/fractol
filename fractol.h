/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:27:21 by digulraj          #+#    #+#             */
/*   Updated: 2025/07/21 16:38:50 by digulraj         ###   ########.fr       */
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
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 800

// COLORS
# define BLACK       0x000000  // RGB(0, 0, 0)
# define WHITE       0xFFFFFF  // RGB(255, 255, 255)
# define RED         0xFF0000  // RGB(255, 0, 0)
# define GREEN       0x00FF00  // RGB(0, 255, 0)
# define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
# define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
# define LIME_SHOCK      0xCCFF00  // A blinding lime
# define NEON_ORANGE     0xFF6600  // A blazing neon orange
# define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
# define AQUA_DREAM      0x33CCCC  // A bright turquoise
# define HOT_PINK        0xFF66B2  // As the name suggests!
# define ELECTRIC_BLUE   0x0066FF  // A radiant blue
# define LAVA_RED        0xFF3300  // A bright, molten red

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
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractol;

typedef struct s_complex 
{
	double	real;
	double	i;
}				t_complex;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			key_handler(int keysym, t_fractol *fractol);
int			mouse_handler(int button, int x, int y, t_fractol *fractol);
int			close_handler(t_fractol *fractol);
void		ft_putstr_fd(char *s, int fd);
void		fractol_init(t_fractol *fractol);
double		map(double u_num, double new_min, double new_max, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		render_fractol(t_fractol *fractol);
void		data_init(t_fractol *fractol);
double		atodbl(char *s);
#endif
