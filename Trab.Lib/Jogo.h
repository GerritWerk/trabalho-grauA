#pragma once
#include "libUnicornio.h"
#include "Knight.h"
#include "Mage.h"
#include "Thief.h"
#include "Tiro.h"

class Jogo
{
public:
	Jogo();
	~Jogo();

	void inicializar();
	void finalizar();

	void executar();
private:
	TileMap mapa;
	Knight* jogador1;
	Knight grito;
	Texto texto;
	Mage* jogador2;
	Tiro tiro;
	Thief* jogador3;
	void desenharInstrucoes();
	void desenharFala();
};

