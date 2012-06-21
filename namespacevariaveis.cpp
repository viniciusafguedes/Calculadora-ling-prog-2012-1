#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "namespacevariaveis.h"

using namespace std;

namespace guarda_variaveis
{

//extern vector<string> nome_variaveis (200);
//extern vector<double> valor_variaveis (200);
//extern int numero_variaveis = 0;
//extern int index=0;
}
//const double VARIAVEL_INEXISTENTE = 1.7e+308;// valor de constante para funçao retorna_valor, quando nao acha a variável

 double guarda_variaveis::retorna_valor_variavel(string variavel)
        {
        
        istringstream iss;
        string var,aux;        
        var=variavel;
        iss.str (var);
        iss >> aux;
        
            for(index=0;index<numero_variaveis;index++)
            {
            if(aux==nome_variaveis[index])
            return valor_variaveis[index];
            }
        
        return VARIAVEL_INEXISTENTE;
        }
//-----------------------------------------------------       
 double guarda_variaveis::salva_variavel (string nome , double valor)// essa funçao testa se a variavel é nova ou se ja existe, caso seja uma nova
        {                                             //variavel ela aloca lugar na matriz, caso contrário, substitui o valor e retorna o valor substituido
        double teste;
        teste=guarda_variaveis::retorna_valor_variavel(nome);                
        
                if (teste == guarda_variaveis::VARIAVEL_INEXISTENTE)
                {                        
                nome_variaveis[numero_variaveis]=nome;
                valor_variaveis[numero_variaveis] =valor;
                numero_variaveis++;
                }
        
                if (teste != guarda_variaveis::VARIAVEL_INEXISTENTE)
                {
                istringstream iss;
                string var,aux;        
                var=nome;
                iss.str (var);
                iss >> aux;
        
                    for(index=0;index<numero_variaveis;index++)
                    {
        
                    if(aux==nome_variaveis[index])
                    valor_variaveis[index]=valor;
        //cout<<"variavel-"<<index<<"nome: "<<nome_variaveis[index]<<" valor= "<<valor_variaveis[index]<<endl;
                    }
                }        
        //cout<<"valor gravado "<<valor<<endl;
        //getchar();        
        return valor;
        }




                                                   
