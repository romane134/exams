/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:07:40 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/01/14 13:40:06 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hex(unsigned int n)
{
	if (n >= 16)
		print_hex(n / 16);
	if (n % 16 < 10)
		ft_putchar((n % 16) + '0');
	else
		ft_putchar((n % 16) - 10 + 'a');
}

int		ft_atoi_for_printhex(char *str)
{
	int		i;
	int		result;

	i = 0;
	while (*str && (*str == ' ' || *str == '\t' ||
				*str == '\n' || *str == '\r'))
		str++;
	if (str[i] == '-')
		return (-1);
	if (str[i] == '+')
		i++;
	result = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result);
}

int		main(int ac, char **av)
{
	int		nb;

	if (ac == 2)
	{
		if ((nb = ft_atoi_for_printhex(av[1])) != -1)
			print_hex(nb);
	}
	write(1, "\n", 1);
	return (0);
}
