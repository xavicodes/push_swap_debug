/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:22:42 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/11/29 12:07:27 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


void exit_error(t_stack_node **stack)
{  
    free_stack(stack);
    printf("error");
}
void free_stack( t_stack_node **stack)
{
    t_stack_node *current;
    t_stack_node *temp;

    current = *stack;
    while(current)
    {
        temp = current->next;
        current->nbr = 0;
        free(current);
        current = temp;
    }
    *stack = NULL;
}
int syntax_error(char *str)
{
    if(!(*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
        return(1);
    
    if((*str == '-' || *str == '+') && !(str[1] >= '0' && str[1] <= '9'))
        return(1);
    while(*++str)
    {
        if(*str >= '0' && *str <= '9')
            return(1);
    }
    return(0);
}
int check_dup(t_stack_node *a, int nbr)
{
    if(!a)
        return(0);
    while(a)
    {
        if(a->nbr == nbr)
            return(1);
    a = a->next;
    }
    return(0);
}
