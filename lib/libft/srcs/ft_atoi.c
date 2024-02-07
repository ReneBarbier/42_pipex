/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:49:23 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:56:33 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../libft.h"

int	find_num(char *str, int i, int digits, int negative)
{
	int	j;
	int	num;
	int	elevate;
	int	iteration;

	j = 0;
	num = 0;
	iteration = digits;
	while (i < digits + i)
	{
		elevate = 1;
		while (j < iteration - 1)
		{
			elevate *= 10;
			j++;
		}
		num += (str[i] - 48) * elevate;
		iteration--;
		digits--;
		j = 0;
		i++;
	}
	if (negative == 1)
		num *= -1;
	return (num);
}

int	ft_atoi(char *str)
{
	int		i;
	int		negative;
	int		digits;

	i = 0;
	digits = 0;
	negative = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		negative = 1;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		digits++;
		i++;
	}
	if (digits == 0)
		return (0);
	i -= digits;
	return (find_num(str, i, digits, negative));
}
