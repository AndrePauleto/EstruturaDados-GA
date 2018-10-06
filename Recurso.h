#pragma once
#include "libUnicornio.h"
#include <iostream>

class Recurso
{
public:
	Recurso();
	~Recurso();
private:
	void carregarSpriteSheet();
	void carregarSons();
	FILE * arquivo;
	fstream arquivoSpriteSheet;
};

