/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamoumi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:01:08 by whamoumi          #+#    #+#             */
/*   Updated: 2021/03/10 09:19:51 by whamoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_flags{
	int		minus;
	int		pos_minus;
	int		zero;
	int		largeur;
	int		point;
	int		pos_point;
	int		precision;
	int		prefixe;
	int		size_a;
	char	*flags;
	char	*precisionc;
	char	*converter;
	char	*result;
	char	type;
	int		breake;
	int		stars;
}					t_flags;

void				flags_stars(t_flags *d, const char *format,
					va_list argument, int i);
void				flags_minus(t_flags *d, int i);
void				printf_give_converter(va_list argument, t_flags *d);
void				printf_init_struct(t_flags *d);
void				printf_traitement_flags(t_flags *d, const char *format);
void				printf_parsing_flags(t_flags *d, const char *format,
					va_list argument);
void				free_str(t_flags *d);
char				*printf_flags_largeur(t_flags *d);
char				*printf_fill_largeur(char *str, int size);
char				*printf_converter_c(int nb, t_flags *d);
char				*printf_converter_id(int nb, t_flags *d);
char				*printf_converter_uxx(unsigned int nb, char *base,
					t_flags *d);
char				*printf_converter_s(char *str, t_flags *d);
char				*printf_converter_pourcent(t_flags *d);
char				*printf_ft_rev(char *str);
char				*place_in_width(t_flags *d);
char				*flags_precision_integer_pre(t_flags *d);
char				*flags_precision_integer_pos(t_flags *d);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(char *str);
char				*flags_precision_string(t_flags *d);
char				*flag_space(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*flag_zero(char *dest, char *src);
char				*flags_precision_integer(t_flags *d);
char				*ft_strncopy(char *dest, char *src, unsigned int n,
					t_flags *d);
char				*flag_spacee(char *dest, char *src, t_flags *d);
char				*flag_zeroo(char *dest, char *src, t_flags *d);
char				*ft_strcpy(char *dest, char *src);
char				*printf_converter_p(void *str, char *base, t_flags *d);
int					printf_block(t_flags d, int i, const char *format,
					va_list argument);
int					printf_ft_putstr(char *str, t_flags *d);
int					printf_ft_putchar(char c);
int					ft_printf(const char *format, ...);
int					printf_return_type(char c);
int					printf_is_flags(const char c);
int					give_size_result(int largeur, int precision, int size);
size_t				printf_ft_strlenn(const char *str, t_flags *d);
size_t				printf_ft_strlen(const char *str);
size_t				printf_size_of_argument(int nb);
unsigned long long	printf_size(unsigned long long nb, char *base);
#endif
