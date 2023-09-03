/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:48:25 by orudek            #+#    #+#             */
/*   Updated: 2023/04/05 17:02:29 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(const char **string, va_list *args)
{
	(*string)++;
	if (**string == 'c')
		return (ft_print_char(args));
	else if (**string == 's')
		return (ft_print_str(args));
	else if (**string == 'p')
		return (ft_print_ptr(args));
	else if (**string == 'd' || **string == 'i')
		return (ft_print_int(args));
	else if (**string == 'u')
		return (ft_print_uint(args));
	else if (**string == 'x')
		return (ft_print_hex(args, 0));
	else if (**string == 'X')
		return (ft_print_hex(args, 1));
	else if (**string == '%')
		return (ft_print_percentage());
	return (0);
}

int	ft_printf(char const *string, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string == '%')
		{
			len += ft_conversion(&string, &args);
			if (!*string)
				break ;
		}
		else
		{
			write(1, string, 1);
			len++;
		}
		string++;
	}
	va_end(args);
	return (len);
}
