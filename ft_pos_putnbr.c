/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_putnbr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-29 13:28:57 by abhmidat          #+#    #+#             */
/*   Updated: 2024-11-29 13:28:57 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pos_putnbr(unsigned int n)
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
