#include "Recurso.h"

Recurso::Recurso()
{
	this->carregarSpriteSheet();	
	this->carregarSons();
}


Recurso::~Recurso()
{
}

void Recurso::carregarSpriteSheet()
{
	this->arquivoSpriteSheet.open("assets/spritesheets/load.txt", ios::in);
	if (!this->arquivoSpriteSheet) {
		gDebug.erro("Não abriu arquivo", "arquivoSpriteSheet");
	}

	string nome;
	string caminho;
	string numeroAnimacoes;
	string numeroFrames;
	
	while (!this->arquivoSpriteSheet.eof())
	{	
		this->arquivoSpriteSheet >> nome >> caminho >> numeroAnimacoes >> numeroFrames;
		if (!this->arquivoSpriteSheet.fail()) {
			gRecursos.carregarSpriteSheet(nome, caminho, std::stoi(numeroAnimacoes), std::stoi(numeroFrames));
			
			if (!gRecursos.carregouSpriteSheet(nome)) {
				gDebug.erro("Não carregou recurso");
			}
		}
	}
	this->arquivoSpriteSheet.close();
}

void Recurso::carregarSons()
{
}

