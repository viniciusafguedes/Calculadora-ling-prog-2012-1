#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "namespacefuncoes.h"

using namespace std;


namespace funcoes{
    extern unsigned int numero_achados_esquerda(0),numero_achados_direita(0);
    extern vector<size_t> posicao_achado_esquerda (30);
    extern vector<size_t> posicao_achado_direita (30);    
    extern vector<size_t> comeco_parentese (30);//contem a posicao do comeco dos blocos formados por parenteses, usar o loop com a variavel numero_de_blocos
    extern vector<size_t> fim_parentese (30);//contem a posicao do final dos blocos formados por parenteses, usar o loop com a variavel numero_de_blocos
    extern unsigned int numero_de_blocos=0;// contem o numero de blocos formados por parenteses   
}
          
          //quero testar se estao balanceados e saber as posiçoes para que na fase de analise de expressao nao se analise
          // + e - dentro de parenteses.
          
//------------------------------------------------------------
          int funcoes::parenteses(string expressao)
        {             
        funcoes::numero_achados_esquerda=0;
        funcoes::numero_achados_direita=0;
        unsigned int i,j,l;
        size_t found;
        j=0;l=0;
        funcoes::numero_de_blocos=0;        
              for(i=0;i<expressao.length();i++)
              {
              found=expressao.find("(",i);              
                    if (found != string::npos)
                    {
                    funcoes::posicao_achado_esquerda[numero_achados_esquerda]=found;//
                    funcoes::numero_achados_esquerda++;
                    i=found;          
                    }              
               }
               for(i=0;i<expressao.length();i++)
               {
               found=expressao.find(")",i);             
                   if (found != string::npos)
                   {
                   funcoes::posicao_achado_direita[numero_achados_direita]=found;//
                   funcoes::numero_achados_direita++;
                   i=found;
                   }
               }
               if(funcoes::numero_achados_esquerda == funcoes::numero_achados_direita)//quer dizer que esta balanceado
               {//se esta balanceado, entao vamos determinar aonde começa e termina os parenteses
                     for(i=0;i<expressao.length();i++)
                     {
                           if (expressao[i]=='(')
                           {
                                 if( j==0)
                                 {
                                 comeco_parentese[funcoes::numero_de_blocos]=i;
                                 funcoes::numero_de_blocos++;
                                 }
                           j++;
                           } 
                                           
                           if(expressao[i]==')')                  
                           l++;                 
                           if(j==l && j!=0)
                           {
                           fim_parentese[funcoes::numero_de_blocos-1]=i;
                           j=0;l=0;
                           }                                                
                     }
               return  0;// parenteses balanceados
               }
               
               else 
               return 1;//parenteses debalanceados
        }
          
