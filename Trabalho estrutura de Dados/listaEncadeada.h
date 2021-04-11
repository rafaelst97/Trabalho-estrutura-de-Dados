#pragma once


template<typename T>
struct TElementoEncadeado
{
	T data;
	TElementoEncadeado<T>* proximo;
};

template<typename T>
struct TListaEncadeada
{
	TElementoEncadeado<T>* inicio;
};

template<typename T>
void iniciaListaEncadeada(TListaEncadeada<T>& lista)
{
	lista.inicio = nullptr;
}

template<typename T>
TElementoEncadeado<T>* criaElementoEncadeado(T dado)
{
	TElementoEncadeado<T>* novo = new TElementoEncadeado<T>;
	novo->data = dado;
	novo->proximo = nullptr;
	return novo;
}

template<typename T>
void adicionaPosicaoEncadeada(TListaEncadeada<T>& lista, T dado, int posicao)
{
	if (posicao < 0)
	{
		throw "posicao invalida";
	}
	else if (lista.inicio == nullptr)
	{
		TElementoEncadeado<T>* novoElemento = criaElementoEncadeado(dado);
		lista.inicio = novoElemento;
	}
	else {
		TElementoEncadeado<T>* nav = nullptr;
		nav = lista.inicio;
		int i = 0;
		while (nav != nullptr && i < posicao - 1)
		{
			nav = nav->proximo;
			i++;
		}
		if (nav == nullptr)
		{
			throw "posicao invalida";
		}
		TElementoEncadeado<T>* novoElemento = criaElementoEncadeado(dado);
		novoElemento->proximo = nav->proximo;
		nav->proximo = novoElemento;
	}
}

template<typename T>
void adicionaInicioEncadeada(TListaEncadeada<T>& lista, T dado)
{
	adicionaPosicaoEncadeada(lista, dado, 0);
}

template<typename T>
void adicionaFinalEncadeada(TListaEncadeada<T>& lista, T dado)
{
	TElementoEncadeado<T>* nav = lista.inicio;
	while (nav->proximo != nullptr)
	{
		nav = nav->proximo;
	}
	TElementoEncadeado<T> novo = criaElementoDE(dado);
	nav->proximo = novo;
}

template<typename T>
void removePosicaoEncadeada(TListaEncadeada<T>& lista, int posicao)
{
	if (posicao < 0 || lista.inicio == nullptr)
	{
		throw "Impossivel realizar exclusao";
	}
	else if (posicao == 0)
	{
		TElementoEncadeado<T>* nav = lista.inicio;
		lista.inicio = nav->proximo;
		delete nav;
	}
	else
	{
		TElementoEncadeado<T>* nav = lista.inicio;
		int i = 0;
		while (nav->proximo != nullptr && i < posicao - 1)
		{
			nav = nav->proximo;
			i++;
		}
		if (nav->proximo == nullptr)
		{
			throw "posicao invalida";
		}
		TElementoEncadeado<T>* temp = nav->proximo;
		nav->proximo = nav->proximo->proximo;
		delete temp;

	}
};

template<typename T>
void removeInicioEncadeada(TListaEncadeada<T>& lista)
{
	removePosicaoEncadeada(lista, 0);

};


template<typename T>
void removeFimEncadeada(TListaEncadeada<T>& lista)
{
	TElementoEncadeado<T>* nav = lista.inicio;
	if (lista.inicio == nullptr)
	{
		throw "impossivel excluir de lista vazia";
	}
	else if (nav->proximo == nullptr)
	{
		removePosicaoEncadeada(lista, 0);
	}
	else
	{
		while (nav->proximo->proximo != nullptr)
		{
			nav = nav->proximo;
		}
		TElementoEncadeado<T>* temp = nav->proximo;
		nav->proximo = nullptr;
		delete temp;

	}

};

template<typename T>
bool pertenceListaEncadeada(TListaEncadeada<T> lista, T dado)
{
	TElementoEncadeado<T>* nav = lista.inicio;
	while (nav != nullptr)
	{
		if (nav->data == dado)
		{
			return true;
		}
		nav = nav->proximo;
	}
	return false;
};
template<typename T>
T obtemItemListaEncadeada(TListaEncadeada<T> lista, int posicao)
{
	if (posicao < 0)
	{
		throw "Impossivel realizar exclusao";
	}
	TElementoEncadeado<T>* nav = lista.inicio;
	int i = 0;
	while (nav != nullptr && i < posicao - 1)
	{
		nav = nav->proximo;
		i++;
	}
	if (nav == nullptr)
	{
		throw "posicao Invalida na obtencao de item da lista encadeada";
	}
	return nav->data;

};
template<typename T>
int obtemIndiceListaEncadeada(TListaEncadeada<T> lista, T dado)
{
	int i = 0;
	TElementoEncadeado<T>* nav = lista.inicio;
	while (nav != nullptr)
	{
		if (nav->data == dado)
		{
			return i;
		}
		nav = nav->proximo;
		i++;
	}
	return -1;
};