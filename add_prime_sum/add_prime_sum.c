/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:33:09 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/01/03 14:14:14 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	if (str[i] == '-')
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		nbr = nbr * 10;
		nbr = nbr + (str[i] - 48);
		i++;
	}
	return (nbr);
}

void	ft_putnbr(int nbr)
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
		write(1, &c, 1);
	}
}

int		ft_is_prime(int nb)
{
	int a;
	int result;

	a = 2;
	while ((nb % a != 0) && (a * a < nb))
	{
		a++;
	}
	if (nb == 2)
		return (2);
	if ((nb % a) == 0 || nb == 1 || nb < 0)
		result = 0;
	else
		result = nb;
	return (result);
}

int		main(int argc, char **argv)
{
	int number;
	int i;

	i = 0;
	number = 0;
	if ((argc != 2) || argv[1][0] == '-' || argv[1][0] == '0')
	{
		write (1, "0\n", 2);
		return (0);
	}
	number = ft_atoi(argv[1]);
	if (ft_is_prime(number) != 0)
	{
		i = ft_is_prime(number);
	}
	else
	{
		i = number;
		number = 0;
	}
	i--;
	while (i)
	{
		number += ft_is_prime(i);
		i--;
	}
	ft_putnbr(number);
	write (1, "\n", 1);
	return (0);
}
