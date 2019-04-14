/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 13:55:11 by viwade            #+#    #+#             */
/*   Updated: 2019/04/14 03:49:06 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef t_param	t_context_t;

static int
	set_flags(char *set, const char *s)
{
	uint	i;
	char	*str;

	i = 0;
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
    uint    i;

    i = 0;
	w[0] = 0;
	if (s[i] == '*')
		w[0] = va_arg(o->arg, int);
	else if (ft_isdigit(s[i]))
		w[0] = ft_atoi(&s[i]);
    i += (s[i] == '*') ? 1 : ft_intlen(w[0]);
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
	set_specifier(uint8_t sb, char set, const char *s)
{
    ;
}

int
	get_params(t_format *obj, t_param *set)
{
	uint64_t	i;
	char    *format;

	i = 0;
    format = obj->str;
	{
		i += (format[i] == '%');
		i += set_flags(set->flags, &format[i]);
		i += set_width(&set->width, &set->precision, &format[i], obj);
		i += set_specifier(set->sub, set->spec, &format[i]);
	}
	return (error ? -1 : set->param_len);
}

/*
**	^^^^	Short file which will tell ft_printf what to do		^^^^
*/
