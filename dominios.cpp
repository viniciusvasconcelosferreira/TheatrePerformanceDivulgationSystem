#include <stdexcept>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "dominios.h"

using namespace std;

//TODO: VERIFICAR CLASS MATRICULA
void Matricula::setMatricula(int nova_matricula) throw (invalid_argument) {
    validar(nova_matricula);
    matricula = nova_matricula;
}
void Matricula::validar(int nova_matricula) throw (invalid_argument) {
    if(nova_matricula > LIMITE) {
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
    int SUCESSO_CODIGO = 0;
    int SUCESSO_NUMERO = 0;
    int codigos[66] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33,
                       34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68,
                       69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99
                      };
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

    if(SUCESSO_TAMANHO != 0 && SUCESSO_MAIUSCULA != 0 && SUCESSO_DIGITO != 0){
        throw invalid_argument("Codigo invalido!");
    }

}

