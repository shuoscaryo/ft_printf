/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:03:17 by orudek            #+#    #+#             */
/*   Updated: 2023/04/05 14:37:05 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int	ft_printf(char const *string, ...);

int	ft_print_char(va_list *args);
int	ft_print_str(va_list *args);
int	ft_print_ptr(va_list *args);
int	ft_print_int(va_list *args);
int	ft_print_uint(va_list *args);
int	ft_print_hex(va_list *args, char mayus);
int	ft_print_HEX(va_list *args);
int	ft_print_percentage(void);

#endif