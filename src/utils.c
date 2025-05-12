/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:56:21 by tle-saut          #+#    #+#             */
/*   Updated: 2025/04/16 17:20:44 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	atoi_philo(const char *nptr)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (nptr[0] == '-')
		return (printf("Pas de nombre negatif\n"));
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		c = (c * 10) + (nptr[i] - '0');
		i++;
	}
	return (c);
}

int	ft_nlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_nlen(n);
	str = NULL;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
