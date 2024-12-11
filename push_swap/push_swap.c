/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:23:32 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/12/09 16:46:37 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


int main(int ac, char **av)
{
    t_stack_node *a;
    t_stack_node *b;

    a = NULL;
    b = NULL;
    if(ac == 1 || (ac == 2 && !av[1][0]))
        return(1);
    else if(av[1])
        av = split(av[1], ' ');

    init_stack(av+1,&a);
    if(!stack_is_sorted(a))
    {
        if(stack_len(a) == 2)
        sa(&a,true);
        else if(stack_len(a) == 3)
            sort_three(&a);
        else
            sort_stack(&a, &b);
    }
    free_stack(&a);
    return(0);
}