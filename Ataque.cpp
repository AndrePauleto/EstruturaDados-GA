#include "Ataque.h"
Ataque::Ataque() {};

Ataque::Ataque(int x, int y, float velocidade, string nomeSprite)
{
	this->inicializado = true;
	this->ativo = true;
	this->y = y;
	this->x = x;
	this->velocidade = velocidade;
	this->sprite.setSpriteSheet(nomeSprite);
}

Ataque::~Ataque()
{
}

bool Ataque::isAtivo()
{
	return this->ativo;
}

bool Ataque::isInicializado()
{
	return this->inicializado;
}

Sprite Ataque::getSprite()
{
	return this->sprite;
}

float Ataque::getX()
{
	return this->x;
}

float Ataque::getY()
{
	return this->y;
}
