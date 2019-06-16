/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 18:05:10 by viwade            #+#    #+#             */
/*   Updated: 2019/06/16 13:19:19 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#define A_M(a, b) ((a) & (b))
#define B_M(a, b) (!((a) & (b)))
#define C_M(a,b,c) (A_M(a,b) && B_M(a,c))
#define SIGN_M(f,a,b,c) C_M(f,a,c)?'+':C_M(f,b,c)?' ':'-'

/*
**	Ensure o->v is allocated before use.
*/

/*
**	Produces a sign
**	If the number is negative, the sign is shifted to the left of all zeros.
**	If padding length is zero, no modifications to value are made.
**	If no precision is given, no modifications are made.
*/

static void
	sign_i(t_format *o)
{
	char	*sign;

	if (!((plus + space) & o->p.flags))
		return ;
	sign = (char[2]){SIGN_M(o->p.flags, plus, space, neg), 0};
	o->v = ft_strjoin_free(ft_strdup(sign), o->v);
}

/*
**	Creates a zero-padded number.
**	If the number is negative, the sign is shifted to the left of all zeros.
**	If padding length is zero, no modifications to value are made.
**	If no precision is given, no modifications are made.
*/

size_t	precision_o(t_format *o)
{
	if (o->p.tick & 4)
		o->p.precision = MIN(ft_strlen(o->v), o->p.precision);
	else
		o->p.precision = ft_strlen(o->v);
	return (o->len = o->p.precision);
}

void	precision_i(t_format *o)
{
	char	*z;
	size_t	len;

	precision_o(o);
	if (!(o->p.tick & 4))
		;
	len = MAX(o->p.precision - ft_strlen(o->v), 0);
	if (!len)
		;
	z = ft_memset(ft_strnew(len), '0', len);
	if ((neg + plus + space) & o->p.flags)
	{
		if (ft_strchr("diefga", ft_tolower(*o->str)))
			sign_i(o);
		if (len && neg & o->p.flags)
			ft_memswap(&((char*)o->v)[0], &z[0]);
	}
	o->v = ft_strjoin_free(z, o->v);
}

void	precision_s(t_format *o)
{
	if (o->p.length & (l + ll) || ft_isuppercase(o->str[0]))
	{
		if (o->p.tick & 4)
			o->v = encode_utf8_w(str_utf8(o->v), o->p.precision);
		else
			o->v = encode_utf8(str_utf8(o->v));
	}
	else
	{
		if (o->p.tick & 4)
			o->v = ft_strsub(o->v, 0, o->p.precision);
		else
			o->v = ft_strdup(o->v);
	}
	o->len = ft_strlen(o->v);
}
