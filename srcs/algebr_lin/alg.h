/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:29:10 by aeddaqqa          #+#    #+#             */
/*   Updated: 2020/12/29 17:38:00 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALG_H
#define ALG_H

#include 		"../../includes/headers.h"
double			ft_magnitude(t_vect3 v);
t_vect3			ft_normalize(t_vect3 v);
t_vect3			ft_negative(t_vect3 v);
double			ft_dotproduct(t_vect3 a, t_vect3 b);
t_vect3			ft_crossproduct(t_vect3 a, t_vect3 b);
t_vect3			ft_vectoradd(t_vect3 a, t_vect3 b);
t_vect3			ft_vectorsub(t_vect3 a, t_vect3 b);
t_vect3			ft_vectormulti(t_vect3 c, double scalar);

#endif