/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:41:00 by noalexan          #+#    #+#             */
/*   Updated: 2022/03/31 13:43:23 by noalexan         ###   ########.fr       */
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
	if (nb == -2147483648)
		return (ft_putnbr(-21474) + ft_putnbr(83648));
	else if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(nb * -1));
	else if (nb >= 10)
		return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}

int	ft_putunsignednbr(unsigned int nb)
{
	if (nb < 0)
		return (ft_putchar('-') + ft_putnbr(nb * -1));
	else if (nb >= 10)
		return (ft_putnbr(nb / 10) + ft_putnbr(nb % 10));
	else
		return (ft_putchar(nb + '0'));
}

int	ft_puthexa(unsigned long nb, int upper)
{
	char	*dic;

	dic = "0123456789abcdef";
	if (upper)
		dic = "0123456789ABCDEF";
	if (nb < 16)
		return (ft_putchar(dic[nb]));
	else
		return (ft_puthexa(nb / 16, upper) + ft_puthexa(nb % 16, upper));
}

int	ft_putadrr(unsigned long adrr)
{
	return (ft_putchar('0') + ft_putchar('x') + ft_puthexa(adrr, 0));
}
