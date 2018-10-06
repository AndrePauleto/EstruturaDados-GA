#include "Mago.h"

Mago::Mago(float x, float y)
{
	this->x = x;
	this->y = y;
	this->setSpriteSheet("Mage");
	this->setPos(this->x, this->y);
}


Mago::~Mago()
{
}

void Mago::atacar()
{
	BolaFogo bolaFogo  = BolaFogo();
	int tamanhoTile = 32;
	bolaFogo.inicializar(this->getXCentro() * tamanhoTile, this->getYCentro() * tamanhoTile, 3, "Mage", this->direcao);
	this->bolaFogoRepository.add(bolaFogo);
	this->bolaFogoRepository.atualizar();
	this->bolaFogoRepository.desenhar();
}

void Mago::atualizar()
{
	Personagem::atualizar();
	this->bolaFogoRepository.atualizar();
	this->bolaFogoRepository.desenhar();
}
