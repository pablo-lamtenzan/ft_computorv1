/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:07:48 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/06 10:34:19 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <computorv1.h>
#include <regex.h>
#include <stdlib.h>

static int      regex_pow0(t_data *data, char *input, char flag)
{
    regex_t     rgx;
    regmatch_t  maches[MAXMACHES];
    
    if (!(regcomp(&rgx, "([+-] )?([0-9]+(.[0-9]*)? \\* X\\^0)", 0)))
    {
        while (!(regexec(&rgx, input, MAXMACHES, maches, 0))) // if it copies all the times the same i increment input adress
            data->pow_0 += !flag ? ft_atoi(input + maches[0].rm_so)
                : -ft_atoi(input + maches[0].rm_so);
        regfree(&rgx);
        return (TRUE);
    }
    regfree(&rgx);
    return (FALSE);
}

static int      regex_pow1(t_data *data, char *input, char flag)
{
    regex_t     rgx;
    regmatch_t  maches[MAXMACHES];

    if (!(regcomp(&rgx, "([+-] )?([0-9]+(.[0-9]*)? \\* X\\^1)", 0)))
    {
        while (!(regexec(&rgx, input, MAXMACHES, maches, 0))) // if it copies all the times the same i increment input adress
            data->pow_1 += !flag ? ft_atoi(input + maches[0].rm_so)
                : -ft_atoi(input + maches[0].rm_so);
        regfree(&rgx);
        return (TRUE);
    }
    regfree(&rgx);
    return (FALSE);
}

static int      regex_pow2(t_data *data, char *input, char flag)
{
    regex_t     rgx;
    regmatch_t  maches[MAXMACHES];

    if (!(regcomp(&rgx, "([+-] )?([0-9]+(.[0-9]*)? \\* X\\^2)", 0)))
    {
        while (!(regexec(&rgx, input, MAXMACHES, maches, 0))) // if it copies all the times the same i increment input adress
            data->pow_2 += !flag ? ft_atoi(input + maches[0].rm_so)
                : -ft_atoi(input + maches[0].rm_so);
        regfree(&rgx);
        return (TRUE);
    }
    regfree(&rgx);
    return (FALSE);
}

static int      regex_parse(t_data *data, char *input, char flag) // + probally check no valid shit
{
    char *tmp;

    if (flag)
    {
            tmp = ft_strdup(" ");
            input = ft_strjoin(input, tmp);
            free(tmp);
    }
    if (!regex_pow0(data, input, flag)
        || !regex_pow1(data, input, flag)
        || !regex_pow2(data, input, flag))
        return (FALSE);
    return (TRUE);    
}
    
int             parse(t_data *data, char *input)
{
    char        **split;

    if (!(split = ft_split(input, EQUAL))
            || split[2]
            || !regex_parse(data, split[0], FALSE)
            || !regex_parse(data, split[1], TRUE)
            || !check_format(split[0])
            || !check_format(split[1]))
        return (FALSE); //error not valid format
    return (TRUE);
}