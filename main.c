#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "structs/Hospital.c";
#define menuSize 2

Hospital hospital = {
    "Hogwarts",
    "Rua Trem 9 3/4",
    "12345678910",
    0
};

void goodBye() {
    printf("\n\n\n----------------------------------\n\n");
    printf("Muito obrigado por usar nosso sistema");
    printf("\n----------------------------------\n\n");
}

// Menu 0
void menuPrincipal() {
    printf("\n Bem vindo ao Gerenciador do Hospital %s\n", hospital.nome);
    printf("\n\nCódigo\t\tComando\n");
    printf("   1\t\tEditar Hospital\n");
    printf("   2\t\tAcessar Gerenciador de Pacientes\n");
    printf("   3\t\tSalvar Dados\n");
    printf("   4\t\tCarregar Dados\n");
    printf("   0\t\tSair\n");
}

// Menu 1
void menuEditarHospital() {
    printf("Editar Hospital\n");
    printf("\nNome: %s", hospital.nome);
    printf("\nEndereço: %s", hospital.endereco);
    printf("\nTelefone: %s", hospital.telefone);
    printf("\n\nCódigo\t\tEditar\n");
    printf("   1\t\tNome\n");
    printf("   2\t\tEndereço\n");
    printf("   3\t\tTelefone\n");
    printf("   0\t\tVoltar\n");
}

// Menu 2
void menuGerenciadorPacientes() {
    printf("Gerenciador de Pacientes\n");
    printf("\nCódigo\t\tComando\n");
    printf("   1\t\tListar Pacientes\n");
    printf("   2\t\tAdicionar Pacientes\n");
    printf("   0\t\tVoltar\n");
}

int voltarMenu(int menu[]) {
    for(int i=menuSize-1; i >= 0; i--) {
        if(menu[i] != 0) {
            menu[i] = 0;
            if(i == 0) {
                return menu[i];
            } else {
                return menu[i-1];
            }
        }
    }
    return 0;
}

int menuBuilder(int menu[]) {
    int menuAtual = 0;
    int opcao = 0;
    for(int i=0; i< menuSize; i++) {
        if(menu[i] != 0) {
            menuAtual = menu[i];
        }
    }
    if(menuAtual == 0) {
        menuPrincipal();
    } else if(menuAtual == 1) {
        menuEditarHospital();
    } else if(menuAtual == 2) {
        menuGerenciadorPacientes();
    }
    scanf("%d", &opcao);
    return opcao;
}

char popupComfimacao(char message[]) {
    char confirmacao;
    printf("\n\t-------------------------\n");
    printf(message);
    printf("\n\t-------------------------\n");
    fflush(stdin);
    scanf("%c", &confirmacao);
    if(confirmacao == 'y') {
        return 'y';
    } else {
        return 'n';
    }
}

void imprimirPaciente(Paciente paciente){
    printf("\n--------------------------------------");
    printf("\nId: %d",paciente.id);
    printf("\n\nDados Pessoais");
    printf("\nNome: %s",paciente.dadosPessoais.nome);
    printf("\nIdade: %d",paciente.dadosPessoais.idade);
    printf("\nData de nascimento: %s",paciente.dadosPessoais.dataNascimento);
    printf("\nCPF: %s",paciente.dadosPessoais.cpf);
    printf("\nTipo sanguíneo: %s",paciente.dadosPessoais.tipoSanguineo);
    printf("\nNome da Mãe: %s",paciente.dadosPessoais.filiacao.nomeMae);
    printf("\nNome do Pai: %s",paciente.dadosPessoais.filiacao.nomePai);
    printf("\nTelefone: %s",paciente.dadosPessoais.telefone);
    printf("\n\nDados Paciente");
    printf("\nData do Registro: %s", paciente.dataRegistro);
    printf("\n---- Doenças -----");
    for(int d=0;d < 20;d++) {
        if(paciente.doencas[d][0] == '\0'){
            break;
        }
        printf("\n%d: %s",d+1, paciente.doencas[d]);
    }
    printf("\n---------------------");
    printf("\n--------------------------------------\n\n");
}

void adicionarPaciente(Paciente paciente) {
    for(int i=0;i < 100;i++) {
        if(hospital.listaPacientes[i].id == 0) {
            hospital.idUltimoPaciente++;
            paciente.id = hospital.idUltimoPaciente;
            hospital.listaPacientes[i] = paciente;
            return;
        }
    }
}

