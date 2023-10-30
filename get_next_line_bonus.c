/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rasc035 <rasc035@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 22:16:05 by rasc035       #+#    #+#                 */
/*   Updated: 2023/10/30 20:17:10 by veno          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
//	clean_for_next_call - cleaning lst for the next call and freeing
//	all characters we already used in the current string

static void	clean_for_next_call(t_list **lst, char *next_line)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*clean_buffer;

	clean_buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!clean_buffer)
		return (free_master(lst, 0, 0, next_line));
	clean_node = ft_calloc(sizeof(t_list), 1);
	if (!clean_node)
		return (free_master(lst, 0, clean_buffer, next_line));
	last_node = *lst;
	while (last_node->next)
		last_node = last_node->next;
	i = 0;
	k = 0;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		i++;
	while (last_node->buffer[i] && last_node->buffer[++i])
		clean_buffer[k++] = last_node->buffer[i];
	clean_node->buffer = clean_buffer;
	free_master(lst, clean_node, clean_buffer, 0);
}

//	lst_to_line - reading lst and creating "next_line" string
//	calloc it's size and returning the string to get_next_line

static char	*lst_to_line(t_list *lst)
{
	int		nl_len;
	char	*next_line;

	if (!lst)
		return (NULL);
	nl_len = lst_until_nl(lst);
	next_line = ft_calloc(nl_len + 1, 1);
	if (!next_line)
		return (NULL);
	lst_to_next_line(lst, next_line);
	return (next_line);
}

//	add_lst_node - taking malloced read characters and adding
//	them as list node to lst

static int	add_lst_node(t_list **lst, char *buffer)
{
	t_list	*new;

	new = ft_calloc(sizeof(t_list), 1);
	if (!new)
	{
		free(buffer);
		return (-1);
	}
	new->buffer = buffer;
	new->next = NULL;
	if (!(*lst))
		*lst = new;
	else
	{
		while ((*lst)->next != NULL)
			lst = &(*lst)->next;
		(*lst)->next = new;
	}
	return (0);
}

//	read_to_list - calloc BUFFER_SIZE string and reading
//	BUFFER_SIZE chars, calling add_lst_node to add a node

static int	read_to_list(t_list **lst, int fd)
{
	char	*buffer;
	int		read_ret;

	while (!(lst_until_nl1(*lst)))
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (0);
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret <= 0)
		{
			free(buffer);
			return (1);
		}
		if (add_lst_node(lst, buffer) == -1)
		{
			free_master(lst, 0, buffer, 0);
			return (0);
		}
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*lst[4096];
	char			*next_line;

	if (fd < 0 || fd > 4095 || read(fd, &next_line, 0) < 0 || BUFFER_SIZE <= 0)
	{
		free_master(&lst[fd], 0, 0, 0);
		return (NULL);
	}
	if (read_to_list(&lst[fd], fd) == 0 || !lst[fd])
		return (NULL);
	next_line = lst_to_line(lst[fd]);
	clean_for_next_call(&lst[fd], next_line);
	return (next_line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int	fd;
// 	char	*curr_line;
// 	int	i;

// 	i = 0;

// 	fd = open("test.txt", O_RDWR);
// 	while (i++ < 25)
// 	{
// 		curr_line = get_next_line(fd);
// 		if (!curr_line)
// 			return (0);
// 		printf(">%s", curr_line);
// 		free(curr_line);
// 	}
// 	close(fd);

// 	return (0);
// }
