/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsahin <elsahin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 08:23:49 by elsahin           #+#    #+#             */
/*   Updated: 2025/11/11 09:18:27 by elsahin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		handle_format(char c, va_list *args, int *count);

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			handle_format(format[i + 1], &args, &count);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			i++;
			count++;
		}
	}
	va_end(args);
	return (count);
}

static void	handle_pointer(va_list *args, int *count)
{
	void	*ptr;

	ptr = va_arg(*args, void *);
	if (!ptr)
		ft_putstr_fd("(nil)", 1, count);
	else
	{
		ft_putstr_fd("0x", 1, count);
		ft_putnbr_base_ul((unsigned long)ptr, "0123456789abcdef", count);
	}
}

void	handle_format(char c, va_list *args, int *count)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(*args, int), 1, count);
	else if (c == 's')
		ft_putstr_fd(va_arg(*args, char *), 1, count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(*args, int), 1, count);
	else if (c == '%')
		ft_putchar_fd('%', 1, count);
	else if (c == 'u')
		ft_putnbr_base_ul(va_arg(*args, unsigned int), "0123456789", count);
	else if (c == 'x')
		ft_putnbr_base_ul(va_arg(*args, unsigned int), "0123456789abcdef",
			count);
	else if (c == 'X')
		ft_putnbr_base_ul(va_arg(*args, unsigned int), "0123456789ABCDEF",
			count);
	else if (c == 'p')
		handle_pointer(args, count);
}
