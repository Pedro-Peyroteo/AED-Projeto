#include "loans.h"
#include <stdio.h>

int main() {
    loans_init();
    loadLoans ("loans.txt");

    int opcao;
    do {
        printf("\n--- MENU EMPRÉSTIMOS ---\n");
        printf("1 - Registar empréstimos\n");
        printf("2 - Registar devolução\n");
        printf("3 - Listar empréstimos ativos\n");
        printf("4 - Guardar e sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: registerLoan(); break;
            case 2: registerReturn(); break;
            case 3: listActiveLoans(); break;
            case 4: saveLoans("loans.txt"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    loans_free();
    return 0;    
}