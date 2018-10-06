#pragma once
#include "Personagem.h"
class Guerreiro :
	public Personagem
{
public:
	Guerreiro(float x, float y);
	~Guerreiro();
	void atacar();

};

