#include<stdio.h>
#include<string.h>

void imprime(char v[][100], int n) {
    printf("---------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%s \n", v[i]);
    }
    printf("\n");
}
void troca(char v[][100], int a, int b) {
    char tmp[100];
    strcpy(tmp, v[a]);
    strcpy(v[a], v[b]);
    strcpy(v[b], tmp);
}

void bubbleSort(char v[][100], int n) { // O(n^2)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (strcmp(v[j], v[j + 1]) > 0) {
                troca(v, j, j + 1);
                //imprimirVetor(v, n);
            }
        }
    }
}

void selectionSort(char v[][100], int n) { // O(n^2)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(v[j], v[i]) < 0) {
                troca(v, i, j);
            }
        }
    }
}


void insertionSort(char v[][100], int n) {
    for (int i = 1; i < n; i++) {
        char x[100];
        strcpy(x, v[i]);
        int j;
        for (j = i - 1; j >= 0 && strcmp(x, v[j]) < 0; j--) {
            strcpy(v[j + 1], v[j]);
        }
        strcpy(v[j + 1], x);
    }
}


/*--------------------------*/

void merge(char v[][100], int s, int m, int e) {
    char tmp[e - s + 1][100];
    int i = s, j = m + 1, k = 0;
    while (i <= m && j <= e) {
        if (strcmp(v[i], v[j]) <= 0) {
            strcpy(tmp[k], v[i]);
            i++;
        } else {
            strcpy(tmp[k], v[j]);
            j++;
        }
        k++;
    }
    while (i <= m) {
        strcpy(tmp[k], v[i]);
        i++;
        k++;
    }
    while (j <= e) {
        strcpy(tmp[k], v[j]);
        j++;
        k++;
    }
    for (i = s, k = 0; i <= e; i++, k++) {
        strcpy(v[i], tmp[k]);
    }
}

void mergeSort(char v[][100], int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        merge(v, s, m, e);
    }
}




int main() {


//-----------------------
#define MAX_NOMES 1000
#define TAM_NOME 100
    FILE *arquivo;
    char nomes[MAX_NOMES][TAM_NOME];
    char linha[TAM_NOME];
    int contador = 0;

    // Abre o arquivo para leitura
    arquivo = fopen("nomes2.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê o arquivo linha por linha até o final
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Remove o caractere de nova linha (\n) da linha lida
        linha[strcspn(linha, "\n")] = '\0';

        // Copia o nome lido para o vetor de nomes
        strcpy(nomes[contador], linha);
        contador++;

        // Verifica se atingiu o limite máximo de nomes
        if (contador == MAX_NOMES) {
            break;
        }
    }

    // Fecha o arquivo
    fclose(arquivo);
//----------------------

    int n = 1000;
    int itemMenu;

    printf("MENU\n");
    printf("Escolha uma das opcoes de ordenacao\n");
    printf("------------------------\n");
    printf("1 - BubbleSort\n");
    printf("2 - SelectionSort\n");
    printf("3 - InsertionSort\n");
    printf("4 - MergeSort\n");
    printf("------------------------\n");

    printf("Digite o numero da opcao desejada: ");
    scanf("%d", &itemMenu);

    switch (itemMenu) {
        case 1:
            printf("Opcao selecionada: BubbleSort\n");
             bubbleSort(nomes, n);
            imprime(nomes, n);
            break;
        case 2:
            printf("Opcao selecionada: SelectionSort\n");
            selectionSort(nomes,n);
            imprime(nomes,n);

            break;
        case 3:
            printf("Opcao selecionada: InsertionSort\n");
            insertionSort(nomes,n);
            imprime(nomes,n);
            break;
        case 4:
        printf("Opcao selecionada: MergeSort\n");
        mergeSort(nomes, 0, n);
        imprime(nomes, n);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
}
