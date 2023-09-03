/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:20:37 by orudek            #+#    #+#             */
/*   Updated: 2023/03/31 14:08:10 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(unsigned int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	n %= 10;
	n += '0';
	write(1, &n, 1);
}

static int	ft_numlen(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		len ++;
	}
	return (len);
}

int	ft_print_uint(va_list *args)
{
	unsigned int	arg;

	arg = va_arg(*args, unsigned int);
	ft_putnbr(arg);
	return (ft_numlen(arg));
}
