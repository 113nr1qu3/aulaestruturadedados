#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main() {
    Agenda agenda = criar_agenda(LIMITE);

    Contato contato1;
    strcpy(contato1.nome, "João");
    strcpy(contato1.telefone, "123456789");

    adicionar_contato(agenda, contato1);

    listar_contatos(agenda);

    contato outro;
    strcpy(outro.nome, "Maria");
    strcpy(outro.telefone, "987654321");

    adicionar_contato(agenda, outro);

    listar_contatos(agenda);

    return 0;
}