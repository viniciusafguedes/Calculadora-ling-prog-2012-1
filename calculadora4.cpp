#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace io
{                            
          const double SINAIS_REPETIDOS=1.69888e+308;
          
          int numero_achados, numero_expr(0);
          vector<size_t> posicao_achados (30) ;
          
//------------------------------------------------------ 
          //esta funçao recebe uma string com varios ; e devolve um vetor de strings, onde cada string é a expressao entre ;           
          
          vector<string> quebrar_strings ( string & entrada)
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

          int imprime_erro(double erro)
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
          
          double sinais_repetidos(string str)
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
          
       string tirar_espacos(string str)
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
 
}  
 
//------------------------------------------FIM DE NAMESPACE-------------------------------------------------------------------------

namespace funcoes
{
        unsigned int numero_achados_esquerda,numero_achados_direita;
        vector<size_t> posicao_achado_esquerda (30);
        vector<size_t> posicao_achado_direita (30);    
        vector<size_t> comeco_parentese (30);//contem a posicao do comeco dos blocos formados por parenteses, usar o loop com a variavel numero_de_blocos
        vector<size_t> fim_parentese (30);//contem a posicao do final dos blocos formados por parenteses, usar o loop com a variavel numero_de_blocos
        unsigned int numero_de_blocos=0;// contem o numero de blocos formados por parenteses
          
          //quero testar se estao balanceados e saber as posiçoes para que na fase de analise de expressao nao se analise
          // + e - dentro de parenteses.
          
//------------------------------------------------------------

        // esta função testa se os parenteses estãao balanceaados
        
        int parenteses(string expressao)
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
          
}

//------------------------------------------FIM DE NAMESPACE-------------------------------------------------------------------------

namespace guarda_variaveis
{
        const double VARIAVEL_INEXISTENTE = 1.7e+308;// valor de constante para funçao retorna_valor, quando nao acha a variável
        vector<string> nome_variaveis (200);
        vector<double> valor_variaveis (200);
        int numero_variaveis = 0;
        int index=0;
        
//------------------------------------------------------

// esta função recebe uma string e procura no vetor nome_variaveis(200) a variavel e retorna seu valor

        double guarda_variaveis::retorna_valor_variavel(string variavel)
        {             
            for(guarda_variaveis::index=0; guarda_variaveis::index < guarda_variaveis::numero_variaveis ; guarda_variaveis::index++)
            {
                  if(variavel== guarda_variaveis::nome_variaveis[index])
                  return guarda_variaveis::valor_variaveis[guarda_variaveis::index];
            }      
        return guarda_variaveis::VARIAVEL_INEXISTENTE;
        }
        
//----------------------FIM DE FUNÇÃO------------------------------- 

// esta função receber um nome e um valor e armazena este nome em guarda_variaveis::nome_variaveis[],
//e guarda o valor em guarda_variaveis::valor_variaveis[] retornando o valor guardado

// essa funçao testa se a variavel é nova ou se ja existe, caso seja uma nova      
//variavel ela aloca lugar na matriz, caso contrário, substitui o valor e retorna o valor substituido
        double guarda_variaveis::salva_variavel (string nome , double valor)
        {                                             
        double teste;
        teste=guarda_variaveis::retorna_valor_variavel(nome);                     
              if (teste == guarda_variaveis::VARIAVEL_INEXISTENTE)
              {                        
              guarda_variaveis::nome_variaveis[guarda_variaveis::numero_variaveis]= nome;
                valor_variaveis[guarda_variaveis::numero_variaveis] = valor;
                guarda_variaveis::numero_variaveis++;
              }
        
              if (teste != guarda_variaveis::VARIAVEL_INEXISTENTE)
              {
                istringstream iss;
                string var,aux;        
                aux=nome;
                    for(guarda_variaveis::index=0; guarda_variaveis::index < guarda_variaveis::numero_variaveis; guarda_variaveis::index++)
                    {        
                          if(aux == guarda_variaveis::nome_variaveis[guarda_variaveis::index] )
                          guarda_variaveis::valor_variaveis[guarda_variaveis::index] = valor;
        //cout<<"variavel-"<<index<<"nome: "<<nome_variaveis[index]<<" valor= "<<valor_variaveis[index]<<endl;
                    }
              }        
        //cout<<"valor gravado "<<valor<<endl;
        //getchar();        
        return valor;
        }

}

