/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xaviermonteiro <xaviermonteiro@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:24:27 by xaviermonte       #+#    #+#             */
/*   Updated: 2024/12/09 15:32:29 by xaviermonte      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	PUSH_SWAP_H
#define	PUSH_SWAP_H 


#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_medium;
	bool			cheapest;
	struct s_stack *target_node;
	struct s_stack	*next;
	struct s_stack *prev;
	
}	t_stack_node;

//-------------------ERROR_HANDLEING------------------------
void exit_error(t_stack_node **stack);
int syntax_error(char *str);
void free_stack( t_stack_node **stack);
int check_dup(t_stack_node *a, int nbr);

//------------------MOVEMENTS---------------------------
void ra(t_stack_node **stack_a, bool check_print);
void rb(t_stack_node **stack_b, bool check_print);
void rra(t_stack_node **stack_a,bool check_print);
void rrb(t_stack_node **stack_b,bool check_print);
void rr(t_stack_node **stack_a, t_stack_node **stack_b);
void rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void sa(t_stack_node **stack_a, bool check_print);
void sb(t_stack_node **stack_b, bool check_print);
void ss(t_stack_node **stack_a, t_stack_node **stack_b);
void pb(t_stack_node **stack_b,t_stack_node **stack_a, bool check_print);
void pa(t_stack_node **stack_a,t_stack_node **stack_b, bool check_print);
//------------------ALGORITMO----------------------------

void sort_three(t_stack_node **a);
bool stack_is_sorted(t_stack_node *stack);
void sort_stack(t_stack_node **a, t_stack_node **b);//----------IN FAULT-------
void place_mini_on_top(t_stack_node **a);

//------------------STACK CREATION-------------------------
void init_stack(char **av, t_stack_node **a);
void append_node(t_stack_node **stack, int n);
//t_stack_node *stack_new(int nbr);
t_stack_node *get_last_node(t_stack_node *stack);
//void stack_add_bottom(t_stack_node **stack, t_stack_node *new_node);

//-------------------EXTRAS---------------------------------
int ft_isdigit(char c);
int ft_atoi(char *nbr);
t_stack_node   *find_biggest_node(t_stack_node *stack);
t_stack_node *find_cheapest_node(t_stack_node *stack);
int stack_len(t_stack_node *stack);
char **split(char *str, char del);

//-------------------EXTRAS ALGORITMO------------------------
void set_cheapest(t_stack_node **stack);
void set_target_node_a(t_stack_node **a, t_stack_node **b);
void set_target_node_b(t_stack_node **a, t_stack_node **b);
void set_index(t_stack_node **stack);
void prepare_nodes_a(t_stack_node **a, t_stack_node **b);
void prepare_nodes_b(t_stack_node **a, t_stack_node **b);
void move_a_to_b(t_stack_node **a, t_stack_node **b);
void move_b_to_a(t_stack_node **a, t_stack_node **b);
void set_push_cost(t_stack_node **a, t_stack_node **b);
void prep_for_push(t_stack_node **stack, t_stack_node *top_node,char stack_type);

//-------------------EXTRAS MOVEMENTS-----------------------
void    rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
void rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);

#endif