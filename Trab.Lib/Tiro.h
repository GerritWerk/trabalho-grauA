#pragma once
#include "libUnicornio.h"
class Tiro: public ObjetoTileMap 
{
public:
	Tiro();
	~Tiro();
	int getX();
	int getY();
	bool getVivo();
	Sprite getsprite();
	void inicializar(string nome, string path);
	void atualizar();
	void desenhar();
	void morrer();
	void diparar(float x, float y, int direcao);
private:
	float x, y, velocidade;
	Sprite sprite;
	bool vivo;
	int diracao;
};

