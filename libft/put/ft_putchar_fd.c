/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angelo <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:01:49 by aprosper          #+#    #+#             */
/*   Updated: 2022/07/29 17:48:11 by angelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
int	main(void)
{
//	int fd1 = open("/etc/passwd", O_RDONLY);
//	(void) fd1;
	int fd2 = open("./test.txt", O_RDWR);
	char	c = 'b';
	printf("fd2 %d\n", fd2);
	ft_putchar_fd(c, fd2);
	return (0);
}
*/
