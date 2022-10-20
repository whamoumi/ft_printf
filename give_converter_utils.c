/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_converter_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 10:11:58 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/09 14:31:20 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t					printf_ft_strlenn(const char *str, t_flags *d)
{
	int i;

	i = 0;
	if (str[0] == 0 && str[1] == 0 && d->type == 'c')
		return (1);
	while (str[i])
		i++;
	return (i);
}

size_t					printf_ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char					*printf_ft_rev(char *str)
{
	size_t			i;
	size_t			n;
	char			temp;

	n = printf_ft_strlen(str);
	i = 0;
	while (n > i)
	{
		n--;
		temp = str[n];
		str[n] = str[i];
		str[i] = temp;
		i++;
	}
	return (str);
}

size_t					printf_size_of_argument(int nb)
{
	unsigned int count;

	count = 0;
	if (nb < 0)
		nb *= -1;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

unsigned long long		printf_size(unsigned long long nb, char *base)
{
	unsigned long long count;

	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		count++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		count++;
		nb /= printf_ft_strlen(base);
	}
	return (count);
}
