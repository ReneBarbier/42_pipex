/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 11:25:02 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:57:42 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

void	r_write_num(long n, int fd)
{
	int	chr;

	if (n > 0)
	{
		chr = n % 10 + '0';
		n /= 10;
		r_write_num(n, fd);
		write(fd, &chr, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		num *= -1;
		write(fd, "-", 1);
	}
	r_write_num(num, fd);
}
