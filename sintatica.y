
%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <utility>


#define MAX_VAR 1000
#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label, tipo, valor, nomeOriginal, traducao;
	int tamanho;
	bool desempilha;
};

struct variavel
{
    string nome, tipo;
    bool declarada;
    bool funcao;
};

struct funcao
{		
	string tipo, label, traducao;
	list<atributos> parametros;
};

struct vetor
{
	string tipo, label;
	int tamanho;
	int funcao;
};

struct matriz
{
	string tipo, label;
	int linhas;
	int colunas;
	int funcao;
};

struct escopo
{
	string inicio, verificacao, fim;
};

typedef list<map<string,atributos> > pilha;
typedef list<escopo> listaEscopo;
typedef map<string,funcao> listaFuncoes;

int variaveis[MAX_VAR];

string intToString(int valor);
int stringToInt(string temp);
void verificaExistencia(string label);
void verificaExistenciaEspertinho(string label);
void empilhaVariavel(string chave, string tipo, string nome, string valor, string nomeOriginal, bool desempilhar);
void adicionaFuncao(string chave, string label, string tipo);
bool compararParametros(list<atributos> fnc1, list<atributos> fnc2);
funcao buscarFuncao(string label);
funcao retornaFuncao(string label);
variavel buscarNaPilha(string label);
atributos retornaVariavel(string label);
string desempilhaTudo(map<string,atributos> mapa);
void manipulaChar(string chave, string str1, string str2, string op, string s1valor, string s3valor);
escopo criaBreakOuContinue();

void verificaPosicaoVetor(string label, int posicao);
void verificaPosicaoMatriz(string label, int linha, int coluna);

string floatToString(float valor);
float stringToFloat(string temp);

int yylex(void);
string geraLabel();
string geraLabelGlobal();
string geraEscopo();
escopo criaEscopo();
string getTipo(string var1, string op, string var2);
map<string, string> geraTabelaTipos();
void yyerror(string);

pilha pilhaVariaveis;
listaEscopo escopos;
listaFuncoes funcoes;

map<string, struct variavel> tabVariaveis;
map<string, struct vetor> tabVetores;
map<string, struct matriz> tabMatrizes;
map<string, string> tabTipos = geraTabelaTipos();

variavel variavelSwitch;
string temporariaSwitch = "";
string fimSwitch = "";

string valoresDeclaracao;

bool temBreakOuContinue = 0;

list<atributos> listaParametros;

%}

%token TK_NUM  TK_ABRE_PAR TK_FECHA_PAR TK_ABRE_CHV TK_FECHA_CHV TK_PNT_VIRGULA
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_TIPO_BOOL TK_TIPO_CHAR TK_CHAR TK_IF TK_ELSE TK_DO TK_WHILE TK_FOR TK_CASE TK_SWITCH TK_DEFAULT TK_SOMA TK_SUB TK_MUL TK_DIV TK_RETURN TK_ABRE_CLCH TK_FECHA_CLCH
%token TK_BREAK TK_CONTINUE
%token TK_FIM TK_ERROR  TK_REAL TK_TIPO_STRING TK_STRING TK_BOOLEAN
%token TK_IGUAL TK_DIFERENTE TK_MAIOR_QUE TK_MENOR_QUE TK_MAIOR_IGUAL TK_MENOR_IGUAL TK_E TK_OU TK_NEGACAO TK_MOD
%token TK_READ TK_WRITE
%token TK_INCREMENTO TK_DECREMENTO

%start S

%left TK_SOMA TK_SUB
%left TK_MUL TK_DIV


%%

S 			: GLOBAL
			{
				cout << "/*Compilador BX*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\n\n" << $1.traducao + "\n" << endl;
			}
			;
			
GLOBAL		: DEC_GLOBAL GLOBAL
			{
				$$.traducao = "\n" + $1.traducao + "\n" + $2.traducao;
			}
			| MAIN FNCS_ABAIXO
			{
				$$.traducao = "\n" + $1.traducao + "\n" + $2.traducao + "\n";
			}
			;

DEC_GLOBAL : TIPO TK_ID TK_PNT_VIRGULA
			{
                struct variavel var = {geraLabelGlobal(), $1.traducao, true, false};
            	verificaExistencia($2.label);
            	tabVariaveis[$2.label] = var;
            	string str1(var.tipo);
                if(str1.compare("string") == 0)
                {
                	$$.traducao = "char " + tabVariaveis[$2.label].nome + "[255];\n";
                }
            	else {
            		if ($1.traducao == "boolean") {
						$1.traducao = "bool";
					}
	              	$$.traducao = $1.traducao + " " + tabVariaveis[$2.label].nome + ";\n";            	
            	}
			}
			| DEC_FUNCAO ESCOPO_FNC
			{
				$$.traducao = $1.traducao + $2.traducao;
				
			}
			| DEC_FUNCAO TK_PNT_VIRGULA
			{
				$$.traducao = $1.traducao + ";\n\n";
				
			}
			;

FNCS_ABAIXO	: FNCS_ABAIXO FNC_ABAIXO
			{
				$$.traducao = $1.traducao + "\n" + $2.traducao;
			}
			| FNC_ABAIXO
			{
				$$.traducao = $1.traducao;
			}
			;
			
FNC_ABAIXO	: DEC_FNC_ABX ESCOPO_FNC
			{
				$$.traducao = $1.traducao + $2.traducao;
				
			}
			|
			{
				$$.traducao = "";
			}
			;
			
DEC_FNC_ABX	: TIPO TK_ID TK_ABRE_PAR VARIAVEIS TK_FECHA_PAR
			{
				funcao fnc = retornaFuncao($2.label);
				if(compararParametros(fnc.parametros, listaParametros)) {
					$$.traducao = $1.traducao + " " + fnc.label + "(" + $4.traducao + ") ";	
				}
				else {
					yyerror("Função não declarada!");
				}
			}
			;

DEC_FUNCAO	: TIPO TK_ID TK_ABRE_PAR VARIAVEIS TK_FECHA_PAR
			{
				string label = geraEscopo() + "funcao";
				adicionaFuncao($2.label, label, $1.traducao);
				$$.traducao = $1.traducao + " " + label + "(" + $4.traducao + ") ";
			}
			;

ESCOPO_FNC	: ESCOPO
			{
				$$.traducao = $1.traducao + "\n\n";
			}
			;

