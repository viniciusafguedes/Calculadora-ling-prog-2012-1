#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "namespaceio.h"

using namespace std;

namespace io{
          
          //const double SINAIS_REPETIDOS=1.69888e+308;
          
          //extern int numero_achados;
          //extern int numero_expr =0;
          //extern vector<size_t> posicao_achados (30) ;
          }
 
vector<string> io::quebrar_strings ( string & entrada)
          {
          io::numero_expr=0;          
          vector<string> expressao (30);
          unsigned i, ultima_pos;
          size_t achou;   
          ultima_pos=0;              
                for (i=0 ; i < entrada.length() ; i++)
                {            
                achou = entrada.find_first_of(";",ultima_pos);           
                      if( achou!= string::npos)
                      {
                      expressao[io::numero_expr]=entrada.substr(ultima_pos,achou-ultima_pos);
                      //cout<<expressao[io::numero_expr]<<endl;
                      ultima_pos=achou+1;            
                      io::numero_expr++;                   
                            if (achou == entrada.length()-1)
                            {
                            i=entrada.length();
                            entrada="";
                            return expressao;
                            }                 
                      }
                      if (achou == string::npos)
                      {
                      entrada.erase(0,ultima_pos);
                      //cout<<entrada<<endl;                  
                      io::numero_expr++;
                      //cout<<"numero_expr no string::npos "<<io::numero_expr<<endl;
                      i=entrada.length();
                      }            
                }
          return expressao ;
          }

//----------------------FIM DE FUNÇÃO------------------------------- 

// esta funçao recebe um valor double e imprime o erro correspondente(poderia usar case)

          int io::imprime_erro(double erro)// pode-se trocar os valores nos erros pelas contantes
          {
          //cout<<"erro-"<<erro<<endl;
          
                if( erro == 1.69999999e+308)
                cout<<"variaveis nao podem ter um nome do tipo: numero seguido do caracter e"<<endl;
     
                if( erro == 1.699999e+308)
                cout<<"divisao por zero"<<endl;
     
                if( erro==1.7e+308)
                cout<<"variavel inexistente"<<endl;
     
                if( erro==1.69e+308)
                cout<<"termo invalido"<<endl;
     
                if( erro==1.699e+308)
                cout<<"nao numero"<<endl;
     
                if( erro==1.6999e+308)
                cout<<"erro no nome da variavel"<<endl;
     
                if( erro==1.69998e+308)
                cout<<"parenteses desbalanceados"<<endl;
     
                if( erro==1.69988e+308)
                cout<<"expressao invalida"<<endl;
     
                if( erro==1.69888e+308)
                cout<<"sinais repetidos"<<endl;
     
                if (erro==1.6999999e+308)// NAO É ERRO, SIMPLESMENTE NAO TEM NADA A FAZER
                return 0;     
     
                if(erro<1.69e+308)
                return 0;//nenhum erro encontrado
     
                else
                return 1;//deu problema
          }
//----------------------FIM DE FUNÇÃO-------------------------------
            
          //esta função verifica a existencia de sinais repetidos na expresssao
          
          double io::sinais_repetidos(string str)
          {
          unsigned found,i;
       
                if(str[0]==0)
                return 0;
       
                for(i=0;i<str.length()-1;i++)
                {         
                found= str.find_first_of("+-*/=",i);            
                      if( found != string::npos )
                      {
                            if(str[found] == '=')
                            {            
                                  if(str[found+1] == '+')
                                  i=found+1;                      
                                  if(str[found+1] == '-')
                                  i=found+1;
                                  if(str[found+1] == '*')
                                  return io::SINAIS_REPETIDOS;
                                  if(str[found+1] == '/')
                                  return io::SINAIS_REPETIDOS;
                                  if(str[found+1] == '=')
                                  return io::SINAIS_REPETIDOS;
                            }
                            else
                            {
                                  if(str[found+1] == '*')
                                  return io::SINAIS_REPETIDOS;
                                  if(str[found+1] == '/')
                                  return io::SINAIS_REPETIDOS;
                                  if(str[found+1] == '=')
                                  return io::SINAIS_REPETIDOS;
                                  if(str[found+1] == '+')
                                  return io::SINAIS_REPETIDOS;
                                  if(str[found+1] == '-')
                                  return io::SINAIS_REPETIDOS;
                            }
                      i=found+1;
                      } 
                }
                return 0; //em caso de sucesso retorna 0
       }

//----------------------FIM DE FUNÇÃO-------------------------------

       // esta função remove todos os espaços vazios da string
          
       string io::tirar_espacos(string str)
       {    
       int i;
             for(int i=0; i<str.length(); i++)
             {
                   if(str[i] == ' ') 
                   {
                   str.erase(i,1);
                   i--;
                   } 
             }
       return str;
       } 
//------------------------------------------FIM DE NAMESPACE-------------------------------------------------------------------------
