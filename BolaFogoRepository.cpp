#include "BolaFogoRepository.h"

BolaFogoRepository::BolaFogoRepository()
{
	this->totalBolasFogo = 0;

	for (int i = 0; i < MAXBOLASFOGO; i++)
	{
		BolaFogo bolaFogo = BolaFogo();
		this->aBolasFogo[i] = bolaFogo;
	}
}

BolaFogoRepository::~BolaFogoRepository()
{
}

/*
  * Atualiza a quantidade de BolasFogo que foram inicializados pelo Jogador e
  * remove as BolasFogo que não estão mais ativas.
  */
void BolaFogoRepository::atualizar()
{
	this->totalBolasFogo = 0;

	// Contamos a quantidade de bolas de fogo que foram inicializadas pelo jogador
	for (int i = 0; i < MAXBOLASFOGO; i++)
	{
		if (this->aBolasFogo[i].isInicializado())
		{
			this->totalBolasFogo++;
		}
	}

	// Verificamos se as bolas de fogo inicializadas pelo jogador ainda estão ativas,
	// caso não estejam mais, as removemos do array.
	for (int i = (this->totalBolasFogo - 1); i >= 0; i--)
	{
		if (!this->aBolasFogo[i].isAtivo())
		{
			//this->removerBolaFogoByIndex(i);
			this->removerBolaFogoByIndexRecursivo(i, 0);
		}
	}

	// Percorremos as bolas de fogo inicializadas pelo jogador e as atualizamos
	for (int i = (this->totalBolasFogo - 1); i >= 0; i--)
	{
		this->aBolasFogo[i].atualizar();
	}
}

/*
 * Desenha as bolas de fogo ativas, na tela
 */
void BolaFogoRepository::desenhar()
{
	for (int i = (this->totalBolasFogo - 1); i >= 0; i--)
	{
		if (this->aBolasFogo[i].isAtivo())
		{
			this->aBolasFogo[i].desenhar();
		}
	}
}

/*
* Retorna um objeto BolaFogo atráves do index do array informado.
* @return BolaFogo
*/
BolaFogo BolaFogoRepository::getBolaFogoByIndex(int index)
{
	return this->aBolasFogo[index];
}

/*
 * Adiciona uma Bola de Fogo no array.
 */
void BolaFogoRepository::add(BolaFogo BolaFogo)
{
	this->aBolasFogo[this->totalBolasFogo] = BolaFogo;
}

/*
 * Copia o próximo elemento do array e sobreescreve a posição atual do elemento,
 * a partir do index informado.
 * Ex.: Caso o index seja 9, será percorrido da posição 0 até a 40. 
 *      O index 9 vai receber a posição 10, a 10 receberá a 11...
 */
void BolaFogoRepository::removerBolaFogoByIndex(int index)
{
	for (int i = 0; i < ((MAXBOLASFOGO - 1) - index); i++)
	{
		this->aBolasFogo[index + i] = this->aBolasFogo[index + i + 1];
	}
	this->totalBolasFogo--;
}

void BolaFogoRepository::removerBolaFogoByIndexRecursivo(int index, int posicaoAtualizada)
{
	if (posicaoAtualizada >= (MAXBOLASFOGO - 1) - index) {
		return;
	}
	
	this->aBolasFogo[index + posicaoAtualizada] = this->aBolasFogo[index + posicaoAtualizada + 1];
	this->removerBolaFogoByIndexRecursivo(index, posicaoAtualizada +1);
}

/*
* Retorna o total de Bolas de Fogo efetuados pelo Jogador
* @return int this->totalBolasFogo
*/
int BolaFogoRepository::getTotalBolasFogo()
{
	return this->totalBolasFogo;
}