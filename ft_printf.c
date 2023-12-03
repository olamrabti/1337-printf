/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:31:28 by olamrabt          #+#    #+#             */
/*   Updated: 2023/12/03 18:52:39 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list ap;
    int count;
    int i;
    
    count = 0;
    i = 0;
    va_start(ap, str);
    while(str[i])
    {
        while (str[i] && str[i] != '%')
            count += write(1, &str[i++], 1);
        if (str[i] && str[i++] == '%')
        {
            if (str[i] && str[i]!= '%')
                count += handle_spe(str[i++], ap);
            else if (str[i])
                count += write(1, &str[i++], 1);
        }
        else if (str[i])
        {
            count += handle_spe(str[i], ap);
            i = count + 1;
        }
    }
    va_end(ap);
    return count; 
}