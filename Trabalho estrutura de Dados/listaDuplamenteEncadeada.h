#pragma once
template<typename T>
struct TElementoDE
{
	T info;
	TElementoDE<T>* anterior;
	TElementoDE<T>* prox;
};

template<typename T>
struct TListaDE
{
	TElementoDE<T>* inicio;
	TElementoDE<T>* fim;
};

template<typename T>
void iniciaListaDE(TListaDE<T>& lista)
{
	lista.inicio = nullptr;
	lista.fim = nullptr;
};

template<typename T>
TElementoDE<T>* criaElementoDE(T dado)
{
	TElementoDE<T>* novoElemento = new TElementoDE<T>;
	novoElemento->anterior = nullptr;
	novoElemento->prox = nullptr;
	novoElemento->info = dado;
	return novoElemento;
};

template<typename T>
void adicionaPosicaoDE(TListaDE<T>& lista, T dado, int posicao)
{
	TElementoDE<T>* novo = criaElementoDE(dado);
	if (posicao < 0)
	{
		throw "posicao inexistente na lista duplamente encadeada";
	}
	else if (posicao == 0)
	{
		novo->prox = lista.inicio;
		lista.inicio = novo;
		if (lista.inicio == nullptr)
		{
			lista.fim = novo;
		}
	}
	else
	{
		TElementoDE<T>* nav = lista.inicio;
		int i = 0;
		while (nav != nullptr && i < posicao - 1)
		{
			nav = nav->prox;
			i++;
		}
		if (nav == nullptr)
		{
			throw "posicao invalida";
		}

		novo->anterior = nav;
		novo->prox = nav->prox;
		nav->prox = novo;
		if (novo->prox == nullptr)
		{
			lista.fim = novo;
		}
		else
		{
			novo->prox->anterior = novo;
		}

	}
};

template<typename T>
void adicionaInicioDe(TListaDE<T>& lista, T dado)
{
	adicionaPosicaoDE(lista, dado, 0);
};

template<typename T>
void adicionaFimDE(TListaDE<T>& lista, T dado)
{
	TElementoDE<T>* nav = lista.inicio;
	while (nav->prox != nullptr)
	{
		nav = nav->prox;
	}
	TElementoDE<T> novo = criaElementoDE(dado);
	novo.anterior = nav;
	nav->prox = novo;
	lista.fim = novo;
};

template<typename T>
void removePosicaoDE(TListaDE<T>& lista, int posicao)
{
	if (lista.inicio == nullptr)
	{
		throw "impossivel realizar remocao de elemento duplamente encadeado, lista vazia";
	}
	else if (posicao < 0)
	{
		throw "impossivel realizar remoca de elemento duplamente encadadeado, posicao invalida";
	}
	else if (posicao == 0)
	{
		TElementoDE<T>* nav = lista.inicio;
		lista.inicio = nav->prox;
		lista.inicio->anterior = nullptr;
		delete nav;
	}
	else
	{
		TElementoDE<T>* nav = lista.inicio;
		int i = 0;
		while (nav != nullptr && i < posicao - 1)
		{
			nav = nav->prox;
			i++;
		}
		if (nav == nullptr)
		{
			throw "posicao invalida";
		}
		TElementoDE<T>* temp = nav;
		nav->prox->anterior = nav->anterior;
		nav->anterior->prox = nav->prox;
		delete temp;
	}
};

template<typename T>
void removeInicioDE(TListaDE<T>& lista)
{
	removePosicaoDE(lista, 0);
};

template<typename T>
void removeFimDE(TListaDE<T> & lista)
{
	TElementoDE<T>* nav = lista.inicio;
	if (lista.inicio == nullptr)
	{
		throw "impossivel excluir de lista vazia";
	}
	else if (nav->prox == nullptr)
	{
		removePosicaoDE(lista, 0);
	}
	else
	{
		while (nav->prox != nullptr)
		{
			nav = nav->proximo;
		}
		TElementoDE<T>* temp = nav;
		nav->anterior->prox = nullptr;
		delete temp;

	}
};

template<typename T>
bool pertenceListaDE(TListaDE<T> lista, T dado)
{
	TElementoDE<T>* nav = lista.inicio;
	while (nav != nullptr)
	{
		if (nav->info == dado)
		{
			return true;
		};
		nav = nav->proximo;
	};
	return false;
};

template<typename T>
T obtemItemListaDE(TListaDE<T> lista, int posicao)
{
	if (posicao < 0)
	{
		throw "posicao para obtencao de item duplamente encadeado invalida";
	}
	else {
		TElementoDE<T>* nav = lista.inicio;
		int i = 0;
		while (nav != nullptr && i < posicao - 1)
		{
			nav = nav->proximo;
			i++;
		}
		if (nav == nullptr)
		{
			throw "posicao para obtencao de item duplamente encadeado invalida";
		}
		return nav->prox->info;
	}
};

template<typename T>
int obtemIndiceListaDE(TListaDE<T> lista, T dado)
{
	TElementoDE<T>* nav = lista.inicio;
	int i = 0;
	while (nav != nullptr)
	{
		if (nav->info == dado)
		{
			return i;
		}
		nav = nav->proximo;
		i++;
	}
	return -1;
};
template<typename T>
TElementoDE<T>* navegaDE(TListaDE<T>& lista, int posicao)
{
	TElementoDE<T>* nav = lista.inicio;
	int i = 0;
	while (nav != nullptr && i < posicao - 1)
	{
		nav = nav->prox;
		i++;
	}
	if (nav == nullptr)
	{
		throw "posicao invalida";
	}
	return nav;
};