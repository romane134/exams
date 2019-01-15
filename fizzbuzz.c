/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 10:00:54 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/01/04 10:17:54 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putnbr(int nbr)
{
	char c;

	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write (1, &c, 1);
	}
}

int			main(void)
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if (((i % 3) == 0) && ((i % 5) == 0))
			write (1, "fizzbuzz\n", 9);
		else if (((i % 5) == 0) && ((i % 3) != 0))
			write (1, "buzz\n", 5);
		else if (((i % 3) == 0) && ((i % 5) != 0))
			write (1, "fizz\n", 5);
		else
		{
			ft_putnbr(i);
			write (1, "\n", 1);
		}
		i++;
	}
	write (1, "\n", 1);
	return (0);
}
