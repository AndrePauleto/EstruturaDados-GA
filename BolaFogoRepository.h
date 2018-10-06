#pragma once
#include "BolaFogo.h"
#include "libUnicornio.h"
#define MAXBOLASFOGO 50
class BolaFogoRepository
{
public:
	BolaFogoRepository();
	~BolaFogoRepository();
	void atualizar();
	void desenhar();

	BolaFogo getBolaFogoByIndex(int index);
	void removerBolaFogoByIndex(int index);
	void removerBolaFogoByIndexRecursivo(int index, int posicaoAtualizada);
	void add(BolaFogo tiro);
	int getTotalBolasFogo();

private:
	int totalBolasFogo;
	BolaFogo aBolasFogo[MAXBOLASFOGO];
};

