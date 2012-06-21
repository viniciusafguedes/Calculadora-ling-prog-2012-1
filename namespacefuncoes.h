#include <string>

namespace funcoes
    {         
    extern unsigned int numero_achados_esquerda,numero_achados_direita;
    extern std::vector<size_t> posicao_achado_esquerda (30);
    extern std::vector<size_t> posicao_achado_direita (30);    
    extern std::vector<size_t> comeco_parentese (30);//contem a posicao do comeco dos blocos formados por parenteses, usar o loop com a variavel numero_de_blocos
    extern std::vector<size_t> fim_parentese (30);//contem a posicao do final dos blocos formados por parenteses, usar o loop com a variavel numero_de_blocos
    extern unsigned int numero_de_blocos;
          
    int parenteses(std::string);
          
    }
