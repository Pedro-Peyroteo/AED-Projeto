#ifndef CLIENTS_H
#define CLIENTS_H


// Estrutura que representa um cliente
typedef struct {
    int id;              // Identificador único do cliente
    char nome[100];      // Nome do cliente
    char telefone[20];   // Número de telefone do cliente
} Cliente;


// Insere um novo cliente no array, se o ID não existir
int inserirCliente(Cliente *clientes, int *num_clientes, Cliente novo);

// Edita os dados (nome/telefone) de um cliente existente pelo ID
int editarCliente(Cliente *clientes, int num_clientes, int id, const char *novo_nome, const char *novo_telefone);

// Remove um cliente do array pelo ID
int cancelarCliente(Cliente *clientes, int *num_clientes, int id);

// Exibe todos os clientes no terminal
void listarClientes(Cliente *clientes, int num_clientes);

// Salva todos os clientes em um arquivo texto
int guardarClientes(const char *filename, Cliente *clientes, int num_clientes);

// Lê clientes de um arquivo texto e preenche o array
int lerClientes(const char *filename, Cliente *clientes, int *num_clientes);

#endif // CLIENTS_H
