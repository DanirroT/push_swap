/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:49:02 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/10/29 12:10:17 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
//	Takes a node as parameter and frees its content using the function ’del’.
//		Free the node itself but does NOT free the next node.

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
}
//	Deletes and frees the given node and all its successors,
//		using the function ’del’ and free(3). Finally,
//		set the pointer to the list to NULL.

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
//	Iterates through the list ’lst’ and applies the function ’f’ to the
//		content of each node.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*res_;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		res_ = ft_lstnew(f(lst->content));
		if (!res_)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, res_);
		lst = lst->next;
	}
	return (res);
}

//	Iterates through the list ’lst’, applies the function ’f’ to each node’s
//		content, and creates a new list resulting of the successive applications
//		of the function ’f’. The ’del’ function is used to delete the content
//		of a node if needed.

/*
#ifndef NO_MAIN

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	*f5(void *n)
{
	if (n == NULL)
		return (NULL);
	return (NULL);
}

void	f6(void *c)
{
	write(1, c, 1);
}

void * addOnemap(void * p)
{
	void * r = malloc(sizeof(int));
	*(int*)r = *(int*)p + 1;
	return (r);
}

void addOneiter(void * p)
{
	//++*(int*)p;
	*(int *)p += 1;
}

int main(void)
{
	int tab[] = {0, 1, 2, 3};
	
	t_list *l =  ft_lstnew(tab);
	
	for (int i = 1; i < 4; ++i)
		ft_lstadd_back(&l, ft_lstnew(tab + i));
	
	ft_lstiter(l, addOneiter);
	t_list *tmp = l;
	// 1 2 3 4 
	for (int i = 0; i < 4; ++i)
	{
		printf("%i: %i\n", i, *(int*)tmp->content);
		tmp = (t_list *)tmp->next;
	}
	return 0;
}


int	main(void)
{
	char str[] = "-1234567890abcdefghijklmnop";

	t_list	*lstM = ft_lstnew(&str[1]);

	t_list	*last = ft_lstlast(lstM);

	printf("lstlast: %c %p\n", last->content, (void *)last->next);

	ft_lstdelone(last, &delite);

	printf("lstdelone: %c %p\n", lstM->content, (void *)lstM->next);

	ft_lstclear(&lstM, &delite);

	printf("lstclear: %c %p\n", lstM->content, (void *)lstM->next);

	ft_lstiter(lstM, &f6);

	printf("lstiter: %c %p\n", lstM->content, (void *)lstM->next);

	t_list	*lstmap = ft_lstmap(lstM, &f5, &delite);

	printf("lstmap: %c %p\n", lstmap->content, (void *)lstmap->next);
}
	
void	delite(void *to_del)
{
	if (!to_del)
		return ;
	free(to_del);
}


t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->content = content;
	return (new);
}

//	Allocates memory (using malloc(3)) and returns a new node.
//		The ’content’ member variable is initialized with the
//		given parameter ’content’. The variable ’next’ is initialized to NULL.

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
//	Adds the node ’new’ at the beginning of the list.

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
//	Counts the number of nodes in the list.

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
//	Returns the last node of the list.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = ft_lstlast(*lst);
	if (!last)
		return ;
	last->next = new;
}
//	Adds the node ’new’ at the end of the list.

#endif
*/
