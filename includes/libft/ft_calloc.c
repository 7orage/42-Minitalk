/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lheteau <lheteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:05:47 by lheteau           #+#    #+#             */
/*   Updated: 2025/11/24 12:12:47 by lheteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)malloc(elementCount * elementSize);
	i = 0;
	if (p == NULL || elementCount < 0 || elementSize < 0)
		return (p);
	while (i < elementCount * elementSize)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
