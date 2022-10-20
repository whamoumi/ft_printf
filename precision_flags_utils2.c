/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_flags_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:57:12 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/09 14:03:50 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strncopy(char *dest, char *src, unsigned int n, t_flags *d)
{
	unsigned int i;

	i = 0;
	while (i < printf_ft_strlenn(src, d) && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = dest[i];
		i++;
	}
	dest[printf_ft_strlen(dest)] = 0;
	return (dest);
}

char		*flag_space(char *dest, char *src)
{
	int i;
	int j;

	i = (int)(printf_ft_strlen(dest) - 1);
	j = (int)(printf_ft_strlen(src) - 1);
	while (j >= 0 && src[j])
	{
		dest[i] = src[j];
		j--;
		i--;
	}
	while (i >= 0)
	{
		dest[i] = ' ';
		i--;
	}
	dest[printf_ft_strlen(dest)] = 0;
	return (dest);
}

char		*flag_spacee(char *dest, char *src, t_flags *d)
{
	int i;
	int j;

	i = (int)(printf_ft_strlen(dest) - 1);
	j = (int)(printf_ft_strlenn(src, d) - 1);
	while (j >= 0)
	{
		dest[i] = src[j];
		j--;
		i--;
	}
	while (i >= 0)
	{
		dest[i] = ' ';
		i--;
	}
	dest[printf_ft_strlen(dest)] = 0;
	return (dest);
}

char		*flag_zero(char *dest, char *src)
{
	int i;
	int j;

	i = (int)(printf_ft_strlen(dest) - 1);
	j = (int)(printf_ft_strlen(src) - 1);
	while (j > -1 && src[j])
	{
		dest[i] = src[j];
		j--;
		i--;
	}
	i++;
	while (i-- > -1)
		dest[i] = '0';
	dest[printf_ft_strlen(dest)] = 0;
	return (dest);
}

char		*flag_zeroo(char *dest, char *src, t_flags *d)
{
	int i;
	int j;

	i = (int)(printf_ft_strlenn(dest, d) - 1);
	j = (int)(printf_ft_strlenn(src, d) - 1);
	while (j > -1)
	{
		dest[i] = src[j];
		j--;
		i--;
	}
	i++;
	while (i-- > -1)
		dest[i] = '0';
	dest[printf_ft_strlenn(dest, d)] = 0;
	return (dest);
}
