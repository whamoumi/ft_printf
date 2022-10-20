/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:55:04 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/09 14:15:53 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_fill_largeur(char *str, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		give_size_result(int largeur, int precision, int size)
{
	if (largeur >= precision && largeur >= size)
		return (largeur);
	else if (largeur >= precision && largeur <= size)
		return (largeur);
	else if (largeur <= precision && largeur >= size)
		return (precision);
	else if (largeur <= precision && largeur >= size)
		return (precision);
	else if (precision >= largeur && precision >= size)
		return (precision);
	else if (precision >= largeur && precision <= size)
		return (precision);
	else if (precision <= largeur && precision >= size)
		return (largeur);
	else if (precision <= largeur && precision <= size)
		return (largeur);
	else
		return (0);
}

char	*printf_flags_largeur(t_flags *d)
{
	int size;
	int convert;

	if (d->prefixe == 1)
		size = (int)printf_ft_strlen(d->converter) + 1;
	else
		size = (int)printf_ft_strlen(d->converter);
	convert = give_size_result(d->largeur,
			(int)printf_ft_strlen(d->precisionc), size);
	if (!(d->result = malloc(sizeof(char) * convert + 1)))
		return (NULL);
	d->result = printf_fill_largeur(d->result, convert);
	return (d->result);
}
