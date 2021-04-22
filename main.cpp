#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "nacional.h"

using namespace std;

#define SUCESSO         0
#define OPCAO_INVALIDA  1

unsigned menu()
{
    unsigned opcao;
    cout << "Menu" << endl;
    cout << "0 - Sair" << endl;
    cout << "1 - Media movel da evolucao do numero de obitos no Brasil e Estados" << endl;
    cout << "2 - Estabilidade dos estados brasileiros" << endl;
    cout << "3 - Estabilidade do país" << endl;
    cout << "4 - Estado com maior alta e com maior baixa, segundo media movel" << endl;
    cout << "5 - Dados acumulados de numero de obitos no pais e nos estados" << endl;
    cout << "Digite o numero da funcionalidade desejada" << endl;
    cin >> opcao;
    return opcao;
}

int main()
{
    unsigned opcao;

    srand ((unsigned) time (NULL));

    Nacional brasil("Brasil");

    opcao = menu();
    while (opcao != 0)
    {
        switch (opcao)
        {
            case 1:
                cout << "\nMEDIAS MOVEIS" << endl;
                cout << brasil.getNomePais() << endl;
                brasil.getMediaMovelPais();
                brasil.getMediasMovelEstados();
                cout << endl;
                break;
            case 2:
                cout << "\nESTABILIDADE DOS ESTADOS" << endl;
                brasil.getEstabilidadeEstados();
                cout << endl;
                break;
            case 3:
                cout << "\nESTABILIDADE DO PAIS" << endl;
                cout << brasil.getEstabilidadeNacional() << endl;
                cout << endl;
                break;
            case 4:
                cout << "\nESTADO COM MAIOR ALTA" << endl;
                cout << brasil.getEstadoMaiorAlta() << endl;
                cout << "\nESTADO COM MAIOR BAIXA" << endl;
                cout << brasil.getEstadoMaiorBaixa() << endl;
                cout << endl;
                break;
            case 5:
                cout << "\nNUMERO TOTAL DE OBITOS" << endl;
                cout << brasil.getObitosTotal() << endl;
                cout << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
                cout << endl;
                exit(OPCAO_INVALIDA);
        }

        opcao = menu();
    }

    return SUCESSO;
}