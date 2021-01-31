/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 16:30:29 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/01/31 18:44:02 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./SDL2.framework/Headers/SDL.h"
#include "./SDL2_image.framework/Headers/SDL_image.h"
#include "./SDL2_ttf.framework/Headers/SDL_ttf.h"

typedef struct	s_sdl
{
	SDL_Window		*win_ptr;
	SDL_Texture		*tex_ptr;
	SDL_Renderer	*ren_ptr;
	SDL_Surface		*sur_ptr;
}				t_sdl;

#define W 800
#define H 800

#define COLOR_1 0x192a56
#define COLOR_2 0xfbc531
#define COLOR_3 0xf5f6fa /*wh*/
#define COLOR_4 0x2f3640

int			main(int ac, char **av)
{
	t_sdl		*sdl;
	int			loop;
	SDL_Event	event;
	char		*key_table;
	SDL_Rect	rect_1;
	SDL_Rect	rect_2;
	TTF_Font	*font;

	loop = 1;
	rect_1.x = 248;
	rect_1.y = 148;
	rect_1.h = 34;
	rect_1.w = 34;
	
	rect_2.x = 251;
	rect_2.y = 151;
	rect_2.h = 28;
	rect_2.w = 28;
	sdl = malloc(sizeof(t_sdl));
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	font = TTF_OpenFont("./great-vibes/GreatVibes-Regular.otf", 70);
	if (!font)
		exit(0);
	sdl->win_ptr = SDL_CreateWindow("Rt",\
	SDL_WINDOWPOS_CENTERED,\
	SDL_WINDOWPOS_CENTERED,\
	W, H, SDL_WINDOW_SHOWN);
	sdl->ren_ptr = SDL_CreateRenderer(sdl->win_ptr, -1, 0);
	sdl->tex_ptr = SDL_CreateTexture(sdl->ren_ptr, SDL_PIXELFORMAT_ARGB8888,
	SDL_TEXTUREACCESS_STREAMING, W, H);
	SDL_Color color = {0, 0, 0};
	SDL_Surface * surface = TTF_RenderText_Solid(font, "ilyass zamilon kabir", color);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(sdl->ren_ptr, surface);
	// int texW = 50;
	// int texH = 50;
	// SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
	// SDL_Rect dstrect = { 0, 0, texW, texH };
	// SDL_RenderCopy(sdl->ren_ptr, texture, NULL, &dstrect);
	while (loop)
	{
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				exit(EXIT_SUCCESS);
			key_table = (char*)SDL_GetKeyboardState(NULL);
			SDL_SetRenderDrawColor(sdl->ren_ptr, 0xf5, 0xf6, 0xfa, 0);/*R G B A*/
			SDL_RenderClear(sdl->ren_ptr);
			/*cadre*/
			SDL_SetRenderDrawColor(sdl->ren_ptr, 0xfb, 0xc5, 0x31, 0xff);/*R G B A*/
			SDL_RenderFillRect(sdl->ren_ptr, &rect_1);
			/*fill*/
			SDL_SetRenderDrawColor(sdl->ren_ptr, 0x19, 0x2a, 0x56, 200);/*R G B A*/
			SDL_RenderFillRect(sdl->ren_ptr, &rect_2);
			/*render present*/
			int texW = 0;
			int texH = 0;
			SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
			SDL_Rect dstrect = { 200, 200, texW, texH };
			SDL_RenderCopy(sdl->ren_ptr, texture, NULL, &dstrect);
			SDL_RenderPresent(sdl->ren_ptr);
			if (key_table[SDL_SCANCODE_ESCAPE])
				loop = 0;
		}
	}
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
	SDL_DestroyRenderer(sdl->ren_ptr);
	SDL_DestroyWindow(sdl->win_ptr);
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();
	return (0);
}
