/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:36:03 by viwade            #+#    #+#             */
/*   Updated: 2019/04/14 02:46:52 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int
    ft_printf(const char *format, ...)
{
    t_format    obj;

    va_start(obj.args, format);
    parse_input(obj, obj.string = format);
    va_end(obj.args);
    return (obj.count);
}