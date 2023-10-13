/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 19:18:38 by crasche       #+#    #+#                 */
/*   Updated: 2023/10/13 13:30:49 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


void	ft_bzero(void *s, size_t n)
{
	while (n--)
		((unsigned char *)s)[n] = '\0';
}


void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max;

	max = INT_MAX;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	else if ((nmemb * size) < size || (nmemb * size) < nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
