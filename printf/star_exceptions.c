/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   star_exceptions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmartine <gmartine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 12:12:42 by gmartine          #+#    #+#             */
/*   Updated: 2019/12/15 13:07:37 by gmartine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	star_exceptions(t_list_flags *flags)
{
	if (flags->precision.active == 1 && flags->precision.star)
		flags->precision.active = 0;
	if (flags->sign.active)
		;
	else if (flags->cero.active && flags->cero.star == 1)
	{
		flags->sign.active = 1;
		flags->sign.number = flags->cero.number;
	}
	else if (flags->minimum.active && flags->minimum.star == 1)
	{
		flags->sign.active = 1;
		flags->sign.number = flags->minimum.number;
	}
}