void removerPaciente(int pacienteId) {
    Paciente novaListaPacientes[100];
    Paciente p;
    int indexNovaLista=0;
    for(int i=0;i < 100;i++) {
        novaListaPacientes[i] = p; // Bug fix;
        if(hospital.listaPacientes[i].id != pacienteId && hospital.listaPacientes[i].id != 0 ) {
            novaListaPacientes[indexNovaLista] = hospital.listaPacientes[i];
            indexNovaLista++;
        }
    }

    for(int i=0; i < 100;i++) {
        hospital.listaPacientes[i] = novaListaPacientes[i];
    }
}

Paciente criarPaciente() {
    Paciente p;
    system("CLS");
    printf("\nRegistrando novo Paciente");

    printf("\n----------------------------------------");
    printf("\nNome: ");
    gets(p.dadosPessoais.nome);
    fflush(stdin);

    printf("\n----------------------------------------");
    printf("\nIdade: ");
    scanf("%d", &p.dadosPessoais.idade);
    fflush(stdin);

    printf("\n----------------------------------------");
    printf("\nDigite a data no formato: dd/mm/aaaa");
    printf("\nData Nascimento: ");
    gets(p.dadosPessoais.dataNascimento);
    fflush(stdin);

    printf("\n----------------------------------------");
    printf("\nCPF: ");
    gets(p.dadosPessoais.cpf);
    fflush(stdin);

    printf("\n----------------------------------------");
    printf("\nPor favor, siga o exemplo de formatação: A+");
    printf("\nTipo sanguíneo: ");
    gets(p.dadosPessoais.tipoSanguineo);
    fflush(stdin);

    printf("\n----------------------------------------");
    printf("\nNome da Mãe: ");
    gets(p.dadosPessoais.filiacao.nomeMae);
    fflush(stdin);

    printf("\n----------------------------------------");
    printf("\nNome do Pai: ");
    gets(p.dadosPessoais.filiacao.nomePai);
    fflush(stdin);

    printf("\n----------------------------------------");
    printf("\nDigite apenas números para o telefone");
    printf("\nTelefone: ");
    gets(p.dadosPessoais.telefone);
    fflush(stdin);

    printf("\n----------------------------------------");
    printf("\nDigite a data no formato: dd/mm/aaaa");
    printf("\nData de Registro: ");
    gets(p.dataRegistro);
    fflush(stdin);

    int opcaoEditDoenca = -1;
    printf("\n----------------------------------------");
    printf("\nAdicionando doenças");
    for(int d=0;d<20;d++) {
        strcpy(p.doencas[d],"");
    }
    while(opcaoEditDoenca != 0) {
        char terminarDoenca = popupComfimacao("Digite y para adicionar doença e n para cancelar");
        if(terminarDoenca == 'n') {
            opcaoEditDoenca= 0;
        } else {
            printf("\nDigite o nome da doença: ");
            char doenca[255];
            getchar();
            fflush(stdin);
            gets(doenca);
            fflush(stdin);
            for(int d=0;d<20;d++) {
                if(p.doencas[d][0] == '\0'){
                    //Só adiciona uma doença nova se houver espaço vazio
                    strcpy(p.doencas[d],doenca);
                    break;
                }
            }
        }
        printf("\n-------------------------------------");
    }

    return p;

}

