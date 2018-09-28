#pragma once
#include "libUnicornio.h"
enum PersonagemAnim {
	CAMINHADO_BAIXO,
	CAMINHADO_ESQ,
	CAMINHADO_DIR,
	CAMINHADO_CIMA
};
class Personagem: public ObjetoTileMap
{
public:
	Personagem();
	virtual ~Personagem();

	void setSpriteSheet(string spritesheet);
	void atualizar();
	void animar();

protected:
	Sprite spr;
	Vetor2D dir;
	float velo;
};

