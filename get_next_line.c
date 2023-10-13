/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/11 19:18:37 by crasche       #+#    #+#                 */
/*   Updated: 2023/10/13 13:30:42 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


//size_t read (int fd, void* buf, size_t cnt);


char	*get_next_line(int fd)
{
	char	*ret;

	ret = ft_calloc(BUFFER_SIZE * sizeof(char));

}

int	main(void)
{
	int	fd;

	fd = open(test.txt, O_RDONLY);
	printf("%d:%s", 1, get_next_line(fd));
	close(fd);
	return (0);
}
