#include <vector>
#include <string>

#include "estadual.h"

using namespace std;

class Nacional
{
    public:
        //construtor para a classe pais com os dados dos Estados do Brasil
        Nacional(string);
        //obter nome do pais
        string getNomePais();
        //obtem a media movel do pais
        void getMediaMovelPais();
        //obtem a media movel dos estados
        void getMediasMovelEstados();
        //obtem a estabilidade dos estados
        void getEstabilidadeEstados();
        //obtem a estabilidade do pais
        string getEstabilidadeNacional();
        //obtem Estado com maior alta
        string getEstadoMaiorAlta();
        //obtem Estado com maior baixa
        string getEstadoMaiorBaixa();
        //obtem todas os obitos no pais
        unsigned getObitosTotal();
    private:
        //nome do pais
        string nome;
        //vector de Estados
        vector <Estadual> dadosEstados;
};