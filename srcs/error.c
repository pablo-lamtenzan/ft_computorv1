/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 03:40:48 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/06 09:40:09 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* https://regex101.com */

#include <computorv1.h>
#include <stdio.h>
#include <regex.h>

int     error(char *code)
{
    if (!ft_strncmp(code, "math", 5))
        printf("Math error. :(\n");
    if (!ft_strncmp(code, "format", 6))
        printf("Format error. :(\n");
    return (FALSE);
}

int     check_format(char *input)
{
    regex_t     rgx;

    if ((regcomp(&rgx, "(( ?)([+-] )?([0-9]+(.[0-9]*)? \\* X\\^[0-2]) )+", 0)) // change " ? to only first character"
            || regexec(&rgx, input, 0, NULL, 0))
        return (FALSE);
        printf("aaa\n\n\n");
    if ((regcomp(&rgx, "(X\\^[3-9)])" , 0)) // have to chage to grather than 2 not in range [3-9]
            || !regexec(&rgx, input, 0, NULL, 0))
        return (FALSE);
    regfree(&rgx);
    return (TRUE);
}