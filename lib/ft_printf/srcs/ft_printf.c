/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:07:13 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:39:03 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_istype(char c)
{
	if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' \
		|| c == 'x' || c == 'X' || c == 'p' || c == '%')
		return (1);
	return (0);
}

int	ft_check_type(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count = ft_print_char('%');
	else if (c == 'c')
		count = ft_print_char(va_arg(args, int));
	else if (c == 's')
		count = ft_print_str(va_arg(args, const char *));
	else if (c == 'd' || c == 'i')
		count = ft_print_int(va_arg(args, int), 0);
	else if (c == 'u')
		count = ft_print_int(va_arg(args, int), 1);
	else if (c == 'x')
		count = ft_print_hex(va_arg(args, unsigned int), 0);
	else if (c == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), 1);
	else if (c == 'p')
		count = ft_print_ptr(va_arg(args, unsigned long));
	return (count);
}

int	ft_text_iter(char const *str, va_list args)
{
	int		i;
	int		count;
	int		ercheck;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			if (ft_istype(str[++i]))
				ercheck = ft_check_type(args, str[i]);
		}
		else
			ercheck = ft_print_char(str[i]);
		if (ercheck == -1)
			return (-1);
		count += ercheck;
	}
	return (count);
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		count;

	if (!s || !*s)
		return (0);
	count = 0;
	va_start(args, s);
	count = ft_text_iter(s, args);
	va_end(args);
	return (count);
}
