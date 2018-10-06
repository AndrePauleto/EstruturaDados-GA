#include "Ladino.h"

Ladino::Ladino(float x, float y)
{
	this->x = x;
	this->y = y;
	this->setSpriteSheet("Thief");
	this->setPos(this->x, this->y);
	this->vel = 3;
}


Ladino::~Ladino()
{
}

void Ladino::atacar()
{
	this->ataque = true;
	this->setVisivel(false);
	this->tempo = 60;
}

void Ladino::atualizar()
{
	Personagem::atualizar();

	if (this->ataque) {
		this->tempo--;
	}

	if (this->tempo < 0) {
		this->ataque = false;
		this->setVisivel(true);
		this->tempo = 0;
	}
}



