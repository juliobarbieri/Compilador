%{
#include <string>

using namespace std;
%}

ESPACO [ \t]
DIGITO [0-9]
LETRA [A-Za-z_]

SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\n\f]

DELIM {ESPACO}+
NUM {DIGITO}+
REAL {NUM}+("."{NUM}+)?
CHAR \'({LETRA}|{NUM})\'
BOOLEAN TRUE|FALSE
ID {LETRA}({LETRA}|{NUM})*
STRING ({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+

OPERADOR "/"|"+"|"-"|"="|"*"

%%

"\n"		{}

{DELIM} 	{}


"main"		{yylval.traducao = yytext; return TK_MAIN;}

"int"		{ yylval.traducao = yytext; return TK_TIPO_INT;}

"float"       { yylval.traducao = yytext; return TK_TIPO_FLOAT;}

"string"       { yylval.traducao = yytext; return TK_TIPO_STRING;}

"char"       { yylval.traducao = yytext; return TK_TIPO_CHAR;}

"boolean"	{ yylval.traducao = yytext; return TK_TIPO_BOOL; }

"if"		{ yylval.traducao = yytext; return TK_IF; 		}

"else"		{ yylval.traducao = yytext; return TK_ELSE; 		}

"do"		{yylval.traducao = yytext;  return TK_DO; 		}

"while"		{ yylval.traducao = yytext; return TK_WHILE; 		}

"for"		{ yylval.traducao = yytext;  return TK_FOR; 		}

"switch"	{ yylval.traducao = yytext;  return TK_SWITCH; 		}

"case"		{ yylval.traducao = yytext;  return TK_CASE; 		}

"default"	{ yylval.traducao = yytext;  return TK_DEFAULT; 		}

"break"		{ yylval.traducao = yytext;  return TK_BREAK; 		}

"continue"	{ yylval.traducao = yytext;  return TK_CONTINUE; 		}

"read"		{ yylval.traducao = yytext; return TK_READ; }

"write"		{ yylval.traducao = yytext; return TK_WRITE; }

"return"	{ yylval.traducao = yytext; return TK_RETURN; }

[+]         {yylval.traducao = yytext; return TK_SOMA;  }

[-]         {yylval.traducao = yytext; return TK_SUB;  }

[*]         {yylval.traducao = yytext; return TK_MUL;  }

[/]         {yylval.traducao = yytext; return TK_DIV;  }

[%]			{ yylval.traducao = yytext; return TK_MOD;	}

"<"			{ yylval.traducao = yytext; return TK_MENOR_QUE;	}

">"			{ yylval.traducao = yytext; return TK_MAIOR_QUE;	}

"<="		{ yylval.traducao = yytext; return TK_MENOR_IGUAL;	}

">="		{ yylval.traducao = yytext; return TK_MAIOR_IGUAL;	}

"=="		{ yylval.traducao = yytext; return TK_IGUAL;	}

"!="		{ yylval.traducao = yytext; return TK_DIFERENTE;	}

"&&"		{ yylval.traducao = yytext; return TK_E;	}

"||"		{ yylval.traducao = yytext; return TK_OU;	}

"!"			{ yylval.traducao = yytext; return TK_NEGACAO;	}

"++"		{ yylval.traducao = yytext; return TK_INCREMENTO;	}

"--"		{ yylval.traducao = yytext; return TK_DECREMENTO;	}

[(]		    { yylval.traducao = yytext; return TK_ABRE_PAR; 	}

[)]		    { yylval.traducao = yytext; return TK_FECHA_PAR; 	}

[{]			{  yylval.traducao = yytext;  return TK_ABRE_CHV;	}

[}]		    {  yylval.traducao = yytext; return TK_FECHA_CHV;	}

[[]			{  yylval.traducao = yytext;  return TK_ABRE_CLCH;	}

[]]		    {  yylval.traducao = yytext; return TK_FECHA_CLCH;	}

[;]         {  yylval.traducao = yytext; return TK_PNT_VIRGULA;  }


[(){}[\];,]	{ return *yytext; }


{BOOLEAN}	{
				if(yytext == "TRUE")
				{
					yylval.traducao = "1";
					return TK_BOOLEAN;
				}
				else
				{
					yylval.traducao = "0";
					return TK_BOOLEAN;
				}
			}
{NUM}       { yylval.traducao = yytext; yylval.tipo = "int"; return TK_NUM; }
{ID}		{ yylval.label = yytext; return TK_ID; }
{REAL}      { yylval.traducao = yytext; yylval.tipo = "float"; return TK_REAL; }
{CHAR}		{ yylval.traducao = yytext; yylval.tipo = "char"; return TK_CHAR; }
{STRING}    { yylval.traducao = yytext; yylval.tipo = "string"; return TK_STRING; }


.			{ return *yytext; }

%%
