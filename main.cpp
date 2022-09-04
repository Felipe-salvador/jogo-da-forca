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

    // vetor de palavras dispon�veis
    string palavras[3] = {"abacaxi","manga" , "morango"};

    //Indice gerado no Intervalo (0, 1, 2)
    int indiceAleatorio = rand() %3;

    // Exibe a palavra aleat�ria
    //cout << palavras[indiceAleatorio];

    return palavras[indiceAleatorio];
}

string retornaPalavraComMascara(string palavra, int tamanhoDapalavra){

    int cont = 0;

    string palavraComMascara;

    //Coloca uma m�scara
    while(cont < tamanhoDapalavra){
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;
}

void exibeStatus(string palavraComMascara, int tamanhoDapalavra, int tentativasRestantes, string letrasJaArriscsdas, string mensagem){

        //cout << " A palavra secreta eh: " << palavra << "( tamanho: " << tamanhoDapalavra << ");
        cout << mensagem;
        cout << "\npalavra: " << palavraComMascara << "( tamanho: " << tamanhoDapalavra << ")";
        cout << "\nTentativas Restantes: " << tentativasRestantes;

        int cont;
        cout << "\nletras arriscadas: ";
        for(cont = 0; cont < letrasJaArriscsdas.size(); cont++){
            cout << letrasJaArriscsdas[cont] << ", ";
        }



}

int jogarSozinho(){

    //Palavra a ser adivinhada
    string palavra = retornaPalavraAleatoria();

    // Vai Retornar o tamanho da palavra fun��o .size();
    int tamanhoDapalavra = palavra.size();

    // Palavra mascarada
    string palavraComMascara = retornaPalavraComMascara(palavra, tamanhoDapalavra);

    //Vari�veis Gerais
    int tentativas = 0, maximoDeTentativas = 12;
    int cont = 0;
    char letra;
    char opcao;
    string letrasJaArriscsdas;
    string mensagem = "Bem vido ao jogo!";
    string palavraArriscada;
    bool jaDigitouLetra = false, acertouLetra = false;

    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0){

        limpaTela();

        // Exibe o status atual do jogo
        exibeStatus(palavraComMascara, tamanhoDapalavra, maximoDeTentativas - tentativas, letrasJaArriscsdas, mensagem);

        cout <<" \nDigite uma letra (ou digite 1 para arriscar a palavra): ";
        cin >> letra;

        if(letra == '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                palavraComMascara = palavraArriscada;
            }else{
                tentativas = maximoDeTentativas;
            }
        }

        for(cont = 0; cont < tentativas; cont++){

            if(letrasJaArriscsdas[cont] == letra){

               mensagem = "Essa letra ja foi digitada!";

                jaDigitouLetra = true;
            }
        }

        //se for uma letra nova
        if(jaDigitouLetra == false){

              letrasJaArriscsdas += letra;

              for(cont = 0; cont < tamanhoDapalavra; cont++){

                if(palavra[cont] == tolower(letra)){

                  palavraComMascara[cont] = palavra[cont];

                  acertouLetra = true;
             }

         }

         //Almenta uma tentativa realizada
         tentativas++;

         if(acertouLetra == false){
             mensagem = "voce errou uma aletra!";
         }else{
             mensagem = "voce acertou uma letra!";

         }

         //Almenta uma tentativa realizada
         tentativas++;

        }

        //Reinicia auxiliares
         jaDigitouLetra = false;
         acertouLetra = false;

    }


    if(palavra == palavraComMascara){

        //limpaTela();
        cout << "\nparabens, voce venceu!";
        cout << "\ndeseja continuar? s/n: ";
        cin >> opcao;
        return opcao;

    }else{
        cout << "\nvoce perdeu!";
        cout << "\ndeseja continuar? s/n: ";
        cin >> opcao;
        return opcao;
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
            if(jogarSozinho() == 's'){
                 menuInicial();
            }
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

    // Para gerar n�meros aleatorio junto com a biblioteca: <time.h>
    srand((unsigned)time (NULL));

    menuInicial();

    return 0;
}
