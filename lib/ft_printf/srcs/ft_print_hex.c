/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:50:25 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:38:44 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_get_base(char *base, int x)
{
	int		i;
	int		offset;

	i = 0;
	offset = '0';
	while (i < 16)
	{
		base[i++] = offset++;
		if (i == 10 && x == 0)
			offset = 'a';
		else if (i == 10 && x == 1)
			offset = 'A';
	}
	return (base);
}

int	ft_n_converter(unsigned int n, char *base, int count)
{
	int		num[16];
	int		i;
	int		c;

	i = 0;
	if (n == 0)
	{
		num[i] = 0;
		if (write(1, "0", 1) == -1)
			return (-1);
		return (count + 1);
	}
	while (n != 0)
	{
		num[i++] = n % 16;
		n /= 16;
	}
	count += i;
	while (--i >= 0)
	{
		c = base[num[i]];
		if (write(1, &c, 1) == -1)
			return (-1);
	}
	return (count);
}

int	ft_print_hex(unsigned int n, int x)
{
	char	base[16];
	int		count;
	int		ercheck;

	ercheck = 0;
	ft_get_base(base, x);
	count = 0;
	if (ercheck == -1)
		return (-1);
	count = ft_n_converter(n, base, count);
	return (count);
}
