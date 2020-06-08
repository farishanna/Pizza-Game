#include "common.h"

static void tick(void);
static void touch(Entity *other);

void initEnemy(char *line) // We defined initEnemy in the common.h file
{
	Entity *e;

	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;

	sscanf(line, "%*s %f %f", &e->x, &e->y);

	e->health = 1;

	e->texture = loadTexture("gfx/enemy.png"); // We added enemy.png for picture
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->flags = EF_WEIGHTLESS;
	e->tick = tick;
	e->touch = touch;
}

static void tick(void)
{
	self->value += 0.1;

	self->x += sin(self->value); // We replace to x to make enemy go left & right
}

static void touch(Entity *other)
{
	if (self->health > 0 && other == player)
	{
		other->health = 0; // We use other to end the program if the enemy is touched
	}
}