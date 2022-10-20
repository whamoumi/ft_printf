/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:27:16 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/09 14:29:44 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*flags_precision_string(t_flags *d)
{
	int i;

	i = 0;
	if (d->point == 0 || d->precision <= -1 || d->type == 'c' || d->type == '%')
		return (d->precisionc = ft_strdup(d->converter));
	while (d->converter[i] && i < d->precision)
		i++;
	if (!(d->precisionc = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (d->converter[i] && i < d->precision)
	{
		d->precisionc[i] = d->converter[i];
		i++;
	}
	d->precisionc[i] = '\0';
	return (d->precisionc);
}

char		*flags_precision_integer(t_flags *d)
{
	int		i;
	int		y;
	char	*str;

	i = -1;
	y = 0;
	if (!(str = malloc(sizeof(char) * d->precision + 1)))
		return (NULL);
	while (++i < (int)(d->precision - printf_ft_strlen(d->converter)))
		str[i] = '0';
	while (i < d->precision)
	{
		str[i] = d->converter[y];
		i++;
		y++;
	}
	str[i] = '\0';
	return (str);
}

char		*flags_precision_integer_pos(t_flags *d)
{
	if (d->converter[0] == '0' && d->point && d->precision == 0
		&& (d->type == 'd' || d->type == 'i' || d->type == 'u'
		|| d->type == 'x' || d->type == 'X'))
		return (d->precisionc = ft_strdup(""));
	if (d->zero && d->minus == 0 && d->largeur
		&& d->precision <= -1 && d->prefixe == 1)
		d->precision = d->largeur - 1;
	if (d->zero && d->minus == 0 && d->largeur
		&& d->precision <= -1 && d->prefixe == 0)
		d->precision = d->largeur;
	if ((printf_ft_strlen(d->converter) > (size_t)d->precision)
		|| d->precision <= -1)
	{
		d->precisionc = ft_strdup(d->converter);
		return (d->precisionc);
	}
	else
		d->precisionc = flags_precision_integer(d);
	return (d->precisionc);
}

char		*flags_precision_integer_pre(t_flags *d)
{
	char *pos;

	if (d->prefixe == 2)
		pos = ft_strjoin("0x", d->precisionc);
	if (d->prefixe == 1)
		pos = ft_strjoin("-", d->precisionc);
	d->precisionc = ft_strcpy(d->precisionc, pos);
	free(pos);
	return (d->precisionc);
}
