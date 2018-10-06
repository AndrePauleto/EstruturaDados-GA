#pragma once
#include "Personagem.h"

class Ladino :
	public Personagem
{
public:
	Ladino(float x, float y);
	~Ladino();
	void atacar();
	void atualizar() override;
private:
	bool ataque = false;
	int tempo = 0;
};

