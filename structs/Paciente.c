#include "Pessoa.c";

typedef struct {
    //Identificador
    int id;

    // Dados pessais
    Pessoa dadosPessoais;

    // Doenças
    char doencas[20][255];

    // Data de registro
    char dataRegistro[11];

} Paciente;
