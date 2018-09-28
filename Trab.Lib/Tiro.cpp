#include "Tiro.h"



Tiro::Tiro()
{
}


Tiro::~Tiro()
{
}

int Tiro::getX()
{
	return x;
}

int Tiro::getY()
{
	return y;
}

bool Tiro::getVivo()
{
	return vivo;
}

Sprite Tiro::getsprite()
{
	return sprite;
}

void Tiro::inicializar(string nome, string path)
{
	if (!gRecursos.carregouSpriteSheet(nome)) {
		gRecursos.carregarSpriteSheet(nome, path);
	}
	sprite.setSpriteSheet(nome);
	velocidade = 3;
	vivo = false;
}

void Tiro::atualizar()
{
	if (vivo) {
		if (diracao == 1) {
			x += velocidade;
		}
		else {
			x -= velocidade;
		}
		if (x<sprite.getLargura() || x>gJanela.getLargura() + sprite.getLargura()) {
			vivo = false;
		}
	}
}

void Tiro::desenhar()
{
	if (vivo) {
		sprite.desenhar(x, y);
	}
}

void Tiro::morrer()
{
	vivo = false;
}

void Tiro::diparar(float x, float y, int direcao)
{
	this->x = x;
	this->y = y;
	this->diracao = direcao;
	vivo = true;
}
