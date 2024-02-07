/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:06:16 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 13:00:05 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub_s;
	unsigned long long	j;
	unsigned long long	i;

	if (start > (unsigned int) ft_strlen(s))
	{
		sub_s = ft_calloc(1, 1);
		return (sub_s);
	}
	if ((unsigned long) ft_strlen(s) - start < len)
		sub_s = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		sub_s = malloc(sizeof(char) * (len + 1));
	if (!sub_s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			sub_s[j++] = s[i];
		i++;
	}
	sub_s[j] = '\0';
	return (sub_s);
}
