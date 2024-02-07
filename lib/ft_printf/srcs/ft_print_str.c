/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:55:12 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:39:00 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_str(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (write(1, "(null)", 6));
	}
	while (s[i])
		if (write(1, &s[i++], 1) == -1)
			return (-1);
	return (i);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}
