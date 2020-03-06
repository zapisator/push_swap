/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:51:45 by ftothmur          #+#    #+#             */
/*   Updated: 2019/10/07 18:14:37 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

# define SA_STR			"sa"
# define SB_STR			"sb"
# define SS_STR			"ss"
# define PA_STR			"pa"
# define PB_STR			"pb"
# define RA_STR			"ra"
# define RB_STR			"rb"
# define RR_STR			"rr"
# define RRA_STR		"rra"
# define RRB_STR		"rrb"
# define RRR_STR		"rrr"

# define CALC_NBR(x)	(*((int *)(x)->content))
# define OP_NBR(x)		(result->curr.x)
# define OP_BEST(x)		(result->best.x)

# define SA(x)			ops_counter((x), 0, &(x)->stack_a, NULL)
# define SB(x)			ops_counter((x), 1, NULL, &(x)->stack_b)
# define SS(x)			ops_counter((x), 2, &(x)->stack_a,  &(x)->stack_b)
# define PA(x)			ops_counter((x), 3, &(x)->stack_a,  &(x)->stack_b)
# define PB(x)			ops_counter((x), 4, &(x)->stack_b,  &(x)->stack_a)
# define RA(x)			ops_counter((x), 5, &(x)->stack_a,  NULL)
# define RB(x)			ops_counter((x), 6, NULL,  &(x)->stack_b)
# define RR(x)			ops_counter((x), 7, &(x)->stack_a,  &(x)->stack_b)
# define RRA(x)			ops_counter((x), 8, &(x)->stack_a,  NULL)
# define RRB(x)			ops_counter((x), 9, NULL,  &(x)->stack_b)
# define RRR(x)			ops_counter((x), 10, &(x)->stack_a,  &(x)->stack_b)

# define SLEEP_TIME		"0.1"

typedef void			(*t_ops)(t_dlist **, t_dlist **);

typedef struct			s_rs
{
	int					ra;
	int					rb;
	int					rra;
	int					rrb;
	int					summary;
}						t_rs;

typedef struct			s_calc
{
	int					nbrs_count;
	t_dlist				*stack_a;
	int					size_a;
	t_dlist				*stack_b;
	int					size_b;
	char				ops_i[BEST_SIZE];
	int					ops_size;
	int					max;
	int					min;
	t_rs				curr;
	int					isset_best;
	t_rs				best;
}						t_calc;

typedef struct			s_check
{
	int					isvisualized;
	int					*nbrs;
	int					counter_of_nbrs;
	char				**instructions;
	int					inst_size;
	t_dlist				*stack_a;
	t_dlist				*stack_b;
}						t_check;

/*
**								COMMON UTILITIES
*/
int						usage_ch(void);
int						usage_ps(void);
void					print_nbrs_ar(int *nbrs, int counter_of_nbrs);
void					print_instrutions(char **instructions);
void					print_stacks_content(void *content);
void					print_params(char ***params);

int						make_stacks(int **nbrs, int inst_size,
							t_dlist **stack_a, t_dlist **stack_b);
int						fill_nbrs(int argc, char **argv,
							int **nbrs, int *counter_of_nbrs);

t_ops					op_dispatcher(int op_i_biased);
int						get_instruction_index(char **instructions);

void					swap(t_dlist **stack_a, t_dlist **stack_b);
void					push(t_dlist **stack_dst, t_dlist **stack_src);
void					rotate(t_dlist **stack_a, t_dlist **stack_b);
void					r_rotate(t_dlist **stack_a, t_dlist **stack_b);
void					op_error(t_dlist **stack_a, t_dlist **stack_b);

/*
**									CHECKER
*/
void					free_params(char ***params, int size);
int						read_params(char ***params, char **argv, int argc);
int						check_params(char ***params);
int						fill_instructions(char ***instructions, int *inst_size);
t_ops					op_dispatcher(int op_i_biased);
void					visualize(t_check *ch);

/*
**									CALCULATOR
*/
void					make_best_estimation(t_calc *result);
void					ops_counter(t_calc *result, int ops_i,
							t_dlist **stack_a, t_dlist **stack_b);
void					calculate(t_calc *result);
void					common_push_except_three(t_calc *result);
void					write_ops(char ops_i[BEST_SIZE], int ops_size);

#endif
