#include<stdio.h>
#define MAX 100

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


struct Fila {
	

    Node *cabeca, *cauda;
    int size;

    Fila() {
        cabeca = NULL;
        cauda = NULL;
        size = 0;
    }

    bool empty() { //O(1)
        return (cabeca == NULL) && (cauda == NULL);
    }

    Node* enqueue(dado valor) { //O(1) - push back
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

    Node* dequeue() { //O(1) -- pop front
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

    dado front() {
        if (!empty()) {
            return cabeca->valor;
        } else {
            return NULL;
        }
    }
    
    	
	

};


struct Pilha {

    dado v[MAX];
    int s;

    Pilha() {
        s = 0;
    }

    bool empty() {
        return (s == 0);
    }

    int size() {
        return s;
    }

    void push(dado e) {
        if (s >= MAX) {
            printf("Pilha cheia\n");
        } else {
            v[s++] = e;
        }
    }

    void pop() {
         if (s <= 0) {
            printf("Pilha vazia\n");
         } else {
            s--;
         }
    }

    dado top() {
        if (s <= 0) {
            printf("Pilha vazia\n");
            return NULL;
        } else {
            return v[s - 1];
        }
    }

};

Fila inverte (Fila t){
	
	Pilha p;
	int tam = t.size;
	
	while(tam != 0){
		
		p.push(t.front());
		t.dequeue();
		tam = tam-1;	
		
	}
	
	tam = p.size();
	
	while(tam != 0){
		t.enqueue(p.top());
		p.pop();
		tam--;	
	}
	
	return t;
			
}

int main() {

//Mateus Augusto da Silva;

    Fila f;
   
    f.enqueue(10);
    f.enqueue(20);
    f.enqueue(30);
    f.enqueue(40);
    f.enqueue(50);
   
   
  
    f = inverte(f);
   
    printf("%d\n", f.front());
    f.dequeue();
    printf("%d\n", f.front());
    f.dequeue();
    printf("%d\n", f.front());
    f.dequeue();
    printf("%d\n", f.front());
    f.dequeue();
    printf("%d\n", f.front());
   
    return 0;
}

