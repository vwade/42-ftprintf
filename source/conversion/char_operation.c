/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/31 09:57:03 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		CHAR
*/

static FT_SIZE
	convert_c(t_format *o)
{
	uint	c[2];
	size_t	ret;

	c[0] = o->str[0] == '%' ? '%' : va_arg(o->arg, int);
	if (!(o->v = encode_utf8(c)))
		ft_error("Memory allocation failure. Exiting.");
	ret = 0;
	o->p.width = (LL)MAX(o->p.width - ft_strlen(o->v), 0);
	modify_o(o, "pad");
	ret = write(1, o->v, ft_strlen(o->v));
	free (o->v);
	return (ret);
}

/*
**	Returns number of bytes written to stdout.
**
**	If a length is specified, a null-terminated wchar_t is retrieved.
**	An uppercase specifier (C) is treated as if the length flag was given.
**	Otherwise, a null-terminated char is retrieved.
*/
int		parse_c(t_format *o)
{
	return (convert_c(o));
}