/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 19:18:36 by crasche       #+#    #+#                 */
/*   Updated: 2023/10/13 13:30:34 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef	struct	s_list
{
	char			*buf;
	strcut	s_list	*next;
}	t_list;

# include <stddef.h>
# include <stdlib.h>


void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif /* GET_NEXT_LINE_H */
