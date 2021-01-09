/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 07:30:18 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/03 11:10:56 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"

static void			handle_keys(t_update *d)
{
	if (d->key_table[SDL_SCANCODE_ESCAPE])
		d->input.game = 0;
	 if (d->key_table[SDL_SCANCODE_LSHIFT])
		 d->input.crouch = 1;
	 if (d->key_table[SDL_SCANCODE_SPACE])
		 d->input.jump = 1;
	 if (d->key_table[SDL_SCANCODE_DOWN])
		 d->input.look_down = 1;
	 if (d->key_table[SDL_SCANCODE_UP])
		 d->input.look_up = 1;
	 if (d->key_table[SDL_SCANCODE_S])
		 d->input.move_back = 1;
	 if (d->key_table[SDL_SCANCODE_A])
		 d->input.move_left = 1;
	 if (d->key_table[SDL_SCANCODE_D])
		 d->input.move_right = 1;
	 if (d->key_table[SDL_SCANCODE_W])
		 d->input.move_forw = 1;
	 if (d->key_table[SDL_SCANCODE_RIGHT])
		 d->input.rot_right = 1;
	 if (d->key_table[SDL_SCANCODE_LEFT])
		 d->input.rot_left = 1;
}

void		process_input(t_update *d)
{
	SDL_Event   event;

	SDL_PollEvent(&event);
	d->key_table = (char*)SDL_GetKeyboardState(NULL);
	if (event.type == SDL_QUIT)
		exit(EXIT_SUCCESS); // need more
	handle_keys(d);
}
