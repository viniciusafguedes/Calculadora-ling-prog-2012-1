#include <string>


//#define  VARIAVEL_INEXISTENTE = 1.7e+308;// valor de constante para fun�ao retorna_valor, quando nao acha a vari�vel
//using namespace std;
namespace guarda_variaveis
{
          const double VARIAVEL_INEXISTENTE = 1.7e+308;// valor de constante para fun�ao retorna_valor, quando nao acha a vari�vel
extern std::vector<std::string> nome_variaveis (200);
extern std::vector<double> valor_variaveis (200);
extern int numero_variaveis;
extern int index;

 double salva_variavel ( std::string , double);    // std:: pois retirei using std    
 double retorna_valor_variavel( std::string);              
} 
