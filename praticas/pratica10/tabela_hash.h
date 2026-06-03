#ifndef TABELA_HASH_H
#define TABELA_HASH_H

typedef struct hash_t TabelaHash;

// Criação
TabelaHash* hash_criar(int tamanho);

// Operações
void hash_inserir(TabelaHash *hash, int valor);
int hash_buscar(TabelaHash *hash, int valor);
int hash_remover(TabelaHash *hash, int valor);
void hash_exibir(TabelaHash *hash);
int hash_esta_vazia(TabelaHash *hash);

// Destruição
void hash_destruir(TabelaHash *hash);

#endif