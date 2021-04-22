#include <vector>
#include <string>

using namespace std;

class Estadual
{
    public:
        //construtor para a classe Estadual com os dados de obito por dia
        Estadual(string);
        //configura o nome do Estado
        string getNomeEstado();
        //obtem a media movel do Estado hoje
        unsigned getMediaMovelEstadoHoje();
        //obtem a media movel do Estado no dia anterior
        unsigned getMediaMovelEstadoDiaAnterior();
        //obtem media movel do Estado no dia anterior ao anterior
        unsigned getMediaMovelEstadoDiaAnteriorAnterior();
        //obtem a estabilidade do Estado
        string getEstabilidadeEstado();
        //obtem todos os obitos do Estado
        unsigned getTotalObitosEstado();
    private:
        //nome do Estado
        string nome;
        //vetor com os casos de obito dos ultimos dez dias
        vector <int> dadosObito;
        //media movel hoje
        unsigned mediaMovelHoje;
        //media movel dia anterior;
        unsigned mediaMovelDiaAnterior;
        //media movel de dois dias antes
        unsigned mediaMovelDiaAnteriorAnterior;
        //estabilidade do Estado: alta, baixa ou em estabilidade
        string estabilidade;
        //numero total de obitos durante o periodo
        unsigned totalObitos;
};