VARIAVEIS	: TIPO TK_ID
			{
				map<string,atributos> tabelaTemp;
				tabelaTemp.clear();			
				pilhaVariaveis.push_front(tabelaTemp);	
				
				string label = geraLabel();	
				empilhaVariavel(label, $1.traducao, label, "", $2.label, true);
				
				listaParametros.clear();
				
				atributos atr;
				atr.label = label;
				atr.tipo = $1.traducao;
				atr.nomeOriginal = $2.label;
				listaParametros.push_back(atr);
					
				struct variavel var = {label, $1.traducao, true, true};
            	tabVariaveis[$2.label] = var;
            	var.tipo = $1.tipo;
				
				$$.label = label;
				$$.traducao = $1.traducao + " " + label;			
				$$.tipo = $1.tipo;	
			}
			| TIPO TK_ID TK_ABRE_CLCH TK_FECHA_CLCH
			{
				string label = geraLabel();	
				empilhaVariavel(label, $1.traducao, label, "", $2.label, true);

				atributos atr;
				atr.label = label;
				atr.tipo = $1.traducao;
				atr.nomeOriginal = $2.label;
				listaParametros.push_back(atr);
				
				struct variavel var = {label, $1.traducao, true, true};
				struct vetor vet = {var.nome, $1.traducao, 0, true};
            	tabVariaveis[$2.label] = var;
            	tabVetores[$2.label] = vet;
				
            	vet.tipo = $1.tipo;
            	var.tipo = $1.tipo;
				
				$$.label = label;
				$$.traducao = $1.traducao + " *" + label;			
				$$.tipo = $1.tipo;	
			}
			// Matriz como parametro
			| TIPO TK_ID TK_ABRE_CLCH TK_FECHA_CLCH TK_ABRE_CLCH TK_FECHA_CLCH
			{
				string label = geraLabel();	
            	empilhaVariavel(label, $1.traducao, label, "", $2.label, true);
            	
				atributos atr;
				atr.label = label;
				atr.tipo = $1.traducao;
				atr.nomeOriginal = $2.label;
				listaParametros.push_back(atr);
				
				struct variavel var = {label, $1.traducao, true, true};
				struct matriz vet = {var.nome, $1.traducao, 0, 0, true};
            	tabVariaveis[$2.label] = var;
            	tabMatrizes[$2.label] = vet;
            	
            	vet.tipo = $1.tipo;
            	var.tipo = $1.tipo;
				
				$$.label = label;
				$$.traducao = $1.traducao + " **" + label;			
				$$.tipo = $1.tipo;	
			}
			| TIPO TK_ID ',' VARIAVEIS
			{
				string label = geraLabel();	
				empilhaVariavel(label, $1.traducao, label, "", $2.label, true);
				
				atributos atr;
				atr.label = label;
				atr.tipo = $1.traducao;
				atr.nomeOriginal = $2.label;
				listaParametros.push_back(atr);
					
				struct variavel var = {label, $1.traducao, true, true};
            	tabVariaveis[$2.label] = var;
            	var.tipo = $1.tipo;
				
				$$.label = label;
				$$.traducao = $1.traducao + " " + label + ", " + $4.traducao;			
				$$.tipo = $1.tipo;	
			}
			| TIPO TK_ID TK_ABRE_CLCH TK_FECHA_CLCH ',' VARIAVEIS
			{
				string label = geraLabel();	
				empilhaVariavel(label, $1.traducao, label, "", $2.label, true);
				
				atributos atr;
				atr.label = label;
				atr.tipo = $1.traducao;
				atr.nomeOriginal = $2.label;
				listaParametros.push_back(atr);
				
				struct variavel var = {label, $1.traducao, true, true};
				struct vetor vet = {var.nome, $1.traducao, 0, true};
            	tabVariaveis[$2.label] = var;
            	tabVetores[$2.label] = vet;
				
            	vet.tipo = $1.tipo;
            	var.tipo = $1.tipo;
				
				$$.label = label;
				$$.traducao = $1.traducao + " *" + label + ", " + $6.traducao;			
				$$.tipo = $1.tipo;	
			}
			// Matriz como parâmtro
			| TIPO TK_ID TK_ABRE_CLCH TK_FECHA_CLCH TK_ABRE_CLCH TK_FECHA_CLCH ',' VARIAVEIS
			{
				string label = geraLabel();	
				empilhaVariavel(label, $1.traducao, label, "", $2.label, true);
				
				atributos atr;
				atr.label = label;
				atr.tipo = $1.traducao;
				atr.nomeOriginal = $2.label;
				listaParametros.push_back(atr);
				
				struct variavel var = {label, $1.traducao, true, true};
				struct matriz vet = {var.nome, $1.traducao, 0, 0, true};
            	tabVariaveis[$2.label] = var;
            	tabMatrizes[$2.label] = vet;
				
            	vet.tipo = $1.tipo;
            	var.tipo = $1.tipo;
				
				$$.label = label;
				$$.traducao = $1.traducao + " **" + label + ", " + $8.traducao;			
				$$.tipo = $1.tipo;	
			}
			|
			{
				$$.traducao = "";
			}
			;
			
MAIN		: TK_TIPO_INT TK_MAIN TK_ABRE_PAR TK_FECHA_PAR ESCOPO
			{
				$$.traducao = "int main(void)\n" + $5.traducao + "\n\n"; 
			}
			;

ESCOPO		: ABRE_CHAVE COMANDOS FECHA_CHAVE
			{
				$$.traducao = "{\n\n" + $3.traducao +"\n" + $2.traducao + "\n}";
			}
			;

ABRE_CHAVE	: TK_ABRE_CHV
			{
				map<string,atributos> tabelaVariaveis;
				tabelaVariaveis.clear();
				pilhaVariaveis.push_front(tabelaVariaveis);
			}
			;
			
FECHA_CHAVE	: TK_FECHA_CHV
			{
				$$.traducao = desempilhaTudo(pilhaVariaveis.front());			
				pilhaVariaveis.pop_front();		
			}
			;

