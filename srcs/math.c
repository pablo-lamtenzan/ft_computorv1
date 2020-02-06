/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 04:33:56 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/06 07:16:19 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorv1.h>

int		ft_pow(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (ft_pow(nb, power - 1) * nb);
}

int		ft_sqrt(int nb)
{
	long int i;

	i = 0;
	while (i * i < nb)
		i++;
	if (nb == i * i)
		return (i);
	return (0);
}