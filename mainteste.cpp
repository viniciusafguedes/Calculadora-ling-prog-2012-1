#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "namespacevariaveis.h"

using namespace std;
using namespace guarda_variaveis;
       
int main()
{
string input,value;
double val,retorno;
//const double VARIAVEL_INEXISTENTE = 1.7e+308;



       while(input!="exit")
       {
       cout<<"Escreva a variavel"<<endl;
       getline(cin, input);        
       if(input!="exit")
                        {

                        if(input!="achar")
                                          {
                                          cout<<"Escreva o valor"<<endl;
                                          getline(cin, value);
                                          istringstream st(value); 
                                          if (!(st >> val))// nao era um +/- number
                                             {
                                             cout<<"erro"<<endl;
                                             return 0;
                                             }
                                          cout <<input << endl;
                                          cout <<val << endl;       
                                          retorno=salva_variavel(input,val);

                                          cout<<"retorno--"<<retorno<<endl;       
                                          getchar();
                                          }

                         if(input=="achar")
                         {
                         cout<<"Escreva o nome da variavel"<<endl;
                         getline(cin, input);
                         retorno=retorna_valor_variavel(input);
                         if( retorno!= VARIAVEL_INEXISTENTE )
                         cout<<"variavel vale--"<<retorno<<endl;
                         else
                         cout<<"variavel nao encontrada"<<endl;
               
                         getchar();

                         }

                         }
             }
return 0; 
}        
