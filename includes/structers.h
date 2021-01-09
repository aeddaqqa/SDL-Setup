/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structers.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:11:47 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/09 09:44:36 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTERS_H
#define STRUCTERS_H

typedef struct		s_vec3
{
	double			x;
	double			y;
	double			z;
}					t_vect3;

typedef t_vect3 	t_point;

typedef struct		s_input
{
	bool			game;
	bool			jump;
	bool			crouch;
	bool			look_up;
	bool			look_down;
	bool			rot_left;
	bool			rot_right;
	bool			move_left;
	bool			move_right;
	bool			move_forw;
	bool			move_back;
	bool			mouse_up;
	bool			mouse_down;
	bool			mouse_right;
	bool			mouse_left;
}					t_input;

typedef struct		s_sdl
{
	SDL_Window		*win_ptr;
	SDL_Texture		*tex_ptr;
	SDL_Renderer	*ren_ptr;
	SDL_Surface		*sur_ptr;
}					t_sdl;

typedef struct		s_render
{
	int				*data;
}					t_render;

typedef struct		s_update
{
	t_input			input;
	char			*key_table;
}					t_update;



typedef struct		s_doom
{
	t_sdl			sdl;
	t_render		rend;
	t_update		upt;
	int				*tex;
	int				w;
	int				h;
}					t_doom;

#endif
