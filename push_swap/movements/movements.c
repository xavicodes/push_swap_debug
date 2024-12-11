/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:23:03 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/12/03 15:00:43 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
//---------------SWAP-----------------

void sa(t_stack_node **stack_a, bool check_print)
{
        if((*stack_a) == NULL)
                return;
        t_stack_node *temp;

        temp = (*stack_a)->next;
        (*stack_a)->next = temp->next;
        temp->next = *stack_a;  
        *stack_a = temp;
        if(check_print == true)
        printf("sa");
}
void sb(t_stack_node **stack_b, bool check_print)
{
        if((*stack_b) == NULL)
                return;
        t_stack_node *temp;

        temp = (*stack_b)->next;
        (*stack_b)->next = temp->next;
        temp->next = *stack_b;  
        *stack_b = temp;
        if(check_print == true)
        printf("sb");

}
//-----------------PUSH------------------------- NEEDS TO BE WORKED ON NOT FINISHED JUST A SQUEMATIC

void pa(t_stack_node **stack_a,t_stack_node **stack_b, bool check_print)
{
        if(*stack_b == NULL)
                return;
        t_stack_node *temp;

        temp = *stack_b;
        *stack_b = (*stack_b)->next;
        temp->next = *stack_a;
        if(check_print == true)
        printf("pa");

}
void pb(t_stack_node **stack_b,t_stack_node **stack_a, bool check_print)
{
        if(*stack_b == NULL)
                return;
        t_stack_node *temp;

        temp = *stack_b;
        *stack_b = (*stack_b)->next;
        temp->next = *stack_a;
        if(check_print == true)
        printf("pb");

}
//-----------ROTATE--------------------------
void ra(t_stack_node **stack_a, bool check_print)
{
    if(*stack_a == NULL ||(*stack_a)->next == NULL)
        return;
    t_stack_node *last;

    last = get_last_node(*stack_a);

    *stack_a = (*stack_a)->next;
    last->next = *stack_a;
    (*stack_a)->prev = NULL;
    last->next->prev = last;
    last->next->next = NULL;
    if(check_print == true)
        printf("ra\n");
}


void rb(t_stack_node **stack_b, bool check_print)
{
    if(*stack_b == NULL ||(*stack_b)->next == NULL)
        return;
    t_stack_node *last;

    last = get_last_node(*stack_b);

    *stack_b = (*stack_b)->next;
    last->next = *stack_b;
    (*stack_b)->prev = NULL;
    last->next->prev = last;
    last->next->next = NULL;
    if(check_print == true)
        printf("rb\n");
}
//-------------REVERSE ROTATE-------------

void rra(t_stack_node **stack_a,bool check_print)
{   
    if((*stack_a) == NULL ||(*stack_a)->next == NULL)
        return;
    t_stack_node *last;
    t_stack_node *second_last;

    second_last = *stack_a;
    while(second_last->next && second_last->next->next)
        second_last = second_last->next;

    last = second_last->next;

    second_last->next = NULL;
    last->next =*stack_a;
    *stack_a = last;
        if(check_print == true)
        printf("rra");

}
void rrb(t_stack_node **stack_b,bool check_print)
{   
    if((*stack_b) == NULL ||(*stack_b)->next == NULL)
        return;
    t_stack_node *last;
    t_stack_node *second_last;

    second_last = *stack_b;
    while(second_last->next && second_last->next->next)
        second_last = second_last->next;

    last = second_last->next;

    second_last->next = NULL;
    last->next =*stack_b;
    *stack_b = last;
    if(check_print == true)
        printf("rrb");
}

//-------------------BOTH AT THE SAME TIME (ra+rb=rr)(rra+rrb=rrr)(sa+sb=ss)--------------------

void rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
    bool print = false;

    ra(stack_a,print);
    rb(stack_b,print);
    printf("rr");
}
void rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
    bool check_print = false;

    rra(stack_a,check_print);
    rrb(stack_b,check_print);
    printf("rrr");
}

void ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
    bool check_print = false;

    sa(stack_a,check_print);
    sb(stack_b,check_print);
    printf("ss");
}