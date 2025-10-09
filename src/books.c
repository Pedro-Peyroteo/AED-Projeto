#include <stdio.h>
#include "cutils.h"
// #include "app.h"

typedef struct
{
    int id;
    char titulo;
    char isbn;
    char autor;
    int numExemplares;
} Livro;

// Inicializa o ArrayList para armazenar livros
ArrayList livro;

// Menu principal Livro
void menuLivros()
{
    // Preparar/Inicializar o ArrayList
    arraylist_init(&livro, sizeof(Livro));

    printf("\n");
    printf("1- Inserir Cliente\n");
    printf("2- Editar Livro\n");
    printf("3-Eliminar Livro\n");
    printf("4- Pesquisar Livro\n");
    printf("5- Listar Livros\n");
    printf("6- Guardar/Ler Ficheiro\n");
    printf("0- Sair\n");
}

// Função para inserir um novo livro
void inserirLivro(Livro livros[], int *numLivros)
{

    Livro novoLivro;
    printf("Id Unico do Livro: ");
    scanf("%d", &novoLivro.id);
    printf("Digite o titulo do livro: ");
    scanf(" %[^\n]", novoLivro.titulo);
    printf("Digite o ISBN do livro: ");
    scanf(" %[^\n]", novoLivro.isbn);
    printf("Digite o Autor do livro: ");
    scanf(" %[^\n]", novoLivro.autor);
    printf("Numero de Exemplares em Stock: ");
    scanf("%d", &novoLivro.numExemplares);

    arraylist_append(&livro, &novoLivro);

    livros[*numLivros] = novoLivro;
    (*numLivros)++;
    printf("Livro inserido com sucesso!\n");
}

// Função para editar um livro existente
void editarLivro(Livro livros[], int numLivros)
{
    int id, i, encontrado = 0;
    printf("Digite o Id do livro a editar: ");
    scanf("%d", &id);

    for (i = 0; i < numLivros; i++)
    {
        if (livros[i].id == id)
        {
            encontrado = 1;
            printf("Editando Livro: %s\n", livros[i].titulo);
            printf("Novo Titulo: ");
            scanf(" %[^\n]", livros[i].titulo);
            printf("Novo ISBN: ");
            scanf(" %[^\n]", livros[i].isbn);
            printf("Novo Autor: ");
            scanf(" %[^\n]", livros[i].autor);
            printf("Novo Numero de Exemplares: ");
            scanf("%d", &livros[i].numExemplares);
            printf("Livro editado com sucesso!\n");
            break;
        }
    }
    if (!encontrado)
    {
        printf("Livro com Id %d nao encontrado.\n", id);
    }
}

// Função para eliminar um livro
void eliminarLivro(Livro livros[], int *numLivros)
{
    int id, i, j, encontrado = 0;
    printf("Lista Livros com ID:\n");
    listarLivros(livros, *numLivros);

    printf("Digite o Id do livro a eliminar: ");
    scanf("%d", &id);

    for (i = 0; i < *numLivros; i++)
    {
        if (livros[i].id == id)
        {
            encontrado = 1;
            for (j = i; j < *numLivros - 1; j++)
            {
                livros[j] = livros[j + 1];
            }
            (*numLivros)--;
            printf("Livro eliminado com sucesso!\n");
            break;
        }
    }
    if (!encontrado)
    {
        printf("Livro com Id %d nao encontrado.\n", id);
    }
}