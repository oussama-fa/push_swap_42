/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 09:37:38 by oufarah           #+#    #+#             */
/*   Updated: 2024/12/28 04:28:17 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

long	ft_atoi(const char *str)
{
	long	res;
	int		sig;

	res = 0;
	sig = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sig *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*(str++) - 48);
		if ((sig == 1 && res > 2147483647) || (sig == -1 && res > 2147483648))
			return (2147483648);
	}
	return (res * sig);
}
