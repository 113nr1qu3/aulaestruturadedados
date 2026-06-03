#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

typedef struct arvore_t Arvore;

// Criação
Arvore* arvore_criar();

// Operações
void arvore_inserir(Arvore *arvore, int valor);

void arvore_exibir_pre_ordem(Arvore *arvore);
void arvore_exibir_em_ordem(Arvore *arvore);
void arvore_exibir_pos_ordem(Arvore *arvore);

int arvore_esta_vazia(Arvore *arvore);

// Destruição
void arvore_destruir(Arvore *arvore);

#endif