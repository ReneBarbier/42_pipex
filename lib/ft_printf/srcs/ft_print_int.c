/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:04:40 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:38:50 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	r_write_num(long n)
{
	int	chr;

	if (n > 0)
	{
		chr = n % 10 + '0';
		n /= 10;
		if (r_write_num(n) == -1)
			return (-1);
		if (write(1, &chr, 1) == -1)
			return (-1);
	}
	return (1);
}

int	ft_count_digits(long n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		digits = 1;
	}
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

long	ft_checks(long num)
{
	int	ercheck;

	ercheck = 0;
	if (num < 0)
	{
		num *= -1;
		ercheck = write(1, "-", 1);
	}
	if (ercheck == -1)
		return (-1);
	return (num);
}

int	ft_print_int(int n, int x)
{
	long	num;
	int		len;

	num = n;
	len = 0;
	if (x == 1 && num < 0)
		num = 4294967296 + num;
	len += ft_count_digits(num);
	num = ft_checks(num);
	if (num == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
	}
	else if (num == -1)
		return (-1);
	if (r_write_num(num) == -1)
		return (-1);
	return (len);
}
