/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:31:28 by olamrabt          #+#    #+#             */
/*   Updated: 2023/12/07 11:11:39 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = check_w();
	va_start(ap, str);
	while (count >= 0 && *str)
	{
		while (*str && *str != '%')
			count += write(1, str++, 1);
		if (*str && *(str++) == '%')
		{
			if (*str && *str != '%')
				count += handle_spe(*str++, ap);
			else if (*str)
				count += write(1, str++, 1);
		}
		else if (*str)
		{
			count += handle_spe(*str, ap);
			str += count + 1;
		}
	}
	va_end(ap);
	return (count);
}
