/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:36:03 by viwade            #+#    #+#             */
/*   Updated: 2019/09/02 15:46:45 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Complete rewrite incoming.
*/

int
	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	length[1];

	va_start(ap, format);
	length[0] = ft_vprintf(format, ap) || 0;
	va_end(ap);
	return (length[0]);
}