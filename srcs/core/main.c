/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 05:19:40 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/09 09:47:54 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int		main(int ac, char **av)
{
	t_doom *d;

	if (ac && av[0])
	{
		d = malloc(sizeof(t_doom));
		setup(d);
		while (d->upt.input.game)
		{
			process_input(&d->upt);
			update(d);
			render(d);
			init_keys(d);
		}
	}
	return (0);
}
