/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rasc035 <rasc035@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 22:16:57 by rasc035       #+#    #+#                 */
/*   Updated: 2023/10/30 20:18:45 by veno          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	char			*buffer;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

int		lst_until_nl(t_list *lst);
int		lst_until_nl1(t_list *lst);
void	*ft_calloc(size_t nmemb, size_t size);
void	lst_to_next_line(t_list *lst, char *next_line);
void	free_master(t_list **list, t_list *clean_node, char *buf, char *nl);

#endif /* GET_NEXT_LINE_H */
