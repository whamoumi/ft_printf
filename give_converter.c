/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:10:46 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/09 14:31:10 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*printf_converter_c(int nb, t_flags *d)
{
	if (!(d->converter = malloc(sizeof(char) * 2)))
		return (NULL);
	if (nb == 0)
		d->breake = 1;
	d->converter[0] = nb % 256;
	d->converter[1] = '\0';
	return (d->converter);
}

char		*printf_converter_id(int nb, t_flags *d)
{
	int i;

	i = 0;
	if (nb == -2147483648)
		return (d->converter = ft_strdup("-2147483648"));
	if (!(d->converter = malloc(printf_size_of_argument(nb) + 1)))
		return (NULL);
	if (nb < 0)
	{
		d->prefixe = 1;
		nb *= -1;
	}
	if (nb == 0)
	{
		d->converter[0] = '0';
		d->converter[1] = '\0';
		return (d->converter);
	}
	while (nb > 0)
	{
		d->converter[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	d->converter[i] = '\0';
	return (d->converter = printf_ft_rev(d->converter));
}

char		*printf_converter_uxx(unsigned int nb, char *base, t_flags *d)
{
	int	i;

	i = 0;
	if (!(d->converter = malloc(printf_size(nb, base) + 1)))
		return (NULL);
	if (nb == 0)
	{
		d->converter[0] = '0';
		d->converter[1] = '\0';
		return (d->converter);
	}
	while (nb > 0)
	{
		d->converter[i] = base[nb % (unsigned int)printf_ft_strlen(base)];
		i++;
		nb /= (unsigned int)printf_ft_strlen(base);
	}
	d->converter[i] = '\0';
	return (printf_ft_rev(d->converter));
}

char		*printf_converter_p(void *str, char *base, t_flags *d)
{
	unsigned long long	nb;
	int					i;

	nb = (unsigned long long)str;
	i = 0;
	if (str == NULL && d->point)
		return (d->converter = ft_strdup(""));
	if (!(d->converter = malloc(printf_size(nb, base) + 1)))
		return (NULL);
	if (nb == 0 || str == NULL)
	{
		d->converter[0] = '0';
		d->converter[1] = '\0';
		return (d->converter);
	}
	while (nb > 0)
	{
		d->converter[i] = base[nb % (unsigned long long)printf_ft_strlen(base)];
		i++;
		nb /= (unsigned long long)printf_ft_strlen(base);
	}
	d->converter[i] = '\0';
	return (printf_ft_rev(d->converter));
}

char		*printf_converter_s(char *str, t_flags *d)
{
	int i;

	i = 0;
	if (str == NULL)
		return (d->converter = ft_strdup("(null)"));
	if (!(d->converter = malloc(printf_ft_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		d->converter[i] = str[i];
		i++;
	}
	d->converter[i] = '\0';
	return (d->converter);
}
