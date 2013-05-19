/*
** my.h for my in /home/serraj_y//c/corewar/asmx/libs/my
** 
** Made by younes serraj
** Login   <serraj_y@epitech.net>
** 
** Started on  Fri Sep 17 16:35:04 2010 younes serraj
** Last update Sat Dec 18 23:19:41 2010 younes serraj
*/

#ifndef MY_H_
# define MY_H_

# define MY_READFILE_BUFFSIZE	2048

# include <stdarg.h>

# define DBG(i)			printf("DEBUG %d\n", (i))

# define x_free(ptr)		if (ptr) free(ptr)

/*
** Get_Next_Line
*/
# define BUFFER_SIZE		1024
# define FINDCHAR(c, s)		findchar((c), (s), 0)
# define STRLEN(s)		findchar('\0', (s), 1)

/*
** my_make_argv
*/
# define SEPARATORS		" \t"
# define IS_SEPARATOR(c)	((my_findchar((c), SEPARATORS) > -1) ? 1 : 0)

# define INHIBITORS		"'\"`"
# define IS_INHIBITOR(c)	((my_findchar((c), INHIBITORS) > -1) ? 1 : 0)

char				*get_next_line(const int fd);

/*
** Display functions
*/
void			my_die(char *msg, int retcode);
int			my_printf(char *s, ...);
int			my_printf_err(char *s, ...);
void			my_putnbr(int nbr);
void			my_putnbr_err(int nbr);
int			my_putchar(char c);
int			my_putchar_err(char c);
int			my_putline(char *s);
int			my_putline_err(char *s);
int			my_putstr(char *s);
int			my_puterr(char *s);

/*
** Strings operations functions
*/
int			my_findchar(char c, char *s);
int			my_strlen(char *s);
int			my_strcmp(char *s1, char *s2);
int			my_strncmp(char *s1, char *s2, int n);
int			my_strcpy(char *dest, char *src);
int			my_strncpy(char *dest, char *src, int n);
char			*my_strdup(char *s);
char			*my_strndup(char *s, int n);
char			*my_strdupcat(char *s1, char *s2);
int			my_getnbr(char *s);
void			my_wt_free(char **wt);
void			my_wt_free_wptr(char ***wt);
int			my_wt_count(char **wt);
void			my_wt_print(char **wt);
char			**my_split(char *s, char *sep);
char			*my_join(char **wt, char *sep);
char			*my_readfile(char *file);
int			my_readfile_from_fd(int fd, char **data);
int			my_trim(char *s, char *sep);
int			my_findchar(char c, char *s);
int			my_strcat(char *dest, char *s);
int			my_strncat(char *dest, char *s, int n);
int			my_isnum(char *s, int strict);
char			*my_strstr(char *s1, char *s2);
char			**my_make_argv(char *s, char call_epurstr);
/*
**
*/
void			my_memcpy(void *dest, void *src, int size);
void			my_memset(void *ptr, char c, int size);
void			my_memrev(void *ptr, int size);
void			my_swap(void *ptr1, void *ptr2);

int			check_fd_read(int fd);

/*
** X functions
*/
void			*x_malloc(int size);

# define my_str_to_wordtab(x) my_split((x), ' ')

#endif /* MY_H_ */
