%{
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <utility>


#define MAX_VAR 1000
#define YYSTYPE atributos

using namespace std;

struct atributos
{
	string label, tipo, traducao;
};

struct variavel
{
    string nome, tipo;
};

int variaveis[MAX_VAR];

int yylex(void);
string geraLabel();
string getTipo(string var1, string op, string var2);
map<string, string> geraTabelaTipos();
void yyerror(string);

map<string, struct variavel> tabVariaveis;
map<string, string> tabTipos = geraTabelaTipos();

%}

%token TK_NUM  TK_ABRE_PAR TK_FECHA_PAR TK_ABRE_CHV TK_FECHA_CHV TK_PNT_VIRGULA
%token TK_MAIN TK_ID TK_TIPO_INT TK_TIPO_FLOAT TK_IF TK_ELSE TK_DO TK_WHILE TK_FOR TK_SOMA TK_SUB TK_MUL TK_DIV
%token TK_FIM TK_ERROR  TK_REAL

%start S

%left TK_SOMA TK_SUB
%left TK_MUL TK_DIV


%%

S 			: TK_TIPO_INT TK_MAIN TK_ABRE_PAR TK_FECHA_PAR BLOCO
			{
				cout << "/*Compilador FOCA*/\n" << "#include <iostream>\n#include<string.h>\n#include<stdio.h>\nint main(void)\n{\n" << $5.traducao << "\treturn 0;\n}" << endl; 
			}
			;

BLOCO		: TK_ABRE_CHV COMANDOS TK_FECHA_CHV
			{
				$$.traducao = $2.traducao;
			}
			;

COMANDOS	: COMANDO TK_PNT_VIRGULA COMANDOS
			{
				$$.traducao = $1.traducao + "\n" + $3.traducao;
			}
			|
			{
				$$.traducao = "";
			}
			;

COMANDO 	: ATT 
			| E
			| DECLARACAO
			;

DECLARACAO	: TIPO TK_ID
            {
                struct variavel var = {geraLabel(), $1.traducao};
            	tabVariaveis[$2.label] = var;
              	$$.traducao = "\t" + $1.traducao + " " + tabVariaveis[$2.label].nome + ";\n";
            }
            ;
			
TIPO		: TK_TIPO_INT | TK_TIPO_FLOAT ;

VALOR		: TK_NUM | TK_REAL ;
			
ATT			: TK_ID '=' E
			{
				struct variavel var = {geraLabel(), $1.traducao};
                tabVariaveis[$2.label] = var;
                $$.traducao = "\t" + $1.traducao + " " + tabVariaveis[$2.label].nome + ";\n";
			}
			|
			TIPO TK_ID '=' E
			{
				struct variavel var = {geraLabel(), $1.traducao};
                tabVariaveis[$2.label] = var;
                $$.traducao = $4. traducao + "\t" + $1.traducao + " " + tabVariaveis[$2.label].nome + ";\n\t" + tabVariaveis[$2.label].nome + " = " + $4.label + ";\n";
			}
			;

OP_MAIS_MENOS   : TK_SOMA | TK_SUB ;

OP_MUL_DIV   : TK_MUL | TK_DIV ;

OPERADOR    : OP_MAIS_MENOS | OP_MUL_DIV ;

E 			: E OPERADOR E
			{
				$$.label = geraLabel();
				
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
				}
				
				$$.tipo = tipo;
				$$.traducao = $1.traducao + $3.traducao + "\t" + $$.tipo + " " + $$.label + " = "+ $1.label + " " + $2.traducao + " " + $3.label + ";\n";
			}

			| TK_ABRE_PAR E TK_FECHA_PAR
			{
				$$.traducao = $2.traducao;
				$$.label = $2.label;
			}
			| VALOR
			{
				$$.label = geraLabel();
				$$.traducao = "\t"+ $$.tipo + " " + $$.label + " = " + $1.traducao + ";\n";
			}
			| TK_ID '=' E
			{
				$$.traducao = $3.traducao + "\t" + tabVariaveis[$1.label].nome + " = " + $3.label + ";\n";
			}
			
			| TK_ID
			{
				$$.traducao = "";
				$$.label = tabVariaveis[$1.label].nome;
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

    const string INT_MENOS_INT = "int-int";
    const string INT_MENOS_FLOAT = "int-float";
    const string INT_MENOS_CHAR = "int-char";
    const string FLOAT_MENOS_FLOAT = "float-float";

    const string INT_VEZES_INT = "int*int";
    const string INT_VEZES_FLOAT = "int*float";
    const string FLOAT_VEZES_FLOAT = "float*float";

    const string INT_DIV_INT = "int/int";
    const string INT_DIV_FLOAT = "int/float";
    const string FLOAT_DIV_FLOAT = "float/float";


    tabela_tipos[INT_MAIS_INT] = INT;
    tabela_tipos[INT_MAIS_FLOAT] = FLOAT;
    tabela_tipos[INT_MAIS_STR] = STRING;
    tabela_tipos[INT_MAIS_CHAR] = CHAR;
    tabela_tipos[FLOAT_MAIS_FLOAT] = FLOAT;
    tabela_tipos[FLOAT_MAIS_STRING] = STRING;
    tabela_tipos[CHAR_MAIS_CHAR] = STRING;
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
    
    return tabela_tipos;   
}

string geraLabel()
{
	static int i = 0;
	stringstream label;
	label << "temp_" << i++;
	
	return label.str();
	
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
