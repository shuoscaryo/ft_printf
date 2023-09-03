/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:01:09 by orudek            #+#    #+#             */
/*   Updated: 2023/09/03 14:22:42 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned int nbr, const char *base)
{
	if (nbr >= 16)
		ft_puthex(nbr / 16, base);
	nbr %= 16;
	write(1, &base[nbr], 1);
}

static int	ft_numlen(unsigned int nbr)
{
	int	len;

	len = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		len ++;
	}
	return (len);
}

int	ft_print_hex(va_list *args, char mayus)
{
	unsigned int	nbr;

	nbr = va_arg(*args, unsigned int);
	if (mayus)
		ft_puthex(nbr, "0123456789ABCDEF");
	else
		ft_puthex(nbr, "0123456789abcdef");
	return (ft_numlen(nbr));
}
