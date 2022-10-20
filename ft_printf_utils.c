/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:28:31 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/10 09:10:12 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			printf_ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int			printf_ft_putstr(char *str, t_flags *d)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	if (str[i] == 0 && (str[i + 1] == 0 || str[i + 1] == ' ')
		&& d->type == 'c' && d->breake == 1)
	{
		write(1, &str[i], 1);
		i += 1;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

char		*place_in_width(t_flags *d)
{
	int pre;
	int res;

	pre = printf_ft_strlen(d->precisionc);
	res = printf_ft_strlen(d->result);
	if (d->type == 'c' && d->minus == 0)
		return (d->result = flag_spacee(d->result, d->converter, d));
	if (d->type == 'c' && d->minus && d->converter[0] == '\0')
		return (d->result = ft_strncopy(d->result, d->converter, res, d));
	if (((d->type == 'd' || d->type == 'i' || d->type == 'u'
		|| d->type == 'x' || d->type == 'X')
		&& d->point && d->precision == 0
		&& d->converter[0] == '0' && d->largeur == 0))
		return (d->result = ft_strncopy(d->result, d->precisionc, pre, d));
	if (d->minus > 0)
		d->result = ft_strncpy(d->result, d->precisionc, res);
	if (d->minus == 0 && d->point >= 0)
		d->result = flag_space(d->result, d->precisionc);
	if (d->zero > 0 && d->minus == 0 && (d->precision <= -1 || d->type == '%'))
		d->result = flag_zero(d->result, d->precisionc);
	return (d->result);
}

void		free_str(t_flags *d)
{
	free(d->converter);
	free(d->precisionc);
	free(d->result);
}

int			printf_block(t_flags d, int i, const char *format, va_list argument)
{
	int y;

	y = 0;
	printf_traitement_flags(&d, &format[i + 1]);
	printf_give_converter(argument, &d);
	if (d.type == 's' || d.type == 'c' || d.type == '%')
		flags_precision_string(&d);
	if (d.type == 'd' || d.type == 'i' || d.type == 'x'
		|| d.type == 'X' || d.type == 'u' || d.type == 'p')
	{
		flags_precision_integer_pos(&d);
		if (d.prefixe)
			flags_precision_integer_pre(&d);
	}
	printf_flags_largeur(&d);
	place_in_width(&d);
	y = printf_ft_putstr(d.result, &d);
	free_str(&d);
	return (y);
}
