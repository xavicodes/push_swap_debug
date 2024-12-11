/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:47:44 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/12/09 14:00:55 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
        while(*b != cheapest_node->target_node && *a != cheapest_node)
        {
        rr(a,b);
        set_index(a);
        set_index(b);
        }
}

void rev_rotate_both(t_stack_node **a,t_stack_node **b, t_stack_node *cheapest_node)
{
        while(*b != cheapest_node->target_node && *a != cheapest_node)
        rrr(a,b);
        set_index(a);
        set_index(b);
}