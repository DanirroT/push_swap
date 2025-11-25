/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmota-ri <dmota-ri@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:01:18 by dmota-ri          #+#    #+#             */
/*   Updated: 2025/11/07 15:53:22 by dmota-ri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

size_t	ft_strlen(const char *s);
//	The strlen() function calculates the length of the string pointed to by
//		s, excluding the terminating null byte ('\0').

char	*ft_substr(char const *s, unsigned int start,
			size_t len);
//	Allocates memory (using malloc(3)) and returns a substring from the
//		string ’s’. The substring starts at index ’start’ and has a maximum
//		length of ’len’.

char	*ft_strjoin(char const *s1, char const *s2);
//	Allocates memory (using malloc(3)) and returns a new string,
//		which is the result of concatenating ’s1’ and ’s2’.

char	*ft_strtrim(char const *s1, char const *set);
//	Allocates memory (using malloc(3)) and returns a copy of ’s1’
//		with characters from ’set’ removed from the beginning and the end.

char	**ft_split(char const *s, char c);
//	Allocates memory (using malloc(3)) and returns an array of strings
//		obtained by splitting ’s’ using the character ’c’ as a delimiter.
//		The array must end with a NULL pointer.

char	*ft_strmapi(char const *s, char (*f)(unsigned int,
				char));
//	Applies the function f to each character of the string s,
//		passing its index as the first argument and the character itself
//		as the second. A new string is created (using malloc(3)) to store
//		the results from the successive applications of f.

void	ft_striteri(char *s, void (*f)(unsigned int,
				char *));
//	Applies the function ’f’ to each character of the string passed as
//		argument, passing its index as the first argument. Each character
//		is passed by address to ’f’ so it can be modified if necessary.

size_t	ft_putchar_fd(char c, int fd);
//	Outputs the character ’c’ to the specified file descriptor.

size_t	ft_putstr_fd(void *s, int fd);
//	Outputs the string ’s’ to the specified file descriptor.

size_t	ft_putendl_fd(void *s, int fd);
//	Outputs the string ’s’ to the specified file descriptor followed by a
//		newline.

size_t	ft_putnbr_fd(int n, int fd);
//	Outputs the integer ’n’ to the specified file descriptor.

int		ft_isascii(int c);
//	checks whether c is a 7-bit unsigned char value that fits into the ASCII
//		character set.

size_t	ft_strlen(const char *s);

//	The strlen() function calculates the length of the string pointed to by
//		s, excluding the terminating null byte ('\0').

size_t	ft_strlcpy(char *dst, const char *src,
			size_t dsize);
//	see man, too mush to put here

size_t	ft_strlcat(char *dst, const char *src,
			size_t dsize);
//	see man, too mush to put here

char	*ft_strchr(const char *s, int c);
//	The strchr() function returns a pointer to the first occurrence of the
//		character c in the string s.

char	*ft_strrchr(const char *s, int c);

//	The strrchr() function returns a pointer to the last occurrence of the
//		character c in the string s.

int		ft_strncmp(const char *s1, const char *s2,
			size_t n);
//	The strcmp() function compares the two strings s1 and s2. The locale is
//		not taken into account (for a locale-aware comparison,see strcoll(3)).
//		The comparison is done using unsignedcharacters. strcmp() returns an
//		integer indicating the result of the comparison,as follows:
//
//		• 0, if the s1 and s2 are equal;
//		• a negative value if s1 is less than s2;
//		• a positive value if s1 is greater than s2.

char	*ft_strnstr(const char *big, const char *little,
			size_t len);
//		The strstr() function locates the first occurrence of the
//		null-termi-nated string little in the null-terminated string big.

char	*ft_strdup(const char *s);
//	The strdup() function returns a pointer to a new string which is a
//		duplicate of the string s. Memory for the new string is obtained
//		with malloc(3),and can be freed with free(3).

int		ft_atoi(const char *nptr);
//	The  atoi() function converts the initial portion of the string pointed
//		to by nptr to int.  The behavior is the same as:
//			strtol(nptr, NULL, 10);
//		except that atoi() does not detect errors.

char	*ft_itoa(int n);
//	Allocates memory (using malloc(3)) and returns a string representing
//		the integer received as an argument. Negative numbers must be handled.

int		ft_toupper(int c);
//	These functions convert lowercase letters to uppercase.

int		ft_tolower(int c);
//	These functions convert uppercase letters to lowercase.

int		ft_isalpha(int c);
//	checks  for  an  alphabetic  character; in the standard "C" locale,
//		it is equivalent to (isupper(c) || islower(c)).  In some locales,
//		there may be  additional  characters  for which isalpha() is
//		true—letters which are neither uppercase nor lowercase.

int		ft_isdigit(int c);
//	checks for a digit (0 through 9).

int		ft_isalnum(int c);
//	checks for an alphanumeric character; it is equivalent to
//		(isalpha(c) || isdigit(c)).

int		ft_isprint(int c);
//	checks for any printable character including space.

int		ft_isascii(int c);
//	checks whether c is a 7-bit unsigned char value that fits into the ASCII
//		character set.

void	ft_bzero(void *s, size_t n);
//	The bzero() function erases the data in the n bytes of the memory starting
//		at the location pointed to by s, by writing zeros (bytes containing
//		'\0') to that area.

void	*ft_memchr(const void *s, int c, size_t n);
//	The memchr() function scans the initial n bytes of the memory area pointed
//		to by s for the first instance of c. Both c and the bytes of the
//		memory area pointed to by s are interpreted as unsigned char.

int		ft_memcmp(const void *s1, const void *s2, size_t n);
//	The memcmp() function compares the first n bytes (each interpreted as
//		unsigned char) of the memory areas s1 and s2

void	*ft_memcpy(void *dest, const void *src, size_t n);
//	The memcpy() function copies n bytes from memory area src to memory area
//		dest. The memory areas must not overlap. Use memmove(3) if the memory
//		areas do overlap.

void	*ft_memmove(void *dest, const void *src, size_t n);
//	The memmove() function copies n bytes from memory area src to memory area
//		dest. The memory areas may overlap: copying takes place as though the
//		bytes in src are first copied into a temporary array that does not
//		overlap src or dest, and the bytes are then copied from the temporary
//		array to dest.

void	*ft_memset(void *s, int c, size_t n);
//	The memset() function fills the first n bytes of the memory area pointed
//		to by s with the constant byte c. : The memset() function returns a
//		pointer to the memory area s.

void	*ft_calloc(size_t nmemb, size_t size);
//	The calloc() function allocates memory for an array of nmemb elements of
//		size bytes each and returns a pointer to the allocated memory.
//		The memory is set to zero. If nmemb or size is 0,
//		then calloc() returns a unique pointer value that
//		can later be successfully passed to free().

//	Translation: create a (nmemb(elements) x size(len)) sized malloc. 
//		set all to 0

t_list	*ft_lstnew(void *content);

//	Allocates memory (using malloc(3)) and returns a new node.
//		The ’content’ member variable is initialized with the
//		given parameter ’content’. The variable ’next’ is initialized to NULL.

void	ft_lstadd_front(t_list **lst, t_list *new);
//	Adds the node ’new’ at the beginning of the list.

int		ft_lstsize(t_list *lst);
//	Counts the number of nodes in the list.

t_list	*ft_lstlast(t_list *lst);
//	Returns the last node of the list.

void	ft_lstadd_back(t_list **lst, t_list *new);
//	Adds the node ’new’ at the end of the list.

void	ft_lstdelone(t_list *lst, void (*del)(void *));
//	Takes a node as parameter and frees its content using the function ’del’.
//		Free the node itself but does NOT free the next node.

void	ft_lstclear(t_list **lst, void (*del)(void *));
//	Deletes and frees the given node and all its successors,
//		using the function ’del’ and free(3). Finally,
//		set the pointer to the list to NULL.

void	ft_lstiter(t_list *lst, void (*f)(void *));
//	Iterates through the list ’lst’ and applies the function ’f’ to the
//		content of each node.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));
//	Iterates through the list ’lst’, applies the function ’f’ to each
//		node’s content, and creates a new list resulting of the successive
//		applications of the function ’f’. The ’del’ function is used to
//		delete the content of a node if needed.

#endif