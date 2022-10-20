/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_converter_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 11:23:12 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/09 14:32:00 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*printf_converter_pourcent(t_flags *d)
{
	if (!(d->converter = malloc(sizeof(char) * 1 + 1)))
		return (NULL);
	d->converter[0] = '%';
	d->converter[1] = '\0';
	return (d->converter);
}

void		printf_give_converter(va_list argument, t_flags *d)
{
	if (d->type == 'd' || d->type == 'i')
		d->converter = printf_converter_id(va_arg(argument, int), d);
	if (d->type == 'c')
		d->converter = printf_converter_c(va_arg(argument, int), d);
	if (d->type == 's')
		d->converter = printf_converter_s(va_arg(argument, char *), d);
	if (d->type == '%')
		d->converter = printf_converter_pourcent(d);
	if (d->type == 'u')
		d->converter = printf_converter_uxx((unsigned long long)
			va_arg(argument, int), "0123456789", d);
	if (d->type == 'x')
		d->converter = printf_converter_uxx((unsigned long long)
			va_arg(argument, int), "0123456789abcdef", d);
	if (d->type == 'X')
		d->converter = printf_converter_uxx((unsigned long long)
			va_arg(argument, int), "0123456789ABCDEF", d);
	if (d->type == 'p')
	{
		d->prefixe = 2;
		d->converter = printf_converter_p(va_arg(argument, void *),
			"0123456789abcdef", d);
	}
}
