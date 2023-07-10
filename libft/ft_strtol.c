/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdurro <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:34:40 by cdurro            #+#    #+#             */
/*   Updated: 2023/06/30 15:47:55 by cdurro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_strtol(const char *str)
{
	int	len;
	long long	power;
	int num;
	long long res;

	len = ft_strlen(str);
	res = 0;
	num = 0;
	power = 1;
	while (--len >= 2)
	{
		if (str[len] >= 'a' && str[len] <= 'z')
			num = str[len] - 87;
		else if (str[len] >= 'A' && str[len] <= 'Z')
			num = str[len] - 55;
		else
			num = str[len] - '0';
		res = res + (num * power);
		power *= 16;
	}
	return (res);
}