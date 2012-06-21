#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "namespaceInterpretador.h"
#include "namespacevariaveis.h"
#include "namespacefuncoes.h"
#include "namespaceio.h"

//using namespace guarda_variaveis;
//using namespace io;
//using namespace Interpretador;
//using namespace funcoes;
using namespace std;

int main()
{
    vector<string> exprs (30);
    double resultado,retorno,val;
    string input,value, direcao, gambiarra;
    unsigned int i;
    int err, listar;
    
    while(input!="exit")
         {
         cout<<endl;
         cout<<"--------------------------------------------------------"<<endl;
         cout<<"|Escreva as expressoes para computa-las                 |"<<endl;
         cout<<"|Escreva listar para listar as variaveis e seus valores |"<<endl;
         cout<<"|Escreva achar para procurar o valor de uma variavel    |"<<endl;
         cout<<"|Escreva exit para sair                                 |"<<endl;
         cout<<"--------------------------------------------------------"<<endl;
         cout<<endl;
       
         getline(cin, input);
         direcao=input;
         
         input=io::tirar_espacos(direcao);// input neste momento é uma string que contem toda expressao, porem sem espaços                
       
         if(direcao=="exit" || direcao=="listar" || direcao=="inserir" || direcao=="achar" || direcao[0]==0 ) 
               {                                      
               if(direcao[0]==0)// apertou somente enter   
               cout<<endl;
       
               if(direcao=="exit")   
               return 0;              
                               
               if(direcao=="inserir")
                     {
                     cout<<"Escreva o nome a inserir"<<endl;
                     getline(cin, input);
                        
                     cout<<"Escreva o valor"<<endl;
                        
                     getline(cin, value);
                     istringstream st(value);
                        
                        if (!(st >> val))// nao era um +/- number                                            
                        cout<<"valor invalido"<<endl;
                        
                     retorno=guarda_variaveis::salva_variavel(input,val);
                     cout<<"variavel inserida com valor->"<<retorno<<endl;
                     }
                        
                        
               if(direcao=="listar")
                     { 
                     cout<<endl;                                            
                     
                     for( listar=0; listar < guarda_variaveis::numero_variaveis ; listar++)
                          {                                      
                          cout<< guarda_variaveis::nome_variaveis[listar];
                          cout<<"->"<<guarda_variaveis::valor_variaveis[listar]<<endl;                                      
                          }
                     cout<<endl;        
                     }                        
                        
        if(direcao=="achar")
               {
               cout<<"Escreva o nome da variavel"<<endl;
               getline(cin, input);
               retorno=guarda_variaveis::retorna_valor_variavel(input);
                      if(retorno!=guarda_variaveis::VARIAVEL_INEXISTENTE)
                             cout<<"variavel vale->"<<retorno<<endl;
                      else
                             cout<<"variavel nao encontrada"<<endl;
               }                        
        }
                       
        else      
               {
                                      
               exprs = io::quebrar_strings(input);// input é passado como referencia neste ponto, logo se houver ; no fim, input será vazio
               // como input é passado como referencia, input é modificado ao longo do quebrar strings
               
               //cout<<exprs[0]<<endl;
               //cout<<"input->"<<input<<endl;
               gambiarra=input;
                                           
               if(input=="")// existe ;  no final da ultima expressao
                      {
                      //cout<<"entrou, logo input nao tem nada"<<endl;                         
                      for( i = 0 ; i < io::numero_expr ; i++)
                            {
                            //cout<<"io::numero_expr="<<io::numero_expr<<endl;
                            //cout<<"exprs[i]"<<exprs[i]<<endl;
                            gambiarra = exprs[i];                                         
                            resultado = Interpretador::expressao (gambiarra);
                            
                            //cout<<resultado<<endl;
                                                                                                     
                            err=io::imprime_erro(resultado);                                            
                                  if(err)
                                  {
                                  cout<<"Deu merda na expressao -> "<<gambiarra<<endl;
                                  cout<<endl;
                                  }
                                                 
                                  if( !err)
                                  {
                                           if (resultado!= Interpretador::PULA_LINHA)                                               
                                           {
                                           cout<<"resultado final de "<<gambiarra<<" -> "<<resultado<<endl;
                                           cout<<"---------------------------- "<<endl;
                                           }
                                  }
                            }                                                                   
                      }
               else// neste else trata-se do caso onde a ultima expressao nao contém ; no final
                      {                                                                                                                
                      for(i=0 ; i < io::numero_expr-1 ; i++)// resolve tudo a nao ser a ultima expressao que nao contem ;
                            {
                            //cout<<"io::numero_expr-1="<<io::numero_expr-1<<endl;
                            //cout<<"exprs[i]"<<exprs[i]<<endl;
                            gambiarra = exprs[i];                                           
                            resultado = Interpretador::expressao (gambiarra);                             
                            err=io::imprime_erro(resultado);
                                   if(err)
                                   {
                                   cout<<"Deu merda na expressao -> "<<gambiarra<<endl;
                                   cout<<endl;      
                                   }
                                                                                                
                                   if( !err)
                                   {
                                          if (resultado!= Interpretador::PULA_LINHA)
                                          {
                                          cout<<"resultado final de "<<gambiarra<<" -> "<<resultado<<endl;
                                          cout<<"---------------------------- "<<endl;
                                          }
                                   } 
                            } 
                                            
                      resultado= Interpretador::expressao (input); // resolve a ultima expressao que nao contem ;                            
                      err= io::imprime_erro(resultado);                                          
                            if(err)
                            {                                                                            
                            cout<<"Deu merda na expressao -> "<<input<<endl;
                            cout<<endl;
                            }                                            
                            if( !err)
                            {
                                    if (resultado!= Interpretador::PULA_LINHA)                                                 
                                    {                             
                                    cout<<"resultado que nao deveria sair "<<gambiarra<<" -> "<<resultado<<endl; 
                                    cout<<"---------------------------- "<<endl;
                                    }
                            }                                  
                      } //fim do else                        
               }//fim de outro else
        }//fim do while
system("pause");
return 0; 
} 
