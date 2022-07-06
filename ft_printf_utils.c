/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noalexan <noalexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:19:48 by noahalexand       #+#    #+#             */
/*   Updated: 2022/05/30 09:53:22 by noalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putchar(const char character, int fd)
{
	write(fd, &character, 1);
	return (1);
}

int	ft_putstr(char *str, int fd)
{
	int	i;

	if (str == NULL)
		return (ft_putstr("(null)", fd));
	i = -1;
	while (str[++i])
		ft_putchar(str[i], fd);
	return (i);
}

int	ft_putnbr(int nb, int fd)
{
	if (nb == -2147483648)
		return (ft_putnbr(-21474, fd) + ft_putnbr(83648, fd));
	if (nb < 0)
		return (ft_putchar('-', fd) + ft_putnbr(nb * -1, fd));
	else if (nb >= 10)
		return (ft_putnbr(nb / 10, fd) + ft_putnbr(nb % 10, fd));
	else
		return (ft_putchar(nb + '0', fd));
}

int	ft_putunsignednbr(unsigned int nb, int fd)
{
	if (nb < 0)
		return (ft_putchar('-', fd) + ft_putnbr(nb * -1, fd));
	else if (nb >= 10)
		return (ft_putnbr(nb / 10, fd) + ft_putnbr(nb % 10, fd));
	else
		return (ft_putchar(nb + '0', fd));
}

int	ft_puthexa(unsigned long nb, int upper, int add, int fd)
{
	char	*dic;

	if (add)
		return (ft_putstr("0x", fd) + ft_puthexa(nb, 0, 0, fd));
	dic = "0123456789abcdef";
	if (upper)
		dic = "0123456789ABCDEF";
	if (nb < 16)
		return (ft_putchar(dic[nb], fd));
	else
		return (ft_puthexa(nb / 16, upper, 0, fd)
			+ ft_puthexa(nb % 16, upper, 0, fd));
}
