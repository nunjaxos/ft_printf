/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-29 13:23:43 by abhmidat          #+#    #+#             */
/*   Updated: 2024-11-29 13:23:43 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(size_t n, int is_upper)
{
	char		*base;
	size_t		mod;
	int			i;

	i = 0;
	mod = 1;
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	while (n / mod >= 16)
		mod *= 16;
	while (mod > 0)
	{
		i += ft_putchar(base[(n / mod) % 16]);
		n %= mod;
		mod /= 16;
	}
	return (i);
}
