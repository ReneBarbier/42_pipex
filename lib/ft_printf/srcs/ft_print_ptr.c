/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:50:59 by rbarbier          #+#    #+#             */
/*   Updated: 2023/12/12 12:42:41 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*array;
	char	*s;
	size_t	i;
	size_t	n;

	if (nelem == 0 || elsize == 0)
	{
		return ((void *)malloc(nelem * elsize));
	}
	array = (void *)malloc(nelem * elsize);
	if (!array)
		return (NULL);
	n = nelem * elsize;
	i = 0;
	s = (char *)array;
	while (i < n)
		s[i++] = '\0';
	return (array);
}

char	*ft_make_str(unsigned long n, int *len)
{
	int		i;
	char	*str;

	i = 0;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	str = ft_calloc(i, sizeof(char));
	*len = i - 1;
	return (str);
}

int	ft_extra(int i, unsigned long ptr, char *output)
{
	char	base[16];
	int		j;
	int		tmp;

	ft_get_base(base, 0);
	j = i;
	while (ptr != 0)
	{
		output[i--] = ptr % 16;
		ptr /= 16;
	}
	while (++i <= j)
	{
		tmp = base[(int)output[i]];
		if (write(1, &tmp, 1) == -1)
			return (-1);
	}
	return (1);
}

int	ft_print_ptr(unsigned long ptr)
{
	char	*output;
	int		count;
	int		i;

	i = 0;
	count = ft_print_str("0x");
	if (count == -1)
		return (-1);
	if (ptr == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (3);
	}
	output = ft_make_str(ptr, &i);
	if (!output)
		return (0);
	count += i + 1;
	if (ft_extra(i, ptr, output) == -1)
		return (-1);
	free(output);
	return (count);
}
