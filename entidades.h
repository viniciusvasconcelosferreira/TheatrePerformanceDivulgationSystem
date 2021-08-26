#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string.h>

using namespace std;

class Participante {
private:
    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;
public:
    void getParticipante(Matricula *matricula_partipante, Nome *nome_participante, Nome *sobrenome_participante, Email *email_participante, Telefone *telefone_participante, Senha *senha_participante, Cargo *cargo_participante);
    void setParticipante(string novo_nome,string novo_sobrenome,string novo_email,string novo_telefone,string senha, string novo_cargo);

};

class Peca {
private:
    Codigo identificador;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;
public:
    void getPeca(Codigo *codigo_peca,Nome *nome_peca,Tipo *tipo_peca,Classificacao *classificacao_peca);
    void setPeca(string novo_codigo,string novo_nome,int novo_tipo,string nova_classificacao);
};

class Sessao {
private:
    Codigo identificador;
    Data data;
    Horario horario;
public:
    void getSessao(Codigo *codigo_sessao,Data *data_sessao,Horario *horario_sessao);
    void setSessao(string novo_codigo,string nova_data,string novo_horario);
};

class Sala {
private:
    Codigo identificador;
    Nome nome;
    Capacidade capacidade;
public:
    void getSala(Codigo *codigo_sala,Nome *nome_sessao,Capacidade *capacidade_sessao);
    void setSala(string novo_codigo,string novo_nome,int nova_capacidade);
};


#endif // ENTIDADES_H_INCLUDED
