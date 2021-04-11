#pragma once
#include <iostream>
#include "eventos.h"

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