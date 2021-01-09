/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_utilfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:29:55 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/29 17:37:49 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./alg.h"


t_vect3		ft_vectoradd(t_vect3 a, t_vect3 b)
{
	t_vect3	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vect3		ft_vectormulti(t_vect3 c, double scalar)
{
	c.x *= scalar;
	c.y *= scalar;
	c.z *= scalar;
	return (c);
}

t_vect3		ft_vectorsub(t_vect3 a, t_vect3 b)
{
	t_vect3	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}
