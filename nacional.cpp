#include <ios>
#include <iostream>
#include <vector>

#include "nacional.h"

using namespace std;

Nacional::Nacional(string pais)
{
    unsigned indice;
    const string estados[] = {
        "Acre",
        "Alagoas",
        "Amapa",
        "Amazonas",
        "Bahia",
        "Ceara",
        "Distrito Federal",
        "Espirito Santo",
        "Goias",
        "Maranhao",
        "Mato Grosso",
        "Mato Grosso do Sul",
        "Minas Gerais",
        "Para",
        "Paraiba",
        "Parana",
        "Pernambuco",
        "Piaui",
        "Rio de Janeiro",
        "Rio Grande do Norte",
        "Rio Grande do Sul",
        "Rondonia",
        "Roraima",
        "Santa Catarina",
        "Sao Paulo",
        "Sergipe",
        "Tocantins"
    };

    for (indice = 0; indice < 27; indice++)
    {
        dadosEstados.push_back(Estadual(estados[indice]));
    }

    nome = pais;
}

string Nacional::getNomePais()
{
    return nome;
}

void Nacional::getMediaMovelPais()
{
    unsigned somaMediasHoje = 0, somaMediasDiaAnterior = 0, somaMediasDiaAnteriorAnterior = 0, indice;

    for (indice = 0; indice < dadosEstados.size(); indice++)
    {
        somaMediasHoje += dadosEstados[indice].getMediaMovelEstadoHoje();
        somaMediasDiaAnterior += dadosEstados[indice].getMediaMovelEstadoDiaAnterior();
        somaMediasDiaAnteriorAnterior += dadosEstados[indice].getMediaMovelEstadoDiaAnteriorAnterior();
    }

    cout << "Hoje: " << (somaMediasHoje / dadosEstados.size()) << endl;
    cout << "Ontem: " << (somaMediasDiaAnterior / dadosEstados.size()) << endl;
    cout << "Antes de Ontem: " << (somaMediasDiaAnteriorAnterior / dadosEstados.size()) << endl;
    cout << endl;
}

void Nacional::getMediasMovelEstados()
{
    unsigned indice;

    for (indice = 0; indice < dadosEstados.size(); indice++)
    {
        cout << dadosEstados[indice].getNomeEstado() << endl;
        cout << "Hoje: " << dadosEstados[indice].getMediaMovelEstadoHoje() << endl;
        cout << "Ontem: " << dadosEstados[indice].getMediaMovelEstadoDiaAnterior() << endl;
        cout << "Antes de Ontem: " << dadosEstados[indice].getMediaMovelEstadoDiaAnteriorAnterior() << endl;
        cout << endl;
    }
}

void Nacional::getEstabilidadeEstados()
{
    vector <string> alta;
    vector <string> estavel;
    vector <string> baixa;
    unsigned indice;

    for (indice = 0; indice < dadosEstados.size(); indice++)
    {
        if (dadosEstados[indice].getEstabilidadeEstado() == "alta")
            alta.push_back(dadosEstados[indice].getNomeEstado());
        else if (dadosEstados[indice].getEstabilidadeEstado() == "baixa")
            baixa.push_back(dadosEstados[indice].getNomeEstado());
        else
            estavel.push_back(dadosEstados[indice].getNomeEstado());
    }

    cout << "\nESTADOS EM ALTA" << endl;

    for (indice = 0; indice < alta.size(); indice++)
    {
        cout << alta[indice] << endl;
    }

    cout << "\nESTADOS EM ESTABILIDADE" << endl;

    for (indice = 0; indice < estavel.size(); indice++)
    {
        cout << estavel[indice] << endl;
    }

    cout << "\nESTADOS EM BAIXA" << endl;

    for (indice = 0; indice < baixa.size(); indice++)
    {
        cout << baixa[indice] << endl;
    }
}

string Nacional::getEstabilidadeNacional()
{
    unsigned indice, somaMediaHoje = 0, somaMediaOntem = 0;

    for (indice = 0; indice < dadosEstados.size(); indice++)
    {
        somaMediaHoje = dadosEstados[indice].getMediaMovelEstadoHoje();
        somaMediaOntem = dadosEstados[indice].getMediaMovelEstadoDiaAnterior();
    }

    if (((somaMediaHoje / somaMediaOntem) * 100) > 115)
        return "alta";
    else if (((somaMediaHoje / somaMediaOntem) * 100) < 85)
        return "baixa";
    else
        return "estavel";
}

string Nacional::getEstadoMaiorAlta()
{
    string maior;
    unsigned indice, valor = 0;
    for (indice = 0; indice < dadosEstados.size(); indice++)
    {
        if (dadosEstados[indice].getMediaMovelEstadoHoje() > valor)
        {
            maior = dadosEstados[indice].getNomeEstado();
            valor = dadosEstados[indice].getMediaMovelEstadoHoje();
        }
    }

    return maior;
}

string Nacional::getEstadoMaiorBaixa()
{
    string menor;
    unsigned indice, valor = 5000;
    for (indice = 0; indice < dadosEstados.size(); indice++)
    {
        if (dadosEstados[indice].getMediaMovelEstadoHoje() < valor)
        {
            menor = dadosEstados[indice].getNomeEstado();
            valor = dadosEstados[indice].getMediaMovelEstadoHoje();
        }
    }

    return menor;
}

unsigned Nacional::getObitosTotal()
{
    unsigned total = 0, indice;
    for (indice = 0; indice < dadosEstados.size(); indice++)
    {
        total += dadosEstados[indice].getTotalObitosEstado();
    }

    return total;
}