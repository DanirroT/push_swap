/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:57:16 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/27 12:32:39 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_out(t_stack *stack, int *input, int code)
{
	if (stack)
	{
		if (stack->a)
			free(stack->a);
		if (stack->b)
			free(stack->b);
	}
	if (input)
		free(input);
	if (code)
	{
		ft_putstr_fd("Error\n", 2);
		exit(code);
	}
	return (0);
}

int	*get_sort_order(int *to_sort, int len)
{
	int		j;
	int		k;
	int		temp;
	int		*sorted;

	sorted = ft_calloc(sizeof(int), len);
	ft_memcpy(sorted, to_sort, sizeof(int) * len);
	k = 0;
	while (k < len - 1)
	{
		j = k + 1;
		while (j < len)
		{
			if (sorted[k] > sorted[j])
			{
				temp = sorted[k];
				sorted[k] = sorted[j];
				sorted[j] = temp;
			}
			j++;
		}
		k++;
	}
	return (sorted);
}

void	print_int_mtx(char *msg, int *mtx, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%s %i: %i\n", msg, i + 1, mtx[i]);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

//	Algurithms
// simple_s_solve, simple_rr_solve, simple_r_solve,
// push_to_side, rotate_to_side, 

void	do_sorting(t_stack	stack, t_sizes stack_sizes, int *input)
{
	int	best_act;
	int	actions;
	int	i;
	int	alg_index;
	int	(*algorithms[])(t_stack, t_sizes, int) = {simple_s_solve,
		simple_rr_solve, simple_r_solve, push_to_side, rotate_to_side, NULL};

	if (stack_sizes.a == 1 || check_sort(input, stack_sizes.a, 1))
		return ;
	best_act = 0;
	actions = 0;
	i = 0;
	while (algorithms[i])
	{
		ft_memcpy(stack.a, input, sizeof(int) * stack_sizes.a);
		ft_bzero(stack.b, sizeof(int) * stack_sizes.a);
		ft_printf("\nAlgorithm %i\n", i);
		actions = (algorithms[i])(stack, stack_sizes, 0);
		if (actions > 0 && (best_act == 0 || actions < best_act))
		{
			alg_index = i;
			best_act = actions;
		}
		ft_printf("\tSorting End: %i\n", actions);
		i++;
		if (best_act == 1)
			break ;
	}
	ft_memcpy(stack.a, input, sizeof(int) * stack_sizes.a);
	ft_bzero(stack.b, sizeof(int) * stack_sizes.a);
	ft_printf("\n\nPrinting Algorithm: %i\n\n", alg_index);
	(algorithms[alg_index])(stack, stack_sizes, 1);
}
#ifdef NO_MAIN

int	main(int argc, const char *argv[])
{
	t_sizes		stack_sizes;
	t_stack		stack;
	int			*input;
	int			*sorted;
	int			i;

	if (argc <= 1)
		return (ft_out(NULL, NULL, -1));
	stack_sizes.a = argc - 1;
	stack_sizes.b = 0;
	input = ft_calloc(sizeof(int), stack_sizes.a);
	stack.a = ft_calloc(sizeof(int), stack_sizes.a);
	stack.b = ft_calloc(sizeof(int), stack_sizes.a);
	if (!stack.b || !stack.a || !input)
		ft_out(&stack, input, -1);
	i = 1;
	while (argv[i])
	{
		if (!ft_isatoi(argv[i]))
			ft_out(&stack, input, -1);
		input[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	print_int_mtx("Input", input, stack_sizes.a);
	sorted = get_sort_order(input, stack_sizes.a);
	print_int_mtx("Sorted", sorted, stack_sizes.a);
	free(sorted);
	do_sorting(stack, stack_sizes, input);
	ft_out(&stack, input, 0);
}
#endif

#ifndef NO_MAIN
# define NO_MAIN

int	main(void)
{
	t_sizes		stack_sizes;
	t_stack		stack;
	int			*input;
	int			*sorted;
	int			i;
	int			argc = 5;
	const char	*argv[] = {"./a.out", "3", "2", "1", "0", NULL};

	stack_sizes.a = argc - 1;
	stack_sizes.b = 0;
	input = ft_calloc(sizeof(int), stack_sizes.a);
	stack.a = ft_calloc(sizeof(int), stack_sizes.a);
	stack.b = ft_calloc(sizeof(int), stack_sizes.a);
	if (!stack.b || !stack.a || !input)
		ft_out(&stack, input, -1);
	i = 1;
	while (argv[i])
	{
		if (!ft_isatoi(argv[i]))
			ft_out(&stack, input, -1);
		input[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	print_int_mtx("Input", input, stack_sizes.a);
	sorted = get_sort_order(input, stack_sizes.a);
	print_int_mtx("Sorted", sorted, stack_sizes.a);
	do_sorting(stack, stack_sizes, input);
	ft_out(&stack, input, 0);
}

	//printf("pre swap\n");
	//print_int_mtx(" ", stack_a, stack_a_size);
	//actions += do_swap(stack_a);
	//printf("post swap\n");
	//print_int_mtx(" ", stack_a, stack_a_size);

	//printf("pre 3 pass\n");
	//print_int_mtx("b ", stack_b, stack_a_size);
	//print_int_mtx("a ", stack_a, stack_a_size);
	//actions += do_pass(stack_b, stack_a, &stack_b_size, &stack_a_size);
	//actions += do_pass(stack_b, stack_a, &stack_b_size, &stack_a_size);
	//actions += do_pass(stack_b, stack_a, &stack_b_size, &stack_a_size);
	//printf("post 3 pass\n");
	//print_int_mtx("b ", stack_b, stack_b_size);
	//print_int_mtx("a ", stack_a, stack_a_size);

	//printf("pre 1 rotate\n");
	//print_int_mtx("b ", stack_b, stack_b_size);
	//actions += do_rotate(stack_b, stack_b_size);
	//printf("post 1 rotate\n");
	//print_int_mtx("b ", stack_b, stack_b_size);

	//printf("pre rev rotate r\n");
	//print_int_mtx("a ", stack_a, stack_a_size);
	//print_int_mtx("b ", stack_b, stack_b_size);
	//actions += do_revrotate_r(stack_a, stack_b, stack_a_size, stack_b_size);
	//printf("post rev rotate r\n");
	//print_int_mtx("a ", stack_a, stack_a_size);
	//print_int_mtx("b ", stack_b, stack_b_size);

	//printf("total actions: %i", actions);

/*

malloc uses heap, not stack...?

s	- swap first 2 in the stack - a b s(both) 1 2 3

p	- pass first in the stack to the first of the other - a b 4 5

r	- rotate all stack back to front (up) - a b r(both) 6 7 8

rr	- rotate all stack front to back (down) - a b r(both) 9 10 11

*/



int	do_pass_a(t_stack stack, t_sizes *size, char print)
{
	int	i;

	i = size->b;
	while (i)
	{
		stack.b[i] = stack.b[i - 1];
		i--;
	}
	stack.b[0] = stack.a[0];
	while (i < size->a - 1)
	{
		stack.a[i] = stack.a[i + 1];
		i++;
	}
	stack.a[size->a - 1] = 0;
	size->b++;
	size->a--;
	if (print)
		ft_putstr_fd("pb\n", 1);
	return (1);
}

int	do_pass_b(t_stack stack, t_sizes *size, char print)
{
	int	i;

	i = size->a;
	while (i)
	{
		stack.a[i] = stack.a[i - 1];
		i--;
	}
	stack.a[0] = stack.b[0];
	while (i < size->b - 1)
	{
		stack.b[i] = stack.b[i + 1];
		i++;
	}
	stack.b[size->b - 1] = 0;
	size->a++;
	size->b--;
	if (print)
		ft_putstr_fd("pa\n", 1);
	return (1);
}

int	do_swap(int *stack, char print)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	if (print)
		ft_printf("s%c\n", print);
	return (1);
}

int	do_rotate(int *stack, int stack_size, char print)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack[0];
	while (i < stack_size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[stack_size - 1] = temp;
	if (print)
		ft_printf("r%c\n", print);
	return (1);
}

int	do_revrotate(int *stack, int stack_size, char print)
{
	int	temp;
	int	i;

	temp = stack[stack_size - 1];
	i = stack_size;
	while (i)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
	if (print)
		ft_printf("rr%c\n", print);
	return (1);
}

int	do_swap_s(t_stack stack, char print)
{
	do_swap(stack.a, 0);
	do_swap(stack.b, 0);
	if (print)
		ft_putstr_fd("ss\n", 1);
	return (1);
}

int	do_rotate_r(t_stack stack, t_sizes sizes, char print)
{
	do_rotate(stack.a, sizes.a, 0);
	do_rotate(stack.b, sizes.b, 0);
	if (print)
		ft_putstr_fd("rr\n", 1);
	return (1);
}

int	do_revrotate_r(t_stack stack, t_sizes sizes, char print)
{
	do_revrotate(stack.a, sizes.a, 0);
	do_revrotate(stack.b, sizes.b, 0);
	if (print)
		ft_putstr_fd("rrr\n", 1);
	return (1);
}

size_t	check_percent(va_list *in, char c)
{
	size_t	len;

	len = 0;
	if (c == '%')
		len = ft_putchar_fd('%', 1);
	else if (c == 'd' || c == 'i')
		len = ft_putnbr_fd(va_arg(*in, int), 1);
	else if (c == 'u')
		len = ft_putunsi_fd(va_arg(*in, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		len = ft_putnbr_hex_fd(va_arg(*in, unsigned int), 1, c);
	else if (c == 'p')
		len = ft_putptr_hex_fd((size_t)va_arg(*in, void *), 1, c);
	else if (c == 'c')
		len = ft_putchar_fd(va_arg(*in, int), 1);
	else if (c == 's')
		len = ft_putstr_null_fd(va_arg(*in, char *), 1);
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	ssize_t	ret;
	va_list	in;

	if (!format)
		return (-1);
	va_start(in, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			ret = check_percent(&in, format[++i]);
			if (ret == -1)
				return (-1);
			len += ret;
		}
		else
			len += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(in);
	return (len);
}

size_t	ft_putnbr_hex_fd(unsigned int n, int fd, char cap)
{
	int		c;
	char	*hex;
	size_t	prev;

	if (!(cap == 'x' || cap == 'X'))
		return (0);
	prev = 0;
	if (n / 16)
		prev += ft_putnbr_hex_fd(n / 16, fd, cap);
	c = (n % 16);
	if (cap == 'X')
		hex = ft_strdup("0123456789ABCDEF");
	if (cap == 'x')
		hex = ft_strdup("0123456789abcdef");
	c = hex[c];
	free(hex);
	return (write(fd, &c, 1) + prev);
}

size_t	ft_putptr_hex_fd(size_t n, int fd, char cap)
{
	int		c;
	char	*hex;
	size_t	prev;

	if (cap != 'p' && cap != 'x')
		return (0);
	if (!n)
		return (ft_putstr_fd("(nil)", fd));
	prev = 0;
	if (cap == 'p')
	{
		prev += ft_putstr_fd("0x", fd);
		cap = 'x';
	}
	if (n / 16)
		prev += ft_putptr_hex_fd(n / 16, fd, cap);
	c = (int)(n % 16);
	hex = ft_strdup("0123456789abcdef");
	c = hex[c];
	free(hex);
	return (write(fd, &c, 1) + prev);
}

size_t	ft_putunsi_fd(unsigned int n, int fd)
{
	size_t	i;
	int		c;
	size_t	prev;

	i = n;
	prev = 0;
	if (i / 10)
		prev += ft_putunsi_fd(i / 10, fd);
	c = (i % 10) + '0';
	return (write(fd, &c, 1) + prev);
}

size_t	ft_putstr_null_fd(void *s, int fd)
{
	int		i;
	char	*str;

	if (!s)
		return (ft_putstr_null_fd("(null)", fd));
	i = 0;
	str = (char *)s;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putstr_fd(void *s, int fd)
{
	int		i;
	char	*str;

	if (!s)
		return (-1);
	i = 0;
	str = (char *)s;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

size_t	ft_putnbr_fd(int n, int fd)
{
	long int	i;
	int			c;
	size_t		prev;

	i = n;
	prev = 0;
	if (i < 0)
	{
		i = i * -1;
		prev = write(1, "-", 1);
	}
	if (i / 10)
	{
		prev += ft_putnbr_fd(i / 10, fd);
	}
	c = (i % 10) + '0';
	return (write(fd, &c, 1) + prev);
}

size_t	ft_strlen(const char *s)
{
	size_t	res;

	if (!s)
		return (0);
	res = 0;
	while (s[res])
		res++;
	return (res);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	if (!s)
		return (NULL);
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	size_t			i;
	size_t			len;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	len = ((nmemb) * (size));
	res = malloc(sizeof(unsigned char) * len);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*d1;

	if (!n || !dest)
		return (NULL);
	if (!src)
		return (dest);
	s1 = (unsigned char *)src;
	d1 = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d1[i] = s1[i];
		i++;
	}
	return (d1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	if (!s || !n)
		return ;
	i = 0;
	s1 = (unsigned char *)s;
	while (i < n)
	{
		s1[i] = 0;
		i++;
	}
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	num;

	if (!nptr)
		return (0);
	i = 0;
	num = 0;
	neg = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (neg * num);
}

int	ft_isatoi(const char *str)
{
	int				i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!(str[i] == '+' || str[i] == '-' || str[i] >= ' '
				|| (str[i] >= 9 && str[i] <= 13)
				|| (str[i] >= '0' && str[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

int	check_sort(int *stack, int size, int order)
{
	int	i;

	i = 0;
	while (i < size -1)
	{
		if (stack[i] > stack[i + 1] && order == 1)
			return (0);
		if (stack[i] < stack[i + 1] && order == -1)
			return (0);
		i++;
	}
	return (1);
}

int	src_super(int *stack, int size, int superlative)
{
	int	i;
	int	loc;

	loc = 0;
	i = 0;
	while (i < size)
	{
		if (stack[loc] < stack[i] && superlative == 1)
			loc = i;
		if (stack[loc] > stack[i] && superlative == -1)
			loc = i;
		i++;
	}
	return (loc);
}

int	simple_s_solve(t_stack stack, t_sizes sizes, int print)
{
	printf("Simple s\n");
	do_swap(stack.a, print * 'a');
	if (check_sort(stack.a, sizes.a, 1))
		return (1);
	return (-1);
}

int	simple_rr_solve(t_stack stack, t_sizes sizes, int print)
{
	int	actions;

	printf("Simple rr\n");
	actions = 0;
	actions += do_revrotate(stack.a, sizes.a, print * 'a');
	while (!check_sort(stack.a, sizes.a, 1) && actions <= sizes.a / 2)
		actions += do_revrotate(stack.a, sizes.a, print * 'a');
	if (check_sort(stack.a, sizes.a, 1))
		return (actions);
	return (-1);
}

int	simple_r_solve(t_stack stack, t_sizes sizes, int print)
{
	int	actions;

	printf("Simple r\n");
	actions = 0;
	actions += do_rotate(stack.a, sizes.a, print * 'a');
	while (!check_sort(stack.a, sizes.a, 1) && actions <= sizes.a / 2)
		actions += do_rotate(stack.a, sizes.a, print * 'a');
	if (check_sort(stack.a, sizes.a, 1))
		return (actions);
	return (-1);
}

int	do_r_to_small(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;
	int	low_loc;

	actions = 0;
	low_loc = src_super(stack.a, sizes->a, -1);
	printf("\t rotating a %d / %d\n", low_loc, sizes->a);
	while (low_loc)
	{
		if (low_loc % sizes->a / 2)
		{
			actions += do_revrotate(stack.a, sizes->a, print * 'a');
			low_loc++;
			if (low_loc == sizes->a)
				low_loc = 0;
		}
		else
		{
			actions += do_rotate(stack.a, sizes->a, print * 'a');
			low_loc--;
		}
	}
	return (actions);
}

int	do_rp_small(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	printf("\t a to b\n");
	actions = 0;
	actions += do_r_to_small(stack, sizes, print);
	printf("\t\tpree loop\n");
	print_int_mtx("\t\tpost_loop", stack.a, sizes->a);
	while (!check_sort(stack.a, sizes->a, 1))
	{
		actions += do_pass_a(stack, sizes, print);
		if (check_sort(stack.a, sizes->a, 1))
			break ;
		actions += do_r_to_small(stack, sizes, print);
		print_int_mtx("\t\tpost_loop", stack.a, sizes->a);
	}
	return (actions);
}

int	do_empty_b(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	printf("\t Empty b\n");
	actions = 0;
	while (sizes->b > 0)
		actions += do_pass_b(stack, sizes, print);
	return (actions);
}

int	rotate_to_side(t_stack stack, t_sizes stack_sizes, int print)
{
	int	actions;
	int	i = 0;

	printf("Rotate to Side\n");
	actions = 0;
	while (!check_sort(stack.a, stack_sizes.a, 1) && i++ < 10)
	{
		printf("Iteration %d\n", i);
		printf("Attempt sort\n");
		actions += do_rp_small(stack, &stack_sizes, print);
		print_int_mtx("\tpost_a.a", stack.a, stack_sizes.a);
		print_int_mtx("\tpost_a.b", stack.b, stack_sizes.b);
		actions += do_empty_b(stack, &stack_sizes, print);
		print_int_mtx("\tpost_b.a", stack.a, stack_sizes.a);
		print_int_mtx("\tpost_b.b", stack.b, stack_sizes.b);
	}
	return (actions);
}

int	do_p_small(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	printf("\t a to b\n");
	actions = 0;
	if (sizes->a > 1 && stack.a[0] > stack.a[1])
		actions += do_swap(stack.a, print * 'a');
	while (!check_sort(stack.a, sizes->a, 1))
	{
		actions += do_pass_a(stack, sizes, print);
		if (check_sort(stack.a, sizes->a, 1))
			break ;
		if ((sizes->b > 1 && stack.b[0] > stack.b[1])
			&& (sizes->a > 1 && stack.a[0] > stack.a[1]))
			actions += do_swap_s(stack, print);
		else
		{
			if (sizes->b > 1 && stack.b[0] > stack.b[1])
				actions += do_swap(stack.b, print * 'b');
			if (sizes->a > 1 && stack.a[0] > stack.a[1])
				actions += do_swap(stack.a, print * 'a');
		}
		print_int_mtx("\t\tpost_loop", stack.a, sizes->a);
	}
	return (actions);
}

int	do_p_big(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;
	int	i = 0;

	printf("\t b to a\n");
	actions = 0;
	if (sizes->b > 1 && stack.b[0] < stack.b[1])
		actions += do_swap(stack.b, print * 'b');
	while (sizes->b > 0 && i++ < 10)
	{
		printf("Iteration %d\n", i);
		actions += do_pass_b(stack, sizes, print);
		if ((sizes->b > 1 && stack.b[0] > stack.b[1])
			&& (sizes->a > 1 && stack.a[0] > stack.a[1]))
			actions += do_swap_s(stack, print);
		else
		{
			if (sizes->b > 1 && stack.b[0] > stack.b[1])
				actions += do_swap(stack.b, print * 'b');
			if (sizes->a > 1 && stack.a[0] > stack.a[1])
				actions += do_swap(stack.a, print * 'a');
		}
	}
	return (actions);
}

int	push_to_side(t_stack stack, t_sizes stack_sizes, int print)
{
	int	actions;

	printf("Push to Side\n");
	actions = 0;
	while (!check_sort(stack.a, stack_sizes.a, 1))
	{
		printf("Attempt sort\n");
		actions += do_p_small(stack, &stack_sizes, print);
		print_int_mtx("\tpost_a.a", stack.a, stack_sizes.a);
		print_int_mtx("\tpost_a.b", stack.b, stack_sizes.b);
		actions += do_p_big(stack, &stack_sizes, print);
		print_int_mtx("\tpost_b.a", stack.a, stack_sizes.a);
		print_int_mtx("\tpost_b.b", stack.b, stack_sizes.b);
	}
	return (actions);
}

#endif
