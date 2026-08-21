\# Sistema de Cadastro de Administradores e Funcionários



Sistema desenvolvido em linguagem C para cadastro e autenticação de usuários, com suporte a múltiplos cadastros por meio de lista encadeada.



\## Funcionalidades



\- Cadastro de Administradores e Funcionários

\- Validação de nome e cargo (apenas letras)

\- Validação de data de nascimento

\- Autenticação por nome e senha

\- Visualização de dados após login

\- Suporte a múltiplos cadastros simultâneos

\- Liberação de memória ao encerrar



\## Como executar



1\. Clone o repositório

```bash

git clone https://github.com/seu-usuario/sistema-cadastro.git

```



2\. Compile o projeto

```bash

gcc sistema.c -o sistema

```



3\. Execute o programa

```bash

./sistema

```



\## Como usar



========== MENU ==========



Cadastrar

Login e Visualizacao

Sair



\- \*\*Opção 1\*\* — Cadastra um novo Administrador ou Funcionário

\- \*\*Opção 2\*\* — Realiza login com nome e senha e exibe os dados

\- \*\*Opção 3\*\* — Encerra o programa e libera a memória



\## Validações implementadas



\- Nome e cargo aceitam apenas letras e espaços

\- Dia deve estar entre 01 e 31

\- Mês deve estar entre 01 e 12

\- Ano deve estar entre 1900 e 2007

\- Senha numérica obrigatória para login



\## Tecnologias



\- Linguagem C

\- Bibliotecas: `stdio.h` `stdlib.h` `string.h` `ctype.h`

\- Estrutura de dados: Lista Encadeada



\## Autor



\- Felipe Sena

