#pragma once
#include "libUnicornio.h"
#include "Personagem.h"
#include "Guerreiro.h"
#include "Mago.h"
#include "Ladino.h"

class Jogador
{
public:
	Jogador(TileMap * mapa);
	~Jogador();
	void atualizar();
	TileMap getMapa();
	void setMapa(TileMap *mapa);

protected:
	Personagem* personagem;
	TileMap* mapa;
	CamadaDeObjetosTileMap* camadaDeObjetosTileMap;
	void validarTrocaDePersonagem();
	void validarAtaquePersonagem();
	void alterarPersonagem(int codigoTecla);
};

