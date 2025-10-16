/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:54:22 by digulraj          #+#    #+#             */
/*   Updated: 2025/10/16 21:41:32 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while ((i < (n - 1)) && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

double	atodbl(char *s)
{
	double	whole;
	double	fraction;
	double	divisor;
	int		sign;

	whole = 0.0;
	fraction = 0.0;
	divisor = 10.0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || (*s == 32))
		s++;
	while ((*s == '+') || (*s == '-'))
		if (*s++ == '-')
			sign = -sign;
	while (*s >= '0' && *s <= '9')
		whole = (whole * 10.0) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		fraction += (*s++ - '0') / divisor;
		divisor *= 10.0;
	}
	return (sign * (whole + fraction));
}
