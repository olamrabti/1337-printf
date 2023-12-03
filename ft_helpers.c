/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:45:42 by olamrabt          #+#    #+#             */
/*   Updated: 2023/12/03 18:08:02 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_nbr_base(long nbr, int base, int to_upper)
{
    char *base_str;

    base_str = "0123456789abcdef";
    if (to_upper)
        base_str = "0123456789ABCDEF";
    if (nbr < 0)
        return (write(1, "-", 1) + print_nbr_base(-nbr, base, to_upper));
    else if (nbr < base)
        return write(1, &base_str[nbr], 1);
    else
        return print_nbr_base(nbr / base, base, to_upper) + print_nbr_base(nbr % base, base, to_upper);
}
int print_str(char *str)
{
    int count;
    count = 0;
    if(!str)
        return print_str("(null)");
    while (str[count])
        count += write(1, &str[count], 1);
    return count;
}
int handle_spe(char sp, va_list ap)
{
    char c;
    if (sp == 'c')
    {
        c = (char)va_arg(ap, int);
        return write(1, &c, 1);
    }
    if (sp == 's')
        return print_str(va_arg(ap, char *));
    if (sp == 'd' || sp == 'i')
        return print_nbr_base(va_arg(ap, int), 10, 0);
    if (sp == 'u')
        return print_nbr_base(va_arg(ap, unsigned int), 10, 0);
    if (sp == 'x')
        return print_nbr_base(va_arg(ap, unsigned int), 16, 0);
    if (sp == 'X')
        return print_nbr_base(va_arg(ap, unsigned int), 16, 1);
    if (sp == 'p')
        return print_str("0x") + print_nbr_base(va_arg(ap, unsigned int), 16, 0);
    c = (char)va_arg(ap, int);
    return write(1, &c, 1);
}
