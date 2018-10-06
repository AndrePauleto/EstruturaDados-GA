#pragma once
#include "libUnicornio.h"

enum
{
	BAIXO,
	ESQUERDA,
	DIREITA,
	CIMA
};

class Personagem: public ObjetoTileMap
{
public:
	Personagem();
	~Personagem();

	void setSpriteSheet(string spritesheet);
	virtual void atualizar();
	virtual void atacar() = 0;

protected:
	Sprite spr;
	Vetor2D dir;
	float vel;
	float x, y;
	TileMap mapa;
	void animar(int animacao);
	int direcao;
};

