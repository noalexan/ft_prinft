/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noahalexandre <noahalexandre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:36:18 by noalexan          #+#    #+#             */
/*   Updated: 2022/04/06 11:52:15 by noahalexand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent2(va_list param, const char character)
{
	if (character == 'X')
		return (ft_puthexa(va_arg(param, unsigned int), 1, 0));
	else if (character == 'p')
		return (ft_puthexa(va_arg(param, unsigned long), 0, 1));
	else if (character == 'u')
		return (ft_putunsignednbr(va_arg(param, unsigned int)));
	else
		return (0);
}

static int	ft_percent(va_list param, const char character)
{
	int		size;
	char	*str;

	size = 1;
	if (character == 's')
	{
		str = va_arg(param, char *);
		if (str == NULL)
			return (ft_printf("(null)"));
		else
			return (ft_putstr(str));
	}
	else if (character == 'c')
		return (ft_putchar(va_arg(param, int)));
	else if (character == 'd' || character == 'i')
		return (ft_putnbr(va_arg(param, int)));
	else if (character == '%')
		return (ft_putchar('%'));
	else if (character == 'x')
		return (ft_puthexa(va_arg(param, unsigned int), 0, 0));
	else
		return (ft_percent2(param, character));
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
