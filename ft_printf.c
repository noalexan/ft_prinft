/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:36:18 by noalexan          #+#    #+#             */
/*   Updated: 2022/03/31 12:02:20 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_percent(va_list param, const char character)
{
	int		size;
	char	*str;

	size = 1;
	if (character == 's')
	{
		str = va_arg(param, char *);
		if (str == NULL)
			size = ft_printf("(null)");
		else
			size = ft_printf(str);
	}
	else if (character == 'c')
		size = ft_putchar(va_arg(param, int));
	else if (character == 'd' || character == 'i')
		size = ft_putnbr(va_arg(param, int));
	else if (character == '%')
		size = ft_putchar('%');
	else if (character == 'x')
		size = ft_puthexa(va_arg(param, unsigned int), 0);
	else if (character == 'X')
		size = ft_puthexa(va_arg(param, unsigned int), 1);
	else if (character == 'p')
		size = ft_putadrr(va_arg(param, unsigned long));
	else if (character == 'u')
		size = ft_putunsignednbr(va_arg(param, unsigned int));
	else
		size = 0;
	return (size);
}

int	ft_printf(const char *string, ...)
{
	va_list	param;
	int		i;
	int		size;

	va_start(param, string);
	i = 0;
	size = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			size += ft_percent(param, string[i]);
		}
		else
			size += ft_putchar(string[i]);
		i++;
	}
	return (size);
}
