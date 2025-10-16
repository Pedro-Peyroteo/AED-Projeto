#include <stdio.h>
#include <clients.h>

int main() {
	Cliente clientes[100];
	int num_clientes = 0;

	// Inserir clientes
	Cliente c1 = {1, "Ana", "912345678"};
	Cliente c2 = {2, "Bruno", "913333333"};
	inserirCliente(clientes, &num_clientes, c1);
	inserirCliente(clientes, &num_clientes, c2);

	// Editar cliente
	editarCliente(clientes, num_clientes, 2, "Bruno Silva", "914444444");

	// Listar clientes
	printf("Lista de clientes após inserção e edição:\n");
	listarClientes(clientes, num_clientes);

	// Cancelar cliente
	cancelarCliente(clientes, &num_clientes, 1);

	printf("\nLista de clientes após cancelamento:\n");
	listarClientes(clientes, num_clientes);

	// Guardar clientes em arquivo
	guardarClientes("customers.txt", clientes, num_clientes);

	// Limpar array e ler do arquivo
	num_clientes = 0;
	lerClientes("customers.txt", clientes, &num_clientes);

	printf("\nLista de clientes lida do arquivo:\n");
	listarClientes(clientes, num_clientes);

	return 0;
}
