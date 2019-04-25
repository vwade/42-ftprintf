/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/04/25 07:56:10 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		CHAR
*/

int		parse_c(va_list args, t_format *o)
{
	unsigned char	c;

	c = (unsigned char)va_arg(args, int);
	write(1, &c, 1);
	o->count += 1;
	o->str++;
	return (1);
}

/*
**		STRING
*/

int		parse_s(va_list args, t_format *o)
{
	char	*s;
	size_t  len;

	s = (char *)va_arg(args, char *);
	len = ft_strlen(s);
	if (!!o->p.precision && o->p.precision <= len)
		write(1, s, len = o->p.precision);
	else
		write(1, s, len);
	o->count += len;
	o->str++;
	return (len);
}