COMANDOS	: COMANDO COMANDOS
			{
				$$.traducao = $1.traducao + "\n" + $2.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: DECLARACOES
			| WHILE
			| DO_WHILE
			| SWITCH
			| FOR
			| IF
			| READ
			| WRITE
			| BREAK
			{
				$$.traducao = $1.traducao;
			}
			| CONTINUE
			{
				$$.traducao = $1.traducao;
			}
			| RETURN
			| CHAMADA_FNC
			| ABRE_CHAVE COMANDOS FECHA_CHAVE
			{
				$$.traducao = "{\n" + $3.traducao +"\n" + $2.traducao + "\n}";				
			}
			;
			
DECLARACOES : DECLARACAO TK_PNT_VIRGULA
			{
				$$.traducao = $1.traducao;
			}
			| E TK_PNT_VIRGULA
			| ATT TK_PNT_VIRGULA
			;
			
DECLARACAO	: TIPO TK_ID
            {
                struct variavel var = {geraLabel(), $1.traducao, true, false};
                verificaExistenciaEspertinho($2.label);
                empilhaVariavel(var.nome, $1.traducao, var.nome, "", $2.label, false);
            	tabVariaveis[$2.label] = var;
            	
            	string str1(var.tipo);
                if(str1.compare("string") == 0)
                {
                	$$.traducao = "\tchar " + retornaVariavel($2.label).label + "[255];\n";
                }
            	else {
            		if ($1.traducao == "boolean") {
						$1.traducao = "bool";
					}
	              	$$.traducao = "\t" + $1.traducao + " " + retornaVariavel($2.label).label + ";\n";            	
            	}
            }
			|
			TIPO TK_ID TK_ABRE_CLCH E TK_FECHA_CLCH
			{
				struct variavel var = {geraLabel(), $1.traducao, true, false};
				struct vetor vet = {var.nome, $1.traducao, stringToInt($4.valor), false};
                verificaExistenciaEspertinho($2.label);
                empilhaVariavel(var.nome, $1.traducao, var.nome, "", $2.label, false);
            	tabVariaveis[$2.label] = var;
            	tabVetores[$2.label] = vet;
            	
            	string str1(var.tipo);
                if(str1.compare("string") == 0)
                {
                	yyerror("Não implementado!");
                }
            	else {
            		if ($1.traducao == "boolean") {
						$1.traducao = "bool";
					}
	              	$$.traducao = $4.traducao + "\t" + $1.traducao + " " + retornaVariavel($2.label).label + "[" + $4.label + "];\n";            	
            	}
			}
			|
			TIPO TK_ID TK_ABRE_CLCH E TK_FECHA_CLCH TK_ABRE_CLCH E TK_FECHA_CLCH
			{
				struct variavel var = {geraLabel(), $1.traducao, true, false};
				struct matriz mtz = {var.nome, $1.traducao, stringToInt($4.valor), stringToInt($7.valor), false};
                verificaExistenciaEspertinho($2.label);
                empilhaVariavel(var.nome, $1.traducao, var.nome, "", $2.label, false);
            	tabVariaveis[$2.label] = var;
            	tabMatrizes[$2.label] = mtz;
            	
            	string str1(var.tipo);
                if(str1.compare("string") == 0)
                {
                	yyerror("Não implementado!");
                }
            	else {
            		if ($1.traducao == "boolean") {
						$1.traducao = "bool";
					}
	              	$$.traducao = $4.traducao + $7.traducao + "\t" + $1.traducao + " " + retornaVariavel($2.label).label + "[" + $4.label + " * " + $7.label + " + " + $7.label + "];\n";            	
            	}
			}
            ;
			
TIPO		: TK_TIPO_INT | TK_TIPO_FLOAT | TK_TIPO_STRING | TK_TIPO_BOOL | TK_TIPO_CHAR;

VALOR		: TK_NUM | TK_REAL | TK_STRING | TK_BOOLEAN | TK_CHAR;
			
ATT			: TIPO TK_ID '=' E
			{
				struct variavel var = {geraLabel(), $1.traducao, true, false};
				verificaExistenciaEspertinho($2.label);
                tabVariaveis[$2.label] = var;
				$2.tipo = $1.traducao;
				$2.valor = $4.valor;
                string str1(var.tipo);
                empilhaVariavel(var.nome, $1.traducao, var.nome, $4.valor, $2.label, true);

                if(str1.compare("string") == 0)
                {
                	if ($2.tipo == $4.tipo) {
                		$$.traducao = $4.traducao + "\t" + "strcpy(" + retornaVariavel($2.label).label + ", " + $4.label + ");\n";
                	}
                	else {
                		yyerror("Tipos " + $2.tipo + " e " + $4.tipo + " incompatíveis!");
                	}
                
                }
                else {
                    if ($1.traducao == "boolean") {
						$1.traducao = "bool";
					}
					
					// Se tipos float = int, ou são iguais, é possível a atribuição
					if ((retornaVariavel($2.label).tipo == $4.tipo) || ($4.tipo == "int" || retornaVariavel($2.label).tipo == "float")) {
		            	$$.traducao = $4.traducao + "\t" + retornaVariavel($2.label).label + " = " + $4.label + ";\n";
                	}
                	// Soma entre chars
                	else if(($2.valor[$2.valor.length()-1] == '\'') &&  ($2.valor[0] == '\'') || ($4.valor[$4.valor.length()-1] == '\'') &&  ($4.valor[0] == '\'')) {
                		$$.traducao = $4.traducao + "\t" + retornaVariavel($2.label).label + " = " + $4.label + ";\n";
                	}
                	else
                	{
                		yyerror("Tipos incompatíveis!");
                	}
                	
                }
			}
			;

E 			: E TK_SOMA E
			{
				// Variável que verifica se deve empilhar ou não ao fim (Caso seja char, já teria empilhado)
				bool character = 0;
			
				string chave = geraLabel();
				$$.label = chave;
				
				string tipo = getTipo($1.tipo, $2.traducao, $3.tipo);
				
				string str1($1.tipo);
				string str2($3.tipo);
				
				// Verifica se é char (char, não string)
				if(($1.valor[$1.valor.length()-1] == '\'') &&  ($1.valor[0] == '\'') || ($3.valor[$3.valor.length()-1] == '\'') &&  ($3.valor[0] == '\'')) {
					character = 1;
					manipulaChar(chave, str1, str2, "+", $1.valor, $3.valor);
 				}
				// Se não, procedimento normal
				else if($1.tipo != $3.tipo)
				{
					string temp_cast = geraLabel();
					
					if($1.tipo != tipo)
					{
						$1.traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + $1.label + ";\n";
						$1.label = temp_cast;
						$1.tipo = tipo;
					}
					if(($1.tipo == tipo) && tipo == "string") {
						$3.traducao += "\tchar " + temp_cast + "[255];" + "\n\tsnprintf(" + temp_cast + ", 255, \"%d\", " + $3.label + ");\n";
						$3.label = temp_cast;
					}
				}
				
				
				if ((str1.compare("string") == 0)  || (str2.compare("string") == 0)) {
					$$.traducao = $1.traducao + $3.traducao + "\tstrcpy("+ $$.label + ", " + $1.label + ");\n" + "\tstrcat("+ $$.label + ", " + $3.label + ");\n";
				}
				else if (tipo.compare("int") == 0) {
					$$.valor = intToString(stringToInt($1.valor) + stringToInt($3.valor));
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = "+ $1.label + " " + $2.traducao + " " + $3.label + ";\n";
				}
				else {
					$$.tipo = tipo;
					$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = "+ $1.label + " " + $2.traducao + " " + $3.label + ";\n";			}
					
				// Se não é char empilha, caso seja char, já empilhou antes
				if (($1.tipo == "int" && $3.tipo == "int") || ($1.tipo == "float" && $3.tipo == "float") || ($1.tipo == "int" && $3.tipo == "float") || ($1.tipo == "float" && $3.tipo == "int")) {
				
					empilhaVariavel(chave, tipo, chave, $1.valor + $3.valor, "", true);
					$$.valor = intToString(stringToInt($1.valor) + stringToInt($3.valor));
				}
				// Caso aconteça concatenação...
				else if(character == 0) {
					
					string str1;
					string str2;
					
					if (($1.tipo == "string" || $1.tipo == "char") && $1.valor.length() != 0) {
						str1 = $1.valor.substr(1, $1.valor.size()-2);
					}
					
					if (($3.tipo == "string" || $3.tipo == "char") && $3.valor.length() != 0) {
						str2 = $3.valor.substr(1, $3.valor.size()-2);
					}
					
					if ($1.tipo == "int") {
						str1 = $1.valor;
					}
					
					if ($3.tipo == "int") {
						str2 = $3.valor;
					}
				
					$$.valor = '\"' + str1 + str2 + '\"';
					
					if ($1.valor.length() != 0 && $3.valor.length() != 0) {
						empilhaVariavel(chave, tipo, chave, '\"' + str1 + str2 + '\"', "", true);
					}
					else {
						empilhaVariavel(chave, tipo, chave, "", "", true);
					}
				}
			}
			| E TK_SUB E
			{
				bool character = 0;
				
				string chave = geraLabel();
				$$.label = chave;
				
				string tipo = getTipo($1.tipo, $2.traducao, $3.tipo);
				
				string str1($1.tipo);
				string str2($3.tipo);
				
				// Verifica se é char (char, não string)
				if(($1.valor[$1.valor.length()-1] == '\'') &&  ($1.valor[0] == '\'') || ($3.valor[$3.valor.length()-1] == '\'') &&  ($3.valor[0] == '\'')) {
					character = 1;
					manipulaChar(chave, str1, str2, "-", $1.valor, $3.valor);
 				}
				// Se não, procedimento normal
				else if($1.tipo != $3.tipo)
				{
					string temp_cast = geraLabel();
					
					if($1.tipo != tipo)
					{
						$1.traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + $1.label + ";\n";
						$1.label = temp_cast;
						$1.tipo = tipo;
					}
					else
					{
						$3.traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + $3.label + ";\n";
						$3.label = temp_cast;
						$3.tipo = tipo;
					}
					
					if (tipo.compare("int") == 0) {
						$$.valor = intToString(stringToInt($1.valor) - stringToInt($3.valor));
					}
					
					
				}
				
				$$.tipo = tipo;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = "+ $1.label + " " + $2.traducao + " " + $3.label + ";\n";
				
				if(character == 0) {
					empilhaVariavel(chave, tipo, chave, $$.valor, "", true);
				}
			}
			| E TK_MUL E
			{
				bool character = 0;
			
				string chave = geraLabel();
				$$.label = chave;
				
				string tipo = getTipo($1.tipo, $2.traducao, $3.tipo);
				
				string str1($1.tipo);
				string str2($3.tipo);
				
				// Verifica se é char (char, não string)
				if(($1.valor[$1.valor.length()-1] == '\'') &&  ($1.valor[0] == '\'') || ($3.valor[$3.valor.length()-1] == '\'') &&  ($3.valor[0] == '\'')) {
					character = 1;
					manipulaChar(chave, str1, str2, "*", $1.valor, $3.valor);
 				}
				else if($1.tipo != $3.tipo)
				{
					string temp_cast = geraLabel();
					
					if($1.tipo != tipo)
					{
						$1.traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + $1.label + ";\n";
						$1.label = temp_cast;
						$1.tipo = tipo;
					}
					else
					{
						$3.traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + $3.label + ";\n";
						$3.label = temp_cast;
						$3.tipo = tipo;
					}
					
					if (tipo.compare("int") == 0) {
						$$.valor = intToString(stringToInt($1.valor) * stringToInt($3.valor));
					}
				}
				
				$$.tipo = tipo;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = "+ $1.label + " " + $2.traducao + " " + $3.label + ";\n";
				
				if(character == 0) {
					empilhaVariavel(chave, tipo, chave, $$.valor, "", true);
				}
			}
			| E TK_DIV E
			{
				bool character = 0;
			
				string chave = geraLabel();
				$$.label = chave;
				
				string tipo = getTipo($1.tipo, $2.traducao, $3.tipo);
				
				string str1($1.tipo);
				string str2($3.tipo);
				
				// Verifica se é char (char, não string)
				if(($1.valor[$1.valor.length()-1] == '\'') &&  ($1.valor[0] == '\'') || ($3.valor[$3.valor.length()-1] == '\'') &&  ($3.valor[0] == '\'')) {
					character = 1;
					manipulaChar(chave, str1, str2, "/", $1.valor, $3.valor);
 				}
				else if($1.tipo != $3.tipo)
				{
					string temp_cast = geraLabel();
					
					if($1.tipo != tipo)
					{
						$1.traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + $1.label + ";\n";
						$1.label = temp_cast;
						$1.tipo = tipo;
					}
					else
					{
						$3.traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + $3.label + ";\n";
						$3.label = temp_cast;
						$3.tipo = tipo;
					}
					
					if (tipo.compare("int") == 0) {
						$$.valor = intToString(stringToInt($1.valor) / stringToInt($3.valor));
					}
				}
				
				$$.tipo = tipo;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = "+ $1.label + " " + $2.traducao + " " + $3.label + ";\n";
				
				if(character == 0) {
					empilhaVariavel(chave, tipo, chave, $$.valor, "", true);
				}
			}
			| E TK_MOD E
			{
				string chave = geraLabel();
				$$.label = chave;
				
				string tipo = getTipo($1.tipo, $2.traducao, $3.tipo);
				
				if($1.tipo != $3.tipo)
				{
					string temp_cast = geraLabel();
					
					if($1.tipo != tipo)
					{
						$1.traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + $1.label + ";\n";
						$1.label = temp_cast;
						$1.tipo = tipo;
					}
					else
					{
						$3.traducao += "\t" + tipo + " " + temp_cast + " = " + "(" + tipo + ") " + $3.label + ";\n";
						$3.label = temp_cast;
						$3.tipo = tipo;
					}
					
					if (tipo.compare("int") == 0) {
						$$.valor = intToString(stringToInt($1.valor) % stringToInt($3.valor));
					}
				}
				
				$$.tipo = tipo;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.label + " = "+ $1.label + " " + $2.traducao + " " + $3.label + ";\n";
				empilhaVariavel(chave, tipo, chave, $$.valor, "", true);
			}
			| E OP_LOGICA E
			{
				string nome = geraLabel();
				$$.label = nome;	
				empilhaVariavel(nome,"bool", nome, "", "", true);		
				$$.traducao = $1.traducao + $3.traducao + "\n\t" + $$.label + " = " + $1.label + " " + $2.traducao + " " + $3.label  + ";\n";	
			}
			| TK_ABRE_PAR E TK_FECHA_PAR
			{
				$$.tipo = $2.tipo;
				$$.traducao = $2.traducao;
				$$.label = $2.label;
			}
			| E TK_INCREMENTO
			{
				$$.traducao = $1.traducao + "\t" + $1.label + "++;\n";
			}
			| E TK_DECREMENTO
			{
				$$.traducao = $1.traducao + "\t" + $1.label + "--;\n";
			}
			| CHAMADA_FNC
			{
				string label = geraLabel();
				$$.traducao = "\t" + valoresDeclaracao + "\n\t" + $$.label + " = " + $1.traducao + ";\n";
				valoresDeclaracao = "";
			}
			| VALOR
			{
				string nome = geraLabel();
				$$.label = nome;
				
				string str1($1.tipo);
				if (str1.compare("string") == 0) {
					
					string str($1.traducao);
					if (str[str.length()-1] == ' ') {
						str = str.substr(0, str.size()-1);
					}
				
					$$.tipo = "string";
					empilhaVariavel(nome,"char", nome, str, "", true);
					$$.traducao = "\tstrcpy(" + $$.label + ", " + $1.traducao + ");\n";
					$$.tamanho = $1.traducao.length() - 2;
					$1.tamanho = $1.traducao.length() - 2;
					$$.valor = str;
				}
				else {
					if ($1.tipo == "") $1.tipo = "bool";
					
					$$.tipo = $1.tipo;
					empilhaVariavel(nome, $1.tipo, nome, $1.traducao, "", true);
					$$.traducao = "\t" + $$.label + " = " + $1.traducao + ";\n";
					$$.valor = $1.traducao;
					$1.valor = $1.traducao;
				}
			}
			| TK_ID '=' E
			{
				$$.tipo = $3.tipo;
				$$.traducao = $3.traducao + "\t" + retornaVariavel($1.label).label + " = " + $3.label + ";\n";
			}
			| TK_ID TK_ABRE_CLCH E TK_FECHA_CLCH '=' E
			{
				$$.tipo = $3.tipo;
				
				$$.traducao = $3.traducao + $6.traducao + "\t" + retornaVariavel($1.label).label + "[" + $3.label + "] = " + $6.label + ";\n";
				verificaPosicaoVetor($1.label, stringToInt($3.valor));
			}
			| TK_ID TK_ABRE_CLCH E TK_FECHA_CLCH TK_ABRE_CLCH E TK_FECHA_CLCH '=' E
			{
				$$.tipo = $3.tipo;
				
				$$.traducao = $3.traducao + $6.traducao + $9.traducao + "\t" + retornaVariavel($1.label).label + "[" + $3.label + " * " + intToString(tabMatrizes[$1.label].colunas) + " + " + $6.label + "] = " + $9.label + ";\n";
				verificaPosicaoMatriz($1.label, stringToInt($3.valor), stringToInt($6.valor));
			}
			| TK_ID
			{
				$$.tipo = retornaVariavel($1.label).tipo;
				$$.traducao = "";
				$$.label = retornaVariavel($1.label).label;
			}
			| TK_ID TK_ABRE_CLCH E TK_FECHA_CLCH
			{
				$$.tipo = retornaVariavel($1.label).tipo;
				$$.traducao = $3.traducao + "\n";
				$$.label = retornaVariavel($1.label).label + "[" + $3.label + "]";
				verificaPosicaoVetor($1.label, stringToInt($3.valor));
			}
			| TK_ID TK_ABRE_CLCH E TK_FECHA_CLCH TK_ABRE_CLCH E TK_FECHA_CLCH
			{
				$$.tipo = retornaVariavel($1.label).tipo;
				$$.traducao = $3.traducao + "\n";
				$$.label = retornaVariavel($1.label).label + "[" + $3.label + " * " + intToString(tabMatrizes[$1.label].colunas) + " + " + $6.label + "]";
				verificaPosicaoMatriz($1.label, stringToInt($3.valor), stringToInt($6.valor));
			}
			;

CHAMADA_FNC	: TK_ID TK_ABRE_PAR VAR_FNC TK_FECHA_PAR
			{
				// Recuperar label da funcao
				string labelOriginal($1.label);
				funcao fnc = buscarFuncao(labelOriginal);

				$1.tipo = fnc.tipo;
				$$.tipo = $1.tipo;
				$$.label = geraLabel();
				empilhaVariavel($$.label, $1.tipo, $$.label, "", "", true);	
				$$.traducao = fnc.label + "(" + $3.traducao + ")"; 
			}
			;

VAR_FNC		: E
			{
				$$.traducao = $1.label;
				valoresDeclaracao += "\n" + $1.traducao;
			}
			| E ',' VAR_FNC
			{
				$$.traducao = $1.label + ", " + $3.label;
				valoresDeclaracao += $1.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

WRITE		: TK_WRITE TK_ABRE_PAR E TK_FECHA_PAR TK_PNT_VIRGULA
			{
				$$.traducao = $3.traducao +  "\tstd::cout << " + $3.label + " << std::endl;";
			}
			;
			
READ		: TK_READ TK_ABRE_PAR TK_ID TK_FECHA_PAR TK_PNT_VIRGULA 
			{
				$$.traducao = "\tstd::cin >> " + retornaVariavel($3.label).label + ";";
 			}
			;

FOR			: TK_FOR TK_ABRE_PAR ATT TK_PNT_VIRGULA E TK_PNT_VIRGULA E TK_FECHA_PAR ESCOPO
			{
				escopo e = criaEscopo();
				string escopoInicio = e.inicio;
				string escopoVerificacao = e.verificacao;
				string escopoFim = e.fim;
				
				$$.traducao = $3.traducao +"\n" + $5.traducao + "\n\tif(" + $5.label + ") goto " + escopoInicio + "; \n\telse goto " + escopoFim + ";\n\t" + escopoInicio + ":" + $9.traducao + "\n\t" + escopoVerificacao + ":;\n" +  $7.traducao + " \n " + $5.traducao + "\n\tif(" + $5.label + ") goto " + escopoInicio + "; \n\telse goto " + escopoFim + ";\n\t" + escopoFim + ":;\n";
			}
			;
			
WHILE		: TK_WHILE TK_ABRE_PAR E TK_FECHA_PAR ESCOPO
			{
				escopo e = criaEscopo();
				string escopoInicio = e.inicio;
				string escopoVerificacao = e.verificacao;
				string escopoFim = e.fim;

				$$.traducao = $3.traducao + "\n\tif("+ $3.label +") goto " + escopoInicio + "; \n\telse goto " + escopoFim + ";\n\t" + escopoInicio + ":" + $5.traducao + "\n\t" + $3.traducao + "\n\t" + escopoVerificacao + ":;\n\tif(" + $3.label +") goto " + escopoInicio + "; \n\telse goto " + escopoFim +";\n\t" + escopoFim + ":;\n";
			}
			;
DO_WHILE	: TK_DO ESCOPO TK_WHILE TK_ABRE_PAR E TK_FECHA_PAR TK_PNT_VIRGULA
			{
				escopo e = criaEscopo();
				string escopoInicio = e.inicio;
				string escopoVerificacao = e.verificacao;
				string escopoFim = e.fim;

				$$.traducao =  "\t" + escopoInicio + ":\n" + $5.traducao + "\n\t" + $2.traducao + "\n\t" + escopoVerificacao + ":\n\tif("+ $5.label +") goto " + escopoInicio + "; \n\telse goto " + escopoFim + ";\n\t" + escopoFim + ":;\n\t";
			}
			;
IF			: TK_IF TK_ABRE_PAR E TK_FECHA_PAR ESCOPO
			{
				string nomeEscopo = geraEscopo();
				string escopoInicio = nomeEscopo + "inicio";
				string escopoFim = nomeEscopo + "fim";
				$$.traducao = $3.traducao + "\n\tif(" + $3.label + ") goto " + escopoInicio + "; \n\telse  goto " + escopoFim + "; \n\t" + escopoInicio + ":" + $5.traducao + escopoFim + ":;\n";
			}
			| TK_IF TK_ABRE_PAR E TK_FECHA_PAR ESCOPO TK_ELSE IF
			{
				string nomeEscopo = geraEscopo();
				string escopoInicio = nomeEscopo + "inicio";
				string escopoVerificacao = nomeEscopo + "verificacao";
				string escopoFim = nomeEscopo + "fim";
				$$.traducao = $3.traducao + "\n\tif(" + $3.label + ") goto " + escopoInicio + "; \n\telse  goto " + escopoVerificacao + "; \n\t" + escopoInicio + ":" + $5.traducao + "\n\tgoto " + escopoFim + ";\n\t" + escopoVerificacao + ":; \n\t" + $7.traducao + escopoFim + ":;\n";
			}
			| TK_IF TK_ABRE_PAR E TK_FECHA_PAR ESCOPO TK_ELSE ESCOPO
			{
				string nomeEscopo = geraEscopo();
				string escopoInicio = nomeEscopo + "inicio";
				string escopoElse = nomeEscopo + "else";
				string escopoFim = nomeEscopo + "fim";
				$$.traducao = $3.traducao + "\n\tif(" + $3.label +")  goto " + escopoInicio + "; \n\telse  goto " + escopoElse + "; \n\t" + escopoInicio + ":" + $5.traducao  + "\n\t goto "+ escopoFim  + ";\n\t"+ escopoElse + ":" + $7.traducao + escopoFim + ":;\n";
			}
			;
SWITCH		: TK_SWITCH TK_ABRE_PAR TK_ID TK_FECHA_PAR TK_ABRE_CHV CASES TK_FECHA_CHV
			{
				variavelSwitch = buscarNaPilha($3.label);
				$$.traducao = "\n" + variavelSwitch.tipo + " " + temporariaSwitch + " = " + variavelSwitch.nome + ";\n{\n" + $6.traducao + "\n}\n" + fimSwitch + ":;\n";
			}
			;
CASES		: CASE CASES
			{
				$$.traducao = $1.traducao + "\n" + $2.traducao;
			}
			| DEFAULT
			{
				$$.traducao = $1.traducao;
			}
			;
CASE		: TK_CASE E ':' ESCOPO
			{
				if(temporariaSwitch == "")
				{
					temporariaSwitch = geraLabel();
				}
				string nomeEscopo = geraEscopo();
				string inicioEscopo = nomeEscopo + "inicio";
				string fimEscopo = nomeEscopo + "fim";
				if(fimSwitch == "")
				{
					fimSwitch = geraEscopo() + "fimSwitch";
				}
				$$.traducao = "\n" + $2.traducao + "\nif(" + temporariaSwitch + " == " + $2.label + ") goto " + inicioEscopo + "; else goto " + fimEscopo + ";\n" + inicioEscopo + ":;\n" + $4.traducao + "\n goto " + fimSwitch + ";\n\n" + fimEscopo + ":;";
			}
			;
DEFAULT		: TK_DEFAULT ':' ESCOPO
			{
				if(fimSwitch == "")
				{
					fimSwitch = geraEscopo() + "fimSwitch";
				}
				$$.traducao = "\n" + $3.traducao + "\n" + "goto " + fimSwitch + ";";
			}
			|
			{
				if(fimSwitch == "")
				{
					fimSwitch = geraEscopo() + "fimSwitch";
				}
				$$.traducao = "goto " + fimSwitch + ";";
			}
			;
BREAK		: TK_BREAK TK_PNT_VIRGULA
			{
				escopo nomeEscopo = criaBreakOuContinue();
				$$.traducao = "goto " + nomeEscopo.fim + ";";
			}
			;
CONTINUE	: TK_CONTINUE TK_PNT_VIRGULA
			{
				escopo nomeEscopo = criaBreakOuContinue();
				$$.traducao = "goto " + nomeEscopo.verificacao + ";";
			}
			;
RETURN		: TK_RETURN E TK_PNT_VIRGULA
			{
				$$.traducao = $2.traducao + "\n\treturn " + $2.label + ";";
			}
			;
OP_LOGICA	: TK_IGUAL
			{
				$$.traducao = "==";
			}
			| TK_DIFERENTE
			{
				$$.traducao = "!=";
			}
			| TK_E
			{
				$$.traducao = "&&";
			}
			| TK_OU
			{
				$$.traducao = "||";
			}
			| TK_MAIOR_QUE
			{
				$$.traducao = ">";
			}
			| TK_MENOR_QUE
			{
				$$.traducao = "<";
			}
			| TK_MAIOR_IGUAL
			{
				$$.traducao = ">=";
			}
			| TK_MENOR_IGUAL
			{
				$$.traducao = "<=";
			}
			;						

%%

#include "lex.yy.c"

int yyparse();

string getTipo(string var1, string op, string var2)
{
    string tipo_retorno = "";

    tipo_retorno = tabTipos[var1+op+var2];
    if(tipo_retorno != "")    
		return tipo_retorno;
		
	tipo_retorno = tabTipos[var2+op+var1];
	if(tipo_retorno != "")
		return tipo_retorno;
	
	perror("ERRO: Tipos incompativeis");
	exit(EXIT_FAILURE);
}





string geraTraducaoExp(struct atributos ss, struct atributos s1, struct atributos s3, string operador)
{
	return s1.traducao + s3.traducao + "\t" + ss.label + " = " + s1.label + " + " + s3.label + ";\n";
}




map<string, string> geraTabelaTipos()
{
    map<string, string> tabela_tipos;

    const string INT = "int";
    const string FLOAT = "float";
    const string STRING = "string";
    const string CHAR = "char";

    const string INT_MAIS_INT = "int+int";
    const string INT_MAIS_FLOAT = "int+float";
    const string INT_MAIS_STR = "int+string";
    const string INT_MAIS_CHAR = "int+char";
    const string FLOAT_MAIS_FLOAT = "float+float";
    const string FLOAT_MAIS_STRING = "float+string";
    const string CHAR_MAIS_STRING = "char+string";
    const string STRING_MAIS_STRING = "string+string";
    const string CHAR_MAIS_CHAR = "char+char";
    
    const string CHAR_MENOS_CHAR = "char-char";
    const string CHAR_VEZES_CHAR = "char*char";
    const string CHAR_DIV_CHAR = "char/char";

    const string INT_MENOS_INT = "int-int";
    const string INT_MENOS_FLOAT = "int-float";
    const string INT_MENOS_CHAR = "int-char";
    const string FLOAT_MENOS_FLOAT = "float-float";
    
    const string INT_VEZES_CHAR = "int*char";
    const string INT_DIV_CHAR = "int/char";
    
    const string INT_VEZES_INT = "int*int";
    const string INT_VEZES_FLOAT = "int*float";
    const string FLOAT_VEZES_FLOAT = "float*float";

    const string INT_DIV_INT = "int/int";
    const string INT_DIV_FLOAT = "int/float";
    const string FLOAT_DIV_FLOAT = "float/float";
    
    const string FLOAT_MOD_FLOAT = "float%float";
    const string INT_MOD_INT = "int%int";
    const string INT_MOD_FLOAT = "int%float";


    tabela_tipos[INT_MAIS_INT] = INT;
    tabela_tipos[INT_MAIS_FLOAT] = FLOAT;
    tabela_tipos[INT_MAIS_STR] = STRING;
    tabela_tipos[INT_MAIS_CHAR] = CHAR;
    tabela_tipos[FLOAT_MAIS_FLOAT] = FLOAT;
    tabela_tipos[FLOAT_MAIS_STRING] = STRING;
    tabela_tipos[CHAR_MAIS_CHAR] = STRING;
    
    tabela_tipos[CHAR_MENOS_CHAR] = CHAR;
    tabela_tipos[CHAR_VEZES_CHAR] = CHAR;
    tabela_tipos[CHAR_DIV_CHAR] = CHAR;
    tabela_tipos[INT_VEZES_CHAR] = CHAR;
    tabela_tipos[INT_DIV_CHAR] = CHAR;
    
    tabela_tipos[CHAR_MAIS_STRING] = STRING;
    tabela_tipos[STRING_MAIS_STRING] = STRING;
    
    tabela_tipos[INT_MENOS_INT] = INT;
    tabela_tipos[INT_MENOS_FLOAT] = FLOAT;
    tabela_tipos[INT_MENOS_CHAR] = CHAR;
    tabela_tipos[FLOAT_MENOS_FLOAT] = FLOAT;
    
    tabela_tipos[INT_VEZES_INT] = INT;
    tabela_tipos[INT_VEZES_FLOAT] = FLOAT;
    tabela_tipos[FLOAT_VEZES_FLOAT] = FLOAT;
    
    tabela_tipos[INT_DIV_INT] = INT;
    tabela_tipos[INT_DIV_FLOAT] = FLOAT;
    tabela_tipos[FLOAT_DIV_FLOAT] = FLOAT;
    
    tabela_tipos[INT_MOD_INT] = INT;
    tabela_tipos[FLOAT_MOD_FLOAT] = FLOAT;
    tabela_tipos[INT_MOD_FLOAT] = FLOAT;
    
    return tabela_tipos;   
}

string intToString(int valor)
{
	stringstream out;
	out << valor;
	return out.str();
}
int stringToInt(string temp)
{
	return atoi(temp.c_str());
}

string floatToString(float valor)
{
	stringstream out;
	out << valor;
	return out.str();
}
float stringToFloat(string temp)
{
	return atoi(temp.c_str());
}

string geraLabel()
{
	static int i = 0;
	stringstream label;
	label << "temp_" << i++;
	
	return label.str();
	
}

string geraLabelGlobal()
{
	static int i = 0;
	stringstream label;
	label << "gtemp_" << i++;
	
	return label.str();
	
}

string geraEscopo()
{
	static int i = 0;
	stringstream label;
	label << "escopo_" << i++ << "_";
	
	return label.str();
	
}

escopo criaEscopo()
{
	escopo nomeEscopo;
	if(escopos.empty())
	{
		string labelEscopo = geraEscopo();
		nomeEscopo.inicio = labelEscopo + "inicio";
		nomeEscopo.verificacao = labelEscopo + "verificacao";
		nomeEscopo.fim = labelEscopo + "fim";
	}
	else
	{
		nomeEscopo = escopos.front();
		escopos.pop_front();
	}
	return nomeEscopo;
}

void verificaExistencia(string label)
{
	map<string,variavel>::const_iterator
	iterator(tabVariaveis.begin()),
    	mend(tabVariaveis.end());
    	
    for(; iterator != mend; ++iterator)
	{
		if ((iterator->first == label) && (iterator->second.declarada == true)) {
			if (!(iterator->second.funcao == true))
				yyerror("Variável '" + label + "' já declarada!");
		}
	}
}

void verificaExistenciaEspertinho(string label)
{
	map<string,atributos> mapa = pilhaVariaveis.front();
	map<string,atributos>::const_iterator
	iterator(mapa.begin()),
    	mend(mapa.end());
    
    	for(;iterator!=mend;++iterator)
		{
			if ((iterator->second.nomeOriginal == label) && (iterator->second.nomeOriginal != "")) 
					yyerror("Variável '" + label + "' já declarada!");
    	}
 }	
 
atributos retornaVariavel(string label)
{
	map<string,atributos> mapa = pilhaVariaveis.front();
	map<string,atributos>::const_iterator
	iterator(mapa.begin()),
    	mend(mapa.end());
    
    	for(;iterator!=mend;++iterator)
		{
			if ((iterator->second.nomeOriginal == label))
				return iterator->second;
    	}
    	
		variavel var = buscarNaPilha(label);
		atributos atr;
		atr.tipo = var.tipo;
		atr.label = var.nome;
		atr.nomeOriginal = label;
		return atr;
		yyerror("Variável '" + label + "' não declarada neste escopo!");
 }	

void empilhaVariavel(string chave, string tipo, string label, string valor, string nomeOriginal, bool desempilhar)
{
	verificaExistenciaEspertinho(nomeOriginal);
	
	map<string, atributos> mapa = pilhaVariaveis.front();
	mapa.erase(chave);	
	atributos atr;
	atr.valor = valor;	
	atr.tipo = tipo;
	atr.label = label;
	atr.nomeOriginal = nomeOriginal;
	atr.desempilha = desempilhar;
	
	mapa.insert(pair<string, atributos>(chave,atr));
	pilhaVariaveis.pop_front();
	pilhaVariaveis.push_front(mapa);
}

void adicionaFuncao(string chave, string label, string tipo)
{	
	funcao fnc;	
	fnc.tipo = tipo;
	fnc.label = label;
	
	if (!listaParametros.empty()) {		
		copy( listaParametros.begin(), listaParametros.end(), back_inserter(fnc.parametros) );	
		atributos atr = fnc.parametros.front();
		atributos atl = fnc.parametros.back();
	}
	
	funcoes.insert(pair<string, funcao>(chave, fnc));
}

bool compararParametros(list<atributos> fnc1, list<atributos> fnc2)
{
	if (fnc1.size() != fnc2.size()) {
		return false;
	}
	
	if (fnc1.size() == 0 && fnc2.size()) {
		return true;
	}
	
    for (list<atributos>::const_iterator iterator = fnc1.begin(), end = fnc1.end(); iterator != end; ++iterator) {
  		atributos atr = fnc2.front();
		fnc2.pop_front();
		if (iterator->nomeOriginal != atr.nomeOriginal) {
			return false;
		}  	
	}
    	
	
	return true;
}

funcao buscarFuncao(string label)
{
	map<string, funcao>::const_iterator
	iterator(funcoes.begin()),
    	mend(funcoes.end());
    	
    for(; iterator != mend; ++iterator)
	{
		if (iterator->first == label) {
			return iterator->second;
		}
	}
	yyerror("Função '" + label + "' não declarada!");
}


variavel buscarNaPilha(string label)
{
	map<string, variavel>::const_iterator
	iterator(tabVariaveis.begin()),
    	mend(tabVariaveis.end());
    	
    for(; iterator != mend; ++iterator)
	{
		if (iterator->first == label) {
			return iterator->second;
		}
	}
	yyerror("Variável '" + label + "' não declarada!");
}

funcao retornaFuncao(string label)
{
	listaFuncoes::const_iterator
	iterator(funcoes.begin()),
    	mend(funcoes.end());
    	
    for(; iterator != mend; ++iterator)
	{
		if (iterator->first == label) {
			return iterator->second;
		}
	}
	yyerror("Função '" + label + "' não declarada!");
}

string desempilhaTudo(map<string,atributos> mapa)
{
	map<string,atributos>::const_iterator
	iterator(mapa.begin()),
    	mend(mapa.end());
    
   	 string s;
    
    	for(;iterator!=mend;++iterator)
		{
			// Poe as variaveis no início do ESCOPO.
			if(iterator->second.tipo == "string" && iterator->second.desempilha == true)
			{
				string tipo = "char";
				int tam = iterator->second.valor.length() - 2;
				if (tam < 0) tam = 255;
				s += "\t" + tipo + " " + iterator->second.label + "[" + intToString(tam) + "];\n";
			}
			else if (iterator->second.tipo == "char" && iterator->second.desempilha == true)
			{
				string str = iterator->second.valor;
				
				// Significa que é char
				if ((str[str.length()-1] == '\'') &&  (str[0] == '\'')) {
					s += "\t" + iterator->second.tipo + " " + iterator->second.label + ";\n";
 				}
 				// É String
 				else {
 					int tam = str.length() - 2;
 					if (tam < 0) tam = 255;
					s += "\t" + iterator->second.tipo + " " + iterator->second.label + "[" + intToString(tam) + "];\n";
 				}
			}
			else if (iterator->second.desempilha == true)
			{
				if (iterator->second.tipo == "boolean") {
					s += "\tbool " + iterator->second.label +";\n";
				}
				else
					s += "\t" + iterator->second.tipo + " " + iterator->second.label +";\n";
			}
    	}
	
	return s;	
}

escopo criaBreakOuContinue()
{
	if(temBreakOuContinue)
	{
		return escopos.front();
	}
	else
	{
		temBreakOuContinue = 1;
		escopo nomeEscopo;
		
		string labelEscopo = geraEscopo();
		
		nomeEscopo.inicio = labelEscopo + "inicio";
		nomeEscopo.verificacao = labelEscopo + "verificacao";
		nomeEscopo.fim = labelEscopo + "fim";
		escopos.push_front(nomeEscopo);
		return nomeEscopo;
	}
	
}

void verificaPosicaoVetor(string label, int posicao)
{
	if (tabVetores[label].tamanho <= posicao || (0 > posicao)) {
		if (tabVetores[label].funcao == false) {
			yyerror("Posição '" + intToString(posicao) + "' não presente no vetor!");
		}
	}
}

void verificaPosicaoMatriz(string label, int linhas, int colunas)
{
	if (((tabMatrizes[label].linhas <= linhas) && (tabMatrizes[label].colunas <= colunas)) || ((0 > linhas) && (0 > colunas))) {
		if (tabMatrizes[label].funcao == false) {
			yyerror("Posição linha '" + intToString(linhas) + "' e posicao coluna '" + intToString(colunas) + "' não presente no vetor!");
		}
	}
}

void manipulaChar(string chave, string str1, string str2, string op, string s1valor, string s3valor) {
	char resultado;
					
	// Se a operação é entre char e string, não faz cast
	if ((str1 == "int" && str2 == "char")) {
		// Don't cast!
		int valor1 = stringToInt(s1valor);
		char valor2 = s3valor[1];
		
		if (op == "+") resultado = valor1 + valor2;
		if (op == "-") resultado = valor1 - valor2;
		if (op == "*") resultado = valor1 * valor2;
		if (op == "/") resultado = valor1 / valor2;
	}
	if (str1 == "char" && str2 == "int") {
		// Don't cast!
		int valor2 = stringToInt(s1valor);
		char valor1 = s3valor[1];	
		
		if (op == "+") resultado = valor1 + valor2;
		if (op == "-") resultado = valor1 - valor2;
		if (op == "*") resultado = valor1 * valor2;
		if (op == "/") resultado = valor1 / valor2;			
	}
					
	if (str1 == "char" && str2 == "char") {
		char valor2 = s1valor[1];
		char valor1 = s3valor[1];
		
		if (op == "+") resultado = valor1 + valor2;
		if (op == "-") resultado = valor1 - valor2;
		if (op == "*") resultado = valor1 * valor2;
		if (op == "/") resultado = valor1 / valor2;						
	}
											
	stringstream ss;
	string s;
	ss << resultado;
	ss >> s;	
						
	empilhaVariavel(chave, "char", chave, "\'" + s + "\'", "", true);
}


int main( int argc, char* argv[] )
{
	yyparse();

	return 0;
}

void yyerror( string MSG )
{
	cout << MSG << endl;
	exit (0);
}				
