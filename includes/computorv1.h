/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:11:35 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/06 09:53:32 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

#include "libft.h"

/*
**      -> DEFINES
*/
#define EQUAL          '='
#define TRUE            1
#define FALSE           0
#define PLUS            1
#define MAXMACHES       64

/*
**      - > STRUCTS
*/
typedef struct          s_data
{
    double              pow_0;
    double              pow_1;
    double              pow_2;
    char                *reduced_from;
    char                *degree;
    double              delta;
    char                *solution1;
    char                *solution2;
}                       t_data;

/*
**      - > DEFINITIONS
*/
int                     computor_v1(int ac, char **argv);
int                     parse(t_data *data, char *input);
int                     calculator(t_data *data);
void                    print_data(t_data data);
int                     error(char *code);
int                     check_format(char *input);
/*
**      - > AUX DEF
*/
int		                ft_pow(int nb, int power);
int		                ft_sqrt(int nb);

#endif