#pragma once
#include "libUnicornio.h"
#include "Jogador.h"
#include "Recurso.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();

private:
	TileMap* mapa;
	Jogador* jogador;
};

