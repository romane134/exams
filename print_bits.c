/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:23:37 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/12/18 18:07:19 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void			ft_putchar(char c)
{
	write (1, &c, 1);
}
void			print_bits(unsigned char octet)
{
	int i;
	i = 0;
	while (i < 8)
	{
		ft_putchar((octet >> (7 - i) & 1) + 48);
		i++;
	}
}
unsigned char	swap_bits(unsigned char octet)
{
	return (((octet >> 4) | (octet << 4)));
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	print_bits(atoi(argv[1]));
	write (1, "\n", 1);
	print_bits(swap_bits((unsigned char)atoi(argv[1])));
	return (0);
}
