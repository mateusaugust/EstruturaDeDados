#include<stdio.h>
#include<time.h>

struct DataGeral {

    
    int dia, mes, ano, diaAtual, mesAtual, anoAtual;


    void recebeData(){

        scanf("%d / %d / %d", &dia, &mes, &ano);

        int controllerSaveDate;

        printf("\n\n[1] - Salvar Data automaticamente.\n[2] - Salvar Data Manualmente.\n");
        printf("--> ");
        scanf("%d", &controllerSaveDate);

        switch (controllerSaveDate){
            
            case 1:
                struct tm *data;//Lembrete: ponteiro que leva para struct que armazena date e hora;
                time_t segundos;//Váriavel responsavel por armazenar o tempo em segundos;
                time(&segundos);//Obtenção do tempo;
                data = localtime(&segundos);//Conversão para o tempo local

                diaAtual = data->tm_mday;
                mesAtual = data->tm_mon+1;
                anoAtual = data->tm_year + 1900;
            break;

            case 2:
                printf("\nDia: ");
                scanf("%d", &diaAtual);
                printf("Mes: ");
                scanf("%d",&mesAtual);
                printf("Ano: ");
                scanf("%d", &anoAtual);

                printf("%d/%d/%d", diaAtual, mesAtual, anoAtual);
            break;
        }   
    }

    int calculaIdade(){
        if(dia<=diaAtual && mes<=mesAtual && ano<anoAtual){
            return anoAtual-ano;
        }else{
            return (anoAtual-ano)-1;
        }
    }
    

};


struct Cliente {
    char nome[20];
    char sexo = '\0' ;
    DataGeral data;
    int idade = 0;

    void registrarDados (){

        printf("\nNome: ");
        scanf("%s", nome);

        do{

           printf("Sexo(M ou F): ");
           scanf("%s", &sexo);

           if(sexo != 'M' && sexo != 'F'){
            printf("Digite uma opcao valida.\n");
           } 
        }while(sexo != 'M' && sexo != 'F');

        printf("Data Nascimento(dia/mes/ano): ");
        data.recebeData();

        idade = data.calculaIdade();

    }

    void mostrarDados(){
        printf("\nNome: %s\n", nome);
        printf("Sexo: %c\n", sexo);
        printf("Data Nascimento: %d/%d/%d\n", data.dia, data.mes, data.ano);
        printf("Idade: %d\n\n", idade);
    }

    bool verificacao(){
        if (idade == 0){
            return true;
        }else{
            return false;
        }
    }


};


int main(){

    Cliente clientes[50];
    
    int controller, numeroClientesArmaze = 0;
    
    while(controller != 3){
        printf("\n\n[1] - Cadastra Cliente.\n[2] - Exibir Clientes.\n[3] - Para Finalizar o Programa.\n");
        printf("Escolha da opcao --> ");
        scanf("%d", &controller);

       switch(controller){

            case 1 :
                for(int i = 0; i<50; i++){
                    if(clientes[i].verificacao()){
                        clientes[i].registrarDados();
                        break;
                    }
                }    
            break;

            case 2:
                for(int j = 0; j<50; j++){   
                   if(clientes[j].verificacao()){
                        break;
                    }else{
                        printf("\nIndice de Armazenamento: %d", j);
                        clientes[j].mostrarDados();

                        numeroClientesArmaze = j+1;
                    }
                }

                printf("\nNumero de Clientes Armazenados: %d\n", numeroClientesArmaze);    
            break;

            case 3:
                printf("\nPrograma Finalizado com sucesso!!\n\n");
            break;

            default:
                printf("Escolha uma opção válida!!\n");
            break;

            
       }

       
    }


return 0;
}
