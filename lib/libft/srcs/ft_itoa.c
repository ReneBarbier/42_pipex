/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:13:07 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:56:22 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

int	find_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;
	int		len;
	int		negative;

	negative = 1;
	i = 0;
	if (n < 0)
		i++;
	if (n < 0)
		negative = -1;
	len = find_digits(n) + i;
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	if (n < 0)
		num[i - 1] = '-';
	num[len--] = '\0';
	while (len >= i)
	{
		num[len] = (n % 10) * negative + '0';
		len--;
		n /= 10;
	}
	return (num);
}