//------------------------------------------FIM DE NAMESPACE-------------------------------------------------------------------------

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
        
        
        double expressao (string);// somente a declaração, pois estou sem .h
        
//----------------------FIM DE FUNÇÃO-------------------------------
       
       // esta função converte uma string em double, ela aceita numeros do tipo 3e+3, se der errado ela retorna Interpretador::NAO_NUMERO
       
       double converter_para_double (string numero)
       {
       string tentativa;
       double d;
       char * cstr;
       char* end = 0 ;
       istringstream st(numero);
       st>>tentativa;              
       cstr = new char [tentativa.size()+1];//cria um vetor com nome cstr para alocar a string str
       strcpy (cstr, tentativa.c_str());                
       d = strtod( cstr, &end );
             if ( *end == 0 )
             {
             delete[] cstr;// desaloca a memoria para nao haver vazamento  
             return d;// a conversao deu certo
             }                
             
             else
             delete[] cstr;// desaloca a memoria para nao haver vazamento               
             return Interpretador::NAO_NUMERO;// conversao errado
       }

//----------------------FIM DE FUNÇÃO-------------------------------

// esta função pega algo como (expressao1+(expressao2)) e retira os parenteses mais internos e retorna somente expressao2

        string expandir_expressao(string expressao)
        {
        string nova_expressao, termo;
        size_t retorno, comeco_parentese,fim_parentese;      
        unsigned int i,j,parentese_esquerdo,parentese_direito, contador;
        contador=0;
        i=0;
        parentese_esquerdo=0;
        parentese_direito=0;       
       /* comeco_parentese e fim_parentesse, vao conter os lugares onde comeeça um grupo de parentese, ex:
        (.....(....)....), comeco_parentese vai conter o numero 0 e fim parentese
       */ 
             for(j=0;j<expressao.length();j++)
             {        
                   while( ( i<expressao.length()) && ( contador==0) )
                   {
                         if(expressao[i] == '(')
                         {
                         parentese_esquerdo++;
                               if(parentese_esquerdo==1)
                               comeco_parentese=i;
                         }
              
                         if(expressao[i]==')')
                         parentese_direito++;
                                                                      
                         if( parentese_esquerdo==parentese_direito && parentese_esquerdo>0)
                         contador++;
                                
                         if (i < expressao.length())
                         fim_parentese=i;//contem a posicao no vetor expressao[] que contem o ultimo parentese
                                                     
                         i++;
                         j=fim_parentese;
                   }
             }       
       nova_expressao=expressao.substr(comeco_parentese+1,(fim_parentese-comeco_parentese)-1);                
       return nova_expressao;
       }
       
//----------------------FIM DE FUNÇÃO-------------------------------

// esta função resolve a primary           
          
       double primary (string input_primary)
       {
       string aux_primary,retorno_expressao;
       double valor;                   
       char * cstr;
       char* end = 0 ;       
       aux_primary=input_primary;       
       
       cstr = new char [input_primary.size()+1];//cria um vetor com nome cstr para alocar a string str para tentar a conversao
       strcpy (cstr, input_primary.c_str());
       valor = strtod( cstr, &end );
              
             if ( *end == 0 )  
             {
             delete[] cstr;// desaloca a memoria alocada em cstr para nao haver vazamento
             return valor;// a conversao deu certo
             }
  
             else// conversao nao deu certo, primary= + ou - primary, (expressao), name.
             {
             delete[] cstr;// desaloca a memoria para nao haver vazamento e continua fazendo testes              
             istringstream st(input_primary);
             st>>aux_primary;
             //aux_primary contem uma string sem os espaços e nao representa um nummber. ou seja, ou é variavel ou (expressao)                             
                   if(aux_primary[0]=='(')//neste ponto estou retornando 0, porem irei aplicar
                   {
                   retorno_expressao = Interpretador::expandir_expressao(aux_primary);
                   //cout<<"nova expressao "<<retorno_expressao<<endl;
                   valor = Interpretador::expressao(retorno_expressao);
                   return valor;// no final mandar retornar o valor da expressao (valor)
                   }/*modificar para retornar o resultado da expressao e nao zero*/
                                                                                                                  
                   if(aux_primary[0]=='-')//estou retornando algo como - primary 
                   {
                   aux_primary.erase(0,1);
                   valor = - primary(aux_primary);
                   return valor;                                                                                                      
                   }
                             
                   if(aux_primary[0]=='+')// estou retornando algo como +primary
                   {
                   aux_primary.erase(0,1);
                   valor = primary(aux_primary);
                   return valor;                                                   
                   }                             
                   
                   else// a coisa escrita era um name, verifico se existe ou nao. se nao existir retorna VARIAVEL_INEXISTENTE
                   {
                   valor= guarda_variaveis::retorna_valor_variavel(aux_primary);
                   return valor;
                   }
             }               
        }

