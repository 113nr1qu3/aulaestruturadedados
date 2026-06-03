#if
#define LIMITE 100

typedef struct contato_t {
    char nome[101];
    char telefone[16];
} Contato;

typedef struct agenda_t {
    Contato contatos[LIMITE];
    int tamanho;
    int quantidade;
} Agenda;

Agendar criar_agenda(int tamanho);
void adicionar_contato(agenda agenda, Contato contato);
void imprimir_contato(Contato contato);
void remover_contato(agenda agenda, char nome[]);
void buscar_contato(agenda agenda, char nome[]);
void desbloquear_contato(agenda agenda, char nome[]);
void listar_contatos(agenda agenda);

#endif