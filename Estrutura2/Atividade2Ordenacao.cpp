#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Time {
    char nome[4];
    int jogos, pontos, vitorias, empates, derrotas;
    int golsPro, golsContra, saldo;
    double aproveitamento;

    Time() {
        strcpy(nome, "");
        jogos = pontos = vitorias = empates = derrotas = 0;
        golsPro = golsContra = saldo = 0;
        aproveitamento = 0;
    }

    Time(char _nome[4]) {
        strcpy(nome, _nome);
        jogos = pontos = vitorias = empates = derrotas = 0;
        golsPro = golsContra = saldo = 0;
        aproveitamento = 0;
    }

    void computarJogo(int _golsPro, int _golsContra) {
        jogos++;
        if (_golsPro > _golsContra) {
            vitorias++;
            pontos += 3;
        } else if (_golsPro == _golsContra) {
            empates++;
            pontos += 1;
        } else {
            derrotas++;
        }
        golsPro += _golsPro;
        golsContra += _golsContra;
        saldo = golsPro - golsContra;
        aproveitamento = (pontos / (jogos * 3.0)) * 100.0;
    }

    void imprimirTime() {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%.2lf\n",
               nome, jogos, pontos, vitorias, empates,
               derrotas, saldo, golsPro, golsContra,
               aproveitamento);
    }
};

void bubble_sorte_pontos(Time times[]){
    Time time2;
    
    cout << "TABELA ORDENADA USANDO BUBBLE SORT " << endl;
     for(int i = 0; i<12; i++){
        for(int j =0; j<12;j++){
                if(times[i].pontos>times[j].pontos){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias>times[j].vitorias){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo>
                times[j].saldo){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo==
                times[j].saldo&&times[i].golsPro>times[j].golsPro){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }
        }
     }
    
}

void select_sort(Time times[]){
    Time time2;

    cout << "TABELA ORDENADA USANDO SELECTION SORT " << endl;
    for(int i = 0; i<12;i++){
        for(int j = i+1; j<12;j++){
            if(times[i].pontos<times[j].pontos){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias<times[j].vitorias){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo<
                times[j].saldo){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }else if(times[i].pontos==times[j].pontos &&times[i].vitorias==times[j].vitorias&&times[i].saldo==
                times[j].saldo&&times[i].golsPro<times[j].golsPro){
                    time2 = times[i];
                    times[i] = times[j];
                    times[j]= time2;
                }
        }
    }

}


bool verifica(Time times, Time time2){
        if(times.pontos<time2.pontos){
            return true;
        }else if(times.pontos==time2.pontos &&times.vitorias<time2.vitorias){
            return true;
        }else if(times.pontos==time2.pontos &&times.vitorias==time2.vitorias&&times.saldo<
                time2.saldo){
            return true;
        }else if(times.pontos==time2.pontos &&times.vitorias==time2.vitorias&&times.saldo==
                time2.saldo&&times.golsPro<time2.golsPro){
            return true;
        }

        return false;
    }

void insertion_sort(Time times[]){
    Time time2;
    int i , j;

    cout << "TABELA ORDENADA USANDO INSERTION SORTE " << endl;
    for(i = 1; i<12;i++){
        time2 = times[i];
        for(j = i-1; j>=0 && verifica(times[j], time2) == true; j--){
                 times[j+1] = times[j];

            }

            times[j+1] = time2;
        }
    }

    


int main() {

    Time times[12];
    char t1[4], t2[4];
    int r1, r2, ultimo_id = -1,opMenu;
    FILE *f = fopen("dados.txt", "r+");

    while(fscanf(f, "%s %dX%d %s", t1, &r1, &r2, t2) != EOF) {
        int i1 = -1, i2 = -1;
        for (int i = 0; i <= ultimo_id; i++) {
            if (strcmp(times[i].nome, t1) == 0) { // Checa se t1 já existe
                i1 = i;
            }
            if (strcmp(times[i].nome, t2) == 0) { // Checa se t2 já existe
                i2 = i;
            }
        }
        if (i1 == -1) { // Se t1 não existe, cria um novo no vetor
            ultimo_id++;
            strcpy(times[ultimo_id].nome, t1);
            i1 = ultimo_id;
        }
        if (i2 == -1) { // Se t2 não existe, cria um novo no vetor
            ultimo_id++;
            strcpy(times[ultimo_id].nome, t2);
            i2 = ultimo_id;
        }
        times[i1].computarJogo(r1, r2); // Computa para t1
        times[i2].computarJogo(r2, r1); // Computa para t2
    }


  

    cout << "\n\nTABELA SEM ORDENACAO" << endl;
    for(int i =0; i<12;i++){
        times[i].imprimirTime();
    }

    
    //bubble_sorte_pontos(times);//passar print para dentro do menu
    //select_sort(times);
    //insertion_sort(times);
    
    /*for(int i =0; i<12;i++){
        times[i].imprimirTime();
    }*/
    
    cout << "\nEscolha a forma de ordenacao:";
    cout << "\n(1) - Bubble Sort\n(2) - Selection Sort\n(3) - Insertion Sort" << endl;
    cout << "--->";
    cin >> opMenu;
    
    
    switch (opMenu){

    case 1:
        bubble_sorte_pontos(times);

        for(int i =0; i<12;i++){
        times[i].imprimirTime();
        }
    break;

    case 2:
        select_sort(times);

        for(int i =0; i<12;i++){
        times[i].imprimirTime();
        }
    break;

    case 3:
        insertion_sort(times);

        for(int i =0; i<12;i++){
        times[i].imprimirTime();
        }
    break;

    default:
        cout << "Digite uma opcao correta!";
    break;
    }
    


    return 0;
}

//Revisão: O bubble sort irá percorrer o vetor inteiro toda vez que for verificar

//         O select sort irá percorrer o vetor(no momento da comparação) a partir 
//           da posição ainda não ordenada.

//         O insertion sempre compara x com os elementos a esquerda, se o elemento se o elemento
//         x for menor que o da esquerda, ele troca e por ai em diante(no caso se for ordenar de forma crescente)

// Mateus Augusto da Silva
