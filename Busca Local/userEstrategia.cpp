#include <vector>
// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 1 ***
//	Implementacao da PRIMEIRA estrategia de jogo. (Subida de encosta com raciocinio aleatorio)

tipo_Valor melhorP1;

void init_Player1() {
	// Determina posicao inicial.
	reinicializa_PosicaoAleatoria();
	// Implementacao das rotinas de inicializacao.
	melhorP1 = superf_VerAmbiente();
}


tipo_Movimento run_Player1() {
	tipo_Movimento movimento;
	movimento.direcao = id_Caminhos[0];
	
	// Define a direcao do movimento sempre levando em conta o melhor caminho tendo em vista o estado atual.
	for(int counter = 1; counter<8; counter++){
		movimento.direcao = (superf_VerVizinho(movimento.direcao) < superf_VerVizinho(id_Caminhos[counter])) ? id_Caminhos[counter]: movimento.direcao;
	}
	
	// Verifica se esta no topo e reseta a posicao do player em um lugar aleatorio.
	if(superf_VerVizinho(movimento.direcao) <= superf_VerAmbiente()){
		melhorP1 = (superf_VerAmbiente() > melhorP1) ? superf_VerAmbiente() : melhorP1;
		reinicializa_PosicaoAleatoria();
		return run_Player1();
	}
	
	// Define o tamanho do passo com base na altura que estiver. Ele diminui quanto mais alto estiver na subida, garantindo
	// que uma certa quantidade de passos nao deixe o player cair em um loop onde nao ha caminho melhor.
	int tam = 2*(melhorP1 - superf_VerVizinho(movimento.direcao))/10;
	movimento.passo = (tam>1) ? tam: 1;
	return movimento;
}


tipo_Valor result_Player1() {
	return melhorP1;
}

// *** 	FUNCOES DE INICIALIZACAO E EXECUCAO DO JOGADOR 2 ***
//	Implementacao da SEGUNDA estrategia de jogo (Subida de encosta estocastica). 
// 	Implementei de forma que o player reinicia ao chegar num topo, pois assim garanto que ele nao vai travar ao chegar no topo.
//  Sei que o metodo nao funciona dessa maneira, mas pra resolver o problema coloquei a verificacao dos passos.

vector<const char*> direcoes;
tipo_Valor melhorP2;
void init_Player2() {
	// Determina posicao inicial.
	reinicializa_PosicaoAleatoria();
	// Implementacao das rotinas de inicializacao.
	melhorP2 = superf_VerAmbiente();
}

tipo_Movimento run_Player2() {
	tipo_Movimento movimento;
	
	// Define a direcao do movimento separando as direcoes que representam subida.
	for(int counter = 1; counter<8; counter++){
		if(superf_VerVizinho(id_Caminhos[counter]) > superf_VerAmbiente())
			direcoes.push_back(id_Caminhos[counter]);
	}
	
	// Escolhe aleatoriamente uma das direcoes separadas
	movimento.direcao = (direcoes.size()>0) ? direcoes[rand() % direcoes.size()] : id_Caminhos[0];
	
	// Verifica se esta no topo e reseta a posicao do player em um lugar aleatorio.
	if(superf_VerVizinho(movimento.direcao) <= superf_VerAmbiente()){
		melhorP2 = (superf_VerAmbiente() > melhorP2) ?  superf_VerAmbiente() : melhorP2;
		reinicializa_PosicaoAleatoria();
		return run_Player2();
	}
	
	// Define o tamanho do passo com base na altura que estiver. Ele diminui quanto mais alto estiver na subida, garantindo
	// que uma certa quantidade de passos nao deixe o player cair em um loop onde nao ha caminho melhor.
	int tam = (melhorP2 - superf_VerVizinho(movimento.direcao))/10;
	movimento.passo = (tam>1) ? tam : 1;
	direcoes.clear();
	return movimento;
}


tipo_Valor result_Player2() {
	return melhorP2;
}
