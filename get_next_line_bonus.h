/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rasc035 <rasc035@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 22:16:57 by rasc035       #+#    #+#                 */
/*   Updated: 2023/10/24 14:10:09 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

void	free_master(t_list **list, t_list *clean_node, char *buf);
int		lst_until_nl(t_list *lst);
int		lst_until_nl1(t_list *lst);
void	*ft_calloc(size_t nmemb, size_t size);
void	lst_to_next_line(t_list *lst, char *next_line);

#endif /* GET_NEXT_LINE_BONUS_H */