Paciente editarPaciente(Paciente p) {
    int opcaoEdit = -1;
    Paciente pModificado = p;
    while(opcaoEdit != 0) {
        //system clear
        system("CLS");
        imprimirPaciente(pModificado);
        printf("\nCódigo\t\tEditar\n");
        printf("   1\t\tNome\n");
        printf("   2\t\tIdade\n");
        printf("   3\t\tData nascimento\n");
        printf("   4\t\tCPF\n");
        printf("   5\t\tTipo Sanguíneo\n");
        printf("   6\t\tNome da Mãe\n");
        printf("   7\t\tNome do Pai\n");
        printf("   8\t\tTelefone\n");
        printf("   9\t\tData registro\n");
        printf("   10\t\tDoenças\n");
        printf("   0\t\tVoltar\n");
        scanf("%d", &opcaoEdit);
        fflush(stdin);
        if(opcaoEdit == 0) {
            continue;
        } else if (opcaoEdit == 1) {
            printf("\nNome: %s",p.dadosPessoais.nome);
            printf("\nNovo nome: ");
            gets(pModificado.dadosPessoais.nome);
            fflush(stdin);
        } else if (opcaoEdit == 2) {
            printf("\nIdade: %d",p.dadosPessoais.idade);
            printf("\nNova Idade: ");
            scanf("%d", &pModificado.dadosPessoais.idade);
            fflush(stdin);
        } else if (opcaoEdit == 3) {
            printf("\nData Nascimento: %s",p.dadosPessoais.dataNascimento);
            printf("\nDigite a data no formato: dd/mm/aaaa");
            printf("\nNova Data Nascimento: ");
            gets(pModificado.dadosPessoais.dataNascimento);
            fflush(stdin);
        } else if (opcaoEdit == 4) {
            printf("\nCPF: %s",p.dadosPessoais.cpf);
            printf("\nNovo CPF: ");
            gets(pModificado.dadosPessoais.cpf);
            fflush(stdin);
        }else if (opcaoEdit == 5) {
            printf("\nTipo Sanguíneo: %s",p.dadosPessoais.tipoSanguineo);
            printf("\nNovo tipo sanguíneo: ");
            gets(pModificado.dadosPessoais.tipoSanguineo);
            fflush(stdin);
        } else if (opcaoEdit == 6) {
            printf("\nNome da Mãe: %s",p.dadosPessoais.filiacao.nomeMae);
            printf("\nNovo nome da Mãe: ");
            gets(pModificado.dadosPessoais.filiacao.nomeMae);
            fflush(stdin);
        } else if (opcaoEdit == 7) {
            printf("\nNome do Pai: %s",p.dadosPessoais.filiacao.nomePai);
            printf("\nNovo nome do Pai: ");
            gets(pModificado.dadosPessoais.filiacao.nomePai);
            fflush(stdin);
        } else if (opcaoEdit == 8) {
            printf("\nTelefone: %s",p.dadosPessoais.telefone);
            printf("\nNovo Telefone: ");
            gets(pModificado.dadosPessoais.telefone);
            fflush(stdin);
        } else if (opcaoEdit == 9) {
            printf("\nData de Registro: %s",p.dataRegistro);
            printf("\nDigite a data no formato: dd/mm/aaaa");
            printf("\nNova Data de Registro: ");
            gets(pModificado.dataRegistro);
            fflush(stdin);
        } else if (opcaoEdit == 10) {
            int opcaoEditDoencas = -1;
            while(opcaoEditDoencas != 0) {
                system("CLS");
                printf("\n--------------------------------------");
                printf("\nEditando doenças");
                printf("\n");
                printf("\nIdentificador\t\tDoença");
                for(int d=0;d < 20;d++) {
                    if(pModificado.doencas[d][0] == '\0'){
                        //Se a doença estiver vazia então ele quebra o loop
                        break;
                    }
                    printf("\n      %d\t\t\t%s",d+1, pModificado.doencas[d]);
                }
                printf("\n-------------------------------------------");
                printf("\nDigite o Identificador da doença para editar/excluir");

                printf("\nCódigo\t\tComando\n");
                printf("\n   200\t\tAdicionar");
                printf("\n     0\t\tVoltar\n");
                scanf("%d", &opcaoEditDoencas);
                fflush(stdin);
                if(opcaoEditDoencas > 0 && opcaoEditDoencas <= 20) {
                    //São 20 doenças por paciente, ou seja, opção para editar será entre 1 e 20;
                    printf("\nEditando a doença: %s", pModificado.doencas[opcaoEditDoencas-1]);
                    printf("\nCódigo\t\tComando\n");
                    printf("\n   1\t\tEditar");
                    printf("\n   2\t\tExcluir");
                    printf("\n   0\t\tVoltar\n");
                    int indexDoenca = opcaoEditDoencas;
                    scanf("%d", &opcaoEditDoencas);
                    fflush(stdin);
                    if(opcaoEditDoencas == 1) {
                        char editDoenca[255];
                        printf("\nNovo nome da doença: ");
                        gets(editDoenca);
                        fflush(stdin);
                        printf("%s", editDoenca);
                        strcpy(pModificado.doencas[indexDoenca-1], editDoenca);
                    } else if(opcaoEditDoencas == 2) {
                        char novaListaDoencas[20][255];
                        int indexNovaLista=0;
                        for(int i=0;i < 20;i++) {
                            //Varre cada doença e checa se não é a doença escolhido para remover
                            if(i != indexDoenca-1 && pModificado.doencas[i][0] != '\0' ) {
                                //Se não é a doença para remover então ele coloca na nova lista;
                                strcpy(novaListaDoencas[indexNovaLista], pModificado.doencas[i]);
                                indexNovaLista++;
                            }
                        }

                       for(int i=0; i < 20;i++) {
                            //Substitui cada item da doença pela nova lista;
                            if(i >= indexNovaLista) {
                                strcpy(pModificado.doencas[i], "");
                            } else {
                                strcpy(pModificado.doencas[i], novaListaDoencas[i]);
                            }
                        }
                    } else if(opcaoEditDoencas == 0) {
                        opcaoEditDoencas = -1;
                    }

                } else if(opcaoEditDoencas == 200) {
                    char novoDoenca[255];
                    printf("\nDigite a nova doença: ");
                    gets(novoDoenca);
                    fflush(stdin);
                    for(int d=0;d<20;d++) {
                        if(pModificado.doencas[d][0] == '\0'){
                            //Se tiver um espaço vazio para adicionar, então adiciona
                            strcpy(pModificado.doencas[d],novoDoenca);
                            break;
                        }
                    }
                }
            }
        }
    }

    int confirmarModificacao = popupComfimacao("Digite y para confirmar modificações e n para cancelar");
    if(confirmarModificacao == 'y') {
        return pModificado;
    } else {
        return p;
    }
}

