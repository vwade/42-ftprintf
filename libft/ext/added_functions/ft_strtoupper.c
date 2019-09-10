/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:38:35 by viwade            #+#    #+#             */
/*   Updated: 2019/09/10 05:32:10 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void
	ft_strtoupper(char **str)
{
	size_t	i;

	if ((i = !(str && str[0])))
		return ;
	while (str[0][i])
	{
		if ('a' <= str[0][i] && str[0][i] <= 'z')
			str[0][i] -= 32;
		i++;
	}
}
