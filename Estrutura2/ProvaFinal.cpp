#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

vector<int> gerarVetorAleatorio(int tamanho) {
    srand(time(NULL));
    vector<int> vetor;

    for (int i = 0; i < tamanho; i++) {
        vetor.push_back(rand());
    }

    cout << "Vetor sem ordenacao:" << endl;
    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;

    return vetor;
}

void imprimirVetor(const vector<int>& vetor) {
    for (int i = 0; i < vetor.size(); i++) {
        cout << vetor[i] << " ";
    }
    cout << endl;
}

vector<int> insertionSort(vector<int> v) {
	//Mateus Augusto
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
    return v;
}

void merge(vector<int>& v, int s, int m, int e) {
    int tmp[e - s + 1];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (v[i] <= v[j]) { 
            tmp[k++] = v[i++];
        } else { 
            tmp[k++] = v[j++];
        }
    }
    while (i <= m) {
        tmp[k++] = v[i++];
    }
    while (j <= e) {
        tmp[k++] = v[j++];
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        v[i] = tmp[k];
    }
}

void mergeSort(vector<int>& v, int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}

int buscaBinaria(const vector<int>& vetor, int valor) {
    int e = 0;
    int d = vetor.size() - 1;
	//Mateus Augsuto
    while (e <= d) {
        int meio = e + (d - e) / 2;

        if (vetor[meio] == valor) {
            return meio;
        }

        if (vetor[meio] < valor) {
            e = meio + 1;
        } else {
            d = meio - 1;
        }
    }

    return -1; 
}

bool buscaSequencial(const vector<int>& vetor, int valor, int& posicao) {
    for (int i = 0; i < vetor.size(); i++) {
        if (vetor[i] == valor) {
            posicao = i;
            return true;
        }
    }
    return false;
}

int main() {
    char opMenu;
    int aOk = 0;
    vector<int> vetor2;

    do {
        cout << "a - Gerar Vetor\nb - Ordenar vetor\nc - Busca sequencial\nd - Busca binaria\ne - sair" << endl;
        cin >> opMenu;
        opMenu = tolower(opMenu);

        switch (opMenu) {
            case 'a':
                int tamanhoVector;
                cout << "Tamanho Vetor: ";
                cin >> tamanhoVector;
                vetor2 = gerarVetorAleatorio(tamanhoVector);
                aOk = 1;
                break;

            case 'b':
                if (aOk == 0) {
                    cout << "A nao executada" << endl;
                    break;
                } else {
                    char opt;
                    cout << "(i ou m)" << endl;
                    cin >> opt;
                    opt = tolower(opt);

                    switch (opt) {
                        case 'i':
                            vetor2 = insertionSort(vetor2);
                            imprimirVetor(vetor2);
                            aOk = 2;
                            break;

                        case 'm':
                            mergeSort(vetor2, 0, vetor2.size() - 1);
                            imprimirVetor(vetor2);
                            aOk = 2;
                            break;
                    }
                }
                break;
            
            //Mateus Augusto
            
            case 'c':
            	 if (aOk == 0) {
                    cout << "A nao executada" << endl;
                    break;
                } else {
                	int valor;
                    cout << "Digite um valor para buscar: ";
                    cin >> valor;
                    int posicao = -1;
                    bool encontrado = buscaSequencial(vetor2, valor, posicao);
                    if (encontrado) {
                        cout << "O valor " << valor << " foi encontrado na posicao " << posicao << endl;
                    } else {
                        cout << "O valor " << valor << " nao foi encontrado no vetor" << endl;
                    }
                   
                }
                break;
            	
            break;

            case 'd':
                if (aOk == 0) {
                    cout << "A e B nao executadas" << endl;
                    break;
                } else if(aOk == 1){
                	cout << "B nao executada, somente a A" << endl;
				}else if (aOk == 2) {
                    int valor;
                    cout << "valor para buscar: ";
                    cin >> valor;
                    int posicao = buscaBinaria(vetor2, valor);
                    if (posicao != -1) {
                        cout << "O valor " << valor << " foi encontrado na posicao " << posicao << endl;
                    } else {
                        cout << "O valor " << valor << " nao foi encontrado no vetor" << endl;
                    }
                }
                break;
        }
    } while (opMenu != 'e');

    return 0;
}
//Mateus Augusto
