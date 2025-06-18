/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amairia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:28:07 by amairia           #+#    #+#             */
/*   Updated: 2025/06/18 15:29:57 by amairia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

enum e_type
{
	YES,
	NO,
	NONE,
	COMMAND,
	FILE_,
	APNDMOD,
	REDIR_IN,
	REDIR_OUT,
	PIPE,
	HERE_DOC,
	DOC_STOP,
};

/*

void open_infile(t_data *data, char *file) // outfile, ...
{
	if (data->in != 1 (infile, 0 pour outfile) && data->in != -1)
		close(data->in);
	data->in = open(file);
	// gestion d'erreur
}

t_data data;

data.out = 0;
data.in = 1;
data.file_error = 0;

...
(dans tes commandes)

dup2(STDOUT_FILENO, data.out);
dup2(STDIN_FILENO, data.in);
...

while token != pipe && token != NULL
{
	if token.type == INFILE
		infile(&data, token); // set data.in
	else if token.type == HEREDOC
		heredoc(&data, token, token.next.content); // set data.in
	else if token.type == OUTFILE
		outfile(&data, token); // set data.out
	else if token.type == APPENDFILE
		appendfile(&data, token); // set data.out
	...
	if (data.file_error)
		return (FALSE); // fait bien attention a fermer les potentiels infile/outfile ouverts
}
// Exec (tes files ont bien été set dans data.in & data.out)

*/

//typedef enum e_type
//{
//	COMMAND,
//	PIPE,
//	INFILE,
//	OUTFILE,
//	APPENDFILE,
//	HEREDOC,
//	HEREDOC_LIM
//}			t_type;

typedef struct s_pars
{
	char			*content;
	enum e_type		type;
	int				*tab;
	int				*dtab;
	int				norm;
	struct s_pars	*next;
	struct s_pars	*prev;
}				t_pars;

typedef struct s_data
{
	int	std_err;
	int	std_in;
	int	std_out;
}		t_data;

typedef struct s_all
{
	t_pars	**lst;
	t_data	data;
}		t_all;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *src);
int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_pars	*ft_lstnew(char *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_pars *lst);
t_pars	*ft_lstlast(t_pars *lst);
int		ft_lstadd_back(t_pars **lst, t_pars *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_pars **lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		conv_hexa(unsigned long nb, char *hexa_case);
int		ft_put_c(va_list lst, int cpt);
int		ft_put_s(va_list lst, int cpt);
int		ft_put_p(va_list lst, int cpt);
int		ft_put_d(va_list lst, int cpt);
int		ft_put_i(va_list lst, int cpt);
int		ft_put_u(va_list lst, int cpt);
int		ft_put_x(va_list lst, int cpt);
int		ft_put_x_up(va_list lst, int cpt);
int		ft_put_end(int cpt);
int		ft_printf(const char *str, ...);
char	*get_next_line(int fd);
char	*ft_strjoin_free(char *s1, char const *s2);

#endif
