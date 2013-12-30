%{
#include <string>

using namespace std;
%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
ID {LETRA}({LETRA}|{NUM})*

OPERADOR "/"|"+"|"-"|"="|"*"

%%

"\n"		{}

{DELIM} 	{}


"main"		{yylval.traducao = yytext; return TK_MAIN;}

"int"		{ yylval.traducao = yytext; return TK_TIPO_INT;}

"float"       { yylval.traducao = yytext; return TK_TIPO_FLOAT;}

"if"		{ yylval.traducao = yytext; return TK_IF; 		}

"else"		{ yylval.traducao = yytext; return TK_ELSE; 		}

"do"		{yylval.traducao = yytext;  return TK_DO; 		}

"while"		{ yylval.traducao = yytext; return TK_WHILE; 		}

"for"		{yylval.traducao = yytext;  return TK_FOR; 		}

[+]         {yylval.traducao = yytext; return TK_SOMA;  }

[-]         {yylval.traducao = yytext; return TK_SUB;  }

[*]         {yylval.traducao = yytext; return TK_MUL;  }

[/]         {yylval.traducao = yytext; return TK_DIV;  }

[(]		    { yylval.traducao = yytext; return TK_ABRE_PAR; 	}

[)]		    { yylval.traducao = yytext; return TK_FECHA_PAR; 	}

[{]			{  yylval.traducao = yytext;  return TK_ABRE_CHV;	}

[}]		    {  yylval.traducao = yytext; return TK_FECHA_CHV;	}

[;]         {  yylval.traducao = yytext; return TK_PNT_VIRGULA;  }


[(){}[\];,]	{ return *yytext; }


{NUM}       { yylval.traducao = yytext; yylval.tipo = "int"; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{REAL}      { yylval.traducao = yytext; yylval.tipo = "float"; return TK_REAL; }

.			{ return *yytext; }

%%