//----------------------FIM DE FUNÇÃO-------------------------------

// esta função expande os termos 

        double termo (string termo)//multiplicaçao tambem nao pode estar dentro de parentese
        {
        string aux_termo,novo_termo;
        double valor,retorno_termo,retorno_termo2;     
        size_t sinal;
        int i,contador,marcador,autorizacao;                
        marcador=0;
        aux_termo=termo;
        //cout<<"termo "<<termo<<endl;
        autorizacao=funcoes::parenteses(aux_termo);    
        
        //cout<<"termo de entrada->"<<termo<<endl;
       
             if (termo[0]==0)// foi passado algo vazio
             return Interpretador::EXPRESSAO_INVALIDA;
             
             /*if (termo[0]=='*')// nao pode começar com o sinal de *
             return TERMO_INVALIDO;
             
             if (termo[0]=='/')// nao pode começar com o sinal de /        
             return TERMO_INVALIDO;*/
       
             //if (termo[termo.length()-1]=='-')// nao pode termo*termo- *
             //return TERMO_INVALIDO;
       
             //if (termo[termo.length()-1]=='+')// nao pode começar com o sinal de *
             //return TERMO_INVALIDO;
              
             if(autorizacao==0)// só posso continuar se os parenteses estiverem ok
             {
                   for(i=0;i<termo.length();i++)
                   {                 
                   sinal=termo.find_first_of("*",i);       
                         if(sinal!=string::npos && (sinal<funcoes::comeco_parentese[marcador] || funcoes::numero_achados_esquerda==0) )
                         {                              
                               if(termo[sinal]=='*')
                               {                                                                                        
                               aux_termo=termo.substr(0,sinal);//sera o novo termo(talvez primary)
                               novo_termo=termo.substr(sinal+1,termo.length());//sera o novo termo
                               
                               //cout<<"termo da esquerda"<<aux_termo<<endl;                                                            
                               //cout<<"termo da direita"<<novo_termo<<endl;
                                     
                                     if (novo_termo[0]==0)// antes ou apos um sinal de * tem q ter algo                                    
                                     return TERMO_INVALIDO;
                                     
                                     if (aux_termo[0]==0)// antes ou apos um sinal de * tem q ter algo                                    
                                     return TERMO_INVALIDO;
                                     
                                     
                               //cout<<"primary esquerda na multiplicacao->"<<aux_termo<<endl;
                               //cout<<"termo direita na multiplicacao->"<<novo_termo<<endl;                    
                               retorno_termo= Interpretador::primary(aux_termo);
                               retorno_termo2=Interpretador::termo(novo_termo);                                                             
                                     
                                     if (retorno_termo > 1.69e+308)// se houver algum erro antes
                                     return retorno_termo;
                                     if (retorno_termo2 > 1.69e+308)// se houver algum erro antes
                                     return retorno_termo2;
                                                             
                               valor=retorno_termo*retorno_termo2;
                               //cout<<"valor->"<<valor<<endl;                                                             
                               return valor;
                               }
                         }                                     
                   sinal=termo.find_first_of("/");                                      
                         if(sinal!=string::npos && (sinal<funcoes::comeco_parentese[marcador] || funcoes::numero_achados_esquerda==0))
                         {                                                                     
                               if(termo[sinal]=='/')
                               {
                               aux_termo=termo.substr(0,sinal);//sera o novo termo;
                               novo_termo=termo.substr(sinal+1,termo.length());//sera o novo primary                                                             
                                     
                                     //cout<<"termo da esquerda"<<aux_termo<<endl;                                                            
                                     //cout<<"termo da direita"<<novo_termo<<endl;
                                     
                                     if (novo_termo[0]==0)
                                     return TERMO_INVALIDO;
                                     
                                     if ( aux_termo[0]==0)
                                     return TERMO_INVALIDO;
                                     
                               //cout<<"primary esquerda na divisao->"<<aux_termo<<endl;
                               //cout<<"termo na divisao direita->"<<novo_termo<<endl;                                                             
                               retorno_termo = Interpretador::primary(aux_termo);
                               retorno_termo2= Interpretador::termo(novo_termo);                                                             
                               
                                     if (retorno_termo > 1.69e+308)// se houver algum erro antes
                                     return retorno_termo;                                     
                                     if (retorno_termo2 > 1.69e+308)// se houver algum erro antes
                                     return retorno_termo2;
                                                             
                                     if (retorno_termo2 == 0)
                                     return Interpretador::DIVISAO_POR_ZERO;
                                                             
                               valor=retorno_termo/retorno_termo2;
                               //cout<<"valor->"<<valor<<endl;
                               return valor;
                               }                                                            
                         }
                               if(i==funcoes::comeco_parentese[marcador])
                               {
                               i=funcoes::fim_parentese[marcador];
                               marcador++;
                               }
                               
                               if( marcador == funcoes::numero_de_blocos)
                               funcoes::comeco_parentese[marcador]=termo.length();
                   }
             }                                                                                                      
       valor = Interpretador::primary(termo);                            
       //cout<<"valor de retorno da primary->"<<valor<<endl;
       return valor;                            
       }

