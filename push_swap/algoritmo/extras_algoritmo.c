/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras_algoritmo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlourenc <xlourenc@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-11 13:08:23 by xlourenc          #+#    #+#             */
/*   Updated: 2024-12-11 13:08:23 by xlourenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void prepare_nodes_a(t_stack_node **a, t_stack_node **b)
{
    set_index(a);
    set_index(b);
    set_target_node_a(a,b);
    set_push_cost(a,b);
    set_cheapest(b);
}
void prepare_nodes_b(t_stack_node **a, t_stack_node **b)
{
    set_index(a);
    set_index(b);
    set_target_node_b(a,b);
}

void move_a_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest_node;

    cheapest_node = find_cheapest_node(*a);
    if(cheapest_node->above_medium && cheapest_node->target_node->above_medium)
        rotate_both(a,b,cheapest_node);
    else if(!(cheapest_node->above_medium) && !(cheapest_node->target_node->above_medium))
        rev_rotate_both(a,b,cheapest_node);
    prep_for_push(a,cheapest_node, 'a');
    prep_for_push(b,cheapest_node->target_node,'b');
    pb(b,a,true);
}

void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    prep_for_push(a,(*b)->target_node, 'a');
    pa(a,b,true);
}
void prep_for_push(t_stack_node **stack, t_stack_node *top_node,char stack_type)
{
    while(stack)
    {
        if((stack_type) == 'a')
        {
            if(top_node->above_medium)
                ra(stack,true);
            else
                rra(stack,true);
        }
        else if((stack_type = 'b'))
        {
            if(top_node->above_medium)
                rb(stack,true);
            else
                rrb(stack,true);    
        }
    }
}
void place_mini_on_top(t_stack_node **a)
{
    while((*a)->nbr != find_cheapest_node(*a)->nbr)
    {
        if((*a)->above_medium)
            ra(a,true);
        else
            rra(a,true);
    }
}
void set_target_node_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *current_b;
    long best_match_index;
    t_stack_node *target_node;

    current_b = *b;
    best_match_index = LONG_MIN;
    while(*a)
    {
    while(current_b)
    {
        if(current_b->nbr < (*a)->nbr && current_b->nbr > best_match_index)
        {
            best_match_index = current_b->nbr;
            target_node = current_b;
        }
        current_b = current_b->next;
    }
    if(best_match_index == LONG_MIN)
        (*a)->target_node = find_biggest_node(*b);
    else
        (*a)->target_node = target_node;

    (*a) = (*a)->next;
    }
}
void set_target_node_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *target_node;
    t_stack_node *current_a;
    long best_match_index;

    current_a = *a;
    target_node = NULL;
    best_match_index = LONG_MAX;
    while(*b)
    {
        while(current_a)
        {
            if(current_a->nbr > (*b)->nbr && current_a->nbr < best_match_index)
            {
                target_node = current_a;
                best_match_index = current_a->nbr;
            }
            current_a = current_a->next;
        }
        if(best_match_index == LONG_MAX)
            (*b)->target_node = find_cheapest_node(current_a);
        else
            (*b)->target_node = target_node;
        (*b) = (*b)->next;
    }
}
void set_push_cost(t_stack_node **a, t_stack_node **b)
{
    int len_a;
    int len_b;

    len_a = stack_len(*a);
    len_b = stack_len(*b);
    while(a)
    {
        if((*a)->above_medium == true)
            (*a)->push_cost = len_a - ((*a)->index);
        else if((*a)->above_medium == false)
            (*a)->push_cost = (*a)->index;

        if((*a)->target_node->above_medium == true)
            (*a)->push_cost += (*b)->index;
        else if((*a)->target_node->above_medium == false)
            (*a)->push_cost += len_b - ((*a)->target_node->index);
    
        (*a) = (*a)->next;
    }
}
void set_index(t_stack_node **stack)
{
    int i;
    long medium;    

    i = 0;
    medium = stack_len(*stack)/2;
    while(*stack)
    {
        (*stack)->index = i;
        if(i <= medium)
            (*stack)->above_medium = false;
        else if(i > medium)
            (*stack)->above_medium = true;
    i++;
    *stack = (*stack)->next;
    }
}

void set_cheapest(t_stack_node **stack)
{
long cheapest_cost;
t_stack_node *cheapest_node;

    cheapest_cost = LONG_MAX;
    while(*stack)
    {
        if((*stack)->push_cost < cheapest_cost)
        {
            cheapest_cost = (*stack)->push_cost;
            cheapest_node = (*stack);
        }
        (*stack) = (*stack)->next;
    }
    cheapest_node->cheapest = true;
}