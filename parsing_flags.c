/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:01:20 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/10 09:18:06 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		printf_is_flags(const char c)
{
	int		i;
	char	*str;

	str = "0123456789.*-";
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int		printf_return_type(char c)
{
	if (c == 'd' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x'
		|| c == 'X' || c == '%' || c == 'c')
		return (1);
	return (0);
}

void	flags_stars(t_flags *d, const char *format, va_list argument, int i)
{
	if (format[i - 1] == '.')
		d->precision = va_arg(argument, int);
	else
	{
		d->largeur = va_arg(argument, int);
		if (d->largeur < 0)
		{
			d->largeur *= -1;
			d->minus += 1;
		}
	}
}

void	flags_minus(t_flags *d, int i)
{
	d->minus += 1;
	d->pos_minus = i;
}

void	printf_traitement_flags(t_flags *d, const char *format)
{
	if (d->minus > 0 && d->pos_minus != -1
			&& d->zero == 0 && format[d->pos_minus + 1] != '*')
	{
		d->largeur = 0;
		d->pos_minus += 1;
		while ((format[d->pos_minus] >= '0'
					&& format[d->pos_minus] <= '9') && format[d->pos_minus])
		{
			d->largeur = d->largeur * 10 + (format[d->pos_minus] - '0');
			d->pos_minus += 1;
		}
	}
	if (d->point > 0 && format[d->pos_point + 1] != '*')
	{
		d->precision = 0;
		d->pos_point += 1;
		while ((format[d->pos_point] >= '0'
					&& format[d->pos_point] <= '9') && format[d->pos_point])
		{
			d->precision = d->precision * 10 + (format[d->pos_point] - '0');
			d->pos_point += 1;
		}
	}
}
