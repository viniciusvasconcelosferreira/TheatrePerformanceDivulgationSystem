#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Matricula {
private:
    int matricula;
    const static int LIMITE = 99999;
    void validar(int) throw (invalid_argument);
public:
    int getMatricula() const {
        return matricula;
    }
    void setMatricula(int) throw (invalid_argument);
};

class Nome {
private:
    const static int LIMITE = 20;
    char nome[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:
    string getNome() {
        return nome;
    }
    void setNome(string) throw (invalid_argument);
};

class Email {
private:
    const static int LIMITE = 319;
    char email[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:
    string getEmail() {
        return email;
    }
    void setEmail(string) throw (invalid_argument);
};

class Telefone {
private:
    const static int LIMITE = 11;
    char telefone[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:
    string getTelefone() {
        return telefone;
    }
    void setTelefone(string) throw (invalid_argument);
};

class Senha {
private:
    const static int LIMITE = 8;
    char senha[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:
    string getSenha() {
        return senha;
    }
    void setSenha(string) throw (invalid_argument);
};

class Cargo {
private:
    const static string cargos[6] = {"ator", "cenógrafo", "figurinista", "maquiador", "sonoplasta", "iluminador"};
    string cargo;
    void validar(string) throw (invalid_argument);
public:
    string getCargo() {
        return cargo;
    }
    void setCargo(string) throw (invalid_argument);
};

class Codigo {
    const static int LIMITE = 6;
    char codigo[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:
    string getCodigo() {
        return codigo;
    }
    void setCodigo(string) throw (invalid_argument);
};

class Tipo {
private:
    int tipo;
    void validar(int) throw (invalid_argument);
public:
    int getTipo() {
        return tipo;
    }
    void setTipo(tipo) throw (invalid_argument);
};

class Classificacao {
private:
    const static int LIMITE = 5;
    char classificacao[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:
    string getClassificacao() {
        return classificacao;
    }
    void setClassificacao(string) throw (invalid_argument);
};

class Data {
private:
    const static int LIMITE = 8;
    char data[LIMITE+1];
    void validar(int) throw (invalid_argument);
public:
    string getData() {
        return data;
    }
    void setData (string) throw (invalid_argument);
};

class Horario {
private:
    const static int LIMITE = 5;
    char horario[LIMITE+1];
    void validar(string) throw (invalid_argument);
public:
    string getHorario() {
        return horario;
    }
    void setHorario (string) throw (invalid_argument);
};

class Capacidade {
private:
    const static int LIMITE_INFERIOR = 100;
    const static int LIMITE_SUPERIOR = 500;
    int capacidade;
    void validar(int) throw (invalid_argument);
public:
    int getCapacidade() const {
        return capacidade;
    }
    void setCapacidade(int) throw (invalid_argument);
};

#endif // DOMINIOS_H_INCLUDED
