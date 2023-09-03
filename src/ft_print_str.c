/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:21:09 by orudek            #+#    #+#             */
/*   Updated: 2023/04/05 13:35:44 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list *args)
{
	size_t	len;
	char	*arg;

	arg = va_arg(*args, char *);
	if (arg == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(arg);
	write (1, arg, len);
	return (len);
}
