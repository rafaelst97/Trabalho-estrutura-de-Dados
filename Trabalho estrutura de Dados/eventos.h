#pragma once
#pragma once
#pragma once
#include <string>
#include <iostream>
#include "listaEstatica.h"
#include "listaDuplamenteEncadeada.h"
using namespace std;

struct TData {
	int dia;
	int mes;
	int ano;
};

struct THora {
	int hora;
	int minuto;
};
struct TPessoa
{
	string nome;
	int ID;
};

struct TSubEvento
{
	string titulo;
	TData dataInicial;
	TData dataFinal;
	THora horarioInicial;
	THora horarioFinal;
	int numeroVagas;
	TListaEstatica<TPessoa> listaEsperaSub;
	TListaEstatica<TPessoa> listaInscricaoSub;

};

struct TEvento
{
	string titulo;
	TData dataInicial;
	TData dataFinal;
	THora horarioInicial;
	THora horarioFinal;
	int numeroVagas;
	TListaEstatica<TPessoa> listaEspera;
	TListaEstatica<TPessoa> listaInscricao;
	TListaEstatica<TSubEvento> subeventos;
};

inline bool operator>= (TData& dataFinal, TData & dataInicial){

	if (dataFinal.ano >= dataInicial.ano){
		if (dataFinal.ano > dataInicial.ano) {
			return true;
		}
		else {
			if (dataFinal.mes >= dataInicial.mes) {
				if(dataFinal.mes > dataInicial.mes){
					return true;
				}
				else {
					if (dataFinal.dia >= dataInicial.dia) {
						if (dataFinal.dia > dataInicial.dia) {
							return true;
						}
						else {
							return false;
						}
					}
					else {
						return false;
					}
				}
			}
			else {
				return false;
			}
		}
		
	}
	else {
		return false;
	}

}

