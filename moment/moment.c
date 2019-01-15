/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 11:05:22 by rlucas-d          #+#    #+#             */
/*   Updated: 2019/01/04 12:12:50 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int			ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_secondes(int *tmp, char *res, int *i, int *div)
{
	if (*tmp % 60 != 0)
	{
		*div = (*tmp % 60);
		if (*div >= 10)
		{
			res[*i] = (*div / 10) + '0';
			(*i)++;
		}
		res[*i] = (*div % 10) + '0';
		(*i)++;
		*tmp -= *div;
		*tmp /= 60;
	}
	else if (*tmp % 60 == 0)
	{
		res[*i] = '0';
		*tmp /= 60;
		(*i)++;
	}
	return (res);
}

char		*ft_minutes(int *tmp, char *res, int *i, int *div)
{
	if (*tmp % 60 != 0)
	{
		*div = (*tmp % 60);
		if (*div >= 10)
		{
			res[*i] = (*div / 10) + '0';
			(*i)++;
		}
		res[*i] = (*div % 10) + '0';
		(*i)++;
		*tmp -= *div;
		*tmp /= 60;
	}
	else if (*tmp % 60 == 0)
	{
		res[*i] = '0';
		*tmp /= 60;
		(*i)++;
	}
	return (res);
}

char		*ft_heures(int *tmp, char *res, int *i, int *div)
{
	if (*tmp % 24 != 0)
	{
		*div = (*tmp % 24);
		if (*div >= 10)
		{
			res[*i] = (*div / 10) + '0';
			(*i)++;
		}
		res[*i] = (*div % 10) + '0';
		(*i)++;
		*tmp -= *div;
		*tmp /= 24;
	}
	else if (*tmp % 24 == 0)
	{
		res[*i] = '0';
		*tmp /= 24;
		(*i)++;
	}
	return (res);
}

char		*moment(unsigned int duration)
{
	int tmp;
	char *res;
	int i;
	int div;

	div = 0;
	i = 0;
	tmp = (int)duration;
	if (!(res = (char *)malloc(sizeof(res) * ((tmp /60) + 1))))
		return (0);
	res = ft_secondes(&tmp, res, &i, &div);
	res = ft_minutes(&tmp, res, &i, &div);
	printf("tmp---%d\n", tmp);

	res = ft_heures(&tmp, res, &i, &div);
//	res = ft_mois(&tmp, res, &i, &div);
	printf("res---%s\n", res);
	printf("tmp---%d\n", tmp);
	printf("div---%d\n", div);
	printf("i---%d\n", i);

	return (res);
}

int		main(void)
{
	moment(82801);
	return (0);
}
