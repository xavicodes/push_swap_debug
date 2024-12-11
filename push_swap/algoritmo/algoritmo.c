/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritmo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:22:55 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/12/09 15:33:08 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

bool stack_is_sorted(t_stack_node *stack)
{

        if(!stack)
                return(1);

        while(stack->next)
        {
                if(stack->nbr > stack->next->nbr)
                        return(false);
        stack = stack->next;
        }
        return(true);
}


void sort_three(t_stack_node **a)
{
        t_stack_node *temp;

        temp = find_biggest_node(*a);
        if(*a == temp)
                ra(a,true);
        else if((*a)->next == temp)
                rra(a,true);
        if((*a)->nbr >(*a)->next->nbr )
                sa(a,true);
}

void sort_stack(t_stack_node **a, t_stack_node **b)
{
        int len_a;
        
        len_a = stack_len(*a);
        if(len_a-- > 3 && !stack_is_sorted(*a))
                pb(b,a,true);
        if(len_a-- > 3 && !stack_is_sorted(*a))
                pb(b,a,true);
        while(len_a-- > 3 && !stack_is_sorted(*a))
        {
                prepare_nodes_a(a, b);
                move_a_to_b(a, b);
        }
        sort_three(a);
        while(*b)
        {
                prepare_nodes_b(a,b);
                move_b_to_a(a,b);
        }
        set_index(a);
        place_mini_on_top(a);
}