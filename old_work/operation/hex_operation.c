/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/09/04 00:23:33 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define PLUS(n) ((n) & (1 << 0))
#define MINUS(n) ((n) & (1 << 1))
#define ZERO(n) ((n) & (1 << 2))
#define HASH(n) ((n) & (1 << 3))
#define SPACE(n) ((n) & (1 << 4))
#define U_HH(n)	n = (unsigned char)(n)
#define U_H(n)	n = (unsigned short)(n)
#define U_L(n)	n = (unsigned long)(n)
#define U_LL(n)	n = (unsigned long long)(n)
#define CHH(a)	(a & hh)
#define CH(a)	(a & h)
#define CL(a)	(a & l)
#define CLL(a)	(a & ll)
#define U_LENGTH(a, n, t)	if(a){t}else{n = (unsigned)n;}

/*
**		OCTAL / HEX
*/

static FT_SIZE
	convert_x(t_format *o)
{
	char	u;

	u = ft_tolower(o->str[0]);
	MATCH(u == 'b', u = 2);
	ELSE(u = 16 >> (u == 'o'));
	o->v = ft_itoa_base(*(ull_t*)o->v, u);
	MATCH(u == 16 && ANY2(o->str[0], 'X', 'P'),
		ft_strcapitalize(o->v));
	precision_i(o);
	width_o(o);
	append_s(o);
	return (1);
}

/*
**	Conditions already taken care of.
**	Input specifier shall be o / O / x / X / p / P
**	Output shall be in in either base 16, or base 8 if o / O is given
*/

int
	parse_x(t_format *o)
{
	ull_t	num;

	o->v = &num;
	o->p.length = ft_isuppercase(o->str[0]) ? ll : o->p.length;
	if (ft_tolower(o->str[0]) == 'p')
	{
		num = (ull_t)(intptr_t)va_arg(o->ap, intptr_t);
		o->p.flags |= hash;
	}
	else
		cast_o(o);
	return (convert_x(o));
}
