#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/uio.h>

char *ft_merge(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
int ft_is_newline(char *line);
char *ft_stock_text(int fd, char *line);
char *ft_append_line(char *line); 
char *ft_clear_line(char *str_temp);
char *get_next_line(int fd);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
#  endif



#  ifndef OPEN_MAX

#  define OPEN_MAX 1024
#endif

# endif

