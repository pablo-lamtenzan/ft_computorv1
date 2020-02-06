/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:10:03 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/06 08:53:32 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorv1.h>

int         computor_v1(int ac, char **argv)
{
    t_data    data;
    
    data = (t_data){.pow_0=0.0, .pow_1=0.0, .pow_2=0.0}; 
    if (ac != 2 || !parse(&data, argv[1]))
        return (error("format"));
    if (!(calculator(&data)))
        return (error("math"));
    print_data(data);
    return (TRUE);
}