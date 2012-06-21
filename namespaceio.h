#include <string>
#include <vector>

namespace io{
          
const double SINAIS_REPETIDOS=1.69888e+308;

extern int numero_expr;
extern int numero_achados;
extern std::vector<size_t> posicao_achados (30) ;

std::vector<std::string> quebrar_strings ( std::string &);

int imprime_erro(double);

double sinais_repetidos(std::string);

std::string tirar_espacos(std::string);

}
