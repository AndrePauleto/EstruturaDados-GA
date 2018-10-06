#include "BolaFogo.h"

BolaFogo::BolaFogo() {}

BolaFogo::~BolaFogo()
{
}

void BolaFogo::inicializar(float x, float y, float velocidade, string nomeSprite, int direcao)
{
	this->inicializado = true;
	this->ativo = true;
	this->y = y;
	this->x = x;
	this->velocidade = velocidade;
	this->sprite.setSpriteSheet(nomeSprite);
	this->direcao = direcao;
}

void BolaFogo::atualizar()
{
	if (this->ativo){

		switch (this->direcao)
		{
		case BOLAFOGO_CIMA:
			y -= velocidade;
			if (y < -sprite.getAltura() / 2 || y > gJanela.getAltura() + sprite.getAltura() / 2) {
				this->ativo = false;
			}
			break;
		case BOLAFOGO_BAIXO:
			y += velocidade;
			if (y > gJanela.getAltura() + sprite.getAltura() / 2) {
				this->ativo = false;
			}
			break;
		case BOLAFOGO_DIREITA:
			x += velocidade;
			if (x > gJanela.getLargura() - sprite.getLargura() / 2) {
				this->ativo = false;
			}
			break;
		case BOLAFOGO_ESQUERDA:
			x -= velocidade;
			if (x < -sprite.getLargura() / 2 || x > gJanela.getLargura() + sprite.getLargura() / 2) {
				this->ativo = false;
			}
			break;
		}


	}
}

void BolaFogo::desenhar()
{
	if (this->ativo){
 		this->sprite.desenhar(this->x, this->y);
	}
}