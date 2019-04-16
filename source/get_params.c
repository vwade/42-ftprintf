/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:55:11 by viwade            #+#    #+#             */
/*   Updated: 2019/04/15 20:21:15 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef t_param	t_context_t;

static int
	set_flags(char *set, const char *s, uint i)
{
	set[0] = 0;
	while (s[i++])
		if (s[i - 1] == plus)
			set[0] |= 1 << 0;
		else if (s[i - 1] == minus)
			set[0] |= 1 << 1;
		else if (s[i - 1] == zero)
			set[0] |= 1 << 2;
		else if (s[i - 1] == hash)
			set[0] |= 1 << 3;
		else if (s[i - 1] == space)
			set[0] |= 1 << 4;
		else
			return (i - 1);
	return (i);
}

static int
	set_width(uint *w, uint *p, const char *s, t_format *o)
{
	uint	i;

	i = 0;
	w[0] = 0;
	if (s[i] == '*')
		w[0] = va_arg(o->arg, int);
	else if (ft_isdigit(s[i]))
		w[0] = ft_atoi(&s[i]);
	i += (s[i] == '*') || ft_isdigit(s[i]) ? ft_intlen(w[0]) : 0;
	if (s[i++] != '.')
		return (i - 1);
	 if (s[i] == '*')
		p[0] = va_arg(o->arg, int);
	else if (ft_isdigit(s[i]))
		p[0] = ft_atoi(&s[i]);
	i += (s[i] == '*') ? 2 : ft_intlen(p[0]);
	return (i);
}

static int
	set_length(uint8_t *l, const char *s, uint i)
{
	l[0] = 0;
	if (s[i] == 'h')
		l[0] |= ((s[i + 1] == 'h') * hh) || h;
	else if (s[i] == 'l')
		l[0] |= ((s[i + 1] == 'l') * ll) || l;
	else if (s[i] == 'j')
		l[0] |= j;
	else if (s[i] == 'j')
		l[0] |= z;
	i += (s[i + 1] == 'h' || s[i + 1] == 'l') ? 2 : 1;
	return (i);
}

static void
	get_function_operator(t_format *o, t_param *p, uint	i)
{
	while (g_dispatch[i++].type)
		if ()
}

int32_t
	get_params(t_format *obj, t_param *set)
{
	uint64_t	i;
	char	*format;

	i = 0;
	format = obj->str;
	{
		i += (format[i] == '%');
		i += set_flags(&set->flags, &format[i], 0);
		i += set_width(&set->width, &set->precision, &format[i], obj);
		i += set_length(&set->length, &format[i], 0);
		i += get_function_operator(obj, set, &format[i]);
	}
	return (error ? -1 : set->param_len);
}

/*
**	^^^^	Short file which will tell ft_printf what to do		^^^^
*/
