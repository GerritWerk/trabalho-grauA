#include "Jogo.h"

Jogo::Jogo()
{
	
}

Jogo::~Jogo()
{
}

void Jogo::inicializar()
{
	uniInicializar(800, 600, false);
	mapa.carregar("assets/tilemaps/tilemap.json");
	//Carregar Recursos
	gRecursos.carregarSpriteSheet("knight", "assets/spritesheets/Knight.png", 4, 4);
	gRecursos.carregarSpriteSheet("mage", "assets/spritesheets/Mage.png", 4, 4);
	gRecursos.carregarSpriteSheet("thief", "assets/spritesheets/Thief.png", 4, 4);
	//gRecursos.carregarAudio("grito", "assets/audio/teste.mp3");
	gRecursos.carregarFonte("fonte1", "assets/texto/Aaargh.ttf", 16);
	gRecursos.carregarMusica("musica1", "assets/musica/musica1.mp3");
	tiro.inicializar("tiro", "assets/spritesheets/tiro.png");
	//texto
	texto.setFonte("fonte1");
	texto.setString("Aqui é monstrao Po");
	texto.setCor(0, 0, 0);
	texto.setAlinhamento(TEXTO_CENTRALIZADO);
	texto.setEspacamentoLinhas(1.5f);
	texto.setLarguraMaxima(300);
	//Jogador1
	jogador1 = new Knight();
	jogador1->setSpriteSheet("knight");
	gRecursos.getSpriteSheet("knight")->setNumFramesDaAnimacao(0, 4);
	ObjetoTileMap* objPos = mapa.getCamadaDeObjetos("Objetos")->getObjeto("Pos1");
	jogador1->setPosCentro(objPos->getPosCentro());
	mapa.getCamadaDeObjetos("Objetos")->adicionarObjeto(jogador1);
	//grito.setAudio("grito");
	//Jogador2
	jogador2 = new Mage();
	jogador2->setSpriteSheet("mage");
	gRecursos.getSpriteSheet("mage")->setNumFramesDaAnimacao(0, 4);
	ObjetoTileMap* objPos2 = mapa.getCamadaDeObjetos("Objetos")->getObjeto("Pos2");
	jogador2->setPosCentro(objPos2->getPosCentro());
	mapa.getCamadaDeObjetos("Objetos")->adicionarObjeto(jogador2);
	//Jogador3
	jogador3 = new Thief();
	jogador3->setSpriteSheet("thief");
	gRecursos.getSpriteSheet("thief")->setNumFramesDaAnimacao(0, 4);
	ObjetoTileMap* objPos3 = mapa.getCamadaDeObjetos("Objetos")->getObjeto("Pos3");
	jogador3->setPosCentro(objPos3->getPosCentro());
	mapa.getCamadaDeObjetos("Objetos")->adicionarObjeto(jogador3);
	
	

	
}

void Jogo::finalizar()
{
	gRecursos.descarregarTudo();
	mapa.descarregar();

	uniFinalizar();
}

void Jogo::executar()
{
	while(!gTeclado.soltou[TECLA_ESC] && !gEventos.sair)
	{
		uniIniciarFrame();

		mapa.desenhar();
		if (gTeclado.segurando[TECLA_1]) {
			// while (gTeclado.pressionou[TECLA_2] || gTeclado.pressionou[TECLA_3]) {
				jogador1->animar();

				jogador1->atualizar();
				if (gTeclado.segurando[TECLA_ESPACO]) {
					desenharFala();
				}
			//}
		}
		if (gTeclado.segurando[TECLA_2]) {
			jogador2->animar();
			jogador2->atualizar();
			if (gTeclado.pressionou[TECLA_ESPACO]) {
				
			}
		}
		if (gTeclado.segurando[TECLA_3]) {
			jogador3->animar();
			jogador3->atualizar();
			if (gTeclado.segurando[TECLA_ESPACO]) {
				jogador3->especial();
			}
		}
		
		if (gTeclado.pressionou[TECLA_T]) {
			gMusica.tocar("musica1", true);
		}
		if (gTeclado.pressionou[TECLA_P]) {
			gMusica.parar();
		}
		
		desenharInstrucoes();
		uniTerminarFrame();
	}
}

void Jogo::desenharInstrucoes()
{
	string txt = "Instruçoes:\n"
		" Pressione [cima] para andar para cima\n"
		" Pressione [baixo] para andar para baixo\n"
		" Pressione [direita] para andar para direita\n"
		" Pressione [esquerda] para andar para esquerda\n"
		" Pressione [espaco] para ativar o especial\n"
		" Pressione [T] para tocar a musica\n"
		" Pressione [P] para para a musica\n"
		" Pressione [1], [2] ou [3] para trocar\n";
	gGraficos.desenharTexto(txt, 25, 25, 255, 255, 255, 255, 0, 0);
}

void Jogo::desenharFala()
{
	string txt2 = "Aqui é monstro Po\n";
	gGraficos.desenharTexto(txt2, 477, 125, 255, 255, 255, 255, 0, 0);
}
