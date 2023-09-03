/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:21:31 by orudek            #+#    #+#             */
/*   Updated: 2023/04/05 14:24:48 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_dir(void *addr)
{
	char	i;
	int		value;
	char	flag;
	char	len;

	len = 2;
	flag = 0;
	i = sizeof (void *) * 2 - 1;
	write(1, "0x", 2);
	while (i >= 0)
	{
		value = (long int)addr >> (i * 4) & 0x0f;
		if (value)
			flag = 1;
		if (i == 0 || flag)
		{
			write(1, &"0123456789abcdef"[(int)value], 1);
			len ++;
		}
		i--;
	}
	return (len);
}

int	ft_print_ptr(va_list *args)
{
	return (ft_print_dir(va_arg(*args, void *)));
}