inline bool operator> (TData& dataFinal, TData& dataInicial) {

	if (dataFinal.ano > dataInicial.ano) {
		return true;
	}
	else if (dataFinal.ano == dataInicial.ano){
		if (dataFinal.mes > dataInicial.mes) {
			return true;
		}
		else if (dataFinal.mes == dataInicial.mes) {
			if (dataFinal.dia > dataInicial.dia) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}

}

inline bool operator== (TData& dataFinal, TData& dataInicial) {
	if (dataFinal.ano == dataInicial.ano) {
		if (dataFinal.mes == dataInicial.mes) {
			if (dataFinal.dia == dataInicial.dia) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

inline bool operator>= (THora& horaFinal, THora& horaInicial) {
	if (horaFinal.hora > horaInicial.hora) {
		return true;
	}
	else if (horaFinal.hora == horaInicial.hora) {
		if (horaFinal.minuto >= horaInicial.minuto) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

inline bool operator> (THora& horaFinal, THora& horaInicial) {
	if (horaFinal.hora > horaInicial.hora) {
		
		return true;

	}else if(horaFinal.hora == horaInicial.hora) {
		if (horaFinal.minuto > horaInicial.minuto) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

inline bool operator== (THora& horaFinal, THora& horaInicial) {
	if (horaFinal.hora == horaInicial.hora) {
		if (horaFinal.minuto == horaInicial.minuto) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

std::ostream& operator<<(std::ostream& out, TData obj)
{
	out << obj.dia << "/" << obj.mes << "/" << obj.ano;

	return out;
}

std::ostream& operator<<(std::ostream& out, THora obj)
{
	out << obj.hora << ":" << obj.minuto;

	return out;
}

std::ostream& operator<<(std::ostream& out, TEvento obj)
{
	out << "Titulo: " << obj.titulo << endl
		<< "Data inicial: " << obj.dataInicial << endl
		<< "Horario inicial: " << obj.horarioInicial << endl
		<< "Data final: " << obj.dataFinal << endl
		<< "Horario final: " << obj.horarioFinal << endl
		<< "Vagas: " << obj.numeroVagas << endl;
	for (int i = 0; i < 10; i++) {
		if (i == 5) {
			out << "\n";
		}
		else if (i < obj.subeventos.qtd)
		{
			out << i << " - " << obj.subeventos.elementos[i].Dado.titulo << "\t";
		}
		else
		{
			out << i << " - " << "\t";
		}
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, TSubEvento obj)
{
	out << "Titulo: " << obj.titulo << endl
		<< "Data inicial: " << obj.dataInicial << endl
		<< "Horario inicial: " << obj.horarioInicial << endl
		<< "Data final: " << obj.dataFinal << endl
		<< "Horario final: " << obj.horarioFinal << endl
		<< "Vagas: " << obj.numeroVagas << endl;
	return out;
}

std::ostream& operator<<(std::ostream& out, TPessoa obj)
{
	out << "Nome: " << obj.nome << endl
		<< "ID: " << obj.ID << endl;
	return out;
}

void criaEvento(TListaDE<TEvento>& lista, string titulo, TData dataInicio, TData dataFim, THora horarioInicial,
	THora horarioFinal, int vagas)
{
	TEvento novoEvento;
	novoEvento.titulo = titulo;
	novoEvento.dataInicial = dataInicio;
	novoEvento.dataFinal = dataFim;
	novoEvento.horarioInicial = horarioInicial;
	novoEvento.horarioFinal = horarioFinal;
	novoEvento.numeroVagas = vagas;
	iniciaListaEstatica(novoEvento.listaEspera, novoEvento.numeroVagas * 0.1);
	iniciaListaEstatica(novoEvento.listaInscricao, vagas);
	iniciaListaEstatica(novoEvento.subeventos, 10);
	adicionaInicioDe(lista, novoEvento);

}

void criaSubEvento(TEvento& evento, string titulo, TData dataInicio, TData dataFim, THora horarioInicial,
	THora horarioFinal, int vagas) {

	TSubEvento novoSubEvento;

	novoSubEvento.titulo = titulo;
	novoSubEvento.dataInicial = dataFim;
	novoSubEvento.dataFinal = dataInicio;
	novoSubEvento.horarioInicial = horarioInicial;
	novoSubEvento.horarioFinal = horarioFinal;
	novoSubEvento.numeroVagas = vagas;
	iniciaListaEstatica(novoSubEvento.listaEsperaSub, novoSubEvento.numeroVagas * 0.1);
	iniciaListaEstatica(novoSubEvento.listaInscricaoSub, vagas);
	adicionaFinalListaEstatica(evento.subeventos, novoSubEvento);
}
void excluiEvento(TListaDE<TEvento>& lista, int posicao)
{
	TElementoDE<TEvento>* nav = navegaDE(lista, posicao);
	if (nav->info.listaInscricao.qtd == 0)
	{
		removePosicaoDE(lista, posicao);
		cout << "Evento removido com sucesso";
	}
	else if (nav->info.listaInscricao.qtd > 0)
	{
		char resposta;
		cout << "Há pessoas inscritas nesse evento. Se deseja excluir mesmo assim digite 's', caso contrario, digite 'n'";
		cin >> resposta;
		if (resposta == 115)
		{
			removePosicaoDE(lista, posicao);
			cout << "Evento removido com sucesso";
		}
		else if (resposta == 110)
		{
			cout << "O evento não foi removido";
		}
		else
		{
			throw "opcao invalida na remocao de eventos";
		}
	}

}

void excluiSubevento(TEvento& evento, int posicao)
{
	if (evento.subeventos.elementos[posicao].Dado.listaInscricaoSub.qtd == 0)
	{
		removePosicaoEstatica(evento.subeventos, posicao);
		cout << "Evento removido com sucesso";
	}
	else if (evento.subeventos.elementos[posicao].Dado.listaInscricaoSub.qtd > 0)
	{
		char resposta;
		cout << "Há pessoas inscritas nesse evento. Se deseja excluir mesmo assim digite 's', caso contrario, digite 'n'";
		cin >> resposta;
		if (resposta == 115)
		{
			removePosicaoEstatica(evento.subeventos, posicao);
			cout << "Evento removido com sucesso";
		}
		else if (resposta == 110)
		{
			cout << "O evento não foi removido";
		}
		else
		{
			throw "opcao invalida na remocao de eventos";
		}
	}
}

void inscricaoListaEsperaEvento(TEvento& evento, TPessoa inscrito)
{
	if (evento.listaEspera.qtd == evento.listaEspera.capacidade)
	{
		throw "Lista de espera cheia, impossivel se inscrever neste evento no momento";
	}
	else
	{
		adicionaFinalListaEstatica(evento.listaEspera, inscrito);
	}
}

void inscricaoEvento(TEvento& evento, string nome, int cpf)
{
	TPessoa novaPessoa;
	novaPessoa.ID = cpf;
	novaPessoa.nome = nome;
	if (evento.listaInscricao.qtd == evento.listaInscricao.capacidade)
	{
		char resposta;
		cout << "Evento cheio, gostaria de se inscrever na lista de espera? Caso sim digite 's', caso contrario digite 'n'";
		cin >> resposta;
		if (resposta == 115)
		{
			inscricaoListaEsperaEvento(evento, novaPessoa);
		}
		else if (resposta == 110)
		{
			cout << "Pessoa não inscrita no evento";
		}
		else
		{
			throw "opcao invalida no cadastro de pessoas no evento";
		}
	}
	else
	{
		adicionaFinalListaEstatica(evento.listaInscricao, novaPessoa);
		cout << "Pessoa inscrita com sucesso";
	}

}


void inscricaoListaEsperaSubevento(TEvento& evento, int posicao, TPessoa inscrito)
{
	if (evento.subeventos.elementos[posicao].Dado.listaEsperaSub.qtd ==
		evento.subeventos.elementos[posicao].Dado.listaEsperaSub.capacidade)
	{
		throw "Lista de espera cheia, impossivel se inscrever neste subevento no momento";
	}
	else
	{
		adicionaFinalListaEstatica(evento.subeventos.elementos[posicao].Dado.listaEsperaSub, inscrito);
	}
}

void inscricaoSubEvento(TEvento& evento, int posicao, TPessoa inscrito)
{
	if (!pertenceListaEstatica(evento.listaInscricao, inscrito))
	{
		throw "tentativa de inscricao em subevento falhou, pessoa não inscrita no evento principal";
	}
	else if (evento.subeventos.elementos[posicao].Dado.listaInscricaoSub.qtd ==
		evento.subeventos.elementos[posicao].Dado.listaInscricaoSub.capacidade)
	{
		char resposta;
		cout << "Subevento cheio, gostaria de se inscrever na lista de espera? Caso sim digite 's', caso contrario digite 'n'";
		cin >> resposta;
		if (resposta == 115)
		{
			inscricaoListaEsperaSubevento(evento, posicao, inscrito);
		}
		else if (resposta == 110)
		{
			cout << "Pessoa não inscrita no Subevento";
		}
		else
		{
			throw "opcao invalida no cadastro de pessoas no Subevento";
		}
	}
	else
	{
		adicionaFinalListaEstatica(evento.subeventos.elementos[posicao].Dado.listaInscricaoSub, inscrito);
	}
}


std::istream& operator>>(std::istream& in, TData& obj)
{
	cout << endl << "Ano: ";
	do {
		in >> obj.ano;
		if (obj.ano < 1900) {
			cout << "Ano invalido" << endl
				<< "Ano: ";
		}
	} while (obj.ano < 1900);

	bool bissexto;
	if (obj.ano % 4 == 0) {
		if (obj.ano % 100 == 0) {
			if (obj.ano % 400 == 0) {
				bissexto = true;
			}
			else {
				bissexto = false;
			}
		}
		else {
			bissexto = true;
		}
	}
	else {
		bissexto = false;
	}
	cout << "Mes: ";
	do {
		in >> obj.mes;
		if (obj.mes < 1 || obj.mes > 12) {
			cout << "Mes invalido" << endl
				<< "Mes: ";
		}
	} while (obj.mes < 1 || obj.mes > 12);
	cout << "Dia: ";
	bool diaValido = false;
	do {
		in >> obj.dia;
		switch (obj.mes) {
		case 1:
			if (obj.dia > 0 && obj.dia <= 31) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 2:
			if (bissexto == true && obj.dia < 30 && obj.dia > 0) {
				diaValido = true;
			}
			else if (obj.dia > 0 && obj.dia < 29) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 3:
			if (obj.dia > 0 && obj.dia <= 31) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 4:
			if (obj.dia > 0 && obj.dia <= 30) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 5:
			if (obj.dia > 0 && obj.dia <= 31) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 6:
			if (obj.dia > 0 && obj.dia <= 30) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 7:
			if (obj.dia > 0 && obj.dia <= 31) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 8:
			if (obj.dia > 0 && obj.dia <= 31) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 9:
			if (obj.dia > 0 && obj.dia <= 30) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 10:
			if (obj.dia > 0 && obj.dia <= 31) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 11:
			if (obj.dia > 0 && obj.dia <= 30) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		case 12:
			if (obj.dia > 0 && obj.dia <= 31) {
				diaValido = true;
			}
			else {
				diaValido = false;
			}
			break;
		}
		if (diaValido == false) {
			cout << "Dia invalido" << endl
				<< "Dia: ";
		}

	} while (diaValido == false);

	return in;
}

std::istream& operator>>(std::istream& in, THora& obj)
{
	cout << endl << "Hora: ";
	do {
		in >> obj.hora;
		if (obj.hora < 0 || obj.hora > 23) {
			cout << "Hora invalida" << endl
				<< "Hora: ";
		}
	} while (obj.hora < 0 || obj.hora > 23);
	cout << "Minutos: ";
	do {
		in >> obj.minuto;
		if (obj.minuto < 0 || obj.minuto > 59) {
			cout << "Minutos invalidos" << endl
				<< "Minutos: ";
		}
	} while (obj.minuto < 0 || obj.minuto > 59);

	return in;
}