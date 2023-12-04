/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olamrabt <olamrabt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:33:49 by olamrabt          #+#    #+#             */
/*   Updated: 2023/12/04 18:55:16 by olamrabt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *str, ...);
int	handle_spe(char sp, va_list ap);
int	print_str(char *str);
int	print_base(long nbr, int base, int to_upper);
int	print_adr(unsigned long long unbr);

#endif