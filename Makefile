all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl

		./glf < contexto.bx > main.cpp
		g++ main.cpp -o main
		./main
