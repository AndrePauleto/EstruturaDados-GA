#include "Personagem.h"



Personagem::Personagem()
{
	vel = 2.0f;
}


Personagem::~Personagem()
{
}

void Personagem::setSpriteSheet(string spritesheet)
{
	spr.setSpriteSheet(spritesheet);
	setSprite(&spr);
	this->direcao = BAIXO;
}

void Personagem::atualizar()
{
	if (gTeclado.segurando[TECLA_D]) {
		dir.set(1, 0);
		this->direcao = DIREITA;
		animar(this->direcao);
	} else if (gTeclado.segurando[TECLA_A]) {
		dir.set(-1, 0);
		this->direcao = ESQUERDA;
		animar(this->direcao);
	} else if (gTeclado.segurando[TECLA_W]) {
		dir.set(0, -1);
		this->direcao = CIMA;
		animar(this->direcao);
	} else if (gTeclado.segurando[TECLA_S]) {
		dir.set(0, 1);
		this->direcao = BAIXO;
		animar(this->direcao);
	} else {
		dir.set(0, 0);
	}

	Vetor2D pos = getPosCentro();	
	if (getTileMap()->tileECaminhavel(pos.x + dir.x * 0.5f, pos.y + dir.y * 0.5f)) {
		pos += dir * vel * gTempo.getDeltaTempo();
		setPosCentro(pos);
	}
}

void Personagem::animar(int animacao)
{
	this->spr.setAnimacao(animacao);
	this->spr.avancarAnimacao();
}
