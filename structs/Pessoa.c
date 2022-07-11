#include "Filiacao.c";

typedef struct {
    //Nome da pessoa
    char nome[255];

    //Idade da pessoa
    int idade;

    //Data de nascimento
    char dataNascimento[11];

    // Telefone
    char telefone[30];

    //Registro do nome do pai e da mae
    Filiacao filiacao;

    //Cpf da pessoa
    char cpf[12];

    //Tipo Sanguíneo
    char tipoSanguineo[3];
} Pessoa;
