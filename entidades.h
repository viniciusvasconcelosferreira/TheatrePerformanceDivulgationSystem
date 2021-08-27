#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <iostream>
#include <exception>
#include <stdexcept>
#include <string.h>

using namespace std;

// Declaração de classe.

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Participante.
///

class Participante {
private:
    // Atributo de classe.
    Matricula matricula;
    Nome nome;
    Nome sobrenome;
    Email email;
    Telefone telefone;
    Senha senha;
    Cargo cargo;
public:

    ///
    /// Obt&eacute;m os dados do Participante.
    ///
    /// @return Matricula, Nome, Sobrenome, Email, Telefone, Senha e Cargo do Participante.
    ///
    void getParticipante(Matricula *matricula_partipante, Nome *nome_participante, Nome *sobrenome_participante, Email *email_participante, Telefone *telefone_participante, Senha *senha_participante, Cargo *cargo_participante);

    ///
    /// Atribui valor para os objetos do participante
    ///
    /// @param string Nome, string Sobrenome, string Email, string Telefone, string Senha, string Cargo.
    ///
    /// @throw invalid_argument
    ///
    void setParticipante(string novo_nome,string novo_sobrenome,string novo_email,string novo_telefone,string nova_senha, string novo_cargo);

};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Pe&ccedil;a.
///
class Peca {
private:
    // Atributo de classe.
    Codigo identificador;
    Nome nome;
    Tipo tipo;
    Classificacao classificacao;
public:
    // Metodos de classe.

    ///
    /// Obt&eacute;m os dados da Pe&ccedil;a.
    ///
    /// @return C&oacute;digo, Nome, Tipo e Classifica&ccedil;&atilde;o da Pe&ccedil;a.
    ///
    void getPeca(Codigo *codigo_peca,Nome *nome_peca,Tipo *tipo_peca,Classificacao *classificacao_peca);

    ///
    /// Atribui valor para os objetos da pe&ccedil;a.
    ///
    /// @param string C&oacute;digo, string Nome, string Tipo, string Telefone, string Classifica&ccedil;&atilde;o.
    ///
    /// @throw invalid_argument
    ///
    void setPeca(string novo_codigo,string novo_nome,string novo_tipo,string nova_classificacao);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Sess&atilde;o.
///
class Sessao {
private:
    // Atributo de classe.
    Codigo identificador;
    Data data;
    Horario horario;
public:
    // Metodos de classe.

    ///
    /// Obt&eacute;m os dados da Sess&atilde;o.
    ///
    /// @return C&oacute;digo, Data e Hor&aacute;rio da Sess&atilde;o.
    ///
    void getSessao(Codigo *codigo_sessao,Data *data_sessao,Horario *horario_sessao);

    ///
    /// Atribui valor para os objetos da sess&atilde;o.
    ///
    /// @param string C&oacute;digo, string Data, string Hor&aacute;rio.
    ///
    /// @throw invalid_argument
    ///
    void setSessao(string novo_codigo,string nova_data,string novo_horario);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Sala.
///
class Sala {
private:
    Codigo identificador;
    Nome nome;
    Capacidade capacidade;
public:
    // Metodos de classe.

    ///
    /// Obt&eacute;m os dados da Sala.
    ///
    /// @return C&oacute;digo, Nome e Capacidade da Sala.
    ///
    void getSala(Codigo *codigo_sala,Nome *nome_sessao,Capacidade *capacidade_sessao);

    ///
    /// Atribui valor para os objetos da sala.
    ///
    /// @param string C&oacute;digo, string Nome, int Capacidade.
    ///
    /// @throw invalid_argument
    ///
    void setSala(string novo_codigo,string novo_nome,int nova_capacidade);
};


#endif // ENTIDADES_H_INCLUDED
