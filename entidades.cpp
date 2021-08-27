/**
 * @file entidades.cpp
 *
 * @brief Arquivo com a declaração das entidades do programa
 *
 * @author Vinicius Ferreira
 *
 */


#include "entidades.h"
#include <string>
#include <iostream>

using namespace std;

void Participante::setParticipante(string novo_nome,string novo_sobrenome,string novo_email,string novo_telefone,string nova_senha, string novo_cargo) throw (invalid_argument) {
    Nome.setNome(novo_nome);
    Nome.setNome(novo_sobrenome);
    Email.setEmail(novo_email);
    Telefone.setTelefone(novo_telefone);
    Senha.setSenha(nova_senha);
    Cargo.setCargo(novo_cargo);
}

void Participante::getParticipante(Matricula *matricula_partipante, Nome *nome_participante, Nome *sobrenome_participante, Email *email_participante, Telefone *telefone_participante, Senha *senha_participante, Cargo *cargo_participante) {
    matricula_partipante->setMatricula(this->matricula.getMatricula());
    nome_participante->setNome(this->nome.getNome());
    sobrenome_participante->setNome(this->sobrenome.getNome());
    email_participante->setEmail(this->email.getEmail());
    telefone_participante->setTelefone(this->telefone.getTelefone());
    senha_participante->setSenha(this->senha.getSenha());
    cargo_participante->setCargo(this->cargo.getCargo());

    return;
}

void Peca::setPeca(string novo_codigo,string novo_nome,string novo_tipo,string nova_classificacao) throw (invalid_argument) {
    Codigo.setCodigo(novo_codigo);
    Nome.setNome(novo_nome);
    Tipo.setTipo(novo_tipo);
    Classificacao.setClassificacao(nova_classificacao);
}

void Peca::getPeca(Codigo *codigo_peca,Nome *nome_peca,Tipo *tipo_peca,Classificacao *classificacao_peca) {
    codigo_peca->setCodigo(this->codigo.getCodigo());
    nome_peca->setNome(this->nome.getNome());
    tipo_peca->setTipo(this->tipo.getTipo());
    classificacao_peca->setClassificacao(this->classificacao.getClassificacao());

    return;
}

void Sessao::setSessao(string novo_codigo,string nova_data,string novo_horario) {
    Codigo.setCodigo(novo_codigo);
    Data.setData(nova_data);
    Horario.setHorario(novo_horario);
}

void Sessao::getSessao(Codigo *codigo_sessao,Data *data_sessao,Horario *horario_sessao) {
    codigo_sessao->setCodigo(this->codigo.getCodigo());
    data_sessao->setData(this->data.getData());
    horario_sessao->setHorario(this->data.getData());

    return;
}

void Sala::setSala(string novo_codigo,string novo_nome,int nova_capacidade) {
    Codigo.setCodigo(novo_codigo);
    Nome.setNome(novo_nome);
    Capacidade.setCapacidade(nova_capacidade);
}

void Sala::getSala(Codigo *codigo_sala,Nome *nome_sessao,Capacidade *capacidade_sessao) {
    codigo_sala->setCodigo(this->codigo.getCodigo());
    nome_sessao->setNome(this->nome.getNome());
    capacidade_sessao->setCapacidade(this->capacidade.getCapacidade());

    return;
}
