#include "Personagem.h"



Personagem::Personagem()
{
	velo = 1.0f;
}


Personagem::~Personagem()
{
}

void Personagem::setSpriteSheet(string spritesheet)
{
	spr.setSpriteSheet(spritesheet);
	setSprite(&spr);
}

void Personagem::atualizar()
{
	if (gTeclado.segurando[TECLA_DIR]) {
		dir.set(1, 0);
		spr.setAnimacao(CAMINHADO_DIR);
	}
	else if (gTeclado.segurando[TECLA_ESQ]) {
		dir.set(-1, 0);
		spr.setAnimacao(CAMINHADO_ESQ);
	}
	else if (gTeclado.segurando[TECLA_CIMA]) {
		dir.set(0, -1);
		spr.setAnimacao(CAMINHADO_CIMA);
	}
	else if (gTeclado.segurando[TECLA_BAIXO]) {
		dir.set(0, 1);
		spr.setAnimacao(CAMINHADO_BAIXO);
	}
	else {
		dir.set(0, 0);
	}

	Vetor2D pos = getPosCentro();
	if (getTileMap()->tileECaminhavel(pos.x + dir.x*0.5f, pos.y + dir.y*0.5f)) {
		pos += dir * velo*gTempo.getDeltaTempo();
		setPosCentro(pos);
	}
}

void Personagem::animar()
{
	spr.avancarAnimacao();
}
