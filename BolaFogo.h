#pragma once
#include "Ataque.h"
enum
{
	BOLAFOGO_BAIXO,
	BOLAFOGO_ESQUERDA,
	BOLAFOGO_DIREITA,
	BOLAFOGO_CIMA
};
class BolaFogo :
	public Ataque
{
public:
	BolaFogo();
	~BolaFogo();
	void atualizar();
	void desenhar();
	void inicializar(float x, float y, float velocidade, string nomeSprite, int direcao);
protected:
	int direcao;
};

