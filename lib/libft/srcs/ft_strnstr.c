/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:43:58 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:59:42 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	int		j;
	int		m_i;

	i = 0;
	len++;
	if (to_find[0] == '\0')
		return ((char *) str);
	while (str[i] != '\0' && len-- > 0)
	{
		m_i = i;
		j = 0;
		while (str[m_i++] == to_find[j] && len-- > 0)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *) str + i);
			if (len == 0)
				return (0);
		}
		len += j;
		i++;
	}
	return (0);
}
