/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhmidat <abhmidat@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-24 16:54:50 by abhmidat          #+#    #+#             */
/*   Updated: 2024-11-24 16:54:50 by abhmidat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	norm(char format, va_list args)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(args, int));
	if (format == 's')
		len += ft_putstr(va_arg(args, char *));
	if (format == 'p')
		len += print_pointer(va_arg(args, void *));
	if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(args, int));
	if (format == 'u')
		len += ft_pos_putnbr(va_arg(args, unsigned int));
	if (format == 'x')
		len += ft_puthex(va_arg(args, unsigned int), 0);
	if (format == 'X')
		len += ft_puthex(va_arg(args, unsigned int), 1);
	if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	args;

	if (!format || (write(1, 0, 0) == -1))
		return (-1);
	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			len += norm(format[i], args);
		}
		else
			len += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
#include <stdio.h>
int main()
{
	ft_printf("%%%%");
	printf("\n%%%%\n");
}