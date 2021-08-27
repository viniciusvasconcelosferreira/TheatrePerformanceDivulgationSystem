#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

///< Declaração de classe.

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Matricula.
///
/// Regras de formato:
///
/// - Matricula v&aacute;lida somente se a quantidade de d&iacute;gitos <strong>n&atilde;o for maior que 5</strong>.
/// - Matricula v&aacute;lida somente se <strong>n&atilde;o</strong> houver d&iacute;gitos duplicados.
/// - Matricula v&aacute;lida somente se estiver no formato XXXXX onde cada X &eacute; um d&iacute;gito (0-9).
///

class Matricula {
private:
    ///< Atributos de classe.
    int matricula;
    const static int LIMITE = 99999; ///< Constante.
    void validar(int) throw (invalid_argument);
public:
    ///< Metodos de classe.

    ///
    /// Obt&eacute;m os dados da Matricula.
    ///
    /// @return Matricula
    ///
    int getMatricula() const {
        return matricula;
    }

    ///
    /// Atribui valor para os objetos da matricula
    ///
    /// @param int Matricula.
    ///
    /// @throw invalid_argument
    ///
    void setMatricula(int) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Nome.
///
/// Regras de formato:
///
/// - Nome v&aacute;lido somente se for de 5 a 20 caracteres podendo ser letra (A-Z ou a-z), ponto (.) ou espa&ccedil;o em branco.
/// - Nome v&aacute;lido somente se caso haja presen&ccedil;a de ponto (.), dever&aacute; ser precedido de letra.
/// - Nome v&aacute;lido somente se n&atilde;o houver espa&ccedil;os em branco em sequ&ecirc;ncia.
/// - Nome v&aacute;lido somente se primeira letra de cada termo &eacute; letra mai&uacute;scula (A-Z).
///

class Nome {
private:
    ///< Atributos de classe.
    const static int LIMITE = 20;
    char nome[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados do Nome.
    ///
    /// @return Nome
    ///
    string getNome() {
        return nome;
    }

    ///
    /// Atribui valor para os objetos do nome
    ///
    /// @param string Nome.
    ///
    /// @throw invalid_argument
    ///
    void setNome(string) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Email.
///
/// Regras de formato:
///
/// - Email v&aacute;lido somente se estiver no formato <i>parte-local@dom&iacute;nio</i> onde <i>parte-local</i> &eacute; composta por at&eacute; 64 caracteres e <i>dom&iacute;nio</i> &eacute; composto por at&eacute; 255 caracteres.
/// - Caractere pode ser letra mai&uacute;scula (A-Z) ou letra min&uacute;scula (a-z).
/// - Caractere pode ser d&iacute;gito (0-9).
/// - Caractere pode ser <code>! # $ % & ' * + - / = ? ^ _ ` { | } ~</code>
/// - Caractere pode ser ponto (.) desde que n&atilde;o seja o primeiro ou o &uacute;ltimo caractere e que n&atilde;o ocorra em sequ&ecirc;ncia
///

class Email {
private:
    ///< Atributos de classe.
    const static int LIMITE = 319;
    char email[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados do Email.
    ///
    /// @return Email
    ///
    string getEmail() {
        return email;
    }

    ///
    /// Atribui valor para os objetos do email
    ///
    /// @param string Email.
    ///
    /// @throw invalid_argument
    ///
    void setEmail(string) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Telefone.
///
/// Regras de formato:
///
/// - Formato (XX)-YYYYYYYYY
/// - XX &eacute; um dos seguintes c&oacute;digos: 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 24, 27, 28, 32, 33, 34, 35, 37, 38, 41, 42, 43, 44, 45, 46, 47, 48, 49, 51, 53, 54, 55, 61, 62, 63, 64, 65, 66, 67, 68, 69, 71, 73, 74, 75, 77, 79, 81, 82, 83, 84, 85, 86, 87, 88, 89, 91, 92, 93, 94, 95, 96, 97, 98, 99.
/// - Cada Y &eacute; d&iacute;gito (0-9).
/// - <strong>N&atilde;o existe n&uacute;mero de telefone 000000000</strong>.
///

class Telefone {
private:
    ///< Atributos de classe.
    const static int LIMITE = 11;
    char telefone[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados do Telefone.
    ///
    /// @return Telefone
    ///
    string getTelefone() {
        return telefone;
    }

    ///
    /// Atribui valor para os objetos do telefone
    ///
    /// @param string Telefone.
    ///
    /// @throw invalid_argument
    ///
    void setTelefone(string) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Senha.
///
/// Regras de formato:
///
/// - Formato XXXXXXXX
/// - Cada caractere X &eacute; letra (A-Z ou a-z), d&iacute;gito (0-9) ou caractere especial.
/// - S&atilde;o poss&iacute;veis caracteres especiais <code>! @ # $ % &amp; ? </code>
/// - <strong>N&atilde;o existe caracter repetido</strong>.
/// - Existe pelo menos uma letra (mai&uacute;scula ou min&uacute;scula), um d&iacute;gito e um caractere especial.
///

class Senha {
private:
    ///< Atributos de classe.
    const static int LIMITE = 8;
    char senha[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados da Senha.
    ///
    /// @return Senha
    ///
    string getSenha() {
        return senha;
    }

    ///
    /// Atribui valor para os objetos da senha
    ///
    /// @param string Senha.
    ///
    /// @throw invalid_argument
    ///
    void setSenha(string) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Cargo.
///
/// Regras de formato:
///
/// - Cargo somente &eacute; valido <strong>se estiver presente</strong> dentre os poss&iacute;veis cargos: ator, cen&oacute;grafo, figurinista, maquiador, sonoplasta, iluminador
///


class Cargo {
private:
    ///< Atributos de classe.
    const static string cargos[6] = {"ator", "cenógrafo", "figurinista", "maquiador", "sonoplasta", "iluminador"};
    string cargo;
    void validar(string) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados do Cargo.
    ///
    /// @return Senha
    ///
    string getCargo() {
        return cargo;
    }

    ///
    /// Atribui valor para os objetos do cargo
    ///
    /// @param string Cargo.
    ///
    /// @throw invalid_argument
    ///
    void setCargo(string) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe C&oacute;digo.
///
/// Regras de formato:
///
/// - Formato LLDDDD
/// - Cada L &eacute; letra mai&uacute;scula (A-Z).
/// - Cada D &eacute; d&iacute;gito (0-9).
///

class Codigo {
private:
    ///< Atributos de classe.
    const static int LIMITE = 6;
    char codigo[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados do C&oacute;digo.
    ///
    /// @return C&oacute;digo
    ///
    string getCodigo() {
        return codigo;
    }

    ///
    /// Atribui valor para os objetos do c&oacute;digo
    ///
    /// @param string C&oacute;digo.
    ///
    /// @throw invalid_argument
    ///
    void setCodigo(string) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Tipo.
///
/// Regras de formato:
///
/// - Tipo somente &eacute; valido <strong>se estiver presente</strong> dentre os poss&iacute;veis tipos: auto, com&eacute;dia, drama, farsa, melodrama, mon&oacute;logo, musical, &oacute;pera, revista
///

class Tipo {
private:
    ///< Atributos de classe.
    const static string tipos[9] = {"auto", "comédia", "drama", "farsa", "melodrama", "monólogo", "musical", "ópera", "revista"};
    string tipo;
    void validar(string) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados do Tipo.
    ///
    /// @return Tipo
    ///
    string getTipo() {
        return tipo;
    }

    ///
    /// Atribui valor para os objetos do tipo
    ///
    /// @param string Tipo.
    ///
    /// @throw invalid_argument
    ///
    void setTipo(string) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Classifica&ccedil;&atilde;o.
///
/// Regras de formato:
///
/// - Classifica&ccedil;&atilde;o v&aacute;lida somente <strong>se estiver presente</strong> dentre as poss&iacute;veis classifica&ccedil;&otilde;es: livre, 10, 12, 14, 16, 18
///

class Classificacao {
private:
    ///< Atributos de classe.
    const static string classificacoes[6] = {"livre", "10", "12", "14", "16", "18"};
    string classificacao;
    void validar(string) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados da Classifica&ccedil;&atilde;o.
    ///
    /// @return Classifica&ccedil;&atilde;o
    ///
    string getClassificacao() {
        return classificacao;
    }

    ///
    /// Atribui valor para os objetos da classifica&ccedil;&atilde;o
    ///
    /// @param string Classifica&ccedil;&atilde;o.
    ///
    /// @throw invalid_argument
    ///
    void setClassificacao(string) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Data.
///
/// Regras de formato:
///
/// - Formato DD/MM/AAAA
/// - 01 a 31 em DD.
/// - 01 e 12 em MM.
/// - 2000 a 9999 em AAAA.
/// - Data considera a ocorr&ecirc;ncia de anos bissextos.
///

class Data {
private:
    ///< Atributos de classe.
    const static int LIMITE = 6;
    char data[LIMITE+1];
    void validar(int) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados da Data.
    ///
    /// @return Data
    ///
    string getData() {
        return data;
    }

    ///
    /// Atribui valor para os objetos da data
    ///
    /// @param string Data.
    ///
    /// @throw invalid_argument
    ///
    void setData (string) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Hor&aacute;rio.
///
/// Regras de formato:
///
/// - Formato esperado HH:MM
/// - Em HH tem-se indica&ccedil;&atilde;o de hor&aacute;rio : 00 a 23
/// - Em MM tem-se indica&ccedil;&atilde;o de minuto : 00, 15, 30, 45
///

class Horario {
private:
    ///< Atributos de classe.
    const static int LIMITE = 5;
    char horario[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados do Hor&aacute;rio.
    ///
    /// @return Hor&aacute;rio
    ///
    string getHorario() {
        return horario;
    }

    ///
    /// Atribui valor para os objetos do hor&aacute;rio
    ///
    /// @param string Hor&aacute;rio.
    ///
    /// @throw invalid_argument
    ///
    void setHorario (string) throw (invalid_argument);
};

///
/// Padr&atilde;o para representa&ccedil;&atilde;o da classe Hor&aacute;rio.
///
/// Regras de formato:
///
/// - Capacidade &eacute; v&aacute;lida somente <strong>se estiver presente</strong> dentre as poss&iacute;veis capacidades presente: 100, 200, 300, 400, 500
///

class Capacidade {
private:
    ///< Atributos de classe.
    const static int LIMITE_INFERIOR = 100;
    const static int LIMITE_SUPERIOR = 500;
    int capacidade;
    void validar(int) throw (invalid_argument);
public:

    ///
    /// Obt&eacute;m os dados da Capacidade.
    ///
    /// @return Capacidade
    ///
    int getCapacidade() const {
        return capacidade;
    }

    ///
    /// Atribui valor para os objetos da capacidade
    ///
    /// @param string Capacidade.
    ///
    /// @throw invalid_argument
    ///
    void setCapacidade(int) throw (invalid_argument);
};

#endif // DOMINIOS_H_INCLUDED
