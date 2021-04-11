#pragma once
template<typename T>
struct TElemento
{
	T Dado;
};

template<typename T>
struct TListaEstatica
{
	TElemento<T>* elementos;
	int qtd;
	int capacidade;
};

template<typename T>
TElemento<T> criaElemento(T dado) 
{
	TElemento<T> novoElemento;
	novoElemento.Dado = dado;
	return novoElemento;
}

template<typename T>
void iniciaListaEstatica(TListaEstatica<T> &lista, int maximo) 
{
	lista.qtd = 0;
	lista.capacidade = maximo;
	lista.elementos = new TElemento<T>[maximo];

}

template<typename T>
void adicionaPosicaoEstatica(TListaEstatica<T> &lista, T dado, int posicao) 
{
	if (lista.qtd > lista.capacidade)
	{
		throw "lista cheia";
		
	}
	else if (posicao > lista.qtd || posicao < 0)
	{
		throw "index invalido";
	}
	else
	{
		TElemento<T> novo = criaElemento(dado);
		for (int i = lista.qtd; i > posicao; i--)
		{
			lista.elementos[i] = lista.elementos[i - 1];
		}
		lista.elementos[posicao] = novo;
		lista.qtd++;
	}
}

template<typename T>
void adicionaInicioListaEstatica(TListaEstatica<T> &lista, T dado) 
{
	adicionaPosicaoEstatica(lista, dado, 0);
}

template<typename T>
void adicionaFinalListaEstatica(TListaEstatica<T> &lista, T dado)
{
	adicionaPosicaoEstatica(lista, dado, lista.qtd);
}

template<typename T>
void removePosicaoEstatica(TListaEstatica<T> &lista, int posicao)
{	
	if (posicao > lista.qtd || posicao < 0)
	{
		throw "indice invalido";
	}else
	{
		for (int i = posicao; i < lista.qtd; i++)
		{
			lista.elementos[i] = lista.elementos[i + 1];
		}
		lista.qtd--;
	}
}

template<typename T>
void removeInicioListaEstatica(TListaEstatica<T> &lista)
{
	removePosicao(lista, 0);
}

template<typename T>
void removeFinalListaEstatica(TListaEstatica<T> &lista)
{
	removePosicao(lista, lista.qtd);
}

template<typename T>
bool pertenceListaEstatica(TListaEstatica<T> lista, T dado)
{
	for (int i = 0; i < lista.qtd; i++)
	{
		if (lista.elementos[i].Dado == dado)
		{
			return true;
		}
	}
	return false;
}

template<typename T>
T retornaItemEstatica(TListaEstatica<T> lista, int posicao)
{	
	if (posicao < 0 || posicao > lista.qtd) 
	{
		throw "posicao invalida";
	}
	else
	{
		return lista.elementos[posicao];
	}
}

template<typename T>
int retornaIndiceEstatica(TListaEstatica<T> lista, T dado)
{
	for (int i = 0; i < lista.qtd; i++)
	{
		if (lista.elementos[i].Dado == dado) 
		{
			return i;
		}
		else
		{
			throw "Impossivel localizar dado";

		}
	}
}