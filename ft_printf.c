/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:31:28 by olamrabt          #+#    #+#             */
/*   Updated: 2023/12/04 18:55:22 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, str);
	if (write(1, "", 0) == -1)
		return (-1);
	while (*str)
	{
		if (*str == '%' && (*(++str) != '%'))
			count += handle_spe(*(str++), ap);
		else
			count += write(1, str++, 1);
	}
	va_end(ap);
	return (count);
}
