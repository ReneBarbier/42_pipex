/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:42:47 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:59:09 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned long	j;
	unsigned long	full_size;

	i = 0;
	j = 0;
	full_size = 0;
	while (dst[i] != '\0')
		i++;
	while (src[full_size] != '\0')
		full_size++;
	if (size <= i)
		full_size += size;
	else
		full_size += i;
	if (size == 0)
		return (full_size);
	while (src[j] != '\0' && i + 1 < size)
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (full_size);
}
