#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

void limpaTela(){
    system("CLS");
}

string retornaPalavraAleatoria(){

    // vetor de palavras disponíveis
    string palavras[3] = {"abacaxi","manga" , "morango"};

    //Indice gerado no Intervalo (0, 1, 2)
    int indiceAleatorio = rand() %3;

    // Exibe a palavra aleatória
    //cout << palavras[indiceAleatorio];

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDapalavra){

    int cont = 0;

    string palavraComMascara;

    //Coloca uma máscara
    while(cont < tamanhoDapalavra){
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDapalavra, int tentativasRestantes){

        //cout << " A palavra secreta eh: " << palavra << "( tamanho: " << tamanhoDapalavra << ");
        cout << "palavra: " << palavraComMascara << "( tamanho: " << tamanhoDapalavra << ")";
        cout << "\nTentativas Restantes: " << tentativasRestantes;

}

void jogarSozinho(){

    //Palavra a ser adivinhada
    string palavra = retornaPalavraAleatoria();

    // Vai Retornar o tamanho da palavra função .size();
    int tamanhoDapalavra = palavra.size();

    // Palavra mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDapalavra);

    //Variáveis Gerais
    int tentativas = 0, maximoDeTentativas = 5;
    int cont = 0;
    char letra;

    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){

        limpaTela();

        // Exibe o status atual do jogo
        exibeStatus(palavraComMascara, tamanhoDapalavra, maximoDeTentativas - tentativas);

        cout <<" \nDigite uma letra: ";
        cin >> letra;

        for(cont = 0; cont < tamanhoDapalavra; cont++){
            if(palavra[cont] == letra){

                palavraComMascara[cont] = palavra[cont];
            }
        }

        //Almenta uma tentativa realizada
        tentativas++;
    }

    if(palavra == palavraComMascara){

        limpaTela();
        cout << "parabens, voce venceu!";
    }else{
        limpaTela();
        cout << "voce perdeu!";
    }

}

void menuInicial(){

    int opcao = 0;

    while(opcao < 1 || opcao > 3)
    {
        limpaTela();
        cout << "Bem vindo ao jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - sobre";
        cout << "\n3 - sair";
        cout << "\n Escolha uma opcao e tecle ENTER: ";
        cin >> opcao;

        switch(opcao)
        {
        case 1:
            // Iniciar jogo
            jogarSozinho();
            break;
        case 2:
            cout << "Informacoes do jogo";
            break;
        case 3:
            cout << "Ate mais!";
            break;
        }
    }
}

int main()
{
    // Para gerar números aleatorio junto com a biblioteca: <time.h>
    srand((unsigned)time (NULL));

    menuInicial();

    return 0;
}