void salvarArquivo(Hospital hospitalParaSalvar) {
    FILE *outfile;

    outfile = fopen("hospital.dat", "w");
    if (outfile == NULL)
    {
        fprintf(stderr, "\nError opened file\n");
        exit(1);
    }

    fwrite(&hospitalParaSalvar, sizeof(Hospital), 1, outfile);

    system("CLS");
    printf("\n------- Salvando --------");
    if (fwrite != 0)
        printf("\nArquivos salvos com sucesso !\n");
    else
        printf("\nErro ao salvar dados!\n");
    printf("\n--------------------");
    sleep(2);
    system("CLS");
    printf("\n.");
    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    sleep(1);
    fflush(stdin);

    fclose(outfile);
}

Hospital lerArquivo() {
    FILE *infile;
    Hospital hospitalLida;

    //Esse loop for eu tentei arrumar o bug dos ids, no programa so aparece o paciente quando o id do paciente é diferente de 0
    for(int i=0; i < 100;i++) {
        hospitalLida.listaPacientes[i].id = 0;
    }

    infile = fopen("hospital.dat", "r");
    if (infile == NULL)
    {
        fprintf(stderr, "\nErro ao abrir o arquivo!\n");
        exit(1);
    }

    system("CLS");
    printf("\n------- Lendo o Arquivo --------\n");


    sleep(1);
    printf(".");
    sleep(1);
    printf(".");
    while (fread(&hospitalLida, sizeof(Hospital), 1, infile)){
    }

    // Outro loop mudando os ids dos pacientes para diminuir a quantidade de bug que aparece por causa da linguagem C e suas atribuições de valores aleatórios
    for(int i=0; i < 100;i++) {
        if(hospitalLida.listaPacientes[i].id <= 0 || hospitalLida.listaPacientes[i].id > hospitalLida.idUltimoPaciente) {
            hospitalLida.listaPacientes[i].id = 0;
        }
    }

    sleep(1);
    printf(".");
    sleep(1);
    fclose(infile);

    return hospitalLida;
}

