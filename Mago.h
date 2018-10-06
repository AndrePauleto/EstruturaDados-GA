#pragma once
#include "Personagem.h"
#include "BolaFogo.h"
#include "BolaFogoRepository.h"
class Mago :
	public Personagem
{
public:
	Mago(float x, float y);
	~Mago();
	void atacar();
	void atualizar() override;
private:
	BolaFogoRepository bolaFogoRepository;
};