//----------------------FIM DE FUNÇÃO-------------------------------
       
       //esta função expande a expressao e verifica os possiveis erros na expressao
       
        double expressao (string expressao)
        { 
        string name,termo,expressao3,aux;
        size_t found,found2,teste,testinho2,testinho3;
        double valor;
        int autorizacao,contador, j;
        unsigned int i,marcador;
        marcador=0;
        teste=0;
            
        valor = io::sinais_repetidos(expressao); //verifica se tem sinais repetidos na expressão              
        //cout<<"expressao de entrada->"<<expressao<<endl;              
              
              if( valor== io::SINAIS_REPETIDOS)
              return valor;
                           
        autorizacao = funcoes::parenteses(expressao);//tem que estar balanceado para continuar, se ok autorizacao==0                         
              if(autorizacao==0)
              {                                             
              found=expressao.find_first_of("=");
              //cout<<"found "<<found<<endl;
              //cout<<"funcoes::posicao_achado_esquerda[0]"<<funcoes::posicao_achado_esquerda[0]<<endl;              
                    if (found !=string::npos && (found<=funcoes::posicao_achado_esquerda[0] || funcoes::numero_achados_esquerda==0))//quer dizer que existe uma atribuiçao de =, 
                    //e o que vem antes do igual deve ser testado para que nao contenha +-*/ e nem seja um numero valido 
                    {                                                           
                    name= expressao.substr (0,found);//estou pegando o q vem antes do = / lado esquerdo da expressao                      
                    contador=0;
                    
                    // variavel nao pode ser um número seguido do caracter e+ numero
                    teste=name.length()-1;//pegando o valor do indice do ultimo caracter na string name
                          if(name[teste]=='e')
                          {
                                for (j=teste-1; j>=0; j--)
                                {                                              
                                testinho2=name.find_last_of("0123456789",j);
                                      
                                      if(testinho2==j)
                                      contador++;
                                }
                                                                           
                               if (contador==teste)
                               return Interpretador::NOME_VARIAVEL_PROIBIDO;                                                                  
                          } 
                     // termina o teste para saber se a variavel era algo como numero 'e'     
                                              
                    found2= name.find_first_of("+-*/()");                                           
                    //cout<<"name la dentro "<<name<<endl;                              
                          
                          if (found2 !=string::npos)//achou sinal em um name
                          return Interpretador::ERRO_NOME_VARIAVEL;
                 
                    valor= Interpretador::converter_para_double(name);//tenta converter a variavel para um número                      
                          
                          if (valor!= NAO_NUMERO) 
                          return Interpretador::ERRO_NOME_VARIAVEL;//a variavel era um numero
                 
                    expressao3=expressao.substr(found+1,expressao.length());//lado diretio da expressao                      
                          
                          if (expressao3[0]==0)// o lado direito da expressao nao contem nada tipo: a=
                          return EXPRESSAO_INVALIDA;
                                         
                    valor = Interpretador::expressao(expressao3);                                                                       
                      
                            if (valor >=1.69e+308)// se houver algum erro antes
                            return valor;//que dizer que deu erro
                                                                                    
                    //cout<<"name "<<name<<" valor "<<valor<<endl;
                    valor=guarda_variaveis::salva_variavel(name,valor);//se nao deu erro entao a variavel deve ser guardada
                    return valor;
                    }
                      
              else// se nao houver uma atribuiçao de =
              {                           
              
              
              //found=expressao.find_first_of("*/"); //expressao nao pode começar com * ou /
              //cout<<"found "<<found<<endl;
                    
                    //if (found==0)//expressao nao pode começar com * ou /                         
                    //return EXPRESSAO_INVALIDA;
                                                                  
              
              autorizacao = funcoes::parenteses(expressao);//tem q estar balanceado para continuar, se ok autorizacao==0                         
              //os sinais de + e - nao podem estar dentro de parentese, por isso a necessidade de saber onde esta a posicao
              //dos blocos formados pelos parenteses, e a função parenteses faz isso tambem.                    
                    if(autorizacao==0)// os parenteses estão balanceados (isto é uma redundancia)
                    {                                                                                             
                          for(i=0;i<expressao.length();i++)
                          {   
                          teste=0;                                                                     
                          //cout<<"comeco parentese"<<funcoes::comeco_parentese[i]<<endl;                                     
                                
                                if(i==0)
                                found=expressao.find("+",1);                                     
                                
                                else
                                found=expressao.find("+",i);//os sinais + e - nao podem estar dentro de parenteses , os que estiverem detro
                                //de parenteses, tem que ser avaliado somante depois de serem avaliados pela primary                                   
                                
                                //cout<<"found "<<found<<endl;
                          teste=0;                                
                                
                                //testa se o + não é de algo como 3e+2 e sim um + de operação
                                if(found!=0 && found!=string::npos)
                                {  
                                      if ( (expressao[found-1] == 'e'))
                                      teste++;
                                              
                                aux=expressao[found-2];                                            
                                testinho2= aux.find_first_of("0123456789");    
                                      
                                      if (testinho2 != string::npos)
                                      teste++;
                                              
                                aux=expressao[found+1];   
                                testinho3= aux.find_first_of("0123456789");    
                                          
                                     if ( testinho3 != string::npos)
                                          teste++;                                                          
                                }                                                                                                                                                                              
                                // final do teste de operação ou se é de Xe+x
                                
                                if(found!=0 && found!=string::npos && funcoes::numero_achados_esquerda==0 && (teste!=3))
                                //nao tem parentese e o sinal de + também é de operação
                                {
                                termo=expressao.substr(0,found);
                                expressao3= expressao.substr(found+1,expressao.length()-found+1);
                                         
                                if(termo[0]==0)
                                return EXPRESSAO_INVALIDA;
                                         
                                if (expressao3[0]==0)
                                return EXPRESSAO_INVALIDA;
                                      
                                //cout<<"expressao1 "<<termo<<" expressao2 "<<expressao3<<endl;
                                      
                                valor = Interpretador::termo(termo)+Interpretador::expressao(expressao3);
                                return valor;
                                }
                                
                                //tem parentese e o sinal de + também é de operação
                                //cout<<marcador<<endl;
                                //cout<<"comeco_parentese "<<funcoes::comeco_parentese[marcador]<<endl;
                                         
                                if (found!=0 && found!=string::npos && found<funcoes::comeco_parentese[marcador] && (teste!=3) )
                                {                                                                                       
                                termo=expressao.substr(0,found);
                                expressao3= expressao.substr(found+1,expressao.length()-found+1);
                                         
                                      if(termo[0]==0)
                                      return EXPRESSAO_INVALIDA;
                                         
                                      if (expressao3[0]==0)
                                      return EXPRESSAO_INVALIDA;
                                         
                                //cout<<"expressao1b "<<termo<<" expressao2b "<<expressao3<<endl;
                                //system("pause");            
                                valor = Interpretador::termo(termo)+Interpretador::expressao(expressao3);
                                return valor;
                                }                               
                          teste=0;
                                            
                                if(i==0)
                                found=expressao.find("-",1);
                                         
                                else
                                found=expressao.find("-",i);
                                //cout<<found<<endl;                                                                                 
                                            
                                //testa se o - não é de algo como 3e-2 e sim um - de operação
                                if(found!=0 && found!=string::npos)
                                {                                                   
                                      
                                      if ( (expressao[found-1] == 'e'))
                                      teste++;        
                                          
                                aux=expressao[found-2];                                              
                                testinho2= aux.find_first_of("0123456789");                                              
                                      
                                      if (testinho2 != string::npos)
                                      teste++;        
                                            
                                aux=expressao[found+1];   
                                testinho3= aux.find_first_of("0123456789");    
                                          
                                      if ( testinho3 != string::npos)
                                                  teste++;                                                                    
                                }                                          
                                // final do teste de operação ou se é de Xe-x
                               
                                if(found!=0 && found!=string::npos && funcoes::numero_achados_esquerda==0 && (teste!=3))
                                //nao tem parentese e o sinal de - também é de operação
                                {
                                termo=expressao.substr(0,found);
                                expressao3= expressao.substr(found,expressao.length()-found+1);
                                         
                                      if(termo[0]==0)// falta a parte esquerda da expressao
                                      return EXPRESSAO_INVALIDA;
                                         
                                      if (expressao3[1]==0)// esta faltando o resto da expressão, só exite o -
                                      return EXPRESSAO_INVALIDA;
                                         
                                      //cout<<"expressao1c "<<termo<<" expressao2c "<<expressao3<<endl;
                                      //system("pause");
                                valor = Interpretador::termo(termo)+Interpretador::expressao(expressao3);
                                return valor;
                                }                                            
                          //tem parentese e o sinal de - também é de operação
                                
                                if (found!=0 && found!=string::npos && found<funcoes::comeco_parentese[marcador] && (teste!=3) )
                                {
                                termo=expressao.substr(0,found);
                                expressao3= expressao.substr(found,expressao.length()-found+1);
                                         
                                      if(termo[0]==0)// falta a parte esquerda da expressao
                                      return EXPRESSAO_INVALIDA;
                                         
                                      if (expressao3[1]==0)
                                      return EXPRESSAO_INVALIDA;// esta faltando o resto da expressão, só exite o -
                                            
                                      //cout<<"expressao1d "<<termo<<" expressao2d "<<expressao3<<endl;
                                      //system("pause");                             
                                valor = Interpretador::termo(termo)+Interpretador::expressao(expressao3);
                                return valor;
                                }
                                            
                                if(i==funcoes::comeco_parentese[marcador])
                                {
                                i=funcoes::fim_parentese[marcador];
                                marcador++;
                                }
                                              
                                if( marcador == funcoes::numero_de_blocos)
                                funcoes::comeco_parentese[marcador]=expressao.length();
                                
                          }
                    }                          
              }
                    
                    
                    if(expressao[0]==0)
                    {
                    //cout<<"tem q pula linha"<<endl;
                    return Interpretador::PULA_LINHA;
                    }
                    
              //cout<<"expressao que vai para termo->"<<expressao<<endl;
                 
              valor=Interpretador::termo(expressao);
              return valor;
              }
       return Interpretador::PARENTESES_DESBALANCEADOS; 
       }
       
}

//------------------------------------------FIM DE NAMESPACE-------------------------------------------------------------------------
     
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
                     
                     for(listar=0; listar< guarda_variaveis::numero_variaveis; listar++)
                          {                                      
                          cout<<guarda_variaveis::nome_variaveis[listar];
                          cout<<"->"<<guarda_variaveis::valor_variaveis[listar]<<endl;                                      
                          }
                     cout<<endl;        
                     }                        
                        
        if(direcao=="achar")
               {
               cout<<"Escreva o nome da variavel"<<endl;
               getline(cin, input);
               retorno= guarda_variaveis::retorna_valor_variavel(input);
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
                      for( i = 0 ; i <io::numero_expr ; i++)
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
                      for(i=0 ; i<io::numero_expr-1 ; i++)// resolve tudo a nao ser a ultima expressao que nao contem ;
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
                                            
                      resultado=Interpretador::expressao (input); // resolve a ultima expressao que nao contem ;                            
                      err=io::imprime_erro(resultado);                                          
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
