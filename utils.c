/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:41:00 by noalexan          #+#    #+#             */
/*   Updated: 2022/03/31 12:02:46 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(const char character)
{
	write(1, &character, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int	size;

	size = 0;
	if (nb == -2147483648)
		size += ft_putnbr(-21474) + ft_putnbr(83648);
	else if (nb < 0)
		size += ft_putchar('-') + ft_putnbr(nb * -1);
	else if (nb >= 10)
		size += ft_putnbr(nb / 10) + ft_putnbr(nb % 10);
	else
		size += ft_putchar(nb + '0');
	return (size);
}

int	ft_putunsignednbr(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
		size += ft_putchar('-') + ft_putnbr(nb * -1);
	else if (nb >= 10)
		size += ft_putnbr(nb / 10) + ft_putnbr(nb % 10);
	else
		size += ft_putchar(nb + '0');
	return (size);
}

int	ft_puthexa(unsigned long nb, int upper)
{
	int		size;
	char	*dic;

	size = 0;
	dic = "0123456789abcdef";
	if (upper)
		dic = "0123456789ABCDEF";
	if (nb < 16)
		size = ft_putchar(dic[nb]);
	else
	{
		size += ft_puthexa(nb / 16, upper);
		size += ft_puthexa(nb % 16, upper);
	}
	return (size);
}

int	ft_putadrr(unsigned long adrr)
{
	int	size;

	size = ft_putchar('0');
	size += ft_putchar('x');
	size += ft_puthexa(adrr, 0);
	return (size);
}
