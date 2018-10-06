#include "Jogador.h"

Jogador::Jogador(TileMap* mapa)
{	
	this->mapa = mapa;
	ObjetoTileMap* objPos = this->mapa->getCamadaDeObjetos("Objetos")->getObjeto("Pos1");
	this->personagem = new Guerreiro(objPos->getXCentro(), objPos->getYCentro());
	this->mapa->getCamadaDeObjetos("Objetos")->adicionarObjeto(this->personagem);
}

Jogador::~Jogador()
{
}

void Jogador::atualizar()
{	
	this->validarTrocaDePersonagem();
	this->validarAtaquePersonagem();
	this->personagem->atualizar();
}

TileMap Jogador::getMapa()
{
	return* this->mapa;
}

void Jogador::setMapa(TileMap *mapa)
{
	this->mapa = mapa;
}

void Jogador::validarTrocaDePersonagem()
{	
	if (gTeclado.pressionou[TECLA_1]) {
		this->alterarPersonagem(TECLA_1);
	}
	else if (gTeclado.pressionou[TECLA_2]) {
		this->alterarPersonagem(TECLA_2);
	}
	else if (gTeclado.pressionou[TECLA_3]) {
		this->alterarPersonagem(TECLA_3);
	}
}

void Jogador::validarAtaquePersonagem()
{
	if (gTeclado.pressionou[TECLA_ESPACO]) {
		this->personagem->atacar();
	}
}

void Jogador::alterarPersonagem(int codigoTecla)
{
	float x = this->personagem->getX();
	float y = this->personagem->getY();
	delete this->personagem;

	switch (codigoTecla){
		case TECLA_1:
			this->personagem = new Guerreiro(x, y);
			break;
		case TECLA_2:
			this->personagem = new Mago(x, y);
			break;
		case TECLA_3:
			this->personagem = new Ladino(x, y);
			break;
		default:
			this->personagem = new Guerreiro(x, y);
			break;
	}

	this->mapa->getCamadaDeObjetos("Objetos")->adicionarObjeto(this->personagem);
}
