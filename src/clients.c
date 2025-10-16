 #include <stdio.h>
 #include <cutils.h>
 #include <clients.h>

// ...existing code...

int lerClientes(const char *filename, Cliente *clientes, int *num_clientes) {
	FILE *f = fopen(filename, "r");
	if (!f) return 0;
	*num_clientes = 0;
	while (fscanf(f, &clientes[*num_clientes].id, clientes[*num_clientes].nome, clientes[*num_clientes].telefone) == 3) {
		(*num_clientes)++;
	}
	fclose(f);
	return 1;
}
#include <stdio.h>
#include <cutils.h>
#include <clients.h>


int inserirCliente(Cliente *clientes, int *num_clientes, Cliente novo) {
	// Verifica se o ID já existe
	for (int i = 0; i < *num_clientes; i++) {
		if (clientes[i].id == novo.id) {
			return 0; // ID já existe
		}
	}
	// Insere um novo cliente no array, se o ID não existir
	clientes[*num_clientes] = novo;
	(*num_clientes)++;
	return 1; // Sucesso
}

int editarCliente(Cliente *clientes, int num_clientes, int id, const char *novo_nome, const char *novo_telefone) {
	for (int i = 0; i < num_clientes; i++) {
		if (clientes[i].id == id) {
			if (novo_nome) snprintf(clientes[i].nome, sizeof(clientes[i].nome), "%s", novo_nome);
			if (novo_telefone) snprintf(clientes[i].telefone, sizeof(clientes[i].telefone), "%s", novo_telefone);
			return 1; // Sucesso
		}
	// Edita os dados (nome/telefone) de um cliente existente pelo ID
	}
	return 0; // Não encontrado
}

int cancelarCliente(Cliente *clientes, int *num_clientes, int id) {
	for (int i = 0; i < *num_clientes; i++) {
		if (clientes[i].id == id) {
			// Move os clientes seguintes para trás
			for (int j = i; j < *num_clientes - 1; j++) {
				clientes[j] = clientes[j + 1];
			}
			(*num_clientes)--;
			return 1; // Sucesso
	// Remove um cliente do array pelo ID
		}
	}
	return 0; // Não encontrado
}

void listarClientes(Cliente *clientes, int num_clientes) {
	printf("ID\tNome\tTelefone\n");
	for (int i = 0; i < num_clientes; i++) {
		printf("%d\t%s\t%s\n", clientes[i].id, clientes[i].nome, clientes[i].telefone);
	}
}

int guardarClientes(const char *filename, Cliente *clientes, int num_clientes) {
	FILE *f = fopen(filename, "w");
	// Exibe todos os clientes no terminal
	if (!f) return 0;
	for (int i = 0; i < num_clientes; i++) {
		fprintf(f, "%d\t%s\t%s\n", clientes[i].id, clientes[i].nome, clientes[i].telefone);
	}
	fclose(f);
	return 1;

}

