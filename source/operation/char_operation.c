/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 22:34:13 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
**		CHAR
*/

static void
	width_c(t_format *o)
{
	MATCH(!o->p.width, RET);
	MATCH(!(o->p.width -= 1), RET);
	o->pad =
	ft_memset(ft_strnew(o->p.width), o->p.flags & zero ? '0' : ' ', o->p.width);
}

static FT_SIZE
	convert_c(t_format *o)
{
	MATCH(o->str[0] == '%', o->v = ft_strdup("%"));
	OR(!*(char *)o->v, o->v = ft_strdup("^@"));
	ELSE(o->v = encode_utf8((int[2]){*(ll_t *)o->v, 0}));
	precision_s(o);
	width_c(o);
	append_s(o);
	return (1);
}

/*
**	Returns number of bytes written to stdout.
**
**	If a length is specified, a null-terminated wchar_t is retrieved.
**	An uppercase specifier (C) is treated as if the length flag was given.
**	Otherwise, a null-terminated char is retrieved.
*/

int
	parse_c(t_format *o)
{
	ull_t	c;

	o->v = &c;
	MATCH(ft_isuppercase(o->str[0]), o->p.length = ll);
	MATCH(o->str[0] != '%', cast_o(o));
	return (convert_c(o));
}
