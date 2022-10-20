/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 11:19:20 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/10 09:18:42 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void		printf_init_struct(t_flags *d)
{
	d->minus = 0;
	d->pos_minus = -1;
	d->zero = 0;
	d->largeur = 0;
	d->point = 0;
	d->pos_point = -1;
	d->precision = -1;
	d->size_a = 0;
	d->prefixe = 0;
	d->flags = NULL;
	d->converter = NULL;
	d->precisionc = NULL;
	d->result = NULL;
	d->type = 0;
	d->breake = 0;
	d->stars = 0;
}

void		printf_parsing_flags(t_flags *d, const char *format,
			va_list argument)
{
	int i;

	i = 0;
	while (format[i] && printf_is_flags(format[i]))
	{
		if ((format[i] == '0' && format[i - 1] != '.')
			&& (format[i] == '0' && ((!(format[i - 1] >= '0'
			&& format[i - 1] <= '9')))))
			d->zero = 1;
		if (format[i] == '-')
			flags_minus(d, i);
		if (d->point == 0 && (format[i] >= '0' && format[i] <= '9'))
			d->largeur = d->largeur * 10 + (format[i] - '0');
		if (format[i] == '.')
		{
			d->point += 1;
			d->pos_point = i;
		}
		if (format[i] == '*')
			flags_stars(d, format, argument, i);
		i++;
	}
	d->size_a = i;
	if ((printf_return_type(format[i]) == 1))
		d->type = format[i];
}

int			ft_printf(const char *format, ...)
{
	int			i;
	int			count;
	va_list		argument;
	t_flags		d;

	i = 0;
	va_start(argument, format);
	count = 0;
	if (*format == '\0')
		return (printf_ft_putstr("", &d));
	while (format[i])
	{
		printf_init_struct(&d);
		if (format[i] == '%')
		{
			printf_parsing_flags(&d, &format[i + 1], argument);
			count += printf_block(d, i, format, argument);
			i += d.size_a + 2;
		}
		else
			count += printf_ft_putchar(format[i++]);
	}
	va_end(argument);
	return (count);
}
