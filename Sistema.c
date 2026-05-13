#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 typedef struct Administrador{

    char nome[50];
    int dia;
    int mes;
    int ano;
    char cargo[50];               //Registros para administrador
    double salario;
    int senha;

    struct Administrador * Adm;

    } Administrador;

 typedef struct Funcionario{
    char nome[50];
    int dia;
    int mes;
    int ano;
    char cargo[50];               //Registros para funcionario
    double salario;
    int senha;

    struct Funcionario * Func;

    } Funcionario;

 int main() {

    system ("cls");

    Administrador *listaAdm = NULL;
    Funcionario *listaFunc = NULL;
    int opcao;
    int cadastro_adm = 0;           //Declaração de variáveis
    int cadastro_func = 0;
    int busca_senha;
    char cargo[20]; 
    char busca_nome[50];
    size_t i;
    int valido;

    do{

        printf("\n========== MENU ==========\n");
        printf("1. Cadastrar\n");
        printf("2. Login e Visualizacao\n");         //Menu
        printf("3. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

    switch (opcao) {

        case 1:
           printf("========== Identificacao ==========\n");

           printf("===== Administrador ou Funcionario: ");
           scanf("%19s", cargo);


        if(strcmp(cargo, "Administrador") == 0 || strcmp(cargo, "administrador") == 0) {

            Administrador *novoAdm = malloc(sizeof(Administrador));
            novoAdm -> salario = 5000;
            novoAdm -> salario = NULL;

            printf("Ola Administrador. Seja bem-vindo!!!\n");

            do {

                valido = 1;

               printf("\nDigite o seu nome: ");
               scanf(" %49[^\n]", novoAdm->nome);

                for(i = 0; i < strlen(novoAdm->nome); i++){
    
                    if(!isalpha(novoAdm->nome[i]) && novoAdm->nome[i] != ' ') {
    
                        valido = 0;
    
                        break;
                    }
                }

                if (!valido) {

                    printf("Nome invalido! Use apenas letras.\n");
                }

            } while(!valido);
            

            printf("\nCadastre sua data de nascimento\n");

            do {

                printf("\nDia: ");
                scanf("%d", &novoAdm->dia);

                if(novoAdm->dia < 1 || novoAdm->dia > 31){

                    printf("\nDia invalido, digite entre (01-31)!\n");
                }     
            } while (novoAdm->dia < 1 || novoAdm->dia > 31);

            do {

                printf("\nMes: ");
                scanf("%d", &novoAdm->mes);

                if (novoAdm->mes < 1 || novoAdm->mes > 12){

                    printf("\nMes invalido, digite entre (01-12)!\n");
                }
            } while (novoAdm->mes < 1 || novoAdm->mes > 12);

            do {
                
                printf("\nAno: ");
                scanf("%d", &novoAdm->ano);

                if(novoAdm->ano < 1900 || novoAdm->ano > 2007) {

                    printf("\nAno invalido, digite entre (1900 - 2007)!\n");
                }   
            } while (novoAdm->ano < 1900 || novoAdm->ano > 2007);

            do{

                valido = 1;

                printf("\nCargo na empresa: ");
                scanf(" %49[^\n]", novoAdm->cargo);

                for(i = 0; i < strlen(novoAdm->cargo); i++) {

                    if(!isalpha(novoAdm->cargo[i]) && novoAdm->cargo[i] != ' ') {

                        valido = 0;

                        break;
                    }
                }

                if(!valido) {

                    printf("Cargo invalido! Use apenas letras.\n");
                }
            }while(!valido);

            printf("\nCrie uma senha numerica para login: ");
            scanf("%d", &novoAdm->senha);

            novoAdm -> proximo = listaAdm;
            listaAdm = novoAdm;

            printf("\nCadastro realizado!!!\n");

            } else if(strcmp(cargo, "Funcionario") == 0 || strcmp(cargo, "funcionario") == 0) {

                Funcionario *novoFunc = malloc(sizeof(Funcionario))
                novoFunc -> salario = 3500;
                novoFunc -> proximo = NULL;

                    printf("Ola funcionario. Seja bem-vindo!!!\n");

                    do {

                        valido = 1;

                        printf("\nDigite o seu nome: ");
                        scanf(" %49[^\n]", novoFunc->nome);

                        for(i = 0; i < strlen(novoFunc->nome); i++) {

                            if(!isalpha(novoFunc->nome[i]) && novoFunc->nome[i] != ' ') {

                                valido = 0;

                                break;
                            }
                        }

                        if(!valido) {

                            printf("Nome invalido! Use apenas letras.\n");
                        }

                    } while(!valido);

                    printf("\nCadastre sua data de nascimento.\n");

                    do {

                        printf("\nDia: ");
                        scanf("%d", &novoFunc->dia);

                        if(novoFunc->dia < 1 || novoFunc->dia > 31){

                            printf("\nDia invalido, digite entre (01-31)!\n");
                        }
                    } while (novoFunc->dia < 1 || novoFunc->dia > 31);

                    do {

                        printf("\nMes: ");
                        scanf("%d", &novoFunc->mes);

                        if(novoFunc->mes < 1 || novoFunc->mes > 12) {

                            printf("\nMes invalido, digite entre (01-12)!\n");
                        }   
                    } while (novoFunc->mes < 1 || novoFunc->mes > 12);

                    do{

                        printf("\nAno: ");
                        scanf("%d", &novoFunc->ano);

                        if(novoFunc->ano < 1900 || novoFunc->ano > 2007) {

                            printf("\nAno invalido, digite entre (1900-2007)!\n");
                        }
                    } while (novoFunc->ano < 1900 || novoFunc->ano > 2007);

                    do {

                        valido = 1;

                        printf("\nCargo na empresa:");
                        scanf(" %49[^\n]", novoFunc->cargo);

                        for(i = 0; i < strlen(novoFunc->cargo); i++){

                            if(!isalpha(novoFunc->cargo[i]) && novoFunc->cargo[i] != ' ') {

                                valido = 0;

                                break;
                            }
                        }

                        if(!valido) {

                            printf("Cargo invalido! Use apenas letras\n");
                        }
                    } while(!valido);

                    printf("\nCrie uma numerica senha para login: ");
                    scanf("%d", &novoFunc->senha);

                    printf("\nCadastro realizado!!!");

                    cadastro_func = 1;

                } else{

                    printf(" ERROR 404 NOT FOUND!\n");
                }
                break;

        case 2:
                do{
                    valido = 1;

                    printf("\n========== Login ==========\n");                                       //LOGIN
                    printf("\nDigite o seu nome cadastrado: ");
                    scanf(" %49[^\n]", busca_nome);

                    for(i = 0; i < strlen(busca_nome); i++){

                        if(!isalpha(busca_nome[i]) && busca_nome[i] != ' ') {

                            valido = 0;

                            break;
                        }
                    }

                    if(!valido) {

                        printf("Nome invalido! Use apenas letras.\n");
                    }
                } while(!valido);

                Administrador *AtualAdm = listaAdm;

                while (AtualAdm != NULL){
                    
                    if(cadastro_adm == 1 && strcmp(busca_nome, Adm.nome) == 0) {
                        
                        printf("\nSenha: ");                                                       //Busca senha adm
                        scanf("%d", &busca_senha);
                        
                        if(busca_senha == AtualAdm->senha){
                            
                            printf("\nAcesso validado!!\n");
                            
                            printf("\nAdministrador(a): %s \n", Adm.nome);
                            printf("\nNascido(a) em %d/%d/%d \n", Adm.dia, Adm.mes, Adm.ano);
                            printf("Cargo: %s", Adm.cargo);
                            printf("\nSalario: %.2f R$\n", Adm.salario);
                            
                        }else {
                            
                            printf("\nSenha invalida!\n");
                        }
                        
                                        }
                        
             } else if(cadastro_func == 1 && strcmp(busca_nome, Func.nome)==0){
    
                    printf("\nSenha: ");                                                         //Busca senha func
                    scanf("%d", &busca_senha);

                if(busca_senha == Func.senha){

                    printf("\nAcesso validado!!\n");

                    printf("Funcionario(a): %s", Func.nome);
                    printf("\nNascido(a) em %d/%d/%d \n", Func.dia, Func.mes, Func.ano);
                    printf("Cargo: %s", Func.cargo);
                    printf("\nSalario: %.2f R$\n", Func.salario);

                } else {

                    printf("\nSenha invalida!\n");
                }
             break;

             AtualFunc = AtualFunc -> Func;

             case 3:                         //Libera memória

                while (ListaAdm != NULL) {

                    Administrador *temp = ListaAdm;
                    ListaAdm = ListaAdm -> Adm;
                    free(temp);
                }

                while (ListaFunc != NULL) {
                    
                    Funcionario *temp = ListaFunc;
                    ListaFunc = ListaFunc -> Func;
                    free(temp);
                }

                printf("\nSaindo...\n");

                break;

            default:
                printf("\nOpcao invalida!!!\n");

            }
                } while (opcao != 3);

                    return 0;
}