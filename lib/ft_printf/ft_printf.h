/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 13:19:51 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:38:31 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_istype(char c);
int		ft_print_str(const char *s);
int		ft_print_int(int n, int x);
int		ft_print_hex(unsigned int n, int x);
int		ft_print_char(char c);
int		ft_print_ptr(unsigned long ptr);
char	*ft_strdup(const char *str);
char	*ft_get_base(char *base, int x);
int		ft_n_converter(unsigned int n, char *base, int count);

#endif