#include <string>


namespace Interpretador
{
        const double NOME_VARIAVEL_PROIBIDO= 1.69999999e+308;
        const double PULA_LINHA = 1.6999999e+308;
        const double TERMO_INVALIDO = 1.69e+308;         
        const double NAO_NUMERO = 1.699e+308;
        const double ERRO_NOME_VARIAVEL = 1.6999e+308;
        const double PARENTESES_DESBALANCEADOS = 1.69998e+308;
        const double EXPRESSAO_INVALIDA = 1.69988e+308;
        const double DIVISAO_POR_ZERO = 1.699999e+308;
 
 double converter_para_double (std::string);
 std::string expandir_expressao(std::string);
 double primary (std::string);
 double termo (std::string);
 double expressao (std::string);
}
