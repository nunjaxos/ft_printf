/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:25:45 by abhmidat          #+#    #+#             */
/*   Updated: 2024/11/21 11:31:27 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_digits(int n)
{
	char	c;
	int		mod;
	int		i;

	i = 0;
	mod = 1;
	while (n / mod >= 10)
		mod *= 10;
	while (mod > 0)
	{
		c = (n / mod) + '0';
		i += write(1, &c, 1);
		n %= mod;
		mod /= 10;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	i += print_digits(n);
	return (i);
}
