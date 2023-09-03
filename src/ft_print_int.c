/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:23:37 by orudek            #+#    #+#             */
/*   Updated: 2023/03/31 14:07:21 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlen(int nbr)
{
	int	len;

	len = 1 + (nbr < 0);
	while (nbr < -9 || nbr > 9)
	{
		nbr /= 10;
		len ++;
	}
	return (len);
}

int	ft_print_int(va_list *args)
{
	int	arg;

	arg = va_arg(*args, int);
	ft_putnbr_fd(arg, 1);
	return (ft_numlen(arg));
}
