#include <stdexcept>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dominios.h"

using namespace std;

void Matricula::setMatricula(int nova_matricula) throw (invalid_argument) {
    validar(nova_matricula);
    matricula = nova_matricula;
}

bool Matricula::hasDuplicates(int nova_matricula) {
    int aux_init[10] = {0};

    if(nova_matricula) return true;

    while(nova_matricula != 0) {
        if(aux_init[nova_matricula%10]) return true;
        aux_init[nova_matricula%10] = 1;
        nova_matricula /= 10;
    }

    return false;
}

void Matricula::validar(int nova_matricula) throw (invalid_argument) {
    int SUCESSO_TAMANHO = 0;
    int SUCESSO_REPETICAO = 0;

    if(nova_matricula > LIMITE) {
        SUCESSO_TAMANHO = 1;
    }

    if(nova_matricula == 00000 || nova_matricula == 11111 || nova_matricula == 22222 || nova_matricula == 33333 || nova_matricula == 44444 || nova_matricula == 55555 || nova_matricula == 66666 || nova_matricula == 77777 || nova_matricula == 88888 || nova_matricula == 99999) {
        SUCESSO_REPETICAO = 1;
    }

    if(SUCESSO_REPETICAO != 0 && SUCESSO_TAMANHO != 0 && hasDuplicates(nova_matricula) == true) {
        throw invalid_argument("Matricula invalida!");
    }


}

void Nome::setNome(string novo_nome) throw (invalid_argument) {
    validar(novo_nome);
    int i;
    for(i = 0; i<LIMITE; i++) {
        nome[i] = novo_nome[i];
    }

    nome[LIMITE] = '\0';
}
void Nome::validar(string novo_nome) throw (invalid_argument) {
    int SUCESSO = 0;
    int i = 0;
    int string_contem_letra = 1;
    int tamanho_real_palavra;
    char char_atual;
    char char_anterior;

    tamanho_real_palavra = novo_nome.size();

    while(i < tamanho_real_palavra) {

        char_atual = novo_nome[i];

        if(i > 0) {
            char_anterior = novo_nome[i-1];
        }
        if((i > 0) && (char_atual == ' ') && (char_anterior == ' ')) {
            SUCESSO = 1;
        }
        if((char_atual >= 65) && (char_atual <=122) && (string_contem_letra != 0)) {
            string_contem_letra = 0;
        }

        i++;
    }

    if((SUCESSO != 0) || (string_contem_letra == 1)) {
        throw invalid_argument("Nome invalido!");
    }
}

void Email::setEmail(string novo_email) throw (invalid_argument) {
    validar(novo_email);

    int i;

    for(i = 0; i < LIMITE; i++) {
        email[i] = novo_email[i];
    }

    email[LIMITE] = '\0';
}
void Email::validar(string novo_email) throw (invalid_argument) {
    int SUCESSO = 0,arroba = -1, ponto = -1,i;

    if(isalpha(novo_email[0]) != true) {
        SUCESSO = 1;
    }

    for(i = 0; i<novo_email.size(); i++) {
        if(novo_email[i] == '@') {
            arroba = i;
        } else if(novo_email[i] == '.') {
            ponto = i;
        }
    }

    if (arroba == -1 || ponto == -1) {
        SUCESSO = 1;
    }


    if (arroba > ponto) {
        SUCESSO = 1;
    }

    if((ponto >= (strlen(novo_email) - 1))) {
        SUCESSO = 1;
    }

    if(SUCESSO != 0) {
        throw invalid_argument("Email invalido!");
    }
}

void Telefone::setTelefone(string novo_telefone) throw (invalid_argument) {
    validar(novo_telefone);

    int i;

    for(i = 0; i < LIMITE; i++) {
        telefone[i] = novo_telefone[i];
    }

    telefone[LIMITE] = '\0';
}
//TODO: FAZER DEPOIS
void Telefone::validar(string novo_telefone) throw (invalid_argument) {
    string dd = telefone.substr(0,2);
    string numero = telefone.substr(2);
    //int dd_convertido = stoi(dd);
//    int numero_convertido = stoi(numero);
    int SUCESSO_CODIGO = 1;
    int SUCESSO_NUMERO = 0;
//    int codigos[66] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33,
//                       34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68,
//                       69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99
//                      };
    string codigos[66] = {"11", "12", "13", "14", "15", "16", "17", "18", "19", "21", "22", "24", "27", "28", "32", "33", "34", "35", "37", "38", "41", "42", "43", "44", "45", "46", "47", "48", "49", "51", "53", "54", "55", "61", "62", "63", "64", "65", "66", "67", "68", "69", "71", "73", "74", "75", "77", "79", "81", "82", "83", "84", "85", "86", "87", "88", "89", "91", "92", "93", "94", "95", "96", "97", "98", "99"};

    for(int i = 0; i < 66; i++) {
        if(codigos[i] == dd) {
            SUCESSO_CODIGO = 0;
            break;
        }
    }

    if(numero.size() > LIMITE) {
        SUCESSO_NUMERO = 1;
    }

    if(SUCESSO_CODIGO != 0 && SUCESSO_NUMERO != 0){
        throw invalid_argument("Numero invalido!");
    }


}

