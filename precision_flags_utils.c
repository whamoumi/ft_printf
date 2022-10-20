/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_flags_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 12:50:28 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/09 14:03:14 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(char *str)
{
	int		i;
	char	*copy;

	i = 0;
	while (str[i])
		i++;
	if (!(copy = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		y;

	if (!(res = malloc(sizeof(char)
					* (printf_ft_strlen(s1) + printf_ft_strlen(s2) + 1))))
		return (NULL);
	i = -1;
	y = 0;
	while (s1[++i])
		res[y++] = s1[i];
	i = -1;
	while (s2[++i])
		res[y++] = s2[i];
	res[y] = '\0';
	return (res);
}

char		*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = dest[i];
		i++;
	}
	return (dest);
}

char		*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
