#include "Paciente.c";

typedef struct {

    //Nome
    char nome[255];

    //Endere�o
    char endereco[255];

    //Telefone
    char telefone[30];

    int idUltimoPaciente;

    // Lista de pacientes
    Paciente listaPacientes[100];

} Hospital;
