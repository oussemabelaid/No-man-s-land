
void updatePlayer(Hero* hero , Acteurs* acteurs, SDL_Rect camera)
{
	if(acteurs->event.type == SDL_MOUSEBUTTONDOWN)
	{
		if(acteurs->event.button.button == SDL_BUTTON_RIGHT)
		{
			if(hero->etat == IMMOBILE || hero->etat == WALK_LEFT)
			{
				hero->etat = WALK_RIGHT;
			}
			if(hero->direction == LEFT)
				{
					hero->direction = RIGHT ;
				}
			hero->sprite = IMG_Load("sprite_hero_right.png") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->x += PLAYER_SPEED ;
			//*frame = AnimationHeroRight(*hero, *acteurs);

			if (hero->x + PLAYER_WIDTH >= Backg_W)
				{
					hero->x = Backg_W - PLAYER_WIDTH ;
				}
		}
		else if(acteurs->event.button.button == SDL_BUTTON_LEFT)
		{
			if(hero->etat == IMMOBILE || hero->etat == WALK_RIGHT)
			{
				hero->etat = WALK_LEFT;
			}
			if(hero->direction == RIGHT)
				{
					hero->direction = LEFT ;
				}
			hero->sprite = IMG_Load("sprite_hero_left.png") ;
			SDL_SetColorKey(hero->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(hero->sprite->format, 255, 255, 255));
			hero->x -= PLAYER_SPEED ;
			//*frame = AnimationHeroLeft(*hero, *acteurs);
            if (hero->x < 0)
				{
					hero->x = 0 ;
				}
		}
	}
	else if(acteurs->event.type == SDL_MOUSEBUTTONUP)
	{
		if(hero->etat != IMMOBILE)
		{
			hero->etat = IMMOBILE;
		}
	}
	//centerScrollingOnPlayer(*hero, acteurs, &camera);

}

void initializeEntite(Entite* entitee)
{
	SDL_Surface* tmp;

	tmp = SDL_LoadBMP("sprite_enemy_right.bmp");
	entitee->sprite = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	SDL_SetColorKey(entitee->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(entitee->sprite->format, 255, 255, 255));


	//Indique l'état et la direction de notre enemy
	entitee->direction = RIGHT;
	entitee->etat = IMMOBILE;

	//Réinitialise le timer de l'animation et la frame
	entitee->frame_timer = TIME_BETWEEN_2_FRAMES;
	entitee->frame_number = 0;

	/* Coordonnées de démarrage de notre enemies */
	entitee->x = 0 ;
	entitee->y = 0 ;

}
void drawEntite( Entite* entitee, Acteurs* acteurs)
{


/* Rectangle de destination à blitter */
SDL_Rect dest;
dest.x = entitee->x;
dest.y = entitee->y ;


/* Rectangle source à blitter */
SDL_Rect src ;
src.x = 0 ;
src.y = 0 ;
src.w = ENEMY_Width ;
src.h = ENEMY_Height ;

/* Blitte notre héros sur l'écran aux coordonnées x et y */

SDL_BlitSurface(entitee->sprite , &src , acteurs->screen , &dest) ;
SDL_SetColorKey(entitee->sprite, SDL_SRCCOLORKEY, SDL_MapRGB(entitee->sprite->format, 255, 255, 255));
}

