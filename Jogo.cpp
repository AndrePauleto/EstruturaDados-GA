#include "Jogo.h"

Jogo::Jogo()
{
	this->mapa = new TileMap();
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(512, 384, false);
	
	Recurso * r = new Recurso();
	delete r;

	this->mapa->carregar("assets/tilemaps/aula.json");
	this->jogador = new Jogador(this->mapa);
}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();
		this->mapa->desenhar();
		jogador->atualizar();
		uniTerminarFrame();
	}
}