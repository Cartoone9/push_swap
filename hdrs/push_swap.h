/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ******* <*******@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:52:54 by *******           #+#    #+#             */
/*   Updated: 2025/01/20 16:09:55 by *******          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_ERROR 9999999999

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_counter
{
	size_t			i;
	size_t			j;
	size_t			k;
}					t_counter;

typedef struct s_array
{
	int				*orig;
	int				*more;
	int				*less;
}					t_array;

typedef struct s_cursor
{
	struct s_list	*src_top;
	struct s_list	*dst_top;
	struct s_list	*src_bot;
	struct s_list	*dst_bot;
	struct s_list	*min_travel;
}					t_cursor;

typedef struct s_price
{
	size_t			dwn;
	size_t			up;
}					t_price;

typedef struct s_travel
{
	size_t			top_half;
	size_t			bot_half;
}					t_travel;

typedef struct s_shortsizet
{
	size_t			al_one;
	size_t			i;
}					t_shsizet;

typedef struct s_shortlist
{
	struct s_list	*tmp;
	struct s_list	*ret;
}					t_shlist;

typedef struct s_list
{
	int				value;
	size_t			rr;
	size_t			rrr;
	size_t			cost;
	size_t			go_up;
	size_t			go_down;
	size_t			top_half;
	size_t			bot_half;
	size_t			last_el;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

long long			ft_quickselect(t_list *list);
t_list				*ft_lstnew_int(int value);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstbeforelast(t_list *lst);
t_list				*ft_convlist_ncheck(char **numbers);
t_list				*ft_find_cost(t_list *lst_src, t_list *lst_dest, int pivot);
size_t				ft_strlcpy(char *dest, const char *src, size_t n);
size_t				ft_is_sorted(t_list *list);
size_t				ft_strlen(const char *str);
size_t				ft_find_way(t_list *hdr);
size_t				ft_handle_more(t_array *ar, t_counter *cnt);
size_t				ft_handle_less(t_array *ar, t_counter *cnt);
size_t				ft_numbers_size(char **numbers);
char				*ft_strjoin_sp(char const *s1, char const *s2);
char				**ft_split(char const *s, char c);
char				**ft_split_ncheck(char **av);
void				ft_lstadd_back(t_list **lst, t_list *new_elem,
						size_t last_one);
void				ft_sort_min(t_list **lst_src, t_list **lst_dst,
						t_list *min_travel);
void				ft_sort_min_suite(t_list **lst_src, t_list **lst_dst);
void				push_swap(int *stackA, int *stackB);
void				swap(t_list **hdr, char c);
void				push(t_list **hdr_src, t_list **hdr_dest, char c);
void				push_suite(t_list **hdr_dest, t_list *temp);
void				rotate(t_list **hdr, char c);
void				double_rotate(t_list **hdr_A, t_list **hdr_B);
void				reverse_rotate(t_list **hdr, char c);
void				double_reverse_rotate(t_list **hdr_A, t_list **hdr_B);
void				swap_ch(t_list **hdr);
void				push_ch(t_list **hdr_src, t_list **hdr_dest);
void				rotate_ch(t_list **hdr);
void				reverse_rotate_ch(t_list **hdr);
void				push_ch_suite(t_list **hdr_dest, t_list *temp);
void				ft_free_str(char *str);
void				ft_free_list(t_list *list, size_t num);
void				ft_free_strr(char **strr);
void				ft_free_array(t_array *ar);
void				ft_lsd_radix(t_list **list_a);
void				ft_swap_values(int *value);
void				ft_init_cnt(int *cnt);
void				ft_cpyar_nreinit(t_array *ar, size_t len, size_t which);
void				ft_reinit_array(int *ar_member, size_t len);
void				ft_swap_values(int *value);
void				ft_reinit_array(int *ar_member, size_t len);
void				ft_cpyar_nreinit(t_array *ar, size_t len, size_t which);
void				ft_init_counter(t_counter *cnt);
void				ft_fewval(t_list **list, size_t mem, char c);
void				ft_fewval_suite(t_list **list, char c);
void				ft_fiveval(t_list **list);
void				ft_test_printf(t_list *list);
void				ft_reinit_list(t_list *list);
void				ft_order_list(t_list **list);
void				ft_init_shlist(t_shlist *list);
void				ft_endstep(t_travel *travel, t_cursor *csr, int which);
void				ft_partition_array(t_array *ar, size_t array_len, int pivot,
						t_counter *cnt);
void				ft_split_list(t_list **list_a, t_list **list_b,
						long long pivot);
void				ft_merge_lists(t_list **list_b, t_list **list_a,
						long long pivot);
void				ft_update_moves_top(t_cursor *csr, t_price *price,
						t_travel *travel);
void				ft_update_moves_bot(t_cursor *csr, t_price *price,
						t_travel *travel);
void				ft_top_part(t_cursor *csr, t_price *price, t_travel *travel,
						t_list *lst_dest);
void				ft_bot_part(t_cursor *csr, t_price *price, t_travel *travel,
						t_list *lst_dest);
void				ft_add_weight_cost(t_cursor *csr, size_t src_size,
						int pivot, int which);
void				ft_init_all(size_t *src_size, t_travel *travel,
						t_cursor *csr, t_list *lst_src);
void				ft_init_price_csr_top(t_price *price, t_cursor *csr,
						t_list *lst_dest);
void				ft_init_price_csr_bot(t_price *price, t_cursor *csr,
						t_list *lst_dest);
void				ft_check_min_travel_bot(t_cursor *csr);
void				ft_check_min_travel_top(t_cursor *csr);
void				ft_update_cost_top(t_cursor *csr, t_price *price,
						t_travel *travel);
void				ft_update_cost_bot(t_cursor *csr, t_price *price,
						t_travel *travel);
void				ft_checker(t_list *list_a, t_list *list_b);
int					ft_lstsize(t_list *lst);
int					ft_check_numbers(char **numbers);
int					ft_check_doubles(t_list *list);
int					ft_atoi_sp(const char *str, size_t *at_least_one);
int					ft_median_ofthr(int *ar_member, size_t ar_len);
int					ft_init_array(t_array *ar, size_t len);
int					ft_median_ofthr(int *ar_member, size_t ar_len);
int					ft_init_array(t_array *ar, size_t len);
int					ft_quicksort(t_list **list_a);
int					ft_quickselect_suite(t_array *ar, size_t array_len);
int					ft_find_smallest_two(t_array *ar);
int					ft_calc_down_pr(t_list *src, t_list *dst);
int					ft_calc_up_pr(t_list *src, t_list *dst);
int					ft_is_min(t_cursor *csr, t_travel *travel, int which);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_gnl_loop(t_list **list_a, t_list **list_b);
int					ft_comp(char *str, t_list **list_a, t_list **list_b);
int					ft_comp_suite(char *str, t_list **list_a, t_list **list_b);

#endif
