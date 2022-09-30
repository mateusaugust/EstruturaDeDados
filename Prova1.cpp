#include<stdio.h>


typedef int dado;

struct Node {

    dado valor;
    Node *prox;

    Node() {
        prox = NULL;
    }

    Node(dado _valor) {
        valor = _valor;
        prox = NULL;
    }

    void print() {
        printf("%d -> ", valor);
    }

};



struct List {

    Node *cabeca, *cauda;
    int size;

    List() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    /*
        empty = testa se a lista est? vazia ou n?o
        size = retorna o tamanho da lista
        pushFront = insere no inicio
        pushBack = insere no final
        popFront = remove no inicio
        popBack = remove no final
    */

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* pushBack(dado valor) { //O(1)
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    Node* pushFront(dado valor) { //O(1)
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        size++;
        return cabeca;
    }

    /*int size() { //O(n)
        int s = 0;
        Node *tmp = cabeca;
        while (tmp != NULL) {
            s++;
            tmp = tmp->prox;
        }
        return s;
    }*/

    void print() { //O(n)
        Node *tmp = cabeca;
        while (tmp != NULL) {
            tmp->print();
            tmp = tmp->prox;
        }
        printf("\n");
    }

    Node* popFront() { //O(1)
        if (!empty()) {
            if (cabeca == cauda) { // Apenas 1 elemento
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *tmp = cabeca;
                cabeca = cabeca->prox;
                delete(tmp);
            }
            size--;
        }
        return cabeca;
    }

    Node* popBack() { //O(n)
        if (!empty()) {
            if (cabeca == cauda) {
                delete(cabeca);
                cabeca = NULL;
                cauda = NULL;
            } else {
                Node *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            size--;
        }
        return cauda;
    }

    Node* find(dado x) { //O(n)
        Node *tmp = cabeca;
        while (tmp != NULL) {
            if (tmp->valor == x) {
                return tmp;
            }
            tmp = tmp->prox;
        }
        return NULL;
    }

    void removeFinal(int N){
        
        if(size<N){
            while(size!=0){
                popBack();
                printf("size : %d \n", size);
            }
        }else{
            int contador = 0;

            while(contador<N){
                popBack();

                printf("size : %d \n", size);
                contador++;
            }
        }
    }

    Node* pushBackSize() { //O(1)
        int valor = size;
        valor++;//O valor mostrará um a mais, pois no momento que o tamanho é adicionado ao 
                //final dessa lista, ela aumenta um, caso não queirá considerar a última posição
                //pois ela armazena somente o tamnho dessa lista, basta tirar esse "valor++";
        Node *novo = new Node(valor);
        if (empty()) {
            cabeca = novo;
            cauda = novo;
        } else {
            cauda->prox = novo;
            cauda = novo;
        }
        size++;
        return cauda;
    }

    void popSecond () { //O(1)
        if(size>1){
            Node *tmp = cabeca->prox;
            cabeca->prox = tmp->prox;
            delete(tmp);
        }
    }

    void addElment(int nElementos){
        for(int i = 1; i<=nElementos; i++){
            pushBack(i);
        }
    }

    void addPenultimo(dado valor){
        Node *tmp = cabeca->prox;
        bool controller = false;
        

        while (controller == false){
            if(tmp->prox == cauda){ 
                Node* novo = new Node(valor);
                novo->prox = tmp->prox; 
                tmp->prox = novo;
                controller = true;
            }else{
                tmp = tmp->prox;
            }
        }
    }

    void removeN(int n) {
        if(n>1)
        {
            Node *tmp = cabeca;
            Node *tmp2;
            int tam=1;
            while (tmp != NULL)
            {
                if(tam==n)
                {
                    tmp2->prox = tmp->prox;
                    delete(tmp);
                    break;
                }
                ++tam;
                tmp2=tmp;
                tmp = tmp->prox;
            }
        }
    }
    
    
    
    
    //Número 1 PROVA
    void questao1(int n){
    		if(size>n){
    				int a = size;
    				n = a - n;
    				for(int i=0;i<n;i++){
    						popBack();
    				}
							}else if(size<n){
									while(size < n){
										pushFront(0);
									}
							}
				}
   
    
 
				//Número 3 PROVA
				void questao3(){
					
					Node *tmp = cabeca;
					int tam=size;
					
					for(int i=0;i<tam; i++){
						int a = tmp->valor;
						pushBack(a);		
						tmp=tmp->prox;
					}
				}
				
				
				//Questao 4    
    void questao4(int i){
    	int m = 1;
					while(m <= i){
							if(find(m)){
    						m ++;
								}else{
										pushBack(m);
										m++;
								}
					}	
    	
				}
    
    
    
};



int main() {
    List l;
    l.pushBack(1);
    //l.pushBack(2);
    l.pushBack(3);
    l.pushBack(4);
    l.pushBack(5);
				l.pushBack(6);
    l.pushBack(7);
    l.pushBack(8);
    
    //l.questao4(18);
   	// l.questao3();
    //l.questao1(9);
    
    l.print();
    printf("%d\n", l.size);
    return 0;

    /*
        empty = testa se a lista est? vazia ou n?o
        size = retorna o tamanho da lista
        pushFront = insere no inicio
        pushBack = insere no final
        popFront = remove no inicio
        popBack = remove no final
    */
}

