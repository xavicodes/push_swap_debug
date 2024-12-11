/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:23:51 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/12/03 14:13:03 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* t_stack_node *stack_new(int number)
{
        t_stack_node *new_node;

        new_node = malloc(sizeof(t_stack_node));
        if(!new_node)
                return(NULL);
	new_node->nbr = number;
	new_node->index = 0;
	new_node->next = NULL;
        return(new_node);
} */
/* void stack_add_bottom(t_stack_node **stack, t_stack_node *new_node)
{
        t_stack_node *tail;
        t_stack_node *node;
        if(!new_node)
                return;
        if(!stack)
        {
                *stack = new_node;
        }
        else 
        tail = get_last_node(*stack);
        tail->next = new_node;
} */
void append_node(t_stack_node **stack, int n)
{
        t_stack_node *tail;
        t_stack_node *node;

        if(!stack)
                return;
        node = malloc(sizeof(t_stack_node));
        if(!node)
                return;
        node->next = NULL;
        node->nbr = n;
        node->index = 0;
        if(!(*stack))
        {
                *stack = node;
                node ->prev = NULL;
        }
        else
        {
                tail = get_last_node(*stack);
                tail->next = node;
                node->prev = tail;
        }
}
void init_stack(char **av, t_stack_node **a)
{

        int long number;
        int i;

        i = 1;
        while(av[i])
        {
                if(syntax_error(av[i]))
                        free_stack(a);
                number = atoi(av[i]);
                if(number > INT_MAX ||number < INT_MIN)
                        return;
                 if(check_dup(*a,(int)number))
                        exit_error(a); 
                append_node(a, number);
        i++;
        }
}