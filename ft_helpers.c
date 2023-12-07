/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:45:42 by olamrabt          #+#    #+#             */
/*   Updated: 2023/12/07 11:10:32 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_base(long n, int b, int to_up)
{
	char	*b_str;

	b_str = "0123456789abcdef";
	if (to_up)
		b_str = "0123456789ABCDEF";
	if (n < 0)
		return (write(1, "-", 1) + print_base(-n, b, to_up));
	if (n < b)
		return (write(1, &b_str[n], 1));
	return (print_base(n / b, b, to_up) + print_base(n % b, b, to_up));
}

int	print_adr(unsigned long long un)
{
	if (un < 16)
		return (print_base(un, 16, 0));
	return (print_adr(un / 16) + print_adr(un % 16));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (print_str("(null)"));
	while (str[count])
		count += write(1, &str[count], 1);
	return (count);
}

int	handle_spe(char sp, va_list ap)
{
	char	c;

	if (sp == 'c')
	{
		c = (char)va_arg(ap, int);
		return (write(1, &c, 1));
	}
	if (sp == 's')
		return (print_str(va_arg(ap, char *)));
	if (sp == 'd' || sp == 'i')
		return (print_base(va_arg(ap, int), 10, 0));
	if (sp == 'u')
		return (print_base(va_arg(ap, unsigned int), 10, 0));
	if (sp == 'x')
		return (print_base(va_arg(ap, unsigned int), 16, 0));
	if (sp == 'X')
		return (print_base(va_arg(ap, unsigned int), 16, 1));
	if (sp == 'p')
		return (print_str("0x") + print_adr(va_arg(ap, unsigned long long)));
	c = (char)va_arg(ap, int);
	return (write(1, &c, 1));
}

int	check_w(void)
{
	return (write(1, "", 0));
}
