/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 06:01:13 by viwade            #+#    #+#             */
/*   Updated: 2019/05/09 08:59:37 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_printf.h"

/*
**		STRING
*/

int		parse_s(va_list args, t_format *o)
{
	char	*s;
	size_t	len;

	s = (char *)va_arg(args, char *);
	if (!s)
		return (ftprintf_write("(null)", 6, o));
	if (o->p.precision && o->p.precision <= (len = ft_strlen(s)))
		return (ftprintf_write(s, len = o->p.precision, o));
	else
		return (ftprintf_write(s, len, o));
}
