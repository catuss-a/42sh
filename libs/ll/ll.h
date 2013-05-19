/*
** ll.h for l in /home/serraj_y//c/corewar/asmx
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Mon Sep  6 15:23:04 2010 younes serraj
** Last update Wed Dec 15 18:57:37 2010 stephane delmas
*/

#ifndef LL_H_
# define LL_H_

typedef struct		s_ll_node
{
  void			*data;
  struct s_ll_node	*previous;
  struct s_ll_node	*next;
}			t_ll_node;

typedef struct		s_ll_list
{
  t_ll_node		*head;
  t_ll_node		*tail;
  char			is_job;
  int			count;
}			t_ll_list;

void			ll_init_list(t_ll_list *list);
t_ll_list		*ll_make_list();
t_ll_node		*ll_make_node(void *data);
void			ll_optimize_search_id(t_ll_list *list,
					      signed int *id);
t_ll_node		*ll_get_node(t_ll_list *list,
				     signed int id);
int			ll_push_node_head(t_ll_list *list,
					  t_ll_node *node);
int			ll_push_node_tail(t_ll_list *list,
					  t_ll_node *node);
int			ll_push_node(t_ll_list *list,
				     t_ll_node *node,
				     signed int id);
t_ll_node		*ll_push_data(t_ll_list *list,
				      void *data,
				      signed int id);
t_ll_node		*ll_pop_head(t_ll_list *list);
t_ll_node		*ll_pop_tail(t_ll_list *list);
t_ll_node		*ll_pop_node(t_ll_list *list,
				     signed int id);
void			*ll_pop_data(t_ll_list *list,
				     signed int id);
int			ll_delete_node(t_ll_list *list,
				       signed int id,
				       void (*f_del)(void *));
int			ll_delete_node_byaddr(t_ll_list *list, t_ll_node *addr,
					      void (*f_del)(void *));
int			ll_delete_node_by_data_addr(t_ll_list *list, void *data_addr,
						    void (*f_del)(void *));
int			ll_clear_list(t_ll_list *list,
				      void (*f_del)(void *));
int			ll_traverse_using_filter(t_ll_list *list,
						 void (*action)(void *),
						 int (*filter)(void *, void *),
						 void *param);
int			ll_traverse(t_ll_list *list,
				    void (*action)(void *));
int			ll_sort(t_ll_list *list,
				int (*f_cmp)(void *, void *));
t_ll_node		*ll_find_data(t_ll_list *list,
				      int (*f_cmp)(void *, void *),
				      void *cmp_data);
int			ll_get_node_id(t_ll_list *list,
				       t_ll_node *node);

#endif /* LL_H_ */
