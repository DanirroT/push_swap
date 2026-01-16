/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_1_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:49:02 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/10/29 12:18:42 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
//	Counts the number of nodes in the list.

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
//	Returns the last node of the list.

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	if (!last)
		return ;
	last->next = new;
}
//	Adds the node ’new’ at the end of the list.
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


int main(void)
{
	t_list * l =  NULL;
	
	// 1
	printf("%i = %i\n", ft_lstlast(l), 0);
	ft_lstadd_back(&l, ft_lstnew((void*)1));
	
	// 2 
	printf("%i = %i\n", ft_lstlast(l)->content, 1);
	ft_lstadd_back(&l, ft_lstnew((void*)2));
	
	printf("%i = %i\n", ft_lstlast(l)->content, 2);
	printf("%i = %i\n", ft_lstlast(l)->next, 0);
}
	
int	main(void)
{
	char str[] = "-1234567890abcdefghijklmnop";

	t_list	lst0;

	lst0.content = &str[0];
	lst0.next = NULL;

	printf("struct: %s %p\n", lst0.content, (void *)lst0.next);

	t_list	*lstM = ft_lstnew(&str[1]);

	printf("lstnew: %c %p\n", lstM->content, (void *)lstM->next);

	t_list	lst2 = *ft_lstnew(&str[2]);

	ft_lstadd_front(&lstM, &lst2);

	printf("lstadd_front: %c %p\n", lstM->content, (void *)lstM->next);

	t_list	lst3 = *ft_lstnew(&str[3]);

	ft_lstadd_back(&lstM, &lst3);

	printf("lstadd_back: %c %p\n", ((lstM->next)->next)->content,
		(void *)((lstM->next)->next)->next);

	printf("lstadd_front: %c %p\n", ft_lstlast(lstM)->content, lst3.content);
		
	int		size = ft_lstsize(lstM);

	printf("lstsize: %i %c %p\n", size, lstM->content, (void *)lstM->next);

}
	
void	delite(void *to_del)
{
	if (!to_del)
		return ;
	free(to_del);
}
#endif
*/
