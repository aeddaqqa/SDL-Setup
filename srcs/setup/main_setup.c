/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:52:53 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/09 15:13:58 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/headers.h"


void		init_keys(t_doom *d)
{
	d->upt.input.jump = false;
	d->upt.input.crouch = false;
	d->upt.input.look_up = false;
	d->upt.input.mouse_up = false;
	d->upt.input.rot_left = false;
	d->upt.input.rot_right = false;
	d->upt.input.move_back = false;
	d->upt.input.move_forw = false;
	d->upt.input.move_left = false;
	d->upt.input.look_down = false;
	d->upt.input.mouse_down = false;
	d->upt.input.mouse_left = false;
	d->upt.input.move_right = false;
	d->upt.input.mouse_right = false;
}

int		*convert_color(char *pixels, int w, int h , int bbp)
{
	int *data;
	int i;
	int r;
	int g;
	int b;
	int a;
	int cmp;

	data= malloc(sizeof(int) * w * h);
	i = 0;
	cmp = 0;
	while (i < w * h)
	{
		r = pixels[cmp++] & 255;
		g = pixels[cmp++] & 255;
		b = pixels[cmp++] & 255;
		if (bbp != 3)
			a = pixels[cmp++] & 255;
		data[i] = ((a << 24) | (r << 16) | (g << 8) | b);
		i++;
	}
	return (data);
}

static void			init_sdl(t_sdl *sdl, int w, int h)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	sdl->win_ptr = SDL_CreateWindow("Doom Nukem 3D",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED,
	w, h, SDL_WINDOW_SHOWN);
	sdl->ren_ptr = SDL_CreateRenderer(sdl->win_ptr, -1, 0);
	sdl->tex_ptr = SDL_CreateTexture(sdl->ren_ptr, SDL_PIXELFORMAT_ARGB8888,
	SDL_TEXTUREACCESS_STREAMING, w, h);
}

void			setup(t_doom *d)
{
	SDL_Surface *s;

	s = IMG_Load("resources/earthmap.jpg");
	printf("%d, %d\n", s->w, s->h);
	printf("the bpp :%d\n", s->format->BytesPerPixel);
	printf("the pitch :%d\n", s->pitch);
	d->tex = convert_color((char*)s->pixels, s->w, s->h, s->format->BytesPerPixel);
	d->w = s->w;
	d->h = s->h;
	d->rend.data = d->tex;
	init_sdl(&d->sdl, d->w, d->h);
	d->upt.input.game = true;
}