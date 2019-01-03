/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 13:08:23 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/01/03 13:30:20 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
			i++;
		i -= 1;
		while ((argv[1][i] == '\t' || argv[1][i] == ' ') && i > 0)
			i--;
		while (((argv[1][i] != '\t') && (argv[1][i] != ' ')) && i > -1)
			i--;
		i += 1;
		while (((argv[1][i] != '\t') && (argv[1][i] != ' ')) && (argv[1][i] != '\0'))
		{
			ft_putchar(argv[1][i]);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
