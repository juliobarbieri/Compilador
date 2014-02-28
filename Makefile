all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y
		g++ -o glf y.tab.c -lfl

		./glf < matrix.bx > main.cpp
		g++ main.cpp -o main
		./main
