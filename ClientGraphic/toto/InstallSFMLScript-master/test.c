/*
** test.c for test in /home/aracthor/game_dev_lab/2019/exemples/window
** 
** Made by 
** Login   <aracthor@epitech.net>
** 
** Started on  Thu Nov 13 18:20:16 2014 
** Last Update Thu Nov 13 19:32:53 2014 
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdio.h>
#include <unistd.h>

void	gere_data()
{
}

void		gere_events(sfRenderWindow* window, sfCircleShape* shape)
{
  sfEvent	event;
  sfVector2f	vector;

  while (sfRenderWindow_pollEvent(window, &event))
    {
      if (event.type == sfEvtClosed)
	sfRenderWindow_close(window);
      else if (event.type == sfEvtKeyPressed)
	{
	  printf("PRESSED : %d\n", event.key.code);
	  if (event.key.code == sfKeyEscape)
	    sfRenderWindow_close(window);
	}
      else if (event.type == sfEvtKeyReleased)
	{
	  printf("RELEASED : %d\n", event.key.code);
	}
      else if (event.type == sfEvtMouseButtonPressed)
	{
	  printf("PRESSED : %d : %d,%d\n",
		 event.mouseButton.button,
		 event.mouseButton.x, event.mouseButton.y);
	}
    }


  if (sfKeyboard_isKeyPressed(sfKeyDown))
    {
      vector.x = 0;
      vector.y = 1;
      sfCircleShape_move(shape, vector); /* Fais bouger l'objet */
      sfCircleShape_rotate(shape, 10); /* Fais tourner l'objet */
      vector.x = 1.1;
      vector.y = 1.1;
      sfCircleShape_scale(shape, vector); /* Resize l'objet */
      /* Merci captain obivious pour les commentaires */
    }
}

void	gere_display(sfRenderWindow* window, sfCircleShape* shape)
{
  sfRenderWindow_clear(window, sfBlack);

  sfRenderWindow_drawCircleShape(window, shape, NULL);

  sfRenderWindow_display(window);
}

void	loop(sfRenderWindow* window, sfCircleShape* shape)
{
  while (sfRenderWindow_isOpen(window))
    {
      gere_data();
      gere_events(window, shape);
      gere_display(window, shape);
    }
}

int	main()
{
  sfRenderWindow*	window;
  sfVideoMode		mode;
  sfCircleShape*	shape;
  sfVector2f		vector;

  mode.width = 800;
  mode.height = 600;
  mode.bitsPerPixel = 32;

  window = sfRenderWindow_create(mode,
				 "Titre de la fenètre",
				 sfResize | sfClose,
				 NULL);
  shape = sfCircleShape_create();

  sfRenderWindow_setFramerateLimit(window, 60);

  sfCircleShape_setRadius(shape, 42);
  sfCircleShape_setFillColor(shape, sfRed);
  vector.x = 42;
  vector.y = 42;
  sfCircleShape_setPosition(shape, vector);
  vector.x = 3;
  vector.y = 1;
  sfCircleShape_scale(shape, vector);

  loop(window, shape);

  sfRenderWindow_destroy(window);

  return (0);
}
