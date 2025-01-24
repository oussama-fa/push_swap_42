/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oufarah <oufarah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 02:09:27 by oufarah           #+#    #+#             */
/*   Updated: 2025/01/19 02:09:28 by oufarah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
