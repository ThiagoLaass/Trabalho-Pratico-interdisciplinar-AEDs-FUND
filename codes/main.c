#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*

Filename: main.c

Authors: Thiago Borges Laaass, Matheus Eduardo Marinho de Miranda Hermenegildo

Description: Desenvolver um programa em C para controlar vendas, cadastros e informações de produtos de uma loja ficticia de roupa.

Notes: Este arquivo é o programa principal a respeito do trabalho pratico de AEDs.

Start date: 02 dez 2023

*/

/*
    Função para atribuir valores iniciais para a matriz de produtos.
                                  Preço  Estoque  PreçoP  Lucro
  Linha de Meia adulta estampada    1       1       1       1
  Linha de Meia adulta lisa         1       1       1       1
  Linha de Meia infantil estampada  1       1       1       1
  Linha de Meia infantil lisa       1       1       1       1

  PrecoP = Preco de produção
    Lucro = Preco - PrecoP

*/

void leiaProdutos(int produtos[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                produtos[i][j] = 0;
            }
            else
                produtos[i][j] = i + 1;
        }
    }
}

/*
    Função para lidar o acesso dos funcionarios, tendo a opção de cadastrar,
    comprar e verificar estoque do produto.
*/

int acessoFuncionario(int produtos[4][4])
{
    int op;
    int productSelection;

    NewChoice:
    printf("Informe o produto desejado\n");
    printf("1 - Linha de Meia adulta estampada\n");
    printf("2 - Linha de Meia adulta lisa\n");
    printf("3 - Linha de Meia infantil estampada\n");
    printf("4 - Linha de Meia infantil lisa\n");
    printf("Para sair, digite qualquer outro numero\n");
    scanf("%d", &productSelection);

        if (productSelection < 1 || productSelection > 4)
        {
            main();
        }

    printf("Informe a operacao desejada\n");
    printf("1 - Verificar preco do produto\n");
    printf("2 - Verificar estoque do produto\n");
    printf("3 - Alterar estoque do produto\n");
    printf("4 - Alterar preco do produto\n");
    scanf("%d", &op); 

    switch (op)
    {
    case 1:

        if (productSelection == 1)
            printf("O preco atual das meias adultas estampadas e: %d\n reais", produtos[0][0]);

        else if (productSelection == 2)
            printf("O preco atual das meias adultas lisas: %d\n", produtos[1][0]);

        else if (productSelection == 3)
            printf("O preco das meias infantis estampadas: %d\n", produtos[2][0]);

        else if (productSelection == 4)
            printf("O preco atual das meias infantis lisas: %d\n", produtos[3][0]);

        else
            printf("Produto nao encontrado\n");

        break;

    case 2:

        if (productSelection == 1)
            printf("O estoque atual das meias adultas estampadas e: %d\n", produtos[0][1]);

        else if (productSelection == 2)
            printf("O estoque atual das meias adultas lisas: %d\n", produtos[1][1]);

        else if (productSelection == 3)
            printf("O estoque atual das meias infantis estampadas: %d\n", produtos[2][1]);

        else if (productSelection == 4)
            printf("O estoque atual das meias infantis lisas: %d\n", produtos[3][1]);

        else
            printf("Produto nao encontrado\n");

        break;

    case 3:
        if (productSelection == 1)
        {
            printf("Informe o novo estoque das meias adultas estampadas\n");
            scanf("%d", &produtos[0][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else if (productSelection == 2)
        {
            printf("Informe o novo estoque das meias adultas lisas\n");
            scanf("%d", &produtos[1][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else if (productSelection == 3)
        {
            printf("Informe o novo estoque das meias infantis estampadas\n");
            scanf("%d", &produtos[2][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else if (productSelection == 4)
        {
            printf("Informe o novo estoque das meias infantis lisas\n");
            scanf("%d", &produtos[3][1]);
            printf("Estoque cadastrado com sucesso\n");
        }
        else
            printf("Produto nao encontrado\n");

        break;

    case 4:
        if (productSelection == 1)
        {
            printf("Informe o novo preco das meias adultas estampadas\n");
            scanf("%d", &produtos[0][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else if (productSelection == 2)
        {
            printf("Informe o novo preco das meias adultas lisas\n");
            scanf("%d", &produtos[1][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else if (productSelection == 3)
        {
            printf("Informe o novo preco das meias infantis estampadas\n");
            scanf("%d", &produtos[2][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else if (productSelection == 4)
        {
            printf("Informe o novo preco das meias infantis lisas\n");
            scanf("%d", &produtos[3][0]);
            printf("Preco cadastrado com sucesso\n");
        }
        else
            printf("Produto nao encontrado\n");
        break;

    default:
        printf("Operacao invalida\n");
        return acessoFuncionario(produtos);
    }

    int choiceNewOp;
    printf("Deseja realizar outra operacao? (1 - sim, 2 - nao)\n");
    scanf("%d", &choiceNewOp);
    
    if ( choiceNewOp == 1 )
        return acessoFuncionario(produtos);
    else
        main();
}

// ***************************************************** TÉRMINO DA FUNÇÂO acessoFuncionario *****************************************************

/*
    Função para lidar o acesso dos clientes, tendo a opção de comprar e verificar preço do produto.
*/

int acessoCliente()
{
    int op;
    
    printf("Informe a operacao desejada (0 - Compra, 1 - verificar o preço de um produto, 2 - verificar o custo de produção)\n");
    scanf("%d", &op);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int pessoa;

    int produtos[4][4];

    leiaProdutos(produtos);

    printf("Informe seu id de usuario (1 - Funcionario, 2 - Cliente, 3 - Encerrar)\n");
    scanf("%d", &pessoa);

    if (pessoa == 1)
    {
        printf("\n***************************** BEM-VINDO FUNCIONARIO *****************************\n");
        acessoFuncionario(produtos);
    }
    else if (pessoa == 2)
    {
        printf("\n***************************** BEM-VINDO CLIENTE *****************************\n");
        acessoCliente(produtos);
    }
    else 
        return 0;

    return 0;
}
