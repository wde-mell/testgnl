/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wde-mell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 19:34:28 by wde-mell          #+#    #+#             */
/*   Updated: 2018/05/12 20:42:09 by wde-mell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static t_element	*ft_newlist(void *a, int nb)
{
	t_element *maillon;

	if (!(maillon = (t_element*)malloc(sizeof(t_element))))
		return (0);
	maillon->data = a;
	maillon->fd = nb;
	maillon->next = NULL;
	return (maillon);
}

static void			list_push_back(t_head *head, t_element *new)
{
	if (!head->begin)
	{
		head->begin = new;
		head->end = new;
	}
	else
	{
		head->end->next = new;
		head->end = new;
	}
}

static void			get_all_fd(t_head *head, char **av)
{
	int	i;
	int	current_fd;

	i = 0;
	while (av[++i])
		if ((current_fd = open(av[i], O_RDONLY)) != -1)
			list_push_back(head, ft_newlist(NULL, current_fd));
}

static void			close_all_fd(t_head *head)
{
	t_element	*current;
	t_element	*tmp;

	current = head->begin;
	while (current)
	{
		tmp = current;
		close((int)current->data);
		current = current->next;
		free(tmp);
	}
}
*/

#include <stdio.h>
int					main(int ac, char **av)
{
	int			current;
	char		*line;
	int			ret = 0;

	
	if (ac < 2)
		return (1);
	if (ac >= 2)
	{
		current = open(av[1], 0);
		int current2 = open(av[2], 0);
		while ((get_next_line(current, &line)) > 0)
		{
			printf("[%d]%s\n", ret, line);
			free(line);
			ret++;
		}
	//	ret = get_next_line(current, &line);
	//	printf("[%d]%s\n", ret, line);
	//	free(line);
	//	ret = get_next_line(current2, &line);
	//	printf("[%d]%s\n", ret, line);
	//	free(line);
	//	ret = get_next_line(current, &line);
	//	printf("[%d]%s\n", ret, line);
	//	free(line);
	//	close(current);
	//	current = open(av[1], 0);
	//	ret = get_next_line(current, &line);
	//	printf("[%d]%s\n", ret, line);
	//	free(line);
		while ((get_next_line(current2, &line)) > 0)
		{
			printf("[%d]%s\n", ret, line);
			free(line);
			ret++;
		}
		free(line);
		close(current2);
		close(current);
	}
	return (0);
}
