#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Administrador {

    char nome[50];
    int dia;
    int mes;
    int ano;
    char cargo[50];
    double salario;
    char senha[51];

    struct Administrador *Adm;

} Administrador;

typedef struct Funcionario {

    char nome[50];
    int dia;
    int mes;
    int ano;
    char cargo[50];
    double salario;
    char senha[51];
    
    struct Funcionario *Func;

} Funcionario;

void limpar_buffer() {

    int c;

    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {

    Administrador *listaAdm = NULL;
    Funcionario  *listaFunc = NULL;
    int  opcao;
    char busca_senha[51];
    char cargo[20];
    char busca_nome[50];
    size_t i;
    int valido;

    do {
        
        printf("\n========== MENU ==========\n");
        printf("[1]. Cadastrar\n");
        printf("[2]. Login e Visualizacao\n");
        printf("[3]. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {

            case 1:
                printf("========== Identificacao ==========\n");
                printf("Administrador ou Funcionario: ");
                scanf("%19s", cargo);
                limpar_buffer();

                // ===================== ADMINISTRADOR =====================
                if (strcmp(cargo, "Administrador") == 0 || strcmp(cargo, "administrador") == 0) {

                    Administrador *novoAdm = malloc(sizeof(Administrador));
                    novoAdm->salario = 5000;
                    novoAdm->Adm = NULL;

                    printf("Ola Administrador. Seja bem-vindo!!!\n");

                    do {
                        valido = 1;
                        printf("\nDigite o seu nome: ");
                        scanf(" %49[^\n]", novoAdm->nome);

                        for (i = 0; i < strlen(novoAdm->nome); i++) {

                            if (!isalpha(novoAdm->nome[i]) && novoAdm->nome[i] != ' ') {
                                valido = 0;
                                break;
                            }
                        }

                        if (!valido) printf("Nome invalido! Use apenas letras.\n");

                    } while (!valido);

                    // Data de nascimento
                    printf("\nDigite sua data de nascimento.\n");

                    do {

                        printf("Dia: ");
                        scanf("%d", &novoAdm->dia);
                        limpar_buffer();

                        if (novoAdm->dia < 1 || novoAdm->dia > 31)

                            printf("Dia invalido, digite entre (01-31)!\n");

                    } while (novoAdm->dia < 1 || novoAdm->dia > 31);

                    do {

                        printf("Mes: ");
                        scanf("%d", &novoAdm->mes);

                        limpar_buffer();

                        if (novoAdm->mes < 1 || novoAdm->mes > 12)

                            printf("Mes invalido, digite entre (01-12)!\n");

                    } while (novoAdm->mes < 1 || novoAdm->mes > 12);

                    do {

                        printf("Ano: ");
                        scanf("%d", &novoAdm->ano);

                        limpar_buffer();

                        if (novoAdm->ano < 1900 || novoAdm->ano > 2007)

                            printf("Ano invalido, digite entre (1900-2007)!\n");

                    } while (novoAdm->ano < 1900 || novoAdm->ano > 2007);

                    // Cargo
                    do {

                        valido = 1;

                        printf("\nCargo na empresa: ");
                        scanf(" %49[^\n]", novoAdm->cargo);

                        for (i = 0; i < strlen(novoAdm->cargo); i++) {

                            if (!isalpha(novoAdm->cargo[i]) && novoAdm->cargo[i] != ' ') {

                                valido = 0;
                                break;
                            }
                        }

                        if (!valido) printf("Cargo invalido! Use apenas letras.\n");

                    } while (!valido);

                    do {

                        printf("\nCrie uma senha numerica (5 a 50 digitos): ");
                        scanf("%50s", novoAdm->senha);

                        limpar_buffer();

                        valido = 1;

                        for (i = 0; i < strlen(novoAdm->senha); i++) {

                            if (!isdigit(novoAdm->senha[i])) { valido = 0; break; }
                        }

                        if (!valido) {

                            printf("Senha invalida! Use apenas numeros.\n");

                        } else if (strlen(novoAdm->senha) < 5 || strlen(novoAdm->senha) > 50) {

                            printf("Senha invalida! Minimo 5 e maximo 50 digitos.\n");

                            valido = 0;
                        }

                    } while (!valido);

                    novoAdm->Adm = listaAdm; 
                    listaAdm = novoAdm;

                    printf("\nCadastro realizado!!!\n");

                // ===================== FUNCIONARIO =====================
                } else if (strcmp(cargo, "Funcionario") == 0 || strcmp(cargo, "funcionario") == 0) {

                    Funcionario *novoFunc = malloc(sizeof(Funcionario));

                    novoFunc->salario = 3500;
                    novoFunc->Func = NULL;

                    printf("Ola Funcionario. Seja bem-vindo!!!\n");

                    // Nome
                    do {

                        valido = 1;

                        printf("\nDigite o seu nome: ");
                        scanf(" %49[^\n]", novoFunc->nome);

                        for (i = 0; i < strlen(novoFunc->nome); i++) {

                            if (!isalpha(novoFunc->nome[i]) && novoFunc->nome[i] != ' ') {

                                valido = 0;
                                break;
                            }
                        }

                        if (!valido) printf("Nome invalido! Use apenas letras.\n");

                    } while (!valido);

                    // Data de nascimento
                    printf("\nDigite sua data de nascimento.\n");

                    do {

                        printf("Dia: ");
                        scanf("%d", &novoFunc->dia);

                        limpar_buffer();

                        if (novoFunc->dia < 1 || novoFunc->dia > 31)

                            printf("Dia invalido, digite entre (01-31)!\n");

                    } while (novoFunc->dia < 1 || novoFunc->dia > 31);

                    do {

                        printf("Mes: ");
                        scanf("%d", &novoFunc->mes);

                        limpar_buffer();

                        if (novoFunc->mes < 1 || novoFunc->mes > 12)

                            printf("Mes invalido, digite entre (01-12)!\n");

                    } while (novoFunc->mes < 1 || novoFunc->mes > 12);

                    do {

                        printf("Ano: ");
                        scanf("%d", &novoFunc->ano);

                        limpar_buffer();

                        if (novoFunc->ano < 1900 || novoFunc->ano > 2007)

                            printf("Ano invalido, digite entre (1900-2007)!\n");

                    } while (novoFunc->ano < 1900 || novoFunc->ano > 2007);

                    // Cargo
                    do {

                        valido = 1;

                        printf("\nCargo na empresa: ");
                        scanf(" %49[^\n]", novoFunc->cargo);

                        for (i = 0; i < strlen(novoFunc->cargo); i++) {

                            if (!isalpha(novoFunc->cargo[i]) && novoFunc->cargo[i] != ' ') {

                                valido = 0;
                                break;
                            }
                        }
                        
                        if (!valido) printf("Cargo invalido! Use apenas letras.\n");
                    } while (!valido);

                    // Senha  CORRIGIDO: char[], valida tamanho antes de cadastrar
                    do {
                        printf("\nCrie uma senha numerica (5 a 50 digitos): ");
                        scanf("%50s", novoFunc->senha);
                        limpar_buffer();

                        valido = 1;
                        for (i = 0; i < strlen(novoFunc->senha); i++) {
                            if (!isdigit(novoFunc->senha[i])) { valido = 0; break; }
                        }

                        if (!valido) {
                            printf("Senha invalida! Use apenas numeros.\n");
                        } else if (strlen(novoFunc->senha) < 5 || strlen(novoFunc->senha) > 50) {
                            printf("Senha invalida! Minimo 5 e maximo 50 digitos.\n");
                            valido = 0;
                        }
                    } while (!valido);

                    novoFunc->Func = listaFunc;   // Encadeia na lista
                    listaFunc = novoFunc;

                    printf("\nCadastro realizado!!!\n");

                } else {
                    printf("Cargo invalido! Digite 'Administrador' ou 'Funcionario'.\n");
                }
                break;

            case 2:
                // Busca por nome
                do {
                    valido = 1;
                    printf("\n========== Login ==========\n");
                    printf("Digite o seu nome cadastrado: ");
                    scanf(" %49[^\n]", busca_nome);

                    for (i = 0; i < strlen(busca_nome); i++) {
                        if (!isalpha(busca_nome[i]) && busca_nome[i] != ' ') {
                            valido = 0;
                            break;
                        }
                    }
                    if (!valido) printf("Nome invalido! Use apenas letras.\n");
                } while (!valido);

                // Percorre lista de administradores
                Administrador *atual_adm = listaAdm;
                while (atual_adm != NULL) {
                    if (strcmp(busca_nome, atual_adm->nome) == 0) {
                        printf("Senha: ");
                        scanf("%50s", busca_senha);    // CORRIGIDO: char[]
                        limpar_buffer();

                        if (strcmp(busca_senha, atual_adm->senha) == 0) {  // CORRIGIDO: strcmp
                            printf("\nAcesso validado!!\n");
                            printf("Administrador(a): %s\n", atual_adm->nome);
                            printf("Nascido(a) em %02d/%02d/%d\n", atual_adm->dia, atual_adm->mes, atual_adm->ano);
                            printf("Cargo: %s\n", atual_adm->cargo);
                            printf("Salario: R$ %.2f\n", atual_adm->salario);
                        } else {
                            printf("\nSenha invalida!\n");
                        }
                        break;
                    }
                    atual_adm = atual_adm->Adm;
                }

                // Percorre lista de funcionarios
                Funcionario *atual_func = listaFunc;
                while (atual_func != NULL) {
                    if (strcmp(busca_nome, atual_func->nome) == 0) {
                        printf("Senha: ");
                        scanf("%50s", busca_senha);    // CORRIGIDO: char[]
                        limpar_buffer();

                        if (strcmp(busca_senha, atual_func->senha) == 0) {  // CORRIGIDO: strcmp
                            printf("\nAcesso validado!!\n");
                            printf("Funcionario(a): %s\n", atual_func->nome);
                            printf("Nascido(a) em %02d/%02d/%d\n", atual_func->dia, atual_func->mes, atual_func->ano);
                            printf("Cargo: %s\n", atual_func->cargo);
                            printf("Salario: R$ %.2f\n", atual_func->salario);
                        } else {
                            printf("\nSenha invalida!\n");
                        }
                        break;
                    }
                    atual_func = atual_func->Func;
                }

                if (atual_adm == NULL && atual_func == NULL) {
                    printf("\nUsuario nao encontrado!\n");
                }
                break;

            case 3:
                // Libera memoria
                while (listaAdm != NULL) {
                    Administrador *temp = listaAdm;
                    listaAdm = listaAdm->Adm;
                    free(temp);
                }
                while (listaFunc != NULL) {
                    Funcionario *temp = listaFunc;
                    listaFunc = listaFunc->Func;
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