void Senha::setSenha(string nova_senha) throw (invalid_argument) {
    validar(nova_senha);

    int i;

    for(i = 0; i < LIMITE; i++) {
        senha[i] = nova_senha[i];
    }

    senha[LIMITE] = '\0';
}
void Senha::validar(string nova_senha) throw (invalid_argument) {
    int SUCESSO_CARACTERE_ESPECIAL = 0;
    int SUCESSO_DIGITO = 0;
    int SUCESSO_LETRA = 0;
    int SUCESSO_IGUALDADE = 0;
    int SUCESSO = 0;
    int i,j,k;

    if(nova_senha.size() > LIMITE) {
        SUCESSO = 1;
    }

    for(i = 0; i < nova_senha.size(); i++) {
        if (!((nova_senha[i] >= 65 && nova_senha[i] <= 90)
                || (nova_senha[i] >= 97 && nova_senha[i] <= 122))) {
            SUCESSO_LETRA = 1;
        }

        if (!(nova_senha[i] >= 48 && nova_senha[i] <= 57)) {
            SUCESSO_DIGITO = 1;
        }

        if(!((nova_senha[i]>= 33 && nova_senha[i]<=47) || (nova_senha[i]>= 58 && nova_senha[i]<=64) || (nova_senha[i]>= 91 && nova_senha[i]<=96)|| (nova_senha[i]>= 123 && nova_senha[i]<=126))) {
            SUCESSO_CARACTERE_ESPECIAL = 1;
        }

    }

    for(j = 0; j < nova_senha.size(); j++) {
        for(k = j+1; k <nova_senha.size(); k++) {
            if(nova_senha[j] == nova_senha[k]) {
                SUCESSO_IGUALDADE = 1;
            }
        }
    }

    if(SUCESSO != 0 && SUCESSO_LETRA != 0 && SUCESSO_DIGITO != 0 && SUCESSO_CARACTERE_ESPECIAL != 0 && SUCESSO_IGUALDADE != 0) {
        throw invalid_argument("Senha invalida!");
    }
}

void Cargo::setCargo(string novo_cargo) throw (invalid_argument) {
    validar(novo_cargo);
    cargo = novo_cargo
}
void Cargo::validar(string novo_cargo) throw (invalid_argument) {
    int SUCESSO = 0;
    int i;
    for(i = 0; i < 6; i++) {
        if(cargos[i] != novo_cargo) {
            SUCESSO = 1;
        }
    }

    if(SUCESSO !=0 ) {
        throw invalid_argument("Cargo invalido!");
    }

}

void Codigo::setCodigo(string novo_codigo) throw (invalid_argument) {
    validar(novo_codigo);

    int i;

    for(i = 0; i < LIMITE; i++) {
        codigo[i] = novo_codigo[i];
    }

    codigo[LIMITE] = '\0';
}
void Codigo::validar(string novo_codigo) throw (invalid_argument) {
    int SUCESSO_TAMANHO = 0;
    int SUCESSO_MAIUSCULA = 0;
    int SUCESSO_DIGITO = 0;

    if(novo_codigo.size() > LIMITE) {
        SUCESSO_TAMANHO = 1;
    }

    if(isupper(novo_codigo[0]) == false || isupper(novo_codigo[1]) == false) {
        SUCESSO_MAIUSCULA = 1;
    } else if(isdigit(novo_codigo[2]) == false || isdigit(novo_codigo[3])== false || isdigit(novo_codigo[4])== false || isdigit(novo_codigo[5])== false ) {
        SUCESSO_DIGITO = 1;
    }

    if(SUCESSO_TAMANHO != 0 && SUCESSO_MAIUSCULA != 0 && SUCESSO_DIGITO != 0) {
        throw invalid_argument("Codigo invalido!");
    }

}

