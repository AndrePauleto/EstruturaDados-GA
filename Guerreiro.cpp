#include "Guerreiro.h"

Guerreiro::Guerreiro(float x, float y)
{
	//this->mapa = mapa;
	this->x = x;
	this->y = y;
	this->setSpriteSheet("Knight");

	this->setPos(this->x, this->y);
	this->vel = 1;

}


Guerreiro::~Guerreiro()
{
}

void Guerreiro::atacar()
{
	gDebug.depurar("ATACAR GUERREIRO", true);
}
