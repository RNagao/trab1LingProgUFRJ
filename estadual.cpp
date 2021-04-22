#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

#include "estadual.h"

using namespace std;

Estadual::Estadual (string estado)
{
    unsigned indice = 0, obitos = 0;

    nome = estado;

    for (indice = 0; indice < 10; indice++)
    {
        dadosObito.push_back(rand() % 5000);

        obitos += dadosObito[indice];

        if (indice == 7)
            mediaMovelDiaAnteriorAnterior = (obitos / 8);

        if (indice == 8)
            mediaMovelDiaAnterior = ((obitos - dadosObito[0]) / 8);

        if (indice == 9)
            mediaMovelHoje = ((obitos - dadosObito[0] - dadosObito[1]) / 8);
    }

    totalObitos = obitos;

    if (((mediaMovelHoje / mediaMovelDiaAnterior) * 100) > 115)
        estabilidade = "alta";
    else if (((mediaMovelHoje / mediaMovelDiaAnterior) * 100) < 85)
        estabilidade = "baixa";
    else
        estabilidade = "estavel";
}

string Estadual::getNomeEstado()
{
    return nome;
}

unsigned Estadual::getMediaMovelEstadoHoje()
{
    return mediaMovelHoje;
}

unsigned Estadual::getMediaMovelEstadoDiaAnterior()
{
   return mediaMovelDiaAnterior;
}

unsigned Estadual::getMediaMovelEstadoDiaAnteriorAnterior()
{
   return mediaMovelDiaAnteriorAnterior;
}

string Estadual::getEstabilidadeEstado()
{
    return estabilidade;
}

unsigned Estadual::getTotalObitosEstado()
{
    return totalObitos;
}