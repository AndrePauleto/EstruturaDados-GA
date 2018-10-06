#pragma once
#include "libUnicornio.h"

class Ataque
{
public:
	Ataque();
	Ataque(int x, int y, float velocidade, string nomeSprite);
	~Ataque();
	virtual void atualizar() = 0;
	virtual void desenhar() = 0;
	bool isAtivo();
	bool isInicializado();
	Sprite getSprite();
	float getX();
	float getY();

protected:
	float velocidade = 5, x, y;
	bool ativo = false, inicializado = false;
	Sprite sprite;
};