void Tipo::setTipo(string novo_tipo) throw (invalid_argument) {
    validar(novo_tipo);
    tipo = novo_tipo
}
void Tipo::validar(string novo_tipo) throw (invalid_argument) {
    int SUCESSO = 0;
    int i;
    for(i = 0; i < 9; i++) {
        if(tipos[i] != novo_tipo) {
            SUCESSO = 1;
        }
    }

    if(SUCESSO !=0 ) {
        throw invalid_argument("Tipo invalido!");
    }

}

void Classificacao::setClassificacao(string nova_classificacao) throw (invalid_argument) {
    validar(nova_classificacao);
    classificacao = nova_classificacao
}
void Classificacao::validar(string nova_classificacao) throw (invalid_argument) {
    int SUCESSO = 0;
    int i;
    for(i = 0; i < 6; i++) {
        if(classificacoes[i] != nova_classificacao) {
            SUCESSO = 1;
        }
    }

    if(SUCESSO !=0 ) {
        throw invalid_argument("Classificacao invalida!");
    }

}

void Data::setData(string nova_data) throw (invalid_argument) {
    int data_int = 0;

    data_int = ((nova_data[5] - 48) + ((nova_data[4] - 48) *10) + ((nova_data[3] - 48)*100) + ((nova_data[2] - 48) * 1000) + ((nova_data[1] - 48) * 10000) + ((nova_data[0] - 48) * 100000)  );

    validar(data_int);

    int k;

    for(k = 0; k<6 ; k++) {
        data[k] = nova_data[k];
    }

    data[6] = '\0';
}
void Data::validar(int data_int) throw (invalid_argument) {

    int SUCESSO = 0;

    int num_dia = 0;
    int num_mes = 0;
    int num_ano = 0;

    int ano_validar_bissexto = 0;
    int fevereiro = 2;
    int limite_dias_fevereiro_ano_bissexto = 29;

    num_dia = data_int % 100;
    data_int = data_int/100;

    num_mes = data_int % 100;
    data_int = data_int/100;

    num_ano = data_int%100;
    data_int = data_int/100;

    if((num_dia > 31) || (num_dia <= 0)) {
        SUCESSO = 1;
    }
    if((num_mes > 12) || (num_mes <= 0)) {
        SUCESSO = 1;
    }
    if((num_ano > 99) || (num_ano <= 0)) {
        SUCESSO = 1;
    }

    ano_validar_bissexto = num_ano + 2000;

    if((ano_validar_bissexto % 4 == 0) && (ano_validar_bissexto % 100 != 0)) {
        if((num_mes == fevereiro) && (num_dia > limite_dias_fevereiro_ano_bissexto)) {
            SUCESSO = 1;
        }
    }

    if(SUCESSO != 0) {
        throw invalid_argument("Data invalida!");
    }

}

void Horario::setHorario(string novo_horario) throw (invalid_argument) {
    validar(novo_horario);

    int i = 0;

    while(i < LIMITE) {
        horario[i] = novo_horario[i];
        i++;
    }

    horario[LIMITE] = '\0';

}
void Horario::validar(string novo_horario) throw (invalid_argument) {

    char HH[2];
    int HHaux, MMaux;
    char MM[2];
    int i, j;

    if(novo_horario[LIMITE] != '\0') {
        throw invalid_argument("Formato invalido de horario (tamanho excedido)!");
    }

    for(i = 0; i < 2; i++) {
        HH[i] = novo_horario[i];
    }

    HH[2] = '\0';
    HHaux = atoi(HH);

    for(j = 3; j < LIMITE; j++) {
        MM[j-3] = novo_horario[j];
    }
    MM[2] = '\0';
    MMaux = atoi(MM);

    if(novo_horario[2] != ':') {

        throw invalid_argument("Formato invalido de horario!");
    }

    if( HHaux < 0 ||  HHaux > 23 ) {

        throw invalid_argument("HH invalido!");

    }

    if(MMaux != 0 || MMaux != 15 || MMaux != 30 || MMaux != 45) {
        throw invalid_argument("MM invalido!");
    }

}

void Capacidade::setCapacidade(int nova_capacidade) throw (invalid_argument) {
    validar(nova_capacidade);
    capacidade = nova_capacidade;
}
void Capacidade::validar(int nova_capacidade) throw (invalid_argument) {
    int SUCESSO = 0;

    if(nova_capacidade != 100 || nova_capacidade != 200 || nova_capacidade != 300 || nova_capacidade != 400 || nova_capacidade != 500) {
        throw invalid_argument("Capacidade invalida!");
    }
}
