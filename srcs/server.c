/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aprosper <aprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 11:18:28 by aprosper          #+#    #+#             */
/*   Updated: 2022/07/31 13:08:44 by aprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_to_char(int signum)
{
	static int				counter = 128;
	static unsigned char	c = 0;
	static int				bitshift = 8;

	if (signum == SIGUSR2)
	{
		c = c + counter;
		counter = counter / 2;
	}
	else if (signum == SIGUSR1)
	{
		counter = counter / 2;
	}
	bitshift--;
	if (counter < 1 || bitshift <= 0)
	{
		write(1, &c, 1);
		counter = 128;
		bitshift = 8;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, bit_to_char);
	signal(SIGUSR2, bit_to_char);
	while (1)
		pause();
}

/*
	char c = 'a' == 97 == 0 1 1 0 0 0 0 1
	SIGUSR2 = 1
	SIGUSR1 = 0
*/

/*
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
	abcdefghijklmnopqrstuvwxyz  1234567890  ()<>;:.,?!
*/

// 1250 caracteres