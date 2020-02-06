/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:04:55 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/06 07:48:50 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorv1.h>
#include <stdio.h> // just cause i haven t a print double right now

static void print_second_degree(t_data data)
{
    printf("Polinomial degree : 2\n");
    if (data.delta > 0)
    {
        printf("Discriminant is strictly positive, the two solutions are:\n");
        printf("%s\n%s\n", data.solution1, data.solution2);
    }
    else if (!data.delta)
    {
        printf("Discriminant is equal zero, the solutions is:\n");
        printf("%s\n", data.solution1);
    }
    else
        printf("Discriminant is under zero, no solution in real numbers.\n");
}

void        print_data(t_data data)
{
    printf("Reduced from: %s\n", data.reduced_from);
    if (data.pow_2)
        print_second_degree(data);
    else
    {
        printf("Polinomial degree : %d", data.pow_1 ? 1 : 0);
        if (data.pow_1)
        {
            printf("Polinomial degree : 1\n");
            printf("Solution is :\n%s\n", data.solution1);
        }
        else
            printf(" Math error, degree 0 is always true or has no sulution.\n");
    }
}