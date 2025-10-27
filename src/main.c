#include <stdio.h>

int main()
{
    int option;
    while (1)
    {
        printf("Menu Principal\n");
        printf("1- Clientes\n");
        printf("2- Livros\n");
        printf("3- Emprestimos\n");
        printf("4- Sugestoes\n");
        printf("0- Sair\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            menuLivros();
            break;
        case 3:
            menuEmprestimos();
            break;
        case 4:
            menuSugestoes();
            break;
        case 0:
            printf("Saindo do programa...\n");
            return 0;
        }
    }
}