int main()
{
    //Remove os erros de compilação na língua portuguesa
    setlocale(LC_ALL, "Portuguese");


    //Paginação do menu, a partir destes números é possível pegar qual foi o último menu aberto
    int menu[menuSize] = {0,0};

    //Configuração do Menu;
    int opcaoMenu = -1;
    int currentMenu = 0;
    int exit = 0;

    //Enquanto o usuário não sair do programa continua no programa;
    while(exit != 1) {
        //Toda vez que o loop roda ele limpa a tela;
        system("CLS");

        //Imprime o menu na tela e recebe a opção do usuário;
        opcaoMenu = menuBuilder(menu);
        fflush(stdin);


        if(currentMenu == 0 && opcaoMenu == 0) {
            //Se estiver no menu inicial e o usuário escolher a opção 0, então fechar o programa;
            char confirmacao = popupComfimacao("\n\tTem certeza que deseja sair do menu? digite y para sim e n para não");
            fflush(stdin);
            if(confirmacao == 'y') {
                //Exit == 1 sai do programa;
                exit = 1;
            }
            continue;
        } else {
            if(opcaoMenu == 0) {
                //O usuário não está no menu inicial e decidir voltar
                currentMenu = voltarMenu(menu);
                continue;
            }
            for(int i=0; i < menuSize;i++) {
                //Varre o vetor do menu de trás para frente
                if(menu[i] == 0) {
                    //Se estiver no menu inicial
                    if(currentMenu == 0) {
                            if(opcaoMenu == 1) {
                                //Escolheu a opção de editar a Instituição
                                menu[i] = 1;
                                currentMenu = 1;
                            } else if(opcaoMenu == 2) {
                                //Escolheu a opção de editar os Pacientes
                                menu[i] = 2;
                                currentMenu = 2;
                            } else if(opcaoMenu == 3) {
                                //Escolheu a opção de salvar
                                char confirmacaoSalvar = popupComfimacao("Você está prestes a salvar os dados e sobreescrever os dados salvos anteriormente, digite y para confirmar e n para cancelar");
                                if(confirmacaoSalvar == 'y') {
                                    salvarArquivo(hospital);
                                }
                            } else if(opcaoMenu == 4) {
                                //Escolheu a opção de ler o arquivo
                                char confirmacaoSalvar = popupComfimacao("Você está prestes a carregar os dados e sobreescrever os dados salvos, digite y para confirmar e n para cancelar");
                                if(confirmacaoSalvar == 'y') {
                                    hospital = lerArquivo();
                                }
                            }
                            break;
                    } else if(currentMenu == 1) {
                        //Está no menu da Instituição
                        system("CLS");
                        if(opcaoMenu == 1) {
                            printf("Digite o novo nome do Hospital: ");
                            gets(hospital.nome);
                        } else if(opcaoMenu == 2) {
                            char novoEndereco[255];
                            printf("Digite o novo endereço do Hospital: ");
                            gets(hospital.endereco);
                        } else if(opcaoMenu == 3) {
                            printf("Digite o novo telefone do Hospital: ");
                            gets(hospital.telefone);
                        }
                        fflush(stdin);
                        break;
                    } else if(currentMenu == 2) {
                        system("CLS");
                        // Menu Gerenciador de Pacientes
                        if(opcaoMenu == 1) {
                                // Listar Pacientes
                                for(int c=0;c < 100;c++) {
                                    if(hospital.listaPacientes[c].id == 0) {
                                        //Checa se há paciente, se não tiver ele sai do loop;
                                        break;
                                    }
                                    system("CLS");
                                    fflush(stdin);
                                    if(hospital.listaPacientes[c].id == 0) {
                                        continue;
                                    }
                                    int opcaoPaciente;
                                    printf("\n-------------------------------------");
                                    printf("\nPaciente");
                                    printf("\nId: %d", hospital.listaPacientes[c].id);
                                    printf("\nNome: %s", hospital.listaPacientes[c].dadosPessoais.nome);
                                    printf("\n-------------------------------------\n\n");
                                    printf("\nCódigo\t\tComando\n");
                                    printf("   1\t\tEditar Paciente\n");
                                    printf("   2\t\tExcluir Paciente\n");
                                    printf("   3\t\tAnterior\n");
                                    printf("   4\t\tPróximo\n");
                                    printf("   0\t\tVoltar\n");
                                    scanf("%d",&opcaoPaciente);
                                    if(opcaoPaciente == 0) {
                                        break;
                                    } else if(opcaoPaciente == 1) {
                                        hospital.listaPacientes[c] = editarPaciente(hospital.listaPacientes[c]);
                                        c--;
                                    } else if(opcaoPaciente == 2) {
                                        char confirmarRomover = popupComfimacao("\nVocê está prestes a remover este paciente, digite y para confirmar e n para cancelar");
                                        if(confirmarRomover == 'y') {
                                            removerPaciente(hospital.listaPacientes[c].id);
                                        }
                                        if(c > 0) {
                                            c-=2;
                                        } else {
                                            c--;
                                        }
                                    } else if(opcaoPaciente == 3) {
                                        if(c > 0) {
                                            c-=2;
                                        } else {
                                            c--;
                                        }
                                        continue;
                                    } else if(opcaoPaciente == 4) {
                                        if(c >= 99) {
                                            c=98;
                                        } else if(hospital.listaPacientes[c+1].id == 0) {
                                            c--;
                                        }
                                    } else {
                                        c--;
                                    }
                                }
                        } else if(opcaoMenu == 2) {
                            adicionarPaciente(criarPaciente());
                        }
                        fflush(stdin);
                        break;
                    }
                }
            }
        }
    }

    goodBye();

    return 0;
}
