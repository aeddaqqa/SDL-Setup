/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect3_utilfun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:30:10 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/29 17:34:50 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg.h"

t_vect3		ft_crossproduct(t_vect3 a, t_vect3 b)
{
	t_vect3	c;

	c.x = (a.y * b.z) - (a.z * b.y);
	c.y = (a.z * b.x) - (a.x * b.z);
	c.z = (a.x * b.y) - (a.y * b.x);
	return (c);
}

double		ft_dotproduct(t_vect3 a, t_vect3 b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double		ft_magnitude(t_vect3 v)
{
	t_vect3	c;

	c.x = v.x * v.x;
	c.y = v.y * v.y;
	c.z = v.z * v.z;
	return (sqrt(c.x + c.y + c.z));
}

t_vect3		ft_negative(t_vect3 v)
{
	t_vect3	c;

	c.x = -1.0 * v.x;
	c.y = -1.0 * v.y;
	c.z = -1.0 * v.z;
	return (c);
}

t_vect3		ft_normalize(t_vect3 v)
{
	double	magnitude;

	magnitude = sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
	v.x /= magnitude;
	v.y /= magnitude;
	v.z /= magnitude;
	return (v);
}
