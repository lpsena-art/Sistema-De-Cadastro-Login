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

    struct Administrador *Adm[100];

    } Administrador;

typedef struct Funcionario{

    char nome[50];
    int dia;
    int mes;
    int ano;
    char cargo[50];               //Registros para funcionario
    double salario;
    int senha;

    struct Funcionario *Func[100];

    } Funcionario;

int main() {

    system ("cls");

    Administrador Adm;
    Funcionario Func;
    int opcao;
    int cadastro_adm = 0;           //Declaração de variáveis
    int cadastro_func = 0;
    int busca_senha;
    char cargo[20]; 
    char busca_nome[50];
    size_t i;
    int valido = 1;

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


            Adm.salario = 5000;

            printf("Ola Administrador. Seja bem-vindo!!!\n");

            do {

                valido = 1;

               printf("\nDigite o seu nome: ");
               scanf(" %49[^\n]", Adm.nome);

                for(i = 0; i < strlen(Adm.nome); i++){
    
                    if(!isalpha(Adm.nome[i]) && Adm.nome[i] != ' ') {
    
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
                scanf("%d", &Adm.dia);

                if(Adm.dia < 1 || Adm.dia > 31){

                    printf("\nDia invalido, digite entre (01-31)!\n");
                }     
            } while (Adm.dia < 1 || Adm.dia > 31);

            do {

                printf("\nMes: ");
                scanf("%d", &Adm.mes);

                if (Adm.mes < 1 || Adm.mes > 12){

                    printf("\nMes invalido, digite entre (01-12)!\n");
                }
            } while (Adm.mes < 1 || Adm.mes > 12);

            do {
                
                printf("\nAno: ");
                scanf("%d", &Adm.ano);

                if(Adm.ano < 1900 || Adm.ano > 2007) {

                    printf("\nAno invalido, digite entre (1900 - 2007)!\n");
                }   
            } while (Adm.ano < 1900 || Adm.ano > 2007);

            do{

                valido = 1;

                printf("\nCargo na empresa: ");
                scanf(" %49[^\n]", Adm.cargo);

                for(i = 0; i < strlen(Adm.cargo); i++) {

                    if(!isalpha(Adm.cargo[i]) && Adm.cargo[i] != ' ') {

                        valido = 0;

                        break;
                    }
                }

                if(!valido) {

                    printf("Cargo invalido! Use apenas letras.\n");
                }
            }while(!valido);

            printf("\nCrie uma senha numerica para login: ");
            scanf("%d", &Adm.senha);

            printf("\nCadastro realizado!!!\n");

            cadastro_adm = 1;

            } else if(strcmp(cargo, "Funcionario") == 0 || strcmp(cargo, "funcionario") == 0) {

                Func.salario = 3500;
                    printf("Ola funcionario. Seja bem-vindo!!!\n");

                    do {

                        valido = 1;

                        printf("\nDigite o seu nome: ");
                        scanf(" %49[^\n]", Func.nome);

                        for(i = 0; i < strlen(Func.nome); i++) {

                            if(!isalpha(Func.nome[i]) && Func.nome[i] != ' ') {

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
                        scanf("%d", &Func.dia);

                        if(Func.dia < 1 || Func.dia > 12){

                            printf("\nDia invalido, digite entre (01-31)!\n");
                        }
                    } while (Func.dia < 1 || Func.dia > 31);

                    do {

                        printf("\nMes: ");
                        scanf("%d", &Func.mes);

                        if(Func.mes < 1 || Func.mes > 12) {

                            printf("\nMes invalido, digite entre (01-12)!\n");
                        }   
                    } while (Func.mes < 1 || Func.mes > 12);

                    do{

                        printf("\nAno: ");
                        scanf("%d", &Func.ano);

                        if(Func.ano < 1900 || Func.ano > 2007) {

                            printf("\nAno invalido, digite entre (1900-2007)!\n");
                        }
                    } while (Func.ano < 1900 || Func.ano > 2007);

                    do {

                        valido = 1;

                        printf("\nCargo na empresa:");
                        scanf(" %49[^\n]", Func.cargo);

                        for(i = 0; i < strlen(Func.cargo); i++){

                            if(!isalpha(Func.cargo[i]) && Func.cargo[i] != ' ') {

                                valido = 0;

                                break;
                            }
                        }

                        if(!valido) {

                            printf("Cargo invalido! Use apenas letras\n");
                        }
                    } while(!valido);

                    printf("\nCrie uma numerica senha para login: ");
                    scanf("%d", &Func.senha);

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
                    scanf("%49[^\n]", busca_nome);

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

                if(cadastro_adm == 1 && strcmp(busca_nome, Adm.nome) == 0) {

                    printf("\nSenha: ");                                                       //Busca senha adm
                    scanf("%d", &busca_senha);

                if(busca_senha == Adm.senha){

                    printf("\nAcesso validado!!\n");

                    printf("\nAdministrador(a): %s \n", Adm.nome);
                    printf("\nNascido(a) em %d/%d/%d \n", Adm.dia, Adm.mes, Adm.ano);
                    printf("Cargo: %s", Adm.cargo);
                    printf("\nSalario: %.2f R$\n", Adm.salario);

                }else {
                    
                    printf("\nSenha invalida!\n");
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
            } else {

                printf("\nNome invalido ou usuario nao cadastrado!\n");
            }
             break;

             case 3:

                printf("\nSaindo...\n");

                break;

            default:
                printf("\nOpcao invalida!!!\n");

            }
                } while (opcao != 3);

                    return 0;
}