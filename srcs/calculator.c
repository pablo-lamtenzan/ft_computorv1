/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:15:46 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/06 07:15:06 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorv1.h>
#include <stdio.h>
#include <stdlib.h>

static void     reduce_form(t_data *data)
{
    char    *pow0;
    char    *pow1;
    char    *pow2;
    char    *tmp;
    char    *tmp2;
    
    asprintf(&pow0, "%lf", data->pow_0 >= 0.0 ? data->pow_0 : -data->pow_0);
    asprintf(&pow1, "%lf", data->pow_1 >= 0.0 ? data->pow_1 : -data->pow_1);
    asprintf(&pow2, "%lf", data->pow_2 >= 0.0 ? data->pow_2 : -data->pow_2);
    asprintf(&data->reduced_from, "%s * X^0 %c %s * X^1 %c %s * X^2", pow2,
            data->pow_1 > 0 ? '+' : '-', pow1,
            data->pow_0 > 0 ? '+' : '-', pow0);
    free(pow0);
    free(pow1);
    free(pow2);
    if (data->pow_2 < 0)
    {
        tmp2 = data->reduced_from;
        tmp = ft_strdup("- ");
        data->reduced_from = ft_strjoin(tmp, tmp2);
        free(tmp);
        free(tmp2);
    }
}

static void     calc_delta(t_data *data)
{
    double tmp;

    tmp = ft_pow(data->pow_1, 2);
    data->delta = tmp - 4.0 * data->pow_2 * data->pow_0;
}

static int      solve_polinomial(t_data *data)
{
    if (data->pow_2)
    {
        if (data->delta > 0)
        {
            /* b+- sqrt(delta) / 2a */
            asprintf(&data->solution1, "%lf", data->pow_1 + ft_sqrt(data->delta) /
                (2.0 * data->pow_2));
            asprintf(&data->solution2, "%lf", data->pow_1 - ft_sqrt(data->delta) /
                (2.0 * data->pow_2));
        }
        else if (!data->delta)
        {
            /* -b / 2a */
            asprintf(&data->solution1, "%lf", -data->pow_1 / (2.0 * data->pow_2));
        }
        else
            return (TRUE);
    }
    else if (data->pow_1)
    {
        /* 1st degree equ */
        asprintf(&data->solution1, "%lf", -data->pow_0 / data->pow_1);
    }
    else
        return (TRUE);
    return (FALSE);
}

int             calculator(t_data *data) // here i can add bonus to print steps
{
    if (!data->pow_0 && !data->pow_1 && !data->pow_2)
        return (FALSE); // format error
    reduce_form(data);
    calc_delta(data);
    if (!(solve_polinomial(data)))
        return (FALSE);
    return (TRUE);
}