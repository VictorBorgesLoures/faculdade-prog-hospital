#include "Pessoa.c";

typedef struct {
    //Identificador
    int id;

    // Dados pessais
    Pessoa dadosPessoais;

    // Doen�as
    char doencas[20][255];

    // Data de registro
    char dataRegistro[11];

} Paciente;
