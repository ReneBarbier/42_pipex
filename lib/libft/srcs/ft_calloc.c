/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:58:44 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:54:53 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*array;

	if (nelem == 0 || elsize == 0)
	{
		return ((void *)malloc(nelem * elsize));
	}
	array = (void *)malloc(nelem * elsize);
	if (!array)
		return (NULL);
	ft_bzero(array, nelem * elsize);
	return (array);
}
