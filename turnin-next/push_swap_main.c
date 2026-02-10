/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:57:16 by dmota-ri          #+#    #+#             */
/*   Updated: 2026/01/24 19:10:36 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_out(t_stack *stack, int *input, char **handle_temp, int code)
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
	if (handle_temp)
		trash_2d_char(handle_temp);
	if (code)
	{
		ft_putstr_fd("Error\n", 2);
		exit(code);
	}
	return (0);
}

//	Algurithms
// simple_s_solve, simple_rotate_solve, push_to_side, push_to_side_empty,
//	rotate_to_side, radix_sort, chunking_sort, 

void	*assign_algs(void)
{
	int	(**algorithms)(t_stack, t_sizes, int);

	algorithms = malloc(sizeof(int (*)(t_stack, t_sizes, int)) * 9);
	algorithms[0] = simple_s_solve;
	algorithms[1] = simple_rotate_solve;
	algorithms[2] = solve_for_three;
	algorithms[3] = push_to_side;
	algorithms[4] = push_to_side_empty;
	algorithms[5] = rotate_to_side;
	algorithms[6] = radix_sort;
	algorithms[7] = chunking_sort;
	algorithms[8] = NULL;
	return (algorithms);
}

//		ft_printf("alg %i - act %i\n", i, actions);

void	do_sorting(t_stack	stack, t_sizes stack_sizes, int *input,
		int (**algorithms)(t_stack, t_sizes, int))
{
	int	best_act;
	int	actions;
	int	i;
	int	alg_index;

	best_act = 0;
	i = 0;
	while (algorithms[i])
	{
		ft_memcpy(stack.a, input, sizeof(int) * stack_sizes.a);
		ft_bzero(stack.b, sizeof(int) * stack_sizes.a);
		actions = (algorithms[i])(stack, stack_sizes, 0);
		if (actions > 0 && (best_act == 0 || actions < best_act))
		{
			alg_index = i;
			best_act = actions;
		}
		i++;
		if (best_act == 1 || best_act == 2)
			break ;
	}
	ft_memcpy(stack.a, input, sizeof(int) * stack_sizes.a);
	ft_bzero(stack.b, sizeof(int) * stack_sizes.a);
	(algorithms[alg_index])(stack, stack_sizes, 1);
	free(algorithms);
}

//#ifdef NO_MAIN

int	*handle_args(char *args[], int size)
{
	t_mult_ind	ind;
	int			*input;
	char		**temp;

	input = malloc(size * sizeof(int));
	if (!input || args[1][0] == '\0')
		return (free(input), NULL);
	ind.i = 0;
	ind.k = 0;
	while (args[++ind.i])
	{
		ind.j = -1;
		temp = ft_split_space(args[ind.i]);
		if (!temp)
			return (free(input), NULL);
		while (temp[++ind.j])
			input[ind.k++] = check_do_atoi(temp, ind.j, input);
		trash_2d_char(temp);
	}
	return (input);
}

int	main(int argc, char *argv[])
{
	t_sizes		stack_sizes;
	t_stack		stack;
	int			*input;

	if (argc < 1)
		return (ft_out(NULL, NULL, NULL, -2));
	else if (argc == 1)
		return (ft_out(NULL, NULL, NULL, 0));
	stack_sizes.a = ft_num_count(&argv[1]);
	input = handle_args(argv, stack_sizes.a);
	stack.a = malloc(sizeof(int) * stack_sizes.a);
	stack.b = malloc(sizeof(int) * stack_sizes.a);
	if (!stack.b || !stack.a || !input || check_dups(input, stack_sizes.a))
		return (ft_out(&stack, input, NULL, -1));
	if (stack_sizes.a <= 1 || check_sort(input, stack_sizes.a, 1))
		return (ft_out(&stack, input, NULL, 0));
	stack_sizes.b = 0;
	do_sorting(stack, stack_sizes, input, assign_algs());
	return (ft_out(&stack, input, NULL, 0));
}

//s		- swap first 2 in the stack - a b s(both) 1 2 3

//p		- pass first in the stack to the first of the other - a b 4 5

//r		- rotate all stack back to front (up) - a b r(both) 6 7 8

//rr	- rotate all stack front to back (down) - a b r(both) 9 10 11

//#else

/*
int	main(void)
{
	t_sizes		stack_sizes;
	t_stack		stack;
	int			*input;
	int			*sorted;
	int			i;
	int			argc = 6;
	const char	*argv[] = {"./a.out", "4", "67", "3", "87", "5", NULL};

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
		input[i - 1] = check_do_atoi(argv[i], &stack, input);
		i++;
	}
	print_int_mtx("Input", input, stack_sizes.a);
	sorted = get_sort_order(input, stack_sizes.a);
	print_int_mtx("Sorted", sorted, stack_sizes.a);
	free(sorted);
	if (check_dups(input, stack_sizes.a))
		ft_out(&stack, input, -1);
	if (stack_sizes.a == 1 || check_sort(input, stack_sizes.a, 1))
		ft_out(&stack, input, 0);
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



//malloc uses heap, not stack...?



int	do_pass_a(t_stack stack, t_sizes *size, char print)
{
	int	i;

	if (size->a == 0)
		return (0);
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

	if (size->b == 0)
		return (0);
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

int	do_swap(int *stack, int size, char print)
{
	int	temp;

	if (size < 2)
		return (0);
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

	if (stack_size <= 1)
		return (0);
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

	if (stack_size <= 1)
		return (0);
	temp = stack[stack_size - 1];
	i = stack_size - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = temp;
	if (print)
		ft_printf("rr%c\n", print);
	return (1);
}

int	do_swap_s(t_stack stack, t_sizes sizes, char print)
{
	do_swap(stack.a, sizes.a, 0);
	do_swap(stack.a, sizes.a, 0);
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

int	check_do_atoi(const char *nptr, t_stack *stack, int *input)
{
	int			neg;
	long long	num;

	num = 0;
	neg = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	if (*nptr == '\0')
		ft_out(stack, input, -1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		if ((num * 10 + (*nptr - '0')) * neg > INT_MAX
			|| (num * 10 + (*nptr - '0')) * neg < INT_MIN)
			ft_out(stack, input, -1);
		num = num * 10 + (*nptr - '0');
		nptr++;
	}
	if (*nptr != '\0')
		ft_out(stack, input, -1);
	return (neg * num);
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

int	check_dups(int *stack, int len)
{
	int		j;
	int		k;

	k = 0;
	while (k < len - 1)
	{
		j = k + 1;
		while (j < len)
		{
			if (stack[k] == stack[j])
				return (1);
			j++;
		}
		k++;
	}
	return (0);
}

int	simple_s_solve(t_stack stack, t_sizes sizes, int print)
{
	do_swap(stack.a, sizes.a, print * 'a');
	if (check_sort(stack.a, sizes.a, 1))
		return (1);
	return (-1);
}

int	do_r_to_super(int *stack, int size, int super, char print)
{
	int	actions;
	int	low_loc;

	actions = 0;
	low_loc = src_super(stack, size, super);
	fprintf(stderr, "\t rotating b %d / %d = %d\n",
		low_loc, size, low_loc > (size / 2));
	while (low_loc)
	{
		if (low_loc > (size / 2))
		{
			actions += do_revrotate(stack, size, print);
			low_loc++;
			if (low_loc == size)
				low_loc = 0;
		}
		else
		{
			actions += do_rotate(stack, size, print);
			low_loc--;
		}
		fprintf(stderr, "\t rotating b %d / %d = %d\n",
			low_loc, size, low_loc > (size / 2));
	}
	return (actions);
}

// 	if (low_loc == 1)
//		return (do_swap(stack, size, print));

int	simple_rotate_solve(t_stack stack, t_sizes sizes, int print)
{
	int	actions;

	actions = 0;
	actions += do_r_to_super(stack.a, sizes.a, -1, print * 'a');
	if (check_sort(stack.a, sizes.a, 1))
		return (actions);
	return (-1);
}

int	do_rp_small(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	fprintf(stderr, "\t a to b\n");
	actions = 0;
	actions += do_r_to_super(stack.a, sizes->a, -1, print * 'a');
	fprintf(stderr, "\t\tpree loop\n");
	print_int_mtx("\t\tpost_loop", stack.a, sizes->a);
	while (!check_sort(stack.a, sizes->a, 1))
	{
		actions += do_pass_a(stack, sizes, print);
		if (check_sort(stack.a, sizes->a, 1))
			break ;
		actions += do_r_to_super(stack.a, sizes->a, -1, print * 'a');
		print_int_mtx("\t\tpost_loop", stack.a, sizes->a);
	}
	return (actions);
}

int	do_empty_b(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	fprintf(stderr, "\t Empty b\n");
	actions = 0;
	while (sizes->b > 0)
		actions += do_pass_b(stack, sizes, print);
	return (actions);
}

int	rotate_to_side(t_stack stack, t_sizes stack_sizes, int print)
{
	int	actions;

	fprintf(stderr, "Rotate to Side\n");
	actions = 0;
	while (!check_sort(stack.a, stack_sizes.a, 1))
	{
		fprintf(stderr, "Attempt sort\n");
		actions += do_rp_small(stack, &stack_sizes, print);
		print_stacks("post a", stack, stack_sizes);
		actions += do_empty_b(stack, &stack_sizes, print);
		print_stacks("post b", stack, stack_sizes);
	}
	return (actions);
}

int	do_p_small(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	fprintf(stderr, "\t a %i to b %i\n", sizes->a, sizes->b);
	actions = 0;
	while (!check_sort(stack.a, sizes->a, 1))
	{
		actions += do_pass_a(stack, sizes, print);
		if ((sizes->b > 1 && stack.b[0] < stack.b[1])
			&& (sizes->a > 1 && stack.a[0] > stack.a[1]))
			actions += do_swap_s(stack, *sizes, print);
		else
		{
			if (sizes->b > 1 && stack.b[0] < stack.b[1])
				actions += do_swap(stack.b, sizes->b, print * 'b');
			if (sizes->a > 1 && stack.a[0] > stack.a[1])
				actions += do_swap(stack.a, sizes->a, print * 'a');
		}
		fprintf(stderr, "\t\t a %i b %i\n", stack.a[0], stack.b[0]);
	}
	fprintf(stderr, "\n");
	return (actions);
}

int	do_p_big(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	fprintf(stderr, "\t b %i to a %i\n", sizes->b, sizes->a);
	actions = 0;
	while (!check_sort(stack.b, sizes->b, -1))
	{
		actions += do_pass_b(stack, sizes, print);
		if ((sizes->b > 1 && stack.b[0] < stack.b[1])
			&& (sizes->a > 1 && stack.a[0] > stack.a[1]))
			actions += do_swap_s(stack, *sizes, print);
		else
		{
			if (sizes->b > 1 && stack.b[0] < stack.b[1])
				actions += do_swap(stack.b, sizes->b, print * 'b');
			if (sizes->a > 1 && stack.a[0] > stack.a[1])
				actions += do_swap(stack.a, sizes->a, print * 'a');
		}
		fprintf(stderr, "\t\t a %i b %i\n", stack.a[0], stack.b[0]);
	}
	fprintf(stderr, "\n");
	return (actions);
}

int	push_to_side(t_stack stack, t_sizes stack_sizes, int print)
{
	int	actions;

	actions = 0;
	print = 1;
	actions += do_p_small(stack, &stack_sizes, print);
	print_stacks("post a", stack, stack_sizes);

	while (!check_sort(stack.b, stack_sizes.b, -1))
	{
		actions += do_p_big(stack, &stack_sizes, print);
		print_stacks("post b", stack, stack_sizes);
		actions += do_p_small(stack, &stack_sizes, print);
		print_stacks("post a", stack, stack_sizes);
	}
	if (stack.a[0] > stack.b[0])
		actions += do_empty_b(stack, &stack_sizes, print);
	else
	{
		// help here!
	}
	return (actions);
}

int	do_p_small_empty(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	if (sizes->a > 1 && stack.a[0] > stack.a[1])
		actions += do_swap(stack.a, sizes->a, print * 'a');
	while (sizes->a > 1)
	{
		actions += do_pass_a(stack, sizes, print);
		if ((sizes->b > 1 && stack.b[0] < stack.b[1])
			&& (sizes->a > 1 && stack.a[0] > stack.a[1]))
			actions += do_swap_s(stack, *sizes, print);
		else
		{
			if (sizes->b > 1 && stack.b[0] < stack.b[1])
				actions += do_swap(stack.b, sizes->b, print * 'b');
			if (sizes->a > 1 && stack.a[0] > stack.a[1])
				actions += do_swap(stack.a, sizes->a, print * 'a');
		}
		print_int_mtx("\t\tpost_loop", stack.a, sizes->a);
	}
	return (actions);
}

int	do_p_big_empty(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	actions = 0;
	while (sizes->b > 0)
	{
		actions += do_pass_b(stack, sizes, print);
		if ((sizes->b > 1 && stack.b[0] < stack.b[1])
			&& (sizes->a > 1 && stack.a[0] > stack.a[1]))
			actions += do_swap_s(stack, *sizes, print);
		else
		{
			if (sizes->b > 1 && stack.b[0] < stack.b[1])
				actions += do_swap(stack.b, sizes->b, print * 'b');
			if (sizes->a > 1 && stack.a[0] > stack.a[1])
				actions += do_swap(stack.a, sizes->a, print * 'a');
		}
	}
	return (actions);
}

int	push_to_side_empty(t_stack stack, t_sizes stack_sizes, int print)
{
	int	actions;

	fprintf(stderr, "Push to Side Stop\n\n");
	actions = 0;
	while (!check_sort(stack.a, stack_sizes.a, 1))
	{
		fprintf(stderr, "Attempt sort\n");
		actions += do_p_small_empty(stack, &stack_sizes, print);
		print_stacks("post a", stack, stack_sizes);
		actions += do_p_big_empty(stack, &stack_sizes, print);
		print_stacks("post b", stack, stack_sizes);
	}
	return (actions);
}

int	get_max_bits(int total_size)
{
	int	max_value;
	int	max_bits;

	max_value = total_size - 1;
	if (max_value < 0)
		return (0);
	max_bits = 0;
	while (max_value > 0)
	{
		max_value = max_value >> 1;
		max_bits++;
	}
	return (max_bits);
}

int	*get_ranks(int *stack, int size)
{
	int		*ranks;
	t_sizes	iter;
	int		rank_count;

	ranks = (int *)malloc(sizeof(int) * size);
	if (!ranks)
		return (NULL);
	iter.a = 0;
	while (iter.a < size)
	{
		rank_count = 0;
		iter.b = 0;
		while (iter.b < size)
		{
			if (stack[iter.b] < stack[iter.a])
				rank_count++;
			iter.b++;
		}
		ranks[iter.a] = rank_count;
		iter.a++;
	}
	return (ranks);
}

int	radix_sort(t_stack stack, t_sizes sizes, int print)
{
	int		actions;
	int		max_bits;
	t_sizes	iter;
	int		*ranks;

	actions = 0;
	ranks = get_ranks(stack.a, sizes.a);
	max_bits = get_max_bits(sizes.a);
	iter.a = 0;
	while (iter.a < max_bits)
	{
		iter.b = 0;
		while (iter.b < sizes.a)
		{
			if (((ranks[stack.a[0]] >> iter.a) & 1) == 0)
				actions += do_pass_a(stack, &sizes, print);
			else
				actions += do_rotate(stack.a, sizes.a, print * 'a');
			iter.b++;
		}
		actions += do_empty_b(stack, &sizes, print);
		iter.a++;
	}
	return (actions);
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

int	*get_order(int *stack, int size)
{
	int	*order;
	int	write;
	int	read;

	order = get_sort_order(stack, size);
	if (!order)
		return (NULL);
	write = 1;
	read = 1;
	while (read < size)
	{
		if (order[read] != order[write - 1])
		{
			order[write] = order[read];
			write++;
		}
		read++;
	}
	return (order);
}

int	get_rank(int value, int *order, int max, int size)
{
	int	i;

	if (!order)
		return (-1);
	i = 0;
	while (order[i] <= max && i < size)
	{
		if (order[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	do_chunking_a(t_stack stack, t_sizes *sizes, int *order, int print)
{
	int		rank;
	int		max;
	t_sizes	iter;
	int		chunk_size;
	int		actions;

	actions = 0;
	max = stack.a[src_super(stack.a, sizes->a, 1)];
	fprintf(stderr, "\t a to b , max %i\n", max);
	iter.a = 0;
	chunk_size = 10;
	fprintf(stderr, "\t\tpree loop\n");
	print_int_mtx("\t\tpost_loop", stack.a, sizes->a);
	while (sizes->a > 0)
	{
		fprintf(stderr, "\tnew chunk\n");
		iter.b = 0;
		while (iter.b < sizes->a + sizes->b && sizes->a > 0)
		{
			rank = get_rank(stack.a[0], order, max, sizes->a + sizes->b);
			if (rank >= iter.a && rank < iter.a + chunk_size)
				actions += do_pass_a(stack, sizes, print);
			else
				actions += do_rotate(stack.a, sizes->a, print * 'a');
			print_int_mtx("\t\tpost_loop", stack.a, sizes->a);
			iter.b++;
		}
		iter.a += chunk_size;
	}
	return (actions);
}


//int	undo_chunking_b(t_stack stack, t_sizes sizes, int *order, int print)
//{
//	int		rank;
//	int		max;
//	t_sizes	iter;
//	int		chunk_size;
//	int		actions;

//	fprintf(stderr, "\t b to a\n");
//	max = stack.a[src_super(stack.a, sizes.a, 1)];
//	iter.a = 0;
//	chunk_size = 10;
//	fprintf(stderr, "\t\tpree loop\n");
//	print_int_mtx("\t\tpost_loop", stack.a, sizes.a);
//	while (sizes.a > 0)
//	{
//		iter.b = 0;
//		while (iter.b < sizes.a + sizes.b && sizes.a > 0)
//		{
//			rank = get_rank(stack.a[0], order, max, sizes.a + sizes.b);
//			if (rank >= iter.a && rank < iter.a + chunk_size)
//				actions += do_pass_a(stack, &sizes, print);
//			else
//				actions += do_rotate(stack.a, sizes.a, print * 'a');
//			print_int_mtx("\t\tpost_loop", stack.a, sizes.a);
//			iter.b++;
//		}
//		iter.a += chunk_size;
//	}
//}

int	undo_chunking_b(t_stack stack, t_sizes *sizes, char print)
{
	int	actions;

	fprintf(stderr, "\t a to b\n");
	actions = 0;
	actions += do_r_to_super(stack.b, sizes->b, 1, print * 'b');
	fprintf(stderr, "\t\tpree loop\n");
	print_int_mtx("\t\tpost_loop", stack.b, sizes->b);
	while (!check_sort(stack.b, sizes->b, -1))
	{
		actions += do_pass_b(stack, sizes, print);
		if (check_sort(stack.b, sizes->b, -1))
			break ;
		actions += do_r_to_super(stack.b, sizes->b, 1, print * 'b');
		print_int_mtx("\t\tpost_loop", stack.b, sizes->b);
	}
	return (actions);
}

int	chunking_sort(t_stack stack, t_sizes sizes, int print)
{
	int		actions;
	int		*order;

	fprintf(stderr, "Chunking Sort\n");
	actions = 0;
	order = get_order(stack.a, sizes.a);
	print_int_mtx("\torder ", order, sizes.a);
	actions += do_chunking_a(stack, &sizes, order, print);
	print_stacks("post a", stack, sizes);
	actions += undo_chunking_b(stack, &sizes, print);
	print_stacks("post b", stack, sizes);
	actions += do_empty_b(stack, &sizes, print);
	print_stacks("post b", stack, sizes);
	free(order);
	return (actions);
}


//char	*ft_strjoin_arg(char *argv[], int argc)
//{
//	t_mult_ind	ind;
//	char		*input;
//	char		*output;


//	ind.i = 0; // #arg
//	ind.j = 0; // output
//	while (++ind.i + 1 < argc)
//	{
//		ind.k = 0; // in_arg
//		output = malloc(sizeof(char) *
//			(ft_strlen(argv[ind.i]) + ft_strlen(input) + 2));
//		if (!output)
//			return (ft_out(NULL, input, 2));
//		while (input && input[ind.j])
//			output[ind.j] = input[ind.j];
//		output[ind.j++] = ' ';
//		while (argv[ind.i][ind.k])
//			output[ind.j++] = argv[ind.i][ind.k++];
//		output[ind.j] = '\0';
//		trash(input);
//		input = output;
//	}
//	return (output);
//}

*/

//#endif
