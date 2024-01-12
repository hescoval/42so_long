/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hescoval <hescoval@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 08:03:49 by hescoval          #+#    #+#             */
/*   Updated: 2024/01/12 08:32:03 by hescoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_l.h"

int close_window(int mask, void *visuals)
{
    (void)mask;
    
    graphics *real = (graphics *) visuals;
    cleanup(real);
    exit(1);
    return(0);
}