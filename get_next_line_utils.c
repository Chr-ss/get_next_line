/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rasc035 <rasc035@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 22:16:29 by rasc035       #+#    #+#                 */
/*   Updated: 2023/11/05 17:10:53 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//	free_master - combined free function, used for most cases when
//	my malloc mem has to be free'd

int	free_master(t_list **list, t_list **clean_node, char **buf, char **nl)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node && (*clean_node)->buffer[0] != '\0')
		*list = *clean_node;
	else if (buf || clean_node || nl)
	{
		if (buf)
			free(*buf);
		if (clean_node)
			free(*clean_node);
		if (nl)
		{
			free(*nl);
			*nl = NULL;
		}
	}
	return (-1);
}

//	lst_to_next_line - reading and copying lst until new line char

void	lst_to_next_line(t_list *lst, char *next_line)
{
	int	i;
	int	j;

	if (!lst)
		return ;
	i = 0;
	while (lst)
	{
		j = 0;
		while (lst->buffer[j])
		{
			if (lst->buffer[j] == '\n')
			{
				next_line[i++] = '\n';
				next_line[i] = '\0';
				return ;
			}
			next_line[i++] = lst->buffer[j++];
		}
		lst = lst->next;
	}
}

//	ft_calloc - pretty much calloc from libft
//	included b_zero in-line to not have another func

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		n;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	else if (!(((nmemb * size) / size) == nmemb))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	n = nmemb * size;
	while (n--)
		((unsigned char *)ptr)[n] = '\0';
	return (ptr);
}

//	lst_until_nl1 - counting characters until new line
//	returning 0 if no nl is found (use for the if statement)

int	lst_until_nl1(t_list *lst)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		while (lst->buffer[i])
		{
			if (lst->buffer[i] == '\n')
				return (1);
			i++;
		}
		ret += i;
		i = 0;
		lst = lst->next;
	}
	return (0);
}

//	lst_until_nl - pretty much copy of lst_until_nl1 - counting characters until
//	new line, returning number of characters until nl or end of list

int	lst_until_nl(t_list *lst)
{
	int	i;
	int	ret;

	ret = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->buffer[i])
		{
			if (lst->buffer[i] == '\n')
				return (++ret);
			i++;
			ret++;
		}
		lst = lst->next;
	}
	return (ret);
}
