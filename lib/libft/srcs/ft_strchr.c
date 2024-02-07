/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:28:05 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:58:38 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (s[size])
		size++;
	while (s[i] != (char)c)
	{
		if (i == size)
			return (NULL);
		else
			i++;
	}
	return ((char *)&s[i]);